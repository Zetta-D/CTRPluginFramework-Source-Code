/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

signed int __fastcall CTRPluginFramework::ConvertString(_WORD *a1, int a2, int a3);
signed int __fastcall CTRPluginFramework::ConvertString(int *a1, int a2, int a3, int a4);
int __fastcall CTRPluginFramework::Process::GetHandle(CTRPluginFramework::Process *this);
int __fastcall CTRPluginFramework::Process::GetProcessID(CTRPluginFramework::Process *this);
unsigned __int64 __fastcall CTRPluginFramework::Process::GetTitleID(CTRPluginFramework::Process *this);
int __fastcall CTRPluginFramework::Process::GetTitleID(int a1);
int __fastcall CTRPluginFramework::Process::GetName(int result);
int __fastcall CTRPluginFramework::Process::GetVersion(CTRPluginFramework::Process *this);
int __fastcall CTRPluginFramework::Process::GetTextSize(CTRPluginFramework::Process *this);
signed int __fastcall CTRPluginFramework::Process::IsPaused(CTRPluginFramework::Process *this);
int __fastcall CTRPluginFramework::Process::Pause(CTRPluginFramework::Process *this, bool a2);
int __fastcall CTRPluginFramework::Process::Play(CTRPluginFramework::Process *this, unsigned int a2);
int __fastcall CTRPluginFramework::Process::Patch(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3, void *a4);
signed int __fastcall CTRPluginFramework::Process::ProtectMemory(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3, int a4);
signed int __fastcall CTRPluginFramework::Process::ProtectRegion(CTRPluginFramework::Process *this, unsigned int a2, int a3);
int __fastcall CTRPluginFramework::Process::CopyMemory(CTRPluginFramework::Process *this, void *a2, const void *a3, unsigned int a4);
bool __fastcall CTRPluginFramework::Process::CheckRegion(CTRPluginFramework::Process *this, unsigned int a2, unsigned int *a3, unsigned int a4);
int __fastcall CTRPluginFramework::Process::Write64(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int64 a3);
int __fastcall CTRPluginFramework::Process::Write32(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3);
int __fastcall CTRPluginFramework::Process::Write16(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int16 a3);
int __fastcall CTRPluginFramework::Process::Write8(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int8 a3);
int __fastcall CTRPluginFramework::Process::WriteFloat(CTRPluginFramework::Process *this, unsigned int a2, float a3);
int __fastcall CTRPluginFramework::Process::WriteDouble(CTRPluginFramework::Process *this, unsigned int a2, double a3);
int __fastcall CTRPluginFramework::Process::Read64(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int64 *a3);
int __fastcall CTRPluginFramework::Process::Read32(CTRPluginFramework::Process *this, unsigned int a2, unsigned int *a3);
int __fastcall CTRPluginFramework::Process::Read16(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int16 *a3);
int __fastcall CTRPluginFramework::Process::Read8(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int8 *a3);
int __fastcall CTRPluginFramework::Process::ReadFloat(CTRPluginFramework::Process *this, unsigned int a2, float *a3);
int __fastcall CTRPluginFramework::Process::ReadDouble(CTRPluginFramework::Process *this, unsigned int a2, double *a3);
int __fastcall CTRPluginFramework::Process::ReadString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3, int a4);
signed int __fastcall CTRPluginFramework::Process::WriteString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3);
signed int __fastcall CTRPluginFramework::Process::WriteString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3, int a4);
// int __fastcall decode_utf8(_DWORD, _DWORD); weak
// int __fastcall encode_utf16(_DWORD, _DWORD); weak
// void *memset(void *s, int c, size_t n);
// int sprintf(char *s, const char *format, ...);
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD, _DWORD); weak
// int __fastcall AM_GetTitleInfo(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::ProcessImpl::Pause(CTRPluginFramework::ProcessImpl *__hidden this, bool); weak
// _DWORD __cdecl CTRPluginFramework::OSDImpl::ResumeFrame(CTRPluginFramework::OSDImpl *__hidden this, unsigned int); weak
// _DWORD __cdecl CTRPluginFramework::ProcessImpl::Play(CTRPluginFramework::ProcessImpl *__hidden this, bool); weak
// _DWORD __cdecl CTRPluginFramework::ProcessImpl::PatchProcess(CTRPluginFramework::ProcessImpl *__hidden this, unsigned int, unsigned __int8 *, unsigned int, unsigned __int8 *); idb
// int __fastcall svcControlProcess(_DWORD, _DWORD, _DWORD); weak
// int __fastcall svcQueryProcessMemory(_DWORD, _DWORD, _DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::ProcessImpl::IsValidAddress(CTRPluginFramework::ProcessImpl *__hidden this, unsigned int); idb
// int __fastcall svcFlushProcessDataCache(_DWORD, _DWORD, _DWORD); weak
// int __fastcall svcInvalidateProcessDataCache(_DWORD, _DWORD, _DWORD); weak
// void *memcpy(void *dest, const void *src, size_t n);
// _DWORD __cdecl CTRPluginFramework::ProcessImpl::GetMemRegion(CTRPluginFramework::ProcessImpl *__hidden this, unsigned int); idb
// int __fastcall decode_utf16(_DWORD, _DWORD); weak
// int __fastcall encode_utf8(_DWORD, _DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

// extern _UNKNOWN CTRPluginFramework::ProcessImpl::ProcessHandle; weak
// extern _UNKNOWN CTRPluginFramework::ProcessImpl::ProcessId; weak
// extern unsigned __int64 CTRPluginFramework::ProcessImpl::TitleId; idb
// extern unsigned __int8 CTRPluginFramework::ProcessImpl::CodeSet[71]; idb
// extern _UNKNOWN CTRPluginFramework::ProcessImpl::IsPaused; weak
// extern CTRPluginFramework::Process *CTRPluginFramework::ProcessImpl::InvalidRegion[2]; idb


//----- (00000004) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::ConvertString(_WORD *a1, int a2, int a3)
{
  _WORD *v3; // r4
  int v4; // r6
  unsigned int v5; // r5
  int v6; // r0
  int v8; // r0
  int v9; // r0
  char *v10; // r3
  __int16 v11; // t1
  int v12; // [sp+4h] [bp-34h]
  char v13; // [sp+8h] [bp-30h]

  v3 = a1;
  v4 = a2;
  v5 = a3 & 0xFFFFFFFE;
  while ( 1 )
  {
    v6 = decode_utf8(&v12, v4);
    if ( v6 == -1 )
      return 0;
    v4 += v6;
    v8 = encode_utf16(&v13, v12);
    v5 -= v8;
    if ( !v5 )
      break;
    v9 = (int)&v3[v8];
    v10 = &v13;
    while ( v3 != (_WORD *)v9 )
    {
      v11 = *(_WORD *)v10;
      v10 += 2;
      *v3 = v11;
      ++v3;
    }
    if ( !v12 )
      return 1;
  }
  *v3 = 0;
  return 1;
}
// 900: using guessed type int __fastcall decode_utf8(_DWORD, _DWORD);
// 904: using guessed type int __fastcall encode_utf16(_DWORD, _DWORD);

//----- (00000088) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::ConvertString(int *a1, int a2, int a3, int a4)
{
  int *v5; // r5
  int v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r1
  int *v10; // r2
  int v11; // r3
  bool v12; // cf
  int v13; // [sp+4h] [bp-14h]

  v13 = a2;
  if ( a4 == 1 )
    return CTRPluginFramework::ConvertString(a1, a2, a3);
  v5 = a1;
  v6 = a2;
  v7 = a3 & 0xFFFFFFFC;
  while ( 1 )
  {
    v8 = decode_utf8(&v13, v6);
    if ( v8 == -1 )
      return 0;
    v7 -= 4;
    v9 = v8;
    v6 += v8;
    if ( !v7 )
      break;
    v10 = v5;
    v11 = v13;
    while ( 1 )
    {
      v12 = v8-- >= 1;
      if ( !v12 )
        break;
      *v10 = v11;
      ++v10;
    }
    v5 += v9;
    if ( !v11 )
      return 1;
  }
  *v5 = 0;
  return 1;
}
// 900: using guessed type int __fastcall decode_utf8(_DWORD, _DWORD);

//----- (00000108) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetHandle(CTRPluginFramework::Process *this)
{
  return CTRPluginFramework::ProcessImpl::ProcessHandle;
}

//----- (00000118) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetProcessID(CTRPluginFramework::Process *this)
{
  return CTRPluginFramework::ProcessImpl::ProcessId;
}

//----- (00000128) --------------------------------------------------------
unsigned __int64 __fastcall CTRPluginFramework::Process::GetTitleID(CTRPluginFramework::Process *this)
{
  return CTRPluginFramework::ProcessImpl::TitleId;
}

//----- (00000138) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetTitleID(int a1)
{
  int v1; // r6
  signed int v2; // r5
  char *v3; // r4
  int v4; // t1
  int result; // r0
  char s; // [sp+4h] [bp-24h]

  v1 = a1;
  memset(&s, 0, 0x11u);
  sprintf(&s, "%016llX", CTRPluginFramework::ProcessImpl::TitleId);
  v2 = 16;
  v3 = &s;
  do
  {
    v4 = (unsigned __int8)*v3++;
    result = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v1, v4);
    --v2;
  }
  while ( v2 );
  return result;
}
// 91C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD, _DWORD);

//----- (00000194) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetName(int result)
{
  int v1; // r6
  int v2; // r4
  unsigned __int8 *v3; // r5
  int v4; // r1
  int v5; // t1

  v1 = result;
  v2 = 0;
  v3 = &CTRPluginFramework::ProcessImpl::CodeSet[80];
  do
  {
    v5 = *v3++;
    v4 = v5;
    ++v2;
    if ( v5 )
      result = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v1, v4);
  }
  while ( v2 != 8 );
  return result;
}
// 91C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD, _DWORD);

//----- (000001CC) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetVersion(CTRPluginFramework::Process *this)
{
  bool v1; // nf
  int result; // r0
  __int64 v3; // [sp+0h] [bp-60h]
  __int64 v4; // [sp+8h] [bp-58h]
  char s; // [sp+10h] [bp-50h]
  unsigned __int16 v6; // [sp+20h] [bp-40h]
  char v7; // [sp+28h] [bp-38h]
  unsigned __int16 v8; // [sp+38h] [bp-28h]
  char v9; // [sp+40h] [bp-20h]
  unsigned __int16 v10; // [sp+50h] [bp-10h]

  memset(&s, 0, 0x18u);
  memset(&v7, 0, 0x18u);
  memset(&v9, 0, 0x18u);
  AM_GetTitleInfo(
    1,
    1,
    &v3,
    &s,
    CTRPluginFramework::ProcessImpl::TitleId,
    CTRPluginFramework::ProcessImpl::TitleId >> 32,
    CTRPluginFramework::ProcessImpl::TitleId,
    (CTRPluginFramework::ProcessImpl::TitleId | 0xE00000000LL) >> 32);
  AM_GetTitleInfo(1, 1, &v4, &v7, v3, HIDWORD(v3), v4, HIDWORD(v4));
  v1 = AM_GetTitleInfo(2, 1, &v3, &v9, v3, HIDWORD(v3), v4, HIDWORD(v4)) < 0;
  result = v8;
  if ( v1 )
  {
    if ( v8 < (unsigned int)v6 )
      result = v6;
  }
  else if ( v10 >= (unsigned int)v8 )
  {
    result = v10;
  }
  return result;
}
// 924: using guessed type int __fastcall AM_GetTitleInfo(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000288) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::GetTextSize(CTRPluginFramework::Process *this)
{
  return (CTRPluginFramework::ProcessImpl::CodeSet[68] | (CTRPluginFramework::ProcessImpl::CodeSet[69] << 8) | (CTRPluginFramework::ProcessImpl::CodeSet[70] << 16)) << 12;
}

//----- (000002AC) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Process::IsPaused(CTRPluginFramework::Process *this)
{
  signed int result; // r0

  result = CTRPluginFramework::ProcessImpl::IsPaused;
  if ( CTRPluginFramework::ProcessImpl::IsPaused )
    result = 1;
  return result;
}

//----- (000002C4) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Pause(CTRPluginFramework::Process *this, bool a2)
{
  return CTRPluginFramework::ProcessImpl::Pause(0, a2);
}
// 92C: using guessed type _DWORD __cdecl CTRPluginFramework::ProcessImpl::Pause(CTRPluginFramework::ProcessImpl *__hidden this, bool);

//----- (000002CC) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Play(CTRPluginFramework::Process *this, unsigned int a2)
{
  int result; // r0

  if ( this )
    result = CTRPluginFramework::OSDImpl::ResumeFrame(this, (unsigned __int8)a2);
  else
    result = CTRPluginFramework::ProcessImpl::Play(0, a2);
  return result;
}
// 930: using guessed type _DWORD __cdecl CTRPluginFramework::OSDImpl::ResumeFrame(CTRPluginFramework::OSDImpl *__hidden this, unsigned int);
// 934: using guessed type _DWORD __cdecl CTRPluginFramework::ProcessImpl::Play(CTRPluginFramework::ProcessImpl *__hidden this, bool);

//----- (000002E0) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Patch(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3, void *a4)
{
  unsigned int v5; // [sp+4h] [bp-Ch]
  unsigned int v6; // [sp+8h] [bp-8h]

  v6 = a3;
  v5 = a2;
  return CTRPluginFramework::ProcessImpl::PatchProcess(
           this,
           (unsigned int)&v5,
           (unsigned __int8 *)CTRPluginFramework::ConvertString,
           a3,
           (unsigned __int8 *)this);
}

//----- (00000300) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Process::ProtectMemory(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3, int a4)
{
  svcControlProcess(CTRPluginFramework::ProcessImpl::ProcessHandle, 1, 0);
  return 1;
}
// 93C: using guessed type int __fastcall svcControlProcess(_DWORD, _DWORD, _DWORD);

//----- (00000328) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Process::ProtectRegion(CTRPluginFramework::Process *this, unsigned int a2, int a3)
{
  CTRPluginFramework::Process *v3; // r4
  unsigned int v4; // r5
  signed int result; // r0
  char v6; // [sp+4h] [bp-24h]
  CTRPluginFramework::Process *v7; // [sp+8h] [bp-20h]
  unsigned int v8; // [sp+Ch] [bp-1Ch]
  int v9; // [sp+14h] [bp-14h]

  v3 = this;
  v4 = a2;
  if ( svcQueryProcessMemory(&v7, &v6, CTRPluginFramework::ProcessImpl::ProcessHandle, this) < 0 )
    goto LABEL_10;
  result = v9;
  if ( !v9 )
    return result;
  if ( v7 > v3 || (CTRPluginFramework::Process *)((char *)v7 + v8) < v3 )
LABEL_10:
    result = 0;
  else
    result = CTRPluginFramework::Process::ProtectMemory(v7, v8, v4, (int)v7 + v8);
  return result;
}
// 940: using guessed type int __fastcall svcQueryProcessMemory(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (000003A0) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::CopyMemory(CTRPluginFramework::Process *this, void *a2, const void *a3, unsigned int a4)
{
  CTRPluginFramework::Process *v4; // r5
  void *v5; // r6
  char *v6; // r4
  unsigned int v7; // r1
  int v8; // r8
  unsigned int v10; // r1
  unsigned int v11; // r1

  v4 = this;
  v5 = a2;
  v6 = (char *)a3;
  if ( !CTRPluginFramework::ProcessImpl::IsValidAddress((CTRPluginFramework::ProcessImpl *)a2, (unsigned int)a2) )
    return 0;
  if ( !CTRPluginFramework::ProcessImpl::IsValidAddress(v4, v7) )
    return 0;
  if ( !CTRPluginFramework::ProcessImpl::IsValidAddress((CTRPluginFramework::ProcessImpl *)&v6[(_DWORD)v4], v10) )
    return 0;
  v8 = CTRPluginFramework::ProcessImpl::IsValidAddress((CTRPluginFramework::ProcessImpl *)&v6[(_DWORD)v5], v11);
  if ( !v8 )
    return 0;
  svcFlushProcessDataCache(CTRPluginFramework::ProcessImpl::ProcessHandle, v5, v6);
  svcInvalidateProcessDataCache(CTRPluginFramework::ProcessImpl::ProcessHandle, v4, v6);
  memcpy((void *)v4, v5, (size_t)v6);
  svcFlushProcessDataCache(CTRPluginFramework::ProcessImpl::ProcessHandle, v4, v6);
  return v8;
}
// 948: using guessed type int __fastcall svcFlushProcessDataCache(_DWORD, _DWORD, _DWORD);
// 94C: using guessed type int __fastcall svcInvalidateProcessDataCache(_DWORD, _DWORD, _DWORD);

//----- (0000044C) --------------------------------------------------------
bool __fastcall CTRPluginFramework::Process::CheckRegion(CTRPluginFramework::Process *this, unsigned int a2, unsigned int *a3, unsigned int a4)
{
  _DWORD *v4; // r4
  unsigned int v5; // r3
  _BOOL4 result; // r0
  CTRPluginFramework::Process *v7; // [sp+0h] [bp-18h]
  unsigned int v8; // [sp+4h] [bp-14h]
  unsigned int *v9; // [sp+8h] [bp-10h]
  unsigned int v10; // [sp+Ch] [bp-Ch]

  v7 = this;
  v8 = a2;
  v9 = a3;
  v10 = a4;
  v4 = (_DWORD *)a2;
  CTRPluginFramework::ProcessImpl::GetMemRegion((CTRPluginFramework::ProcessImpl *)&v7, (unsigned int)this);
  v5 = v8;
  *v4 = v8;
  if ( v7 == CTRPluginFramework::ProcessImpl::InvalidRegion[0] )
    result = CTRPluginFramework::ProcessImpl::InvalidRegion[1] != (CTRPluginFramework::Process *)v5;
  else
    result = 1;
  return result;
}

//----- (00000498) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Write64(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int64 a3)
{
  CTRPluginFramework::Process *v3; // r4
  unsigned __int64 v4; // r6
  int result; // r0

  v3 = this;
  v4 = a3;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *(_QWORD *)v3 = v4;
  return result;
}

//----- (000004B8) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Write32(CTRPluginFramework::Process *this, unsigned int a2, unsigned int a3)
{
  CTRPluginFramework::Process *v3; // r5
  unsigned int v4; // r4
  int result; // r0

  v3 = this;
  v4 = a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
  {
    *(_WORD *)v3 = v4;
    *((_BYTE *)v3 + 2) = BYTE2(v4);
    *((_BYTE *)v3 + 3) = HIBYTE(v4);
  }
  return result;
}

//----- (000004F0) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Write16(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int16 a3)
{
  __int16 v3; // r4
  CTRPluginFramework::Process *v4; // r5
  int result; // r0

  v3 = a2;
  v4 = this;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *(_WORD *)v4 = v3;
  return result;
}

//----- (00000514) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Write8(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int8 a3)
{
  CTRPluginFramework::Process *v3; // r4
  char v4; // r5
  int result; // r0

  v3 = this;
  v4 = a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *(_BYTE *)v3 = v4;
  return result;
}

//----- (00000530) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::WriteFloat(CTRPluginFramework::Process *this, unsigned int a2, float a3)
{
  int v3; // s0
  CTRPluginFramework::Process *v4; // r4
  int result; // r0

  v4 = this;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *(_DWORD *)v4 = v3;
  return result;
}

//----- (00000554) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::WriteDouble(CTRPluginFramework::Process *this, unsigned int a2, double a3)
{
  __int64 v3; // d0
  CTRPluginFramework::Process *v4; // r4
  int result; // r0

  v4 = this;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *(_QWORD *)v4 = v3;
  return result;
}

//----- (00000578) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Read64(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int64 *a3)
{
  CTRPluginFramework::Process *v3; // r5
  _QWORD *v4; // r4
  int result; // r0

  v3 = this;
  v4 = (_QWORD *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *(_QWORD *)v3;
  return result;
}

//----- (00000598) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Read32(CTRPluginFramework::Process *this, unsigned int a2, unsigned int *a3)
{
  unsigned __int8 *v3; // r4
  _DWORD *v4; // r5
  int result; // r0

  v3 = (unsigned __int8 *)this;
  v4 = (_DWORD *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *v3 | (v3[1] << 8) | (v3[2] << 16) | (v3[3] << 24);
  return result;
}

//----- (000005D4) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Read16(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int16 *a3)
{
  CTRPluginFramework::Process *v3; // r4
  _WORD *v4; // r5
  int result; // r0

  v3 = this;
  v4 = (_WORD *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *(unsigned __int8 *)v3 | (unsigned __int16)(*((unsigned __int8 *)v3 + 1) << 8);
  return result;
}

//----- (000005FC) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::Read8(CTRPluginFramework::Process *this, unsigned int a2, unsigned __int8 *a3)
{
  CTRPluginFramework::Process *v3; // r5
  _BYTE *v4; // r4
  int result; // r0

  v3 = this;
  v4 = (_BYTE *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *(_BYTE *)v3;
  return result;
}

//----- (0000061C) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::ReadFloat(CTRPluginFramework::Process *this, unsigned int a2, float *a3)
{
  CTRPluginFramework::Process *v3; // r5
  _DWORD *v4; // r4
  int result; // r0

  v3 = this;
  v4 = (_DWORD *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *(_DWORD *)v3;
  return result;
}

//----- (0000063C) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::ReadDouble(CTRPluginFramework::Process *this, unsigned int a2, double *a3)
{
  CTRPluginFramework::Process *v3; // r5
  _QWORD *v4; // r4
  int result; // r0

  v3 = this;
  v4 = (_QWORD *)a2;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(this, a2);
  if ( result )
    *v4 = *(_QWORD *)v3;
  return result;
}

//----- (0000065C) --------------------------------------------------------
int __fastcall CTRPluginFramework::Process::ReadString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3, int a4)
{
  CTRPluginFramework::ProcessImpl *v4; // r4
  unsigned int v5; // r7
  int v6; // r5
  int v7; // r8
  int v8; // r6
  int v9; // r0
  int v10; // r8
  int v11; // t1
  bool v12; // zf
  unsigned int v14; // r5
  unsigned int v15; // r5
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r8
  int *v19; // r9
  bool v20; // cf
  int v21; // t1
  bool v22; // zf
  int v23; // r9
  int v24; // t1
  unsigned int v25; // r8
  int *v26; // r9
  int v27; // t1
  int v28; // [sp+4h] [bp-34h]
  int v29; // [sp+8h] [bp-30h]

  v4 = a1;
  v5 = a2;
  v6 = a3;
  v7 = a4;
  v8 = CTRPluginFramework::ProcessImpl::IsValidAddress(a1, a2);
  if ( v8 )
  {
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        v15 = v6 & 0xFFFFFFFE;
        v28 = 0;
        while ( 1 )
        {
          v16 = decode_utf16(&v28, v4);
          if ( v16 == -1 )
            break;
          v17 = 2 * v16;
          v4 = (CTRPluginFramework::ProcessImpl *)((char *)v4 + v17);
          v15 -= v17;
          v18 = encode_utf8(&v29, v28);
          if ( v18 == -1 )
            break;
          if ( v28 )
          {
            v19 = &v29;
            while ( 1 )
            {
              v20 = v18-- >= 1;
              if ( !v20 )
                break;
              v21 = *(unsigned __int8 *)v19;
              v19 = (int *)((char *)v19 + 1);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v21);
            }
            v22 = v15 == 0;
            if ( v15 )
              v22 = v28 == 0;
            if ( !v22 )
              continue;
          }
          return v8;
        }
      }
      else
      {
        v14 = (unsigned int)v4 + (v6 & 0xFFFFFFFC);
        while ( 1 )
        {
          v24 = *(_DWORD *)v4;
          v4 = (CTRPluginFramework::ProcessImpl *)((char *)v4 + 4);
          v23 = v24;
          v25 = encode_utf8(&v29, v24);
          if ( v25 == -1 )
            break;
          if ( v23 )
          {
            v26 = &v29;
            while ( 1 )
            {
              v20 = v25-- >= 1;
              if ( !v20 )
                break;
              v27 = *(unsigned __int8 *)v26;
              v26 = (int *)((char *)v26 + 1);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v27);
            }
            if ( v4 != (CTRPluginFramework::ProcessImpl *)v14 )
              continue;
          }
          return v8;
        }
      }
    }
    else
    {
      v29 = 0;
      while ( 1 )
      {
        v9 = decode_utf8(&v29, v4);
        if ( v9 == -1 )
          break;
        v6 -= v9;
        if ( v29 )
        {
          v10 = (int)v4 + v9;
          while ( v4 != (CTRPluginFramework::ProcessImpl *)v10 )
          {
            v11 = *(unsigned __int8 *)v4;
            v4 = (CTRPluginFramework::ProcessImpl *)((char *)v4 + 1);
            std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v11);
          }
          v12 = v6 == 0;
          if ( v6 )
            v12 = v29 == 0;
          if ( !v12 )
            continue;
        }
        return v8;
      }
    }
  }
  return 0;
}
// 900: using guessed type int __fastcall decode_utf8(_DWORD, _DWORD);
// 91C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD, _DWORD);
// 95C: using guessed type int __fastcall decode_utf16(_DWORD, _DWORD);
// 960: using guessed type int __fastcall encode_utf8(_DWORD, _DWORD);

//----- (000007C8) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Process::WriteString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3)
{
  int *v3; // r4
  unsigned int v4; // r6
  int v5; // r5
  signed int result; // r0
  int v7; // r12
  _BYTE *v8; // r1
  int v9; // r12
  int v10; // r4
  int v11; // r2

  v3 = (int *)a1;
  v4 = a2;
  v5 = a3;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(a1, a2);
  if ( result )
  {
    v7 = *(_DWORD *)(v4 + 4);
    if ( v7 )
    {
      v8 = *(_BYTE **)v4;
      if ( v5 )
      {
        v11 = v7 + 1;
        if ( v5 == 1 )
          result = CTRPluginFramework::ConvertString(v3, (int)v8, 2 * v11);
        else
          result = CTRPluginFramework::ConvertString(v3, (int)v8, 4 * v11, v5);
      }
      else
      {
        v9 = (int)&v8[v7];
        v10 = (char *)v3 - v8;
        while ( v8 != (_BYTE *)v9 )
        {
          v8[v10] = *v8;
          ++v8;
        }
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00000854) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::Process::WriteString(CTRPluginFramework::ProcessImpl *a1, unsigned int a2, int a3, int a4)
{
  int *v4; // r4
  unsigned int v5; // r7
  int v6; // r5
  int v7; // r6
  signed int result; // r0
  int v9; // r12
  char *v10; // r1
  int v11; // r12
  int v12; // r4
  int v13; // r5
  char *v14; // r3
  char v15; // r2
  char v16; // t1

  v4 = (int *)a1;
  v5 = a2;
  v6 = a3;
  v7 = a4;
  result = CTRPluginFramework::ProcessImpl::IsValidAddress(a1, a2);
  if ( result )
  {
    v9 = *(_DWORD *)(v5 + 4);
    if ( v9 )
    {
      v10 = *(char **)v5;
      if ( v7 )
      {
        if ( v7 == 1 )
          result = CTRPluginFramework::ConvertString(v4, (int)v10, v6);
        else
          result = CTRPluginFramework::ConvertString(v4, (int)v10, v6, v7);
      }
      else
      {
        v11 = (int)&v10[v9];
        v12 = (char *)v4 - v10;
        v13 = (int)&v10[v6];
        while ( 1 )
        {
          v14 = &v10[v12];
          if ( (char *)v11 == v10 )
            break;
          v16 = *v10++;
          v15 = v16;
          if ( v10 == (char *)v13 )
          {
            *v14 = 0;
            return result;
          }
          *v14 = v15;
        }
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// ALL OK, 32 function(s) have been successfully decompiled
