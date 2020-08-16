#include "types.h"
#include "ctrulib/srv.h"
#include "ctrulib/gfx.h"
#include "ctrulib/archive.h"
#include "ctrulib/services/apt.h"
#include "ctrulib/services/fs.h"
#include "ctrulib/services/hid.h"

void __attribute__((weak)) userAppExit(void);

void __attribute__((weak)) __appExit(void)
{
	if (&userAppExit) userAppExit();

	// Exit services
	archiveUnmountAll();
	fsExit();

	hidExit();
	aptExit();
	srvExit();
}