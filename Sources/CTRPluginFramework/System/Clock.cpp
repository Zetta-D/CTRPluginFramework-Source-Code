#include "CTRPluginFramework/System/Clock.hpp"
#include "ctrulib/svc.h"

namespace CTRPluginFramework
{
	Time GetCurrentTime(void) const
	{
		return Seconds(svcGetSystemTick());
	}

	Clock::Clock(void) : _startTime(GetCurrentTime()) {}

	Clock::Clock(Time time) : _startTime(time) {}

	Time Clock::GetElapsedTime(void) const
	{
		return GetCurrentTime() - _startTime;
	}

	bool Clock::HasTimePassed(Time time) const
	{
		return time >= _startTime;
	}

	Time Clock::Restart(Time time)
	{
		Time time(GetCurrentTime() - _startTime);
		_startTime = 0;
		return time;
	}
}