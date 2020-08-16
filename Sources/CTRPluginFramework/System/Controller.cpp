#include "CTRPluginFramework/System/Controller.hpp"
#include "ctrulib/services/hid.h"

namespace CTRPluginFramework
{
	u32 Controller::_keysDown = hidKeysDown(),
		Controller::_keysHeld = hidKeysHeld(),
		Controller::_keysReleased = hidKeysUp();

	void Controller::Update(void)
    {
		hidScanInput();
		_keysDown = hidKeysDown();
		_keysHeld = hidKeysHeld();
		_keysReleased = hidKeysUp();
	}

	u32 Controller::GetKeysDown(void)
    {
		return _keysDown | _keysHeld;
	}

	u32 Controller::GetKeysReleased(void)
    {
		return _keysReleased;
	}

	bool Controller::IsKeyDown(Key key)
    {
		return (key & _keysHeld) != 0;
	}

	bool Controller::IsKeyPressed(Key key)
    {
		return (key & _keysDown) != 0;
	}

	bool Controller::IsKeyReleased(Key key)
    {
		return (key & _keysReleased) != 0;
	}

	bool Controller::IsKeysDown(u32 keys)
    {
		return (keys & ~_keysHeld) == 0;
	}

	bool Controller::IsKeysPressed(u32 keys)
    {
		return (_keysDown & keys) ? (keys & ~(_keysDown | _keysHeld)) == 0 : 0;
	}

	bool Controller::IsKeysReleased(u32 keys)
    {
		return (keys & ~_keysReleased) == 0;
	}

	void Controller::InjectTouch(u16 posX, u16 posY)
    {
		for (int i = 200; i < 264; i += 8)
        {
			*(u16*)(hidSharedMem + i) = posX;
			*(u16*)(hidSharedMem + i + 2) = posY;
			*(u32*)(hidSharedMem + i + 4) = 1;
		}
		*(u64*)(hidSharedMem + 168) = svcGetSystemTick();
	}

	void Controller::InjectKey(u32 key)
    {
		for (int i = 40; i < 168; i += 16)
			*(u32*)(hidSharedMem + i) |= key;
	}
}