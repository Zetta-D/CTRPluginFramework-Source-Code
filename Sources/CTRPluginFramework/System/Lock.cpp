#include "CTRPluginFramework/System/Lock.hpp"

namespace CTRPluginFramework
{
	Lock::Lock(LightLock &llock) : _type(1), _llock(llock)
	{
		LightLock_Lock(llock);
	}

	Lock::Lock(RecursiveLock &rlock) : _type(2), _rlock(rlock)
	{
		RecursiveLock_Lock(rlock);
	}

	Lock::Lock(Mutex &mutex) : _type(3), _mutex(mutex)
	{
		Mutex::Lock(mutex._lock);
	}

	Lock Lock::~Lock(void)
	{
		switch (_type)
		{
			case 1:
				LightLock_Unlock(_llock);
				break;
			case 2:
				RecursiveLock_Unlock(_rlock);
				break;
			case 3:
				Mutex::Unlock();
				break;
		}
	}
}