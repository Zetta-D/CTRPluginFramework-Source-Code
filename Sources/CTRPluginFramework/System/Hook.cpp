/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::Hook::Hook(int result);
int __fastcall CTRPluginFramework::Hook::Initialize(int result, unsigned int a2, unsigned int a3, unsigned int a4);
signed int __fastcall CTRPluginFramework::Hook::Enable(CTRPluginFramework::Hook *this, int a2);
int __fastcall CTRPluginFramework::Hook::Disable(int result, int a2);
// _DWORD CTRPluginFramework::HookManager::Lock(CTRPluginFramework::HookManager *__hidden this); idb
// int __fastcall CTRPluginFramework::Lock::Lock(_DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Lock::~Lock(CTRPluginFramework::Lock *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Process::CheckAddress(CTRPluginFramework::Process *__hidden this, unsigned int, unsigned int); idb
// _DWORD __cdecl CTRPluginFramework::HookManager::AllocNewHook(CTRPluginFramework::HookManager *__hidden this, unsigned int); idb
// _DWORD __cdecl CTRPluginFramework::Process::Write32(CTRPluginFramework::Process *__hidden this, unsigned int, unsigned int); idb
// _DWORD __cdecl CTRPluginFramework::HookManager::FreeHook(CTRPluginFramework::HookManager *__hidden this, unsigned int *); idb

//-------------------------------------------------------------------------
// Data declarations

int IsInstructionPCDependant(unsigned long)::forbiddenInstructions = 58783; // weak
// extern _UNKNOWN CTRPluginFramework::HookManager::instance; weak


//----- (00000004) --------------------------------------------------------
int __fastcall CTRPluginFramework::Hook::Hook(int result)
{
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_BYTE *)result = 6;
  *(_DWORD *)(result + 20) = -1;
  return result;
}

//----- (00000030) --------------------------------------------------------
int __fastcall CTRPluginFramework::Hook::Initialize(int result, unsigned int a2, unsigned int a3, unsigned int a4)
{
  if ( !a4 )
    a4 = a2 + 4;
  *(_DWORD *)(result + 4) = a2;
  *(_DWORD *)(result + 12) = a3;
  *(_DWORD *)(result + 8) = a4;
  return result;
}

//----- (00000048) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Hook::Enable(CTRPluginFramework::Hook *this, int a2)
{
  signed int v2; // r4
  CTRPluginFramework::Hook *v3; // r4
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v7; // r1
  int *v8; // r0
  int v9; // r3
  unsigned int v10; // r2
  unsigned int v11; // r3
  int v12; // r3
  int v13; // r0
  signed int v14; // r3
  int *v15; // r2
  int v16; // t1
  int v17; // r2
  int v18; // r0
  char *v19; // r3
  signed int v20; // r1
  signed int v21; // r1
  signed int v22; // r12
  int v23; // r2
  unsigned int *v24; // r1
  CTRPluginFramework::Hook *v25; // [sp+0h] [bp-10h]
  int v26; // [sp+4h] [bp-Ch]

  v25 = this;
  v26 = a2;
  if ( !(*(_BYTE *)this & 1) )
  {
    v3 = this;
    v4 = CTRPluginFramework::HookManager::Lock(this);
    CTRPluginFramework::Lock::Lock(&v25, v4);
    if ( *(_BYTE *)v3 & 4 && *(_BYTE *)v3 & 8 )
      goto LABEL_5;
    if ( !CTRPluginFramework::Process::CheckAddress(*((CTRPluginFramework::Process **)v3 + 1), 7u, v5) )
    {
      v2 = 1;
      goto LABEL_6;
    }
    v8 = (int *)*((_DWORD *)v3 + 1);
    v9 = *v8;
    v10 = (unsigned int)*v8 >> 24;
    *((_DWORD *)v3 + 4) = *v8;
    if ( v10 == 234 )
    {
      v11 = v9 & 0xFFFFFF;
      v7 = 31985656 - (_DWORD)v8;
      v12 = v11 < (unsigned int)(31985656 - (_DWORD)v8) >> 2 ? (unsigned __int8)(v11 >= (unsigned int)(31981560 - (_DWORD)v8) >> 2) : 0;
      if ( v12 )
        goto LABEL_15;
    }
    v13 = CTRPluginFramework::HookManager::AllocNewHook(0, v7);
    if ( v13 < 0 )
    {
      switch ( v13 )
      {
        case -1:
LABEL_5:
          v2 = 4;
LABEL_6:
          CTRPluginFramework::Lock::~Lock((CTRPluginFramework::Lock *)&v25);
          return v2;
        case -2:
LABEL_15:
          v2 = 2;
          goto LABEL_6;
        case -3:
          v2 = 3;
          goto LABEL_6;
      }
    }
    else
    {
      *((_DWORD *)v3 + 5) = v13;
    }
    if ( *(_BYTE *)v3 & 4 || *(_BYTE *)v3 & 8 )
    {
      v14 = 6;
      v15 = &IsInstructionPCDependant(unsigned long)::forbiddenInstructions;
      while ( 1 )
      {
        v16 = *v15;
        ++v15;
        if ( *((unsigned __int16 *)v3 + 9) == v16 )
          break;
        if ( !--v14 )
          goto LABEL_27;
      }
      v2 = 5;
    }
    else
    {
LABEL_27:
      v17 = *((_DWORD *)v3 + 5);
      v18 = CTRPluginFramework::HookManager::instance;
      v19 = *(char **)(CTRPluginFramework::HookManager::instance + 24 * v17 + 32);
      if ( *(_BYTE *)v3 & 2 )
      {
        *(_DWORD *)v19 = -443555808;
        *((_DWORD *)v19 + 2) = -509550577;
        *((_DWORD *)v19 + 3) = -493953016;
        v20 = -442507256;
      }
      else
      {
        v20 = -484380672;
        *(_DWORD *)v19 = -484380672;
        *((_DWORD *)v19 + 2) = -484380672;
        *((_DWORD *)v19 + 3) = -484380672;
      }
      *((_DWORD *)v19 + 6) = v20;
      if ( *(_BYTE *)v3 & 4 )
        v21 = *((_DWORD *)v3 + 4);
      else
        v21 = -484380672;
      *((_DWORD *)v19 + 1) = v21;
      *((_DWORD *)v19 + 4) = -450891772;
      *((_DWORD *)v19 + 5) = *((_DWORD *)v3 + 3);
      if ( *(_BYTE *)v3 & 8 )
        v22 = *((_DWORD *)v3 + 4);
      else
        v22 = -484380672;
      *((_DWORD *)v19 + 8) = -450891772;
      *((_DWORD *)v19 + 7) = v22;
      *((_DWORD *)v19 + 9) = *((_DWORD *)v3 + 2);
      v23 = v18 + 24 * v17;
      *(_BYTE *)(v23 + 16) = 1;
      v24 = (unsigned int *)*((_DWORD *)v3 + 1);
      *(_DWORD *)(v23 + 20) = v24;
      *v24 = ((unsigned int)(v19 - (char *)v24 - 8) >> 2) & 0xFFFFFF | 0xEA000000;
      *(_BYTE *)v3 |= 1u;
      v2 = 0;
    }
    goto LABEL_6;
  }
  return 0;
}
// 2D4: using guessed type int IsInstructionPCDependant(unsigned long)::forbiddenInstructions;
// 2F0: using guessed type int __fastcall CTRPluginFramework::Lock::Lock(_DWORD, _DWORD);

//----- (00000278) --------------------------------------------------------
int __fastcall CTRPluginFramework::Hook::Disable(int result, int a2)
{
  int v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int *v5; // r1
  int v6; // [sp-10h] [bp-10h]
  int v7; // [sp-Ch] [bp-Ch]

  if ( *(_BYTE *)result & 1 )
  {
    v6 = result;
    v7 = a2;
    v2 = result;
    v3 = CTRPluginFramework::HookManager::Lock((CTRPluginFramework::HookManager *)result);
    CTRPluginFramework::Lock::Lock(&v6, v3);
    if ( CTRPluginFramework::Process::Write32(*(CTRPluginFramework::Process **)(v2 + 4), *(_DWORD *)(v2 + 16), v4) )
    {
      *(_BYTE *)v2 &= 0xFEu;
      CTRPluginFramework::HookManager::FreeHook((CTRPluginFramework::HookManager *)(v2 + 20), v5);
    }
    result = CTRPluginFramework::Lock::~Lock((CTRPluginFramework::Lock *)&v6);
  }
  return result;
}
// 2F0: using guessed type int __fastcall CTRPluginFramework::Lock::Lock(_DWORD, _DWORD);

// ALL OK, 4 function(s) have been successfully decompiled
