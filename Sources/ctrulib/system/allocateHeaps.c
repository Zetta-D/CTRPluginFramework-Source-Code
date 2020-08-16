#include "ctrulib/svc.h"
#include "ctrulib/allocator/mappable.h"
#include "ctrulib/env.h"
#include "ctrulib/os.h"

#define DEFAULT_LINEAR_HEAP_SIZE (32 << 20) // 32MB

extern char* fake_heap_start;
extern char* fake_heap_end;

u32 __ctru_heap;
u32 __ctru_linear_heap;

__attribute__((weak)) u32 __ctru_heap_size        = 0;
__attribute__((weak)) u32 __ctru_linear_heap_size = 0;

void __attribute__((weak)) __system_allocateHeaps(void) {
	u32 tmp = 0;
	u32 remaining = osGetMemRegionFree(MEMREGION_APPLICATION) &~ 0xFFF;

	if (__ctru_heap_size + __ctru_linear_heap_size > remaining)
		svcBreak(USERBREAK_PANIC);

	if (__ctru_heap_size == 0 && __ctru_linear_heap_size == 0) {
		// By default, automatically allocate all remaining free memory, aligning to page size.
		__ctru_linear_heap_size = (remaining / 2) & ~0xFFF;
		__ctru_linear_heap_size = __ctru_linear_heap_size <= DEFAULT_LINEAR_HEAP_SIZE ? __ctru_linear_heap_size : DEFAULT_LINEAR_HEAP_SIZE;
		__ctru_heap_size = remaining - __ctru_linear_heap_size;
	} else if (__ctru_heap_size == 0) {
		__ctru_heap_size = remaining - __ctru_linear_heap_size;
	} else if (__ctru_linear_heap_size == 0) {
		__ctru_linear_heap_size = remaining - __ctru_heap_size;
	}

	// Allocate the application heap
	__ctru_heap = 0x08000000;
	svcControlMemory(&tmp, __ctru_heap, 0x0, __ctru_heap_size, MEMOP_ALLOC, MEMPERM_READ | MEMPERM_WRITE);

	// Allocate the linear heap
	svcControlMemory(&__ctru_linear_heap, 0x0, 0x0, __ctru_linear_heap_size, MEMOP_ALLOC_LINEAR, MEMPERM_READ | MEMPERM_WRITE);

	// Mappable allocator init
	mappableInit(0x10000000, 0x14000000);

	// Set up newlib heap
	fake_heap_start = (char*)__ctru_heap;
	fake_heap_end = fake_heap_start + __ctru_heap_size;

}
