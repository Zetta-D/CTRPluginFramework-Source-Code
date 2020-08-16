/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

unsigned int *__fastcall CTRPluginFramework::SubMenu::SubMenu(unsigned int *a1, int *a2);
void **__fastcall CTRPluginFramework::SubMenu::~SubMenu(CTRPluginFramework::SubMenu *this);
signed int __fastcall CTRPluginFramework::SubMenu::operator()(int a1);
int __fastcall CTRPluginFramework::SubMenu::Draw(int result);
int __fastcall CTRPluginFramework::SubMenu::ProcessEvent(int result, const Event *a2, int a3);
int __fastcall CTRPluginFramework::SubMenu::IsOpen(CTRPluginFramework::SubMenu *this);
int __fastcall CTRPluginFramework::SubMenu::OptionsCount(CTRPluginFramework::SubMenu *this);
unsigned int *__fastcall std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::operator=(unsigned int *a1, unsigned int *a2);
unsigned int *__fastcall CTRPluginFramework::SubMenu::ChangeOptions(unsigned int *a1, unsigned int *a2);
// void __noreturn std::__throw_bad_alloc(void); idb
// _DWORD __cdecl operator new(unsigned int); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Clock::Clock(CTRPluginFramework::Clock *__hidden this); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// void __cdecl operator delete(void *); idb
// int __fastcall _cxa_guard_acquire(_DWORD); weak
// int __fastcall _cxa_guard_release(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawRect2(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawLine(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Seconds(CTRPluginFramework *__hidden this, float); idb
// _DWORD __cdecl CTRPluginFramework::Clock::HasTimePassed(CTRPluginFramework::Clock *__hidden this, Time); idb
// int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Clock::Restart(CTRPluginFramework::Clock *__hidden this); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

char `guard variable for'CTRPluginFramework::SubMenu::Draw(void)::background; // weak
_UNKNOWN CTRPluginFramework::SubMenu::Draw(void)::background; // weak
_UNKNOWN unk_10; // weak
// extern _DWORD CTRPluginFramework::Preferences::Settings[5]; idb
// extern _UNKNOWN CTRPluginFramework::Color::DarkGrey; weak
// extern _UNKNOWN CTRPluginFramework::Color::Gainsboro; weak
// extern _UNKNOWN CTRPluginFramework::Color::Black; weak


//----- (00000018) --------------------------------------------------------
unsigned int *__fastcall CTRPluginFramework::SubMenu::SubMenu(unsigned int *a1, int *a2)
{
  signed int v2; // r6
  unsigned int v3; // r4
  unsigned int *v4; // r5
  int *v5; // r7
  int v6; // r9
  int v7; // r6
  unsigned int v8; // r8
  int i; // r7

  v2 = a2[1] - *a2;
  v3 = -1431655765 * (v2 >> 3);
  v4 = a1;
  v5 = a2;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  if ( -1431655765 * (v2 >> 3) )
  {
    if ( v3 > 0xAAAAAAA )
      std::__throw_bad_alloc();
    v3 = operator new(v2);
  }
  *v4 = v3;
  v4[1] = v3;
  v4[2] = v3 + v2;
  v6 = *v5;
  v7 = v5[1];
  v8 = v3;
  for ( i = *v5; v7 != i; i += 24 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v8, i);
    v8 += 24;
  }
  v4[1] = v3 + 24 * (178956971 * ((unsigned int)(v7 - v6) >> 3) & 0x1FFFFFFF);
  v4[3] = 0;
  *((_WORD *)v4 + 8) = 0;
  CTRPluginFramework::Clock::Clock((CTRPluginFramework::Clock *)(v4 + 6));
  return v4;
}
// 630: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

//----- (000000F0) --------------------------------------------------------
void **__fastcall CTRPluginFramework::SubMenu::~SubMenu(CTRPluginFramework::SubMenu *this)
{
  void **v1; // r4
  int v2; // r5
  int v3; // r6

  v1 = (void **)this;
  v2 = *(_DWORD *)this;
  v3 = *((_DWORD *)this + 1);
  while ( v3 != v2 )
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v2);
    v2 += 24;
  }
  if ( *v1 )
    operator delete(*v1);
  return v1;
}
// 638: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (0000012C) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::SubMenu::operator()(int a1)
{
  int v1; // r3
  signed int result; // r0

  v1 = *(unsigned __int8 *)(a1 + 17);
  *(_BYTE *)(a1 + 17) = 0;
  if ( v1 )
    result = *(_DWORD *)(a1 + 12);
  else
    result = -1;
  return result;
}

//----- (00000148) --------------------------------------------------------
int __fastcall CTRPluginFramework::SubMenu::Draw(int result)
{
  __int64 v1; // d8
  __int64 *v2; // r4
  unsigned int v3; // r5
  int v4; // r0
  int v5; // r2
  float v6; // r1
  __int64 v7; // r2
  int v8; // r9
  Time v9; // r1
  int v10; // r3
  __int64 v11; // [sp+8h] [bp-48h]
  int v12; // [sp+14h] [bp-3Ch]
  int v13; // [sp+18h] [bp-38h]
  int v14; // [sp+1Ch] [bp-34h]
  int v15; // [sp+20h] [bp-30h]
  int v16; // [sp+24h] [bp-2Ch]
  __int64 v17; // [sp+28h] [bp-28h]

  if ( *(_BYTE *)(result + 16) )
  {
    v17 = v1;
    v2 = (__int64 *)result;
    __mcr(15, 0, result, 7, 10, 5);
    if ( !(`guard variable for'CTRPluginFramework::SubMenu::Draw(void)::background & 1) )
    {
      if ( _cxa_guard_acquire(&`guard variable for'CTRPluginFramework::SubMenu::Draw(void)::background) )
      {
        CTRPluginFramework::SubMenu::Draw(void)::background = 85899346160LL;
        unk_10 = 858993459330LL;
        _cxa_guard_release(&`guard variable for'CTRPluginFramework::SubMenu::Draw(void)::background, 20);
      }
    }
    CTRPluginFramework::Renderer::SetTarget(1);
    v3 = 0;
    CTRPluginFramework::Renderer::DrawRect2(
      &CTRPluginFramework::SubMenu::Draw(void)::background,
      &CTRPluginFramework::Preferences::Settings[8]);
    v12 = 25;
    v4 = CTRPluginFramework::Renderer::DrawSysString(
           "Options",
           245,
           &v12,
           340,
           CTRPluginFramework::Preferences::Settings[4],
           0);
    result = CTRPluginFramework::Renderer::DrawLine(
               245,
               v12,
               v4 - 225,
               &CTRPluginFramework::Preferences::Settings[4],
               1);
    v5 = *((_DWORD *)v2 + 1);
    v12 = 46;
    if ( v5 != *(_DWORD *)v2 )
    {
      LODWORD(v6) = 241;
      v14 = 12 * *((_DWORD *)v2 + 3) + 45;
      v13 = 241;
      v15 = 110;
      v16 = 12;
      while ( 1 )
      {
        v7 = *v2;
        if ( v3 >= -1431655765 * ((HIDWORD(v7) - (signed int)v7) >> 3) )
          return result;
        v8 = *(_DWORD *)(v7 + 24 * v3);
        if ( *((_DWORD *)v2 + 3) == v3 )
        {
          CTRPluginFramework::Seconds((CTRPluginFramework *)&v11, v6);
          if ( !CTRPluginFramework::Clock::HasTimePassed((CTRPluginFramework::Clock *)(v2 + 3), v9) )
          {
            CTRPluginFramework::Renderer::DrawRect(&v13, &CTRPluginFramework::Color::Gainsboro, 1);
            CTRPluginFramework::Renderer::DrawRect(&v13, &CTRPluginFramework::Color::DarkGrey, 0);
            v10 = CTRPluginFramework::Color::Black;
            goto LABEL_11;
          }
          CTRPluginFramework::Renderer::DrawRect(&v13, &CTRPluginFramework::Color::DarkGrey, 0);
        }
        v10 = CTRPluginFramework::Preferences::Settings[4];
LABEL_11:
        result = CTRPluginFramework::Renderer::DrawString(v8, 245, &v12, v10);
        ++v3;
        v12 += 2;
      }
    }
  }
  return result;
}
// 4: using guessed type char `guard variable for'CTRPluginFramework::SubMenu::Draw(void)::background;
// 640: using guessed type int __fastcall _cxa_guard_acquire(_DWORD);
// 644: using guessed type int __fastcall _cxa_guard_release(_DWORD, _DWORD);
// 648: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 64C: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect2(_DWORD, _DWORD);
// 650: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 654: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawLine(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 660: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD);
// 664: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000348) --------------------------------------------------------
int __fastcall CTRPluginFramework::SubMenu::ProcessEvent(int result, const Event *a2, int a3)
{
  signed int v3; // r3
  unsigned int v4; // r3
  unsigned int v5; // r2
  int v6; // [sp+0h] [bp-10h]
  const Event *v7; // [sp+4h] [bp-Ch]
  int v8; // [sp+8h] [bp-8h]

  v6 = result;
  v7 = a2;
  v8 = a3;
  if ( *(_BYTE *)(result + 16) )
  {
    if ( !LOBYTE(a2->modifiers) )
    {
      v3 = a2->modifierMask;
      if ( v3 == 2 )
      {
        *(_BYTE *)(result + 16) = 0;
      }
      else if ( v3 > 2 )
      {
        if ( v3 == 64 )
        {
          *(_DWORD *)(result + 12) = (*(_DWORD *)(result + 12) - 1) & ~((*(_DWORD *)(result + 12) - 1) >> 31);
        }
        else if ( v3 == 128 )
        {
          v4 = -1431655765 * ((*(_DWORD *)(result + 4) - *(_DWORD *)result) >> 3) - 1;
          v5 = *(_DWORD *)(result + 12) + 1;
          if ( v4 > v5 )
            *(_DWORD *)(result + 12) = v5;
          else
            *(_DWORD *)(result + 12) = v4;
        }
      }
      else if ( v3 == 1 )
      {
        *(_BYTE *)(result + 17) = 1;
        result = CTRPluginFramework::Clock::Restart((CTRPluginFramework::Clock *)&v6);
      }
    }
  }
  else if ( !LOBYTE(a2->modifiers) && a2->modifierMask == 1024 )
  {
    *(_BYTE *)(result + 16) = 1;
  }
  return result;
}

//----- (0000040C) --------------------------------------------------------
int __fastcall CTRPluginFramework::SubMenu::IsOpen(CTRPluginFramework::SubMenu *this)
{
  return *((unsigned __int8 *)this + 16);
}

//----- (00000414) --------------------------------------------------------
int __fastcall CTRPluginFramework::SubMenu::OptionsCount(CTRPluginFramework::SubMenu *this)
{
  return -1431655765 * ((*((_DWORD *)this + 1) - *(_DWORD *)this) >> 3);
}

//----- (00000430) --------------------------------------------------------
unsigned int *__fastcall std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::operator=(unsigned int *a1, unsigned int *a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r6
  unsigned int v4; // r10
  unsigned int v5; // r9
  int v6; // r8
  unsigned int v7; // r4
  unsigned int *v8; // r11
  unsigned int v9; // r7
  __int64 i; // r6
  int v12; // r7
  int v13; // r7
  unsigned int v14; // r10
  int v15; // r4
  unsigned int v16; // r6
  unsigned int v17; // r6
  unsigned int v18; // r7
  int v19; // r4

  v2 = a1;
  if ( a2 != a1 )
  {
    v3 = *a2;
    v4 = a2[1];
    v5 = *a1;
    v6 = v4 - *a2;
    v7 = -1431655765 * (v6 >> 3);
    v8 = a2;
    if ( -1431655765 * ((signed int)(a1[2] - *a1) >> 3) >= v7 )
    {
      v12 = -1431655765 * ((signed int)(a1[1] - v5) >> 3);
      if ( v7 > v12 )
      {
        while ( v12 > 0 )
        {
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v5, v3);
          v3 += 24;
          v5 += 24;
          --v12;
        }
        v17 = v2[1];
        v18 = v8[1];
        v19 = *v8 + v17 - *v2;
        while ( v18 != v19 )
        {
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v17, v19);
          v19 += 24;
          v17 += 24;
        }
      }
      else
      {
        v13 = -1431655765 * (v6 >> 3);
        v14 = *a1;
        while ( v13 > 0 )
        {
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v14, v3);
          v3 += 24;
          v14 += 24;
          --v13;
        }
        v15 = v5 + 24 * (v7 & ~((signed int)v7 >> 31));
        v16 = v2[1];
        while ( v16 != v15 )
        {
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v15);
          v15 += 24;
        }
      }
    }
    else
    {
      if ( v7 )
      {
        if ( v7 > 0xAAAAAAA )
          std::__throw_bad_alloc();
        v7 = operator new(v4 - *a2);
      }
      v9 = v7;
      while ( v4 != v3 )
      {
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v9, v3);
        v9 += 24;
        v3 += 24;
      }
      for ( i = *(_QWORD *)v2; HIDWORD(i) != (_DWORD)i; LODWORD(i) = i + 24 )
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(i);
      if ( *v2 )
        operator delete((void *)*v2);
      *v2 = v7;
      v2[2] = v7 + v6;
    }
    v2[1] = *v2 + v6;
  }
  return v2;
}
// 630: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 638: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 67C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD);

//----- (000005D4) --------------------------------------------------------
unsigned int *__fastcall CTRPluginFramework::SubMenu::ChangeOptions(unsigned int *a1, unsigned int *a2)
{
  __int64 v2; // r6
  unsigned int *v3; // r4
  unsigned int *v4; // r8
  int v5; // r5
  int v6; // r0

  v2 = *(_QWORD *)a1;
  v3 = a1;
  v4 = a2;
  a1[3] = 0;
  if ( (_DWORD)v2 != HIDWORD(v2) )
  {
    v5 = v2;
    do
    {
      v6 = v5;
      v5 += 24;
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v6);
    }
    while ( HIDWORD(v2) != v5 );
    v3[1] = v2;
  }
  return std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::operator=(
           v3,
           v4);
}
// 638: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

// ALL OK, 9 function(s) have been successfully decompiled