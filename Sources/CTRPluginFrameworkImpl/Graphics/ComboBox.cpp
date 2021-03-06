/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::ComboBox::Draw(int result, int a2);
CTRPluginFramework::ComboBox *__fastcall CTRPluginFramework::ComboBox::~ComboBox(CTRPluginFramework::ComboBox *this);
CTRPluginFramework::ComboBox *__fastcall CTRPluginFramework::ComboBox::~ComboBox(CTRPluginFramework::ComboBox *this);
int __fastcall CTRPluginFramework::ComboBox::operator()(int a1);
int __fastcall CTRPluginFramework::ComboBox::ComboBox(int result, int a2, __int64 a3, int a4);
int __fastcall CTRPluginFramework::ComboBox::Clear(int result);
void __fastcall std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::_M_realloc_insert<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&>(char **a1, char *a2, int a3);
void __fastcall CTRPluginFramework::ComboBox::Add(int a1, int a2);
bool __fastcall CTRPluginFramework::Rect<int>::Contains(int *a1, int a2, int a3);
int __fastcall CTRPluginFramework::ComboBox::Update(int result, int a2, int *a3);
// int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// void __cdecl operator delete(void *); idb
// int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void); weak
// int __fastcall CTRPluginFramework::Keyboard::Keyboard(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Keyboard::Populate(_DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Keyboard::Open(CTRPluginFramework::Keyboard *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Keyboard::~Keyboard(CTRPluginFramework::Keyboard *__hidden this); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// _DWORD __cdecl operator new(unsigned int); idb

//-------------------------------------------------------------------------
// Data declarations

_DWORD (__fastcall *off_4EC[2])(CTRPluginFramework::ComboBox *__hidden this) =
{
  &CTRPluginFramework::ComboBox::~ComboBox,
  &CTRPluginFramework::ComboBox::~ComboBox
}; // weak
// extern _UNKNOWN CTRPluginFramework::Color::Gray; weak
// extern _UNKNOWN CTRPluginFramework::Color::Gainsboro; weak
// extern _UNKNOWN CTRPluginFramework::Color::Black; weak


//----- (00000004) --------------------------------------------------------
int __fastcall CTRPluginFramework::ComboBox::Draw(int result, int a2)
{
  _DWORD *v2; // r4
  void *v3; // r1
  int v4; // r12
  int v5; // [sp+0h] [bp-10h]
  int v6; // [sp+4h] [bp-Ch]

  if ( *(_BYTE *)(result + 5) )
  {
    v5 = result;
    v6 = a2;
    v2 = (_DWORD *)result;
    v3 = &CTRPluginFramework::Color::Gainsboro;
    if ( !*(_BYTE *)(result + 4) )
      v3 = &CTRPluginFramework::Color::Gray;
    result = CTRPluginFramework::Renderer::DrawRect(result + 16, v3, 1);
    v4 = v2[2];
    if ( v4 != -1 )
      result = CTRPluginFramework::Renderer::DrawString(
                 *(_DWORD *)(v2[8] + 24 * v4),
                 v2[4] + 5,
                 &v6,
                 CTRPluginFramework::Color::Black,
                 v5,
                 v2[5] + (v2[7] - 10) / 2);
  }
  return result;
}
// 504: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD);
// 508: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000098) --------------------------------------------------------
CTRPluginFramework::ComboBox *__fastcall CTRPluginFramework::ComboBox::~ComboBox(CTRPluginFramework::ComboBox *this)
{
  CTRPluginFramework::ComboBox *v1; // r4
  int v2; // r5
  int v3; // r6
  void *v4; // r0

  v1 = this;
  v2 = *((_DWORD *)this + 8);
  v3 = *((_DWORD *)this + 9);
  *(_DWORD *)this = off_4EC;
  while ( v3 != v2 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v2);
    v2 += 24;
  }
  v4 = (void *)*((_DWORD *)v1 + 8);
  if ( v4 )
    operator delete(v4);
  return v1;
}
// 4EC: using guessed type _DWORD (__fastcall *off_4EC[2])(CTRPluginFramework::ComboBox *__hidden this);
// 518: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (000000E4) --------------------------------------------------------
CTRPluginFramework::ComboBox *__fastcall CTRPluginFramework::ComboBox::~ComboBox(CTRPluginFramework::ComboBox *this)
{
  CTRPluginFramework::ComboBox *v1; // r4

  v1 = this;
  CTRPluginFramework::ComboBox::~ComboBox(this);
  operator delete((void *)v1);
  return v1;
}

//----- (00000100) --------------------------------------------------------
int __fastcall CTRPluginFramework::ComboBox::operator()(int a1)
{
  int v1; // r6
  int v2; // r4
  int v3; // r0
  char v5; // [sp+4h] [bp-34h]
  char *v6; // [sp+10h] [bp-28h]
  int v7; // [sp+14h] [bp-24h]
  char v8; // [sp+18h] [bp-20h]

  if ( (unsigned int)*(_QWORD *)(a1 + 32) == *(_QWORD *)(a1 + 32) >> 32 )
    return 0;
  v1 = *(unsigned __int8 *)(a1 + 4);
  if ( *(_BYTE *)(a1 + 4) )
  {
    v1 = *(unsigned __int8 *)(a1 + 12);
    if ( *(_BYTE *)(a1 + 12) )
    {
      v2 = a1;
      v6 = &v8;
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
      v7 = 0;
      v8 = 0;
      CTRPluginFramework::Keyboard::Keyboard(&v5, &v6);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v6);
      CTRPluginFramework::Keyboard::Populate(&v5, v2 + 32);
      v5 = 0;
      v3 = CTRPluginFramework::Keyboard::Open((CTRPluginFramework::Keyboard *)&v5);
      if ( v3 != -1 )
        *(_DWORD *)(v2 + 8) = v3;
      *(_BYTE *)(v2 + 12) = 0;
      CTRPluginFramework::Keyboard::~Keyboard((CTRPluginFramework::Keyboard *)&v5);
    }
  }
  return v1;
}
// 518: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 520: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void);
// 524: using guessed type int __fastcall CTRPluginFramework::Keyboard::Keyboard(_DWORD, _DWORD);
// 528: using guessed type int __fastcall CTRPluginFramework::Keyboard::Populate(_DWORD, _DWORD);

//----- (000001A8) --------------------------------------------------------
int __fastcall CTRPluginFramework::ComboBox::ComboBox(int result, int a2, __int64 a3, int a4)
{
  *(_QWORD *)(result + 20) = a3;
  *(_DWORD *)result = off_4EC;
  *(_WORD *)(result + 4) = 257;
  *(_DWORD *)(result + 8) = -1;
  *(_DWORD *)(result + 16) = a2;
  *(_WORD *)(result + 12) = 0;
  *(_DWORD *)(result + 28) = a4;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = 0;
  *(_DWORD *)(result + 40) = 0;
  return result;
}
// 4EC: using guessed type _DWORD (__fastcall *off_4EC[2])(CTRPluginFramework::ComboBox *__hidden this);

//----- (000001F4) --------------------------------------------------------
int __fastcall CTRPluginFramework::ComboBox::Clear(int result)
{
  __int64 v1; // r6
  int v2; // r4
  int v3; // r5
  int v4; // r0

  v1 = *(_QWORD *)(result + 32);
  v2 = result;
  if ( (_DWORD)v1 != HIDWORD(v1) )
  {
    v3 = v1;
    do
    {
      v4 = v3;
      v3 += 24;
      result = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v4);
    }
    while ( HIDWORD(v1) != v3 );
    *(_DWORD *)(v2 + 36) = v1;
  }
  *(_DWORD *)(v2 + 8) = -1;
  return result;
}
// 518: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (00000230) --------------------------------------------------------
void __fastcall std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::_M_realloc_insert<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&>(char **a1, char *a2, int a3)
{
  char *v3; // r7
  char *v4; // r6
  int v5; // r4
  int v6; // r3
  unsigned __int8 v7; // cf
  unsigned int v8; // r4
  char **v9; // r8
  char *v10; // r9
  __int64 v11; // r10
  unsigned int v12; // r5
  char *v13; // r11
  int i; // r0
  int v15; // r5
  int v16; // r5
  int v17; // r11
  int v18; // r3
  int v19; // r2
  int v20; // ST04_4
  int v21; // ST00_4
  unsigned int v22; // r9
  char *v23; // r6
  int v24; // r9
  int v25; // r5
  int v26; // [sp+0h] [bp-30h]

  v3 = *a1;
  v4 = a1[1];
  v5 = -1431655765 * ((v4 - *a1) >> 3);
  if ( -1431655765 * ((v4 - *a1) >> 3) )
    v6 = -1431655765 * ((v4 - *a1) >> 3);
  else
    v6 = 1;
  v7 = __CFADD__(v5, v6);
  v8 = v5 + v6;
  v9 = a1;
  v10 = a2;
  HIDWORD(v11) = a3;
  v12 = a2 - v3;
  if ( v7 || v8 > 0xAAAAAAA )
  {
    v8 = 178956970;
    goto LABEL_21;
  }
  if ( v8 )
  {
LABEL_21:
    LODWORD(v11) = operator new(24 * v8);
    goto LABEL_8;
  }
  LODWORD(v11) = 0;
LABEL_8:
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v11 + v12, HIDWORD(v11));
  v13 = v3;
  for ( i = v11; ; i = v26 )
  {
    v26 = i + 24;
    if ( v10 == v13 )
      break;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(i, v13);
    v13 += 24;
  }
  v15 = 178956971 * (v12 >> 3) & 0x1FFFFFFF;
  HIDWORD(v11) = 24 * v15 + 24;
  v16 = (int)&v3[24 * v15];
  v17 = v11 + HIDWORD(v11);
  v18 = v16;
  v19 = v17;
  while ( v4 != (char *)v18 )
  {
    v20 = v18;
    v21 = v19;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v19, v18);
    v19 = v21 + 24;
    v18 = v20 + 24;
  }
  v22 = 178956971 * ((unsigned int)&v4[-v16] >> 3);
  v23 = v3;
  v24 = 24 * (v22 & 0x1FFFFFFF);
  v25 = v16 + v24;
  HIDWORD(v11) = v17 + v24;
  while ( (char *)v25 != v23 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v23);
    v23 += 24;
  }
  if ( v3 )
    operator delete(v3);
  *(_QWORD *)v9 = v11;
  v9[2] = (char *)(v11 + 24 * v8);
}
// 518: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 534: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 538: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

//----- (000003A0) --------------------------------------------------------
void __fastcall CTRPluginFramework::ComboBox::Add(int a1, int a2)
{
  int v2; // r4
  char *v3; // r0

  v2 = a1;
  v3 = *(char **)(a1 + 36);
  if ( v3 == *(char **)(v2 + 40) )
  {
    std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::_M_realloc_insert<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&>(
      (char **)(v2 + 32),
      v3,
      a2);
  }
  else
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v3, a2);
    *(_DWORD *)(v2 + 36) += 24;
  }
  if ( *(_DWORD *)(v2 + 8) == -1 )
    *(_DWORD *)(v2 + 8) = 0;
}
// 534: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

//----- (000003F0) --------------------------------------------------------
bool __fastcall CTRPluginFramework::Rect<int>::Contains(int *a1, int a2, int a3)
{
  int v3; // r12
  int v4; // r3
  int v5; // r4
  int v6; // lr
  int v7; // r0
  _BOOL4 v8; // r4
  int v9; // r0
  bool v10; // zf
  bool v11; // nf
  unsigned __int8 v12; // vf

  v3 = *a1;
  v4 = a1[1];
  v5 = *a1 + a1[2];
  v6 = a1[3];
  if ( *a1 < v5 )
  {
    v7 = *a1;
    v3 = v5;
  }
  else
  {
    v7 = *a1 + a1[2];
  }
  v8 = a2 >= v7;
  if ( a2 >= v3 )
    v8 = 0;
  if ( v8 )
  {
    if ( v4 >= v4 + v6 )
      v9 = v4 + v6;
    else
      v9 = v4;
    if ( v4 < v4 + v6 )
      v4 += v6;
    v12 = __OFSUB__(a3, v9);
    v10 = a3 == v9;
    v11 = a3 - v9 < 0;
    if ( a3 >= v9 )
    {
      v12 = __OFSUB__(v4, a3);
      v10 = v4 == a3;
      v11 = v4 - a3 < 0;
    }
    if ( (unsigned __int8)(v11 ^ v12) | v10 )
      v8 = 0;
    else
      v8 = 1;
  }
  return v8;
}

//----- (00000460) --------------------------------------------------------
int __fastcall CTRPluginFramework::ComboBox::Update(int result, int a2, int *a3)
{
  int *v3; // r5
  int v4; // r2
  int v5; // r4

  if ( *(_DWORD *)(result + 32) != *(_DWORD *)(result + 36) && *(_BYTE *)(result + 4) )
  {
    v3 = a3;
    v4 = *(unsigned __int8 *)(result + 13);
    v5 = result;
    if ( a2 & (v4 ^ 1) )
    {
      result = CTRPluginFramework::Rect<int>::Contains((int *)(result + 16), *v3, v3[1]);
      if ( !result )
        return result;
      *(_BYTE *)(v5 + 13) = 1;
      goto LABEL_7;
    }
    if ( a2 & v4 )
    {
LABEL_7:
      result = CTRPluginFramework::Rect<int>::Contains((int *)(v5 + 16), *v3, v3[1]);
      if ( !result )
        *(_BYTE *)(v5 + 13) = 0;
      return result;
    }
    if ( !(a2 | v4 ^ 1) )
      *(_WORD *)(result + 12) = 1;
  }
  return result;
}

// ALL OK, 10 function(s) have been successfully decompiled
