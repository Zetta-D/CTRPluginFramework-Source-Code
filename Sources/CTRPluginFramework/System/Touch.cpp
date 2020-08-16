#include "CTRPluginFramework/System/Touch.hpp"
#include "CTRPluginFramework/System/Controller.hpp"
#include "ctrulib/hid.h"

namespace CTRPluginFramework
{
	bool Touch::IsDown(void)
    {
		return (Controller::GetKeysDown() >> 20) & 1;
	}

	UIntVector Touch::GetPosition(void)
    {
		UIntVector pos;
		touchPosition touchP;
		hidTouchRead(&touchP);
		pos.x = touchP.px;
		pos.y = touchP.py;
		return pos;
	}

}