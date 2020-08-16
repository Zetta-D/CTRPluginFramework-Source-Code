#ifndef CTRPLUGINFRAMEWORK_SYSTEM_SYSTEMIMPL_HPP
#define CTRPLUGINFRAMEWORK_SYSTEM_SYSTEMIMPL_HPP

#include "CTRPluginFramework/System/System.hpp"

namespace CTRPluginFramework
{ 
    class SystemImpl
    {
    public:
        Result Initialize(void);
        bool Status(void) const;

    private:
        static LanguageId Language;
        static bool IsNew3DS;
        static u32 CFWVersion, RosalinaHotkey, AptStatus;
    };
}

#endif
