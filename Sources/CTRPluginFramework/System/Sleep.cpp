#include "CTRPluginFramework/System/Sleep.hpp"
#include "ctrulib/svc.h"

namespace CTRPluginFramework
{
	void Sleep(Time sleepTime)
	{
		if (sleepTime > Time::Zero)
			svcSleepThread(1000 * Time::AsMicroseconds(sleepTime._microseconds));
	}
}