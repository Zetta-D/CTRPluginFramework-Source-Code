#include "CTRPluginFrameworkImpl/System/SystemImpl.hpp"

namespace CTRPluginFramework
{
    LightEvent g_sleepEvent;
    LanguageId SystemImpl::Language;
    bool SystemImpl::IsNew3DS;
    u32 SystemImpl::CFWVersion,
    SystemImpl::RosalinaHotkey,
    SystemImpl::AptStatus;

    Result SystemImpl::Initialize(void)
    {
    	s64 info;
    	LightEvent_Init(&g_sleepEvent, RESET_STICKY);
    	SystemImpl::IsNew3DS = svcGetSystemInfo(&info, 0x10001, 1) >= 0;
    	if ( svcGetSystemInfo(&info, 0x10000, 0) >= 0 )
    	{
    		SystemImpl::CFWVersion = (u32)info;
    		if (svcGetSystemInfo(&info, 0x10000, 0x101) >= 0)
    			SystemImpl::RosalinaHotkey = (u32)info;
    	}
    	else
    		SystemImpl::CFWVersion = 0;
    	return CFGU_GetSystemLanguage(&SystemImpl::Language);
    }

    bool SystemImpl::Status(void) const
    {
    	if (SystemImpl::AptStatus & 8)
    		return true;
    	if (SystemImpl::AptStatus & 0x80)
    		LightEvent_Wait();
    	return false;
    }
}