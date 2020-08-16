/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

signed int __fastcall CTRPluginFramework::FSPath::SdmcFixPath(_DWORD *a1);
void __fastcall std::vector<unsigned short,std::allocator<unsigned short>>::_M_fill_insert(char **a1, char *a2, unsigned int a3, __int16 *a4);
char **__fastcall CTRPluginFramework::FSPath::FSPath(char **a1, _DWORD *a2);
int GLOBAL__sub_I__ZN18CTRPluginFramework6FSPath7FSMutexE();
// int __fastcall decode_utf8(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD); weak
// void *memmove(void *dest, const void *src, size_t n);
// void __cdecl __noreturn std::__throw_length_error(const char *); idb
// _DWORD __cdecl operator new(unsigned int); idb
// void *memcpy(void *dest, const void *src, size_t n);
// void __cdecl operator delete(void *); idb
// _DWORD __cdecl CTRPluginFramework::Lock::Lock(CTRPluginFramework::Lock *__hidden this, CTRPluginFramework::Mutex *); weak
// int __fastcall utf8_to_utf16(_DWORD, _DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Lock::~Lock(CTRPluginFramework::Lock *__hidden this); idb
// _DWORD CTRPluginFramework::Mutex::Mutex(CTRPluginFramework::Mutex *__hidden this); idb
// int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Mutex::~Mutex(CTRPluginFramework::Mutex *__hidden this); weak

//-------------------------------------------------------------------------
// Data declarations

int ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E; // weak
int dword_8; // weak
char byte_C; // weak
_UNKNOWN CTRPluginFramework::FSPath::FSMutex; // weak
// extern _UNKNOWN _dso_handle; weak
// extern _UNKNOWN std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string; weak


//----- (00000028) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::FSPath::SdmcFixPath(_DWORD *a1)
{
  int v1; // r4
  _DWORD *v2; // r5
  int v3; // r6
  int v4; // r0
  bool v5; // zf
  _BYTE *v6; // r6
  int v7; // r0
  signed int v8; // r4
  int v10; // [sp+4h] [bp-44h]
  char *v11; // [sp+8h] [bp-40h]
  int v12; // [sp+Ch] [bp-3Ch]
  char v13; // [sp+10h] [bp-38h]
  char v14; // [sp+20h] [bp-28h]

  v1 = 0;
  v2 = a1;
  v3 = *a1;
  v11 = &v13;
  v12 = 0;
  v13 = 0;
  do
  {
    v4 = decode_utf8(&v10, v3);
    v3 += v4;
    v5 = v10 == 0;
    if ( v10 )
      v5 = v10 == 58;
    v1 += v4;
  }
  while ( !v5 );
  if ( v10 == 58 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(&v14, v2, v1, -1);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(v2, &v14);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
  }
  v6 = (_BYTE *)*v2;
  do
  {
    v7 = decode_utf8(&v10, v6);
    v8 = v10;
    if ( v10 == 58 )
    {
      v8 = -1;
      goto LABEL_15;
    }
    v6 += v7;
  }
  while ( v10 );
  if ( *(_BYTE *)*v2 != 47 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(
      &v11,
      &ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(&v11, v2);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v2, &v11);
    if ( v2[1] > 0xFFu )
      v8 = -1;
    else
      v8 = 0;
  }
LABEL_15:
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v11);
  return v8;
}
// 4: using guessed type int ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E;
// 448: using guessed type int __fastcall decode_utf8(_DWORD, _DWORD);
// 44C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD);
// 450: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(_DWORD, _DWORD);
// 454: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 458: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD);
// 45C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD);

//----- (0000012C) --------------------------------------------------------
void __fastcall std::vector<unsigned short,std::allocator<unsigned short>>::_M_fill_insert(char **a1, char *a2, unsigned int a3, __int16 *a4)
{
  unsigned int v4; // r5
  __int16 *v5; // r10
  char *v6; // r4
  char *v7; // r6
  char **v8; // r7
  char *v9; // r8
  __int16 v10; // r9
  int v11; // r10
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r3
  char *v15; // r2
  size_t v16; // r5
  int v17; // r10
  int v18; // r5
  char *v19; // r0
  unsigned int v20; // r4
  unsigned int v21; // r1
  unsigned __int8 v22; // cf
  int v23; // r4
  int v24; // r8
  char *v25; // r9
  unsigned int v26; // r2
  __int16 v27; // r1
  char *v28; // r3
  char *v29; // r10
  int v30; // r8
  char *v31; // r3
  char *v32; // r5
  int v33; // r8
  int v34; // r5

  v4 = a3;
  if ( !a3 )
    return;
  v5 = a4;
  v6 = a1[1];
  v7 = a2;
  v8 = a1;
  v9 = a2;
  if ( a3 <= (a1[2] - v6) >> 1 )
  {
    v10 = *a4;
    v11 = v6 - a2;
    v12 = (v6 - a2) >> 1;
    if ( a3 < v12 )
    {
      v16 = 2 * a3;
      v17 = (int)&v6[-2 * a3];
      if ( v6 != &v6[-2 * a3] )
        memmove(v6, &v6[-v16], v16);
      v8[1] += v16;
      if ( (char *)v17 != v7 )
        memmove(&v7[v16], v7, v17 - (_DWORD)v7);
      v18 = (int)&v7[v16];
      while ( (char *)v18 != v9 )
      {
        *(_WORD *)v9 = v10;
        v9 += 2;
      }
    }
    else
    {
      v13 = a3 - v12;
      v14 = v13;
      v15 = v6;
      while ( v14 )
      {
        *(_WORD *)v15 = v10;
        v15 += 2;
        --v14;
      }
      v19 = &v6[2 * v13];
      v8[1] = v19;
      if ( v6 != a2 )
        memmove(v19, a2, v6 - a2);
      v8[1] += v11;
      while ( v6 != v9 )
      {
        *(_WORD *)v9 = v10;
        v9 += 2;
      }
    }
    return;
  }
  v20 = (v6 - *a1) >> 1;
  if ( a3 > 0x7FFFFFFF - v20 )
    std::__throw_length_error("vector::_M_fill_insert");
  if ( a3 < v20 )
    v21 = v20;
  else
    v21 = a3;
  v22 = __CFADD__(v20, v21);
  v23 = v20 + v21;
  v24 = v7 - *a1;
  if ( v22 || v23 < 0 )
  {
    v23 = 0x7FFFFFFF;
  }
  else if ( !v23 )
  {
    v25 = 0;
    goto LABEL_29;
  }
  v25 = (char *)operator new(2 * v23);
LABEL_29:
  v26 = v4;
  v27 = *v5;
  v28 = &v25[v24];
  do
  {
    --v26;
    *(_WORD *)v28 = v27;
    v28 += 2;
  }
  while ( v26 );
  v29 = *v8;
  v30 = v7 - *v8;
  if ( v7 != *v8 )
    memmove(v25, *v8, v7 - *v8);
  v31 = v8[1];
  v32 = &v25[2 * v4 + v30];
  v33 = v31 - v7;
  if ( v7 != v31 )
    memcpy(v32, v7, v31 - v7);
  v34 = (int)&v32[v33];
  if ( v29 )
    operator delete(v29);
  *v8 = v25;
  v8[1] = (char *)v34;
  v8[2] = &v25[2 * v23];
}

//----- (00000308) --------------------------------------------------------
char **__fastcall CTRPluginFramework::FSPath::FSPath(char **a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  char **v3; // r4
  signed int v4; // r0
  char *v5; // r1
  char *v6; // r3
  unsigned int v7; // r2
  int v8; // r0
  signed int v9; // r3
  int v11; // r3
  __int16 v12; // [sp+6h] [bp-1Ah]
  char v13; // [sp+8h] [bp-18h]

  v2 = a2;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  a1[4] = 0;
  v3 = a1;
  CTRPluginFramework::Lock::Lock(
    (CTRPluginFramework::Lock *)&v13,
    (CTRPluginFramework::Mutex *)&CTRPluginFramework::FSPath::FSMutex);
  v4 = CTRPluginFramework::FSPath::SdmcFixPath(v2);
  *v3 = (char *)v4;
  if ( !v4 )
  {
    v5 = v3[3];
    v6 = v3[2];
    v12 = 0;
    v7 = (v5 - v6) >> 1;
    if ( v7 > 0xFF )
    {
      if ( v7 != 256 )
      {
        v11 = (int)(v6 + 512);
        if ( v5 != (char *)v11 )
          v3[3] = (char *)v11;
      }
    }
    else
    {
      std::vector<unsigned short,std::allocator<unsigned short>>::_M_fill_insert(v3 + 2, v5, 256 - v7, &v12);
    }
    v8 = utf8_to_utf16(v3[2], *v2, 256);
    if ( v8 <= 0 )
      v9 = -1;
    v3[1] = (char *)v8;
    if ( v8 <= 0 )
      *v3 = (char *)v9;
  }
  CTRPluginFramework::Lock::~Lock((CTRPluginFramework::Lock *)&v13);
  return v3;
}
// 474: using guessed type _DWORD __cdecl CTRPluginFramework::Lock::Lock(CTRPluginFramework::Lock *__hidden this, CTRPluginFramework::Mutex *);
// 478: using guessed type int __fastcall utf8_to_utf16(_DWORD, _DWORD, _DWORD);

//----- (000003CC) --------------------------------------------------------
int GLOBAL__sub_I__ZN18CTRPluginFramework6FSPath7FSMutexE()
{
  CTRPluginFramework::Mutex::Mutex((CTRPluginFramework::Mutex *)&CTRPluginFramework::FSPath::FSMutex);
  _aeabi_atexit(&CTRPluginFramework::FSPath::FSMutex, &CTRPluginFramework::Mutex::~Mutex, &_dso_handle);
  ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E = (int)&byte_C;
  dword_8 = 0;
  byte_C = 0;
  return _aeabi_atexit(
           &ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E,
           &std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string,
           &_dso_handle);
}
// 4: using guessed type int ZN18CTRPluginFramework6FSPath23CurrentWorkingDirectoryB5cxx11E;
// 8: using guessed type int dword_8;
// C: using guessed type char byte_C;
// 484: using guessed type int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD);
// 48C: using guessed type _DWORD __cdecl CTRPluginFramework::Mutex::~Mutex(CTRPluginFramework::Mutex *__hidden this);

// ALL OK, 4 function(s) have been successfully decompiled
