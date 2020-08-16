#include "CTRPluginFramework/System/Mutex.hpp"

namespace CTRPluginFramework
{
	Mutex::Mutex(void)
    {
		RecursiveLock_Init(&_lock);
	}

	Mutex::~Mutex(void)
    {
		RecursiveLock_Unlock(&_lock);
	}

    void Mutex::Lock(void)
    {
        RecursiveLock_Lock(&_lock);
    }

    bool Mutex::TryLock(void)
    {
        return RecursiveLock_TryLock(&_lock) != 0;
    }

    void    Unlock(void)
    {
        RecursiveLock_Unlock(&_lock);
    }
}