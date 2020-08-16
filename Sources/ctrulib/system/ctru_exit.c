#include "types.h"
#include "ctrulib/svc.h"
#include "ctrulib/env.h"

extern u32 __ctru_heap;
extern u32 __ctru_heap_size;
extern u32 __ctru_linear_heap;
extern u32 __ctru_linear_heap_size;

extern void (*__system_retAddr)(void);

void envDestroyHandles(void);
Result __sync_fini(void);

void __attribute__((weak)) __attribute__((noreturn)) __libctru_exit(int rc)
{
	u32 tmp=0;

	// Unmap the linear heap
	svcControlMemory(&tmp, __ctru_linear_heap, 0x0, __ctru_linear_heap_size, MEMOP_FREE, 0x0);

	// Unmap the application heap
	svcControlMemory(&tmp, __ctru_heap, 0x0, __ctru_heap_size, MEMOP_FREE, 0x0);

	// Close some handles
	envDestroyHandles();

	// Finalize the synchronization subsystem
	__sync_fini();

	// Jump to the loader if it provided a callback
	if (__system_retAddr)
		__system_retAddr();

	// Since above did not jump, end this process
	svcExitProcess();
}