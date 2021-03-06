/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

void **__fastcall std::vector<unsigned char,std::allocator<unsigned char>>::~vector(void **a1);
int __fastcall CTRPluginFramework::ActionReplayPriv::Str2U32(int *a1, _BYTE *a2);
unsigned __int8 *__fastcall CTRPluginFramework::ARCode::ARCode(unsigned __int8 *a1, int a2, _BYTE *a3);
bool __fastcall CTRPluginFramework::ARCode::IsCodeWithData(CTRPluginFramework::ARCode *this);
int __fastcall CTRPluginFramework::ARCode::Update(unsigned __int8 *a1, int a2);
int __fastcall CTRPluginFramework::ARCode::Update(CTRPluginFramework::ARCode *this);
int __fastcall CTRPluginFramework::ARCodeContext::ARCodeContext(int result);
int __fastcall ZNK18CTRPluginFramework6ARCode8ToStringB5cxx11Ev(int a1, int a2);
CTRPluginFramework::ARCode *__fastcall CTRPluginFramework::ARCode::ARCode(CTRPluginFramework::ARCode *this, const CTRPluginFramework::ARCode *a2);
int __fastcall CTRPluginFramework::ARCode::ARCode(int result, unsigned __int8 a2, __int64 a3);
int __fastcall CTRPluginFramework::ARCodeContext::Update(CTRPluginFramework::ARCodeContext *this);
void __fastcall CTRPluginFramework::ARCodeContext::Clear(CTRPluginFramework::ARCodeContext *this);
int GLOBAL__sub_I__ZN18CTRPluginFramework11g_codeTypesE();
// void __cdecl operator delete(void *); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD); weak
// int __fastcall CTRPluginFramework::ActionReplay_IsValidCode(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(void); weak
// void __noreturn std::__throw_bad_alloc(void); idb
// _DWORD __cdecl operator new(unsigned int); idb
// void *memmove(void *dest, const void *src, size_t n);
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Hook::Disable(CTRPluginFramework::Hook *__hidden this); idb
// int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

int CTRPluginFramework::g_codeTypes; // weak
int dword_8; // weak
int dword_C; // weak
int dword_688 = 807407616; // weak
_UNKNOWN unk_6B0; // weak
// extern _UNKNOWN _dso_handle; weak


//----- (00000010) --------------------------------------------------------
void **__fastcall std::vector<unsigned char,std::allocator<unsigned char>>::~vector(void **a1)
{
  void **v1; // r4
  void *v2; // r0

  v1 = a1;
  v2 = *a1;
  if ( v2 )
    operator delete(v2);
  return v1;
}

//----- (00000030) --------------------------------------------------------
int __fastcall CTRPluginFramework::ActionReplayPriv::Str2U32(int *a1, _BYTE *a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r12
  int v5; // lr
  int v6; // r3
  int v7; // t1
  unsigned int v8; // r2
  unsigned __int8 v9; // r3

  v2 = *a1;
  *a2 = 0;
  result = a1[1];
  if ( result )
  {
    result = 0;
    v4 = v2 + 8;
    v5 = v2 - 1;
    while ( 1 )
    {
      v7 = *(unsigned __int8 *)(v5++ + 1);
      v6 = v7;
      if ( !v7 || v5 == v4 )
        break;
      v8 = (unsigned __int8)(v6 - 48);
      if ( v8 > 9 )
      {
        if ( (unsigned int)(v6 - 97) > 5 )
        {
          if ( (unsigned int)(v6 - 65) > 5 )
          {
            result = 0;
            *a2 = 1;
            return result;
          }
          v9 = v6 - 55;
        }
        else
        {
          v9 = v6 - 87;
        }
        v8 = v9;
      }
      result = v8 | 16 * result;
    }
  }
  return result;
}

//----- (000000B8) --------------------------------------------------------
unsigned __int8 *__fastcall CTRPluginFramework::ARCode::ARCode(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  int v3; // r7
  unsigned __int8 *v4; // r4
  _BYTE *v5; // r6
  int v7; // r3
  unsigned int v8; // r3
  unsigned __int8 v9; // r1
  unsigned int v10; // r0
  bool v11; // cf
  bool v12; // zf
  int v13; // r3
  int v14; // [sp+0h] [bp-48h]
  char v15; // [sp+18h] [bp-30h]

  v3 = a2;
  *((_DWORD *)a1 + 6) = a1 + 32;
  *((_DWORD *)a1 + 3) = 0;
  *((_DWORD *)a1 + 4) = 0;
  *((_DWORD *)a1 + 5) = 0;
  *((_DWORD *)a1 + 7) = 0;
  a1[32] = 0;
  v4 = a1;
  v5 = a3;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(a1 + 24);
  if ( *(_DWORD *)(v3 + 4) > 0x10u && CTRPluginFramework::ActionReplay_IsValidCode(v3) )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(&v14, v3, 0, 8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(&v15, v3, 9, 8);
    *((_DWORD *)v4 + 1) = CTRPluginFramework::ActionReplayPriv::Str2U32(&v14, v4);
    *((_DWORD *)v4 + 2) = CTRPluginFramework::ActionReplayPriv::Str2U32((int *)&v15, v5);
    v7 = (unsigned __int8)*v5 | *v4;
    *v5 = v7;
    if ( v7 )
    {
      *v4 = 1;
    }
    else
    {
      v8 = *((_DWORD *)v4 + 1);
      v9 = *((_DWORD *)v4 + 1) >> 24;
      v10 = (v8 >> 28) - 12;
      v11 = v8 >> 28 >= 0xF;
      v12 = v8 >> 28 == 15;
      if ( v8 >> 28 != 15 )
      {
        v11 = v10 >= 1;
        v12 = v10 == 1;
      }
      if ( !v12 && v11 )
        v13 = v8 & 0xFFFFFFF;
      else
        v13 = v8 & 0xFFFFFF;
      *((_DWORD *)v4 + 1) = v13;
      v4[1] = v9;
      if ( !v12 && v11 )
        v4[1] = v9 & 0xF0;
      *v4 = 0;
      *v5 = 0;
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v15);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
  }
  else
  {
    *v4 = 1;
    *v5 = 1;
  }
  return v4;
}
// 6C4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD);
// 6C8: using guessed type int __fastcall CTRPluginFramework::ActionReplay_IsValidCode(_DWORD);
// 6CC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD);
// 6D0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (000001E4) --------------------------------------------------------
bool __fastcall CTRPluginFramework::ARCode::IsCodeWithData(CTRPluginFramework::ARCode *this)
{
  unsigned int v1; // r2
  unsigned int v2; // r3
  bool v3; // cf
  bool v4; // zf
  _BOOL4 v5; // r3

  v1 = *((unsigned __int8 *)this + 1);
  v2 = (unsigned __int8)(v1 + 3);
  v3 = v1 >= 0xE0;
  v4 = v1 == 224;
  if ( v1 != 224 )
  {
    v3 = v2 >= 1;
    v4 = v2 == 1;
  }
  if ( !v4 && v3 )
    v5 = 0;
  else
    v5 = 1;
  if ( !v4 && v3 && v1 == 240 )
    v5 = *((_DWORD *)this + 1) == 15728640;
  return v5;
}

//----- (00000220) --------------------------------------------------------
int __fastcall CTRPluginFramework::ARCode::Update(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *v2; // r4
  int v3; // r5
  int v5; // r6
  int v6; // r0
  int v7; // r5
  int v8; // r3
  unsigned int v9; // r3
  unsigned __int8 v10; // r1
  unsigned int v11; // r0
  bool v12; // cf
  bool v13; // zf
  int v14; // r3
  unsigned __int8 v15; // [sp+7h] [bp-41h]
  char v16; // [sp+8h] [bp-40h]
  char v17; // [sp+20h] [bp-28h]

  v2 = a1;
  if ( *(_DWORD *)(a2 + 4) > 0x10u )
  {
    v5 = a2;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(&v16, a2, 0, 8);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(&v17, v5, 9, 8);
    v15 = 0;
    *((_DWORD *)v2 + 1) = CTRPluginFramework::ActionReplayPriv::Str2U32((int *)&v16, v2);
    v6 = CTRPluginFramework::ActionReplayPriv::Str2U32((int *)&v17, &v15);
    v7 = *v2;
    v8 = v15;
    *((_DWORD *)v2 + 2) = v6;
    v3 = v7 | v8;
    *v2 = v3;
    if ( v3 )
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v2 + 24);
      v3 = *v2;
    }
    else
    {
      v9 = *((_DWORD *)v2 + 1);
      v10 = *((_DWORD *)v2 + 1) >> 24;
      v11 = (v9 >> 28) - 12;
      v12 = v9 >> 28 >= 0xF;
      v13 = v9 >> 28 == 15;
      if ( v9 >> 28 != 15 )
      {
        v12 = v11 >= 1;
        v13 = v11 == 1;
      }
      if ( !v13 && v12 )
        v14 = v9 & 0xFFFFFFF;
      else
        v14 = v9 & 0xFFFFFF;
      *((_DWORD *)v2 + 1) = v14;
      v2[1] = v10;
      if ( !v13 && v12 )
        v2[1] = v10 & 0xF0;
      *v2 = 0;
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v17);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v16);
  }
  else
  {
    v3 = 1;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(a1 + 24);
    *v2 = 1;
  }
  return v3;
}
// 6C4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD);
// 6CC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD);
// 6D0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (00000320) --------------------------------------------------------
int __fastcall CTRPluginFramework::ARCode::Update(CTRPluginFramework::ARCode *this)
{
  unsigned int v1; // r1
  unsigned int v2; // r2
  bool v3; // cf
  bool v4; // zf
  CTRPluginFramework::ARCode *v5; // r4
  _BYTE *v6; // r2

  v1 = *((unsigned __int8 *)this + 1);
  v2 = (unsigned __int8)(v1 + 3);
  v3 = v1 >= 0xE0;
  v4 = v1 == 224;
  if ( v1 != 224 )
  {
    v3 = v2 >= 1;
    v4 = v2 == 1;
  }
  if ( v4 || !v3 )
    return *(unsigned __int8 *)this;
  v5 = this;
  if ( !*(_BYTE *)this
    || *((_DWORD *)this + 7)
    && (CTRPluginFramework::ARCode::Update((unsigned __int8 *)this, (int)this + 24), !*(_BYTE *)v5) )
  {
    if ( *((_DWORD *)v5 + 7) )
    {
      v6 = (_BYTE *)*((_DWORD *)v5 + 6);
      *((_DWORD *)v5 + 7) = 0;
      *v6 = 0;
    }
  }
  return *(unsigned __int8 *)v5;
}

//----- (000003A4) --------------------------------------------------------
int __fastcall CTRPluginFramework::ARCodeContext::ARCodeContext(int result)
{
  *(_BYTE *)result = 0;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = 0;
  *(_DWORD *)(result + 4) = 0;
  *(_DWORD *)(result + 8) = 0;
  return result;
}

//----- (000003C8) --------------------------------------------------------
int __fastcall ZNK18CTRPluginFramework6ARCode8ToStringB5cxx11Ev(int a1, int a2)
{
  int v2; // r4
  __int64 v3; // r2
  int v4; // r12

  v2 = a1;
  v3 = *(_QWORD *)(a2 + 4);
  v4 = *(unsigned __int8 *)(a2 + 1);
  ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz();
  return v2;
}
// 6D4: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(void);

//----- (000003F0) --------------------------------------------------------
CTRPluginFramework::ARCode *__fastcall CTRPluginFramework::ARCode::ARCode(CTRPluginFramework::ARCode *this, const CTRPluginFramework::ARCode *a2)
{
  CTRPluginFramework::ARCode *v2; // r4
  const CTRPluginFramework::ARCode *v3; // r5
  signed int v4; // r6
  unsigned int v5; // r3
  _BYTE *v6; // r1
  _BYTE *v7; // r2
  int v8; // r6

  v2 = this;
  *(_BYTE *)this = *(_BYTE *)a2;
  v3 = a2;
  *((_BYTE *)this + 1) = *((_BYTE *)a2 + 1);
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  v4 = *((_DWORD *)a2 + 4) - *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  v5 = v4 >> 2;
  if ( v4 >> 2 )
  {
    if ( v5 > 0x3FFFFFFF )
      std::__throw_bad_alloc();
    v5 = operator new(v4);
  }
  *((_DWORD *)v2 + 5) = v5 + v4;
  *((_DWORD *)v2 + 3) = v5;
  *((_DWORD *)v2 + 4) = v5;
  v6 = (_BYTE *)*((_DWORD *)v3 + 3);
  v7 = (_BYTE *)*((_DWORD *)v3 + 4);
  v8 = v7 - v6;
  if ( v6 != v7 )
    v5 = (unsigned int)memmove((void *)v5, v6, v7 - v6);
  *((_DWORD *)v2 + 4) = v5 + v8;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
    (char *)v2 + 24,
    (char *)v3 + 24);
  return v2;
}
// 6E4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

//----- (000004A8) --------------------------------------------------------
int __fastcall CTRPluginFramework::ARCode::ARCode(int result, unsigned __int8 a2, __int64 a3)
{
  *(_QWORD *)(result + 4) = a3;
  *(_BYTE *)result = 0;
  *(_BYTE *)(result + 1) = a2;
  *(_DWORD *)(result + 12) = 0;
  *(_DWORD *)(result + 16) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 24) = result + 32;
  *(_DWORD *)(result + 28) = 0;
  *(_BYTE *)(result + 32) = 0;
  return result;
}

//----- (000004DC) --------------------------------------------------------
int __fastcall CTRPluginFramework::ARCodeContext::Update(CTRPluginFramework::ARCodeContext *this)
{
  CTRPluginFramework::ARCodeContext *v1; // r6
  int v2; // r4
  CTRPluginFramework::ARCode *v3; // r7
  CTRPluginFramework::ARCode *i; // r5

  v1 = this;
  v2 = 0;
  v3 = (CTRPluginFramework::ARCode *)*((_DWORD *)this + 4);
  for ( i = (CTRPluginFramework::ARCode *)*((_DWORD *)this + 3); v3 != i; i = (CTRPluginFramework::ARCode *)((char *)i + 48) )
    v2 = (unsigned __int8)(v2 | CTRPluginFramework::ARCode::Update(i));
  *(_BYTE *)v1 = v2;
  return v2;
}

//----- (0000051C) --------------------------------------------------------
void __fastcall CTRPluginFramework::ARCodeContext::Clear(CTRPluginFramework::ARCodeContext *this)
{
  __int64 v1; // r6
  CTRPluginFramework::ARCodeContext *v2; // r4
  int v3; // r5
  void *v4; // r0
  CTRPluginFramework::Hook **v5; // r3
  CTRPluginFramework::Hook *v6; // r5
  CTRPluginFramework::Hook *v7; // r6
  _DWORD *v8; // r3

  v1 = *(_QWORD *)((char *)this + 12);
  v2 = this;
  *(_BYTE *)this = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  if ( (_DWORD)v1 != HIDWORD(v1) )
  {
    v3 = v1;
    do
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v3 + 24);
      v4 = *(void **)(v3 + 12);
      if ( v4 )
        operator delete(v4);
      v3 += 48;
    }
    while ( HIDWORD(v1) != v3 );
    *((_DWORD *)v2 + 4) = v1;
  }
  v5 = (CTRPluginFramework::Hook **)*((_DWORD *)v2 + 6);
  if ( v5 )
  {
    v6 = *v5;
    v7 = v5[1];
    while ( v7 != v6 )
    {
      CTRPluginFramework::Hook::Disable(v6);
      v6 = (CTRPluginFramework::Hook *)((char *)v6 + 24);
    }
    v8 = (_DWORD *)*((_DWORD *)v2 + 6);
    if ( *v8 != v8[1] )
      v8[1] = *v8;
  }
}
// 6D0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (000005AC) --------------------------------------------------------
int GLOBAL__sub_I__ZN18CTRPluginFramework11g_codeTypesE()
{
  int *v0; // r2
  int *v1; // r3
  int v2; // r0
  int v3; // r1
  int v4; // r12
  int v5; // r0
  int *v6; // r3
  int v7; // lr
  int *v8; // r2
  int v9; // r12
  int v10; // r1
  bool v11; // zf
  int v13; // [sp+0h] [bp-40h]
  char v14; // [sp+28h] [bp-18h]

  v0 = &v13;
  v1 = &dword_688;
  do
  {
    v2 = *v1;
    v3 = v1[1];
    v1 += 2;
    *v0 = v2;
    v0[1] = v3;
    v4 = (int)(v0 + 2);
    v0 += 2;
  }
  while ( v1 != (int *)&unk_6B0 );
  v5 = *v1;
  *(_WORD *)(v4 + 4) = *((_WORD *)v1 + 2);
  *(_DWORD *)v4 = v5;
  CTRPluginFramework::g_codeTypes = 0;
  dword_8 = 0;
  dword_C = 0;
  v6 = (int *)operator new(0x2Eu);
  v7 = (int)v6 + 46;
  v8 = &v13;
  CTRPluginFramework::g_codeTypes = (int)v6;
  dword_C = (int)v6 + 46;
  do
  {
    v10 = v8[1];
    v9 = (int)(v8 + 2);
    v11 = v8 + 2 == (int *)&v14;
    *v6 = *v8;
    v6[1] = v10;
    v8 += 2;
    v6 += 2;
  }
  while ( !v11 );
  *v6 = *(_DWORD *)v9;
  *((_WORD *)v6 + 2) = *(_WORD *)(v9 + 4);
  dword_8 = v7;
  return _aeabi_atexit(
           &CTRPluginFramework::g_codeTypes,
           std::vector<unsigned char,std::allocator<unsigned char>>::~vector,
           &_dso_handle);
}
// 4: using guessed type int CTRPluginFramework::g_codeTypes;
// 8: using guessed type int dword_8;
// C: using guessed type int dword_C;
// 688: using guessed type int dword_688;
// 6EC: using guessed type int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD);

// ALL OK, 13 function(s) have been successfully decompiled
