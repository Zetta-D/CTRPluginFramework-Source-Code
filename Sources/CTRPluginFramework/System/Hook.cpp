#include "CTRPluginFramework/System/Hook.hpp"

namespace CTRPluginFramework
{
 	int IsInstructionPCDependant::forbiddenInstructions = 58783;

 	//extern u32 HookManager::instance;

 	Hook::Hook() : targetAddress(0), returnAddress(0), callbackAddress(0), overwrittenInstr(0), index(0xFFFFFFFF)
 	{
 	 	flags.raw = 6;
 	}

 	void Hook::Initialize(u32 targetAddr, u32 callbackAddr, u32 returnAddr)
 	{
 	 	targetAddress = targetAddr;
 	 	callbackAddress = callbackAddr;
 	 	returnAddress = returnAddr ? returnAddr : targetAddr + 4;
 	}
    
    void Hook::Disable(void)
    {
        if (flags.isEnabled)
        {
            Lock::Lock(HookManager::Lock(flags));
            if ( Process::Write32(targetAddress, overwrittenInstr)
            {
                *(u8 *)flags &= 0xFEu;
                HookManager::FreeHook(index);
            }
            Lock::~Lock();
        }
    }

 	HookResult 	Hook::Enable(void)
 	{
 	 	HookResult res;
 	 	int alloc;
 	 	int v14;
 	 	int *ptr;
 	 	char *instance;
 	 	int res0, res1, res2, res3;
 	 	u32 *res4;

 	 	if ( !flags.isEnabled )
 	 	{
 	 	 	Lock::Lock(HookManager::Lock(flags));
 	 	 	if ( flags.ExecuteOverwrittenInstructionBeforeCallback && flags.ExecuteOverwrittenInstructionAfterCallback )
 	 	 	 	goto LABEL_5;
 	 	 	if ( !Process::CheckAddress(targetAddress, 7u) )
 	 	 	{
 	 	 	 	res = 1;
 	 	 	 	goto LABEL_6;
 	 	 	}
 	 	 	overwrittenInstr = targetAddress;
 	 	 	if (targetAddress >> 24 == 234 && targetAddress & 0xFFFFFF < (u32)(0x1E80FF8 - targetAddress) >> 2 ? (u8)(targetAddress & 0xFFFFFF >= (u32)(31981560 - targetAddress) >> 2) : 0 )
 	 	  	 	goto LABEL_15;
 	 	 	alloc = HookManager::AllocNewHook(0, 0x1E80FF8 - targetAddress);
 	 	 	if ( alloc < 0 )
 	 	 	{
 	 	 	 	switch ( alloc )
 	 	 	 	{
 	 	 	 	 	case -1:
 	 	 	 	 	 	LABEL_5:
 	 	 	 	 	 	res = 4;
 	 	 	 	 	 	LABEL_6:
 	 	 	 	 	 	Lock::~Lock();
 	 	 	 	 	 	return res;
 	 	 	 	 	case -2:
 	 	 	 	 	 	LABEL_15:
 	 	 	 	 	 	res = 2;
 	 	 	 	 	 	goto LABEL_6;
 	 	 	 	 	case -3:
 	 	 	 	 	 	res = 3;
 	 	 	 	 	 	goto LABEL_6;
 	 	 	 	}
 	 	 	}
 	 	 	else
 	 	 	 	index = alloc;
 	 	 	if ( flags.ExecuteOverwrittenInstructionBeforeCallback || flags.ExecuteOverwrittenInstructionAfterCallback )
 	 	 	{
 	 	 	 	v14 = 6;
 	 	 	 	ptr = &IsInstructionPCDependant::forbiddenInstructions;
 	 	 	 	while ( 1 )
 	 	 	 	{
 	 	 	 	 	if ( (u16)overwrittenInstr == *ptr++ )
 	 	 	 	 	 	break;
 	 	 	 	 	if ( !--v14 )
 	 	 	 	 	 	goto LABEL_27;
 	 	 	 	}
 	 	 	 	res = 5;
 	 	 	}
 	 	 	else
 	 	 	{
 	LABEL_27:
 	 	 	 	instance = *(char **)(HookManager::instance + 24 * index + 32);
 	 	 	 	if ( flags.useLinkRegisterToReturn )
 	 	 	 	{
 	 	 	 	 	*(u32 *)instance = -443555808;
 	 	 	 	 	*((u32 *)instance + 2) = -509550577;
 	 	 	 	 	*((u32 *)instance + 3) = -493953016;
 	 	 	 	 	res0 = -442507256;
 	 	 	 	}
 	 	 	 	else
 	 	 	 	{
 	 	 	 	 	res0 = -484380672;
 	 	 	 	 	*(u32 *)instance = -484380672;
 	 	 	 	 	*((u32 *)instance + 2) = -484380672;
 	 	 	 	 	*((u32 *)instance + 3) = -484380672;
 	 	 	 	}
 	 	 	 	*((u32 *)instance + 6) = res0;
 	 	 	 	if ( flags.ExecuteOverwrittenInstructionBeforeCallback )
 	 	 	 	 	res1 = overwrittenInstr;
 	 	 	 	else
 	 	 	 	 	res1 = -484380672;
 	 	 	 	*((u32 *)instance + 1) = res1;
 	 	 	 	*((u32 *)instance + 4) = -450891772;
 	 	 	 	*((u32 *)instance + 5) = callbackAddress;
 	 	 	 	if ( flags.ExecuteOverwrittenInstructionAfterCallback )
 	 	 	 	 	res2 = overwrittenInstr;
 	 	 	 	else
 	 	 	 	 	res2 = -484380672;
 	 	 	 	*((u32 *)instance + 8) = -450891772;
 	 	 	 	*((u32 *)instance + 7) = res2;
 	 	 	 	*((u32 *)instance + 9) = returnAddress;
 	 	 	 	res3 = HookManager::instance + 24 * index;
 	 	 	 	*(u8 *)(res3 + 16) = 1;
 	 	 	 	res4 = &targetAddress;
 	 	 	 	*(u32 *)(res3 + 20) = res4;
 	 	 	 	*res4 = ((u32)(instance - (char *)res4 - 8) >> 2) & 0xFFFFFF | 0xEA000000;
 	 	 	 	flags.isEnabled |= 1u;
 	 	 	 	res = 0;
 	 	 	}
 	 	 	goto LABEL_6;
 	 	}
 	 	return 0;
 	}
}
