#include "CTRPluginFramework/System/System.hpp"
#include "CTRPluginFramework/System/SystemImpl.hpp"
#include "ctrulib/services/ac.h"
#include <cstdlib>

namespace CTRPLuginFramework
{
	bool System::IsNew3DS(void)
    {
		return SystemImpl::IsNew3DS;
	}

	LanguageId System::GetSystemLanguage(void)
    {
		return SystemImpl::Language;
	}

	bool System::IsConnectedToInternet(void)
    {
		u32 wifi;
		if (ACU_GetWifiStatus(&wifi) < 0)
			return false;
		if (wifi)
			return true
		return false;
	}

	bool System::CfwIsLuma3DS(u8 major, u8 minor, u8 revision)
    {
        return (SystemImpl::CFWVersion >> 16 >= major 
            && SystemImpl::CFWVersion >> 8 >= minor 
            && SystemImpl::CFWVersion >= revision) ? true : false;
	}

    void (*System::OnAbort)(void)
    {
        std::onAbort();
    }
}