/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::Screenshot::TaskCallback(CTRPluginFramework::Screenshot *this, void *a2);
int __fastcall CTRPluginFramework::Screenshot::OSDCallback(CTRPluginFramework::Screenshot *this, unsigned int a2, void *a3, void *a4, unsigned int a5, int a6);
int __fastcall CTRPluginFramework::Screenshot::UpdateFileCount(CTRPluginFramework::Screenshot *this);
int __fastcall CTRPluginFramework::Screenshot::Initialize(CTRPluginFramework::Screenshot *this);
int GLOBAL__sub_I__ZN18CTRPluginFramework10Screenshot9IsEnabledE();
// _DWORD CTRPluginFramework::Clock::Restart(CTRPluginFramework::Clock *__hidden this); idb
// int __fastcall LightEvent_Wait(_DWORD); weak
// int __fastcall LightEvent_Clear(_DWORD); weak
// _DWORD __cdecl CTRPluginFramework::ScreenImpl::Screenshot(CTRPluginFramework::ScreenImpl *__hidden this, int, CTRPluginFramework::BMPImage *); weak
// _DWORD CTRPluginFramework::BMPImage::IsLoaded(CTRPluginFramework::BMPImage *__hidden this); idb
// _DWORD CTRPluginFramework::System::IsNew3DS(CTRPluginFramework::System *__hidden this); idb
// int __fastcall LightEvent_Signal(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD); weak
// int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::BMPImage::SaveImage(_DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Clock::HasTimePassed(CTRPluginFramework::Clock *__hidden this, Time); idb
// _DWORD __cdecl CTRPluginFramework::BMPImage::~BMPImage(CTRPluginFramework::BMPImage *__hidden this); idb
// void __cdecl operator delete(void *); idb
// _DWORD CTRPluginFramework::Controller::GetKeysDown(CTRPluginFramework::Controller *__hidden this); idb
// _DWORD CTRPluginFramework::Task::Status(CTRPluginFramework::Task *__hidden this); idb
// _DWORD CTRPluginFramework::Task::Wait(CTRPluginFramework::Task *__hidden this); idb
// _DWORD CTRPluginFramework::Task::Start(CTRPluginFramework::Task *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::ScreenImpl::Acquire(CTRPluginFramework::ScreenImpl *__hidden this, unsigned int, unsigned int, unsigned int, unsigned int, bool); idb
// _DWORD CTRPluginFramework::ScreenImpl::Acquire(CTRPluginFramework::ScreenImpl *__hidden this); idb
// int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(_DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Process::GetHandle(CTRPluginFramework::Process *__hidden this); idb
// int __fastcall svcFlushProcessDataCache(_DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::pop_back(_DWORD); weak
// int __fastcall CTRPluginFramework::Directory::Directory(_DWORD, _DWORD, _DWORD); weak
// int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void); weak
// int __fastcall CTRPluginFramework::Directory::ListFiles(_DWORD, _DWORD, _DWORD); weak
// int memcmp(const void *s1, const void *s2, size_t n);
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(_DWORD, _DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Directory::~Directory(CTRPluginFramework::Directory *__hidden this); idb
// int __fastcall LightEvent_Init(_DWORD, _DWORD); weak
// int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::Clock::Clock(CTRPluginFramework::Clock *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Task::Task(CTRPluginFramework::Task *__hidden this, int (__cdecl *)(void *), void *, int); idb
// _DWORD __cdecl CTRPluginFramework::Task::~Task(CTRPluginFramework::Task *__hidden this); weak

//-------------------------------------------------------------------------
// Data declarations

int CTRPluginFramework::Screenshot::Screens = 3; // weak
int CTRPluginFramework::Screenshot::Hotkeys = 8; // weak
_UNKNOWN CTRPluginFramework::Screenshot::_timer; // weak
_UNKNOWN CTRPluginFramework::Screenshot::_readyEvent; // weak
_UNKNOWN CTRPluginFramework::Screenshot::_resumeEvent; // weak
int ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E; // weak
int dword_2C; // weak
char byte_30; // weak
int CTRPluginFramework::Screenshot::_filecount; // weak
int ZN18CTRPluginFramework10Screenshot4PathB5cxx11E; // weak
int dword_48; // weak
char byte_4C; // weak
int CTRPluginFramework::Screenshot::_display; // weak
int CTRPluginFramework::Screenshot::_mode; // weak
_UNKNOWN CTRPluginFramework::Screenshot::Timer; // weak
char CTRPluginFramework::Screenshot::IsEnabled; // weak
_UNKNOWN CTRPluginFramework::Screenshot::_task; // weak
// extern _UNKNOWN CTRPluginFramework::ScreenImpl::Top; weak
// extern _UNKNOWN CTRPluginFramework::ScreenImpl::Bottom; weak
// extern _UNKNOWN CTRPluginFramework::SystemImpl::IsNew3DS; weak
// extern _UNKNOWN CTRPluginFramework::Color::ForestGreen; weak
// extern _UNKNOWN CTRPluginFramework::Color::White; weak
// extern _UNKNOWN CTRPluginFramework::Color::Red; weak
// extern _UNKNOWN CTRPluginFramework::Time::Zero; weak
// extern _UNKNOWN _dso_handle; weak
// extern _UNKNOWN std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string; weak


//----- (0000007C) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screenshot::TaskCallback(CTRPluginFramework::Screenshot *this, void *a2)
{
  CTRPluginFramework::BMPImage *v2; // r5
  CTRPluginFramework::BMPImage *v3; // r2
  CTRPluginFramework::System *v4; // r9
  Time v5; // r1
  signed int v6; // r3
  int v8; // [sp+0h] [bp-58h]
  char *v9; // [sp+8h] [bp-50h]
  int v10; // [sp+Ch] [bp-4Ch]
  char v11; // [sp+10h] [bp-48h]
  char v12; // [sp+20h] [bp-38h]

  v2 = 0;
  v9 = &v11;
  v10 = 0;
  v11 = 0;
  CTRPluginFramework::Clock::Restart((CTRPluginFramework::Clock *)&v8);
  do
  {
    LightEvent_Wait(&CTRPluginFramework::Screenshot::_readyEvent);
    LightEvent_Clear(&CTRPluginFramework::Screenshot::_readyEvent);
    v2 = (CTRPluginFramework::BMPImage *)CTRPluginFramework::ScreenImpl::Screenshot(
                                           (CTRPluginFramework::ScreenImpl *)(CTRPluginFramework::Screenshot::Screens & 3),
                                           (int)v2,
                                           v3);
    v4 = (CTRPluginFramework::System *)CTRPluginFramework::BMPImage::IsLoaded(v2);
    if ( !CTRPluginFramework::System::IsNew3DS(v4) )
      LightEvent_Signal(&CTRPluginFramework::Screenshot::_resumeEvent);
    if ( v4 )
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(
        &v9,
        &ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E);
      ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(&v12, " - %03d.bmp", CTRPluginFramework::Screenshot::_filecount);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(&v9, &v12);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v12);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
        &v12,
        &ZN18CTRPluginFramework10Screenshot4PathB5cxx11E);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v12, &v9);
      CTRPluginFramework::BMPImage::SaveImage(v2, &v12);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v12);
      ++CTRPluginFramework::Screenshot::_filecount;
      v6 = 1;
    }
    else
    {
      v6 = 131;
    }
    CTRPluginFramework::Screenshot::_display = v6;
    if ( !(CTRPluginFramework::Screenshot::_mode & 4) )
      break;
    CTRPluginFramework::Screenshot::_mode = CTRPluginFramework::Screenshot::Screens;
    if ( !(CTRPluginFramework::Screenshot::Screens & 4) )
      break;
  }
  while ( !CTRPluginFramework::Clock::HasTimePassed(
             (CTRPluginFramework::Clock *)&CTRPluginFramework::Screenshot::_timer,
             v5) );
  if ( v2 )
  {
    CTRPluginFramework::BMPImage::~BMPImage(v2);
    operator delete((void *)v2);
  }
  CTRPluginFramework::Screenshot::_mode = 0;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v9);
  return 0;
}
// 4: using guessed type int CTRPluginFramework::Screenshot::Screens;
// 28: using guessed type int ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E;
// 40: using guessed type int CTRPluginFramework::Screenshot::_filecount;
// 44: using guessed type int ZN18CTRPluginFramework10Screenshot4PathB5cxx11E;
// 5C: using guessed type int CTRPluginFramework::Screenshot::_display;
// 60: using guessed type int CTRPluginFramework::Screenshot::_mode;
// 794: using guessed type int __fastcall LightEvent_Wait(_DWORD);
// 798: using guessed type int __fastcall LightEvent_Clear(_DWORD);
// 79C: using guessed type _DWORD __cdecl CTRPluginFramework::ScreenImpl::Screenshot(CTRPluginFramework::ScreenImpl *__hidden this, int, CTRPluginFramework::BMPImage *);
// 7A8: using guessed type int __fastcall LightEvent_Signal(_DWORD);
// 7AC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD);
// 7B0: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...);
// 7B4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD);
// 7B8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 7BC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 7C0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(_DWORD, _DWORD);
// 7C4: using guessed type int __fastcall CTRPluginFramework::BMPImage::SaveImage(_DWORD, _DWORD);

//----- (000001F4) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screenshot::OSDCallback(CTRPluginFramework::Screenshot *this, unsigned int a2, void *a3, void *a4, unsigned int a5, int a6)
{
  int v6; // r9
  int v7; // r4
  unsigned int v9; // r7
  void *v10; // r8
  unsigned int v11; // r6
  CTRPluginFramework::Screenshot *v12; // r5
  int v13; // r3
  signed int v14; // r3
  CTRPluginFramework::ScreenImpl **v15; // r3
  int v16; // r0
  CTRPluginFramework::Process *v17; // r0
  int v18; // r0
  int v19; // [sp+Ch] [bp-5Ch]
  char v20; // [sp+10h] [bp-58h]
  int v21; // [sp+28h] [bp-40h]

  v6 = (unsigned __int8)CTRPluginFramework::Screenshot::IsEnabled;
  if ( !CTRPluginFramework::Screenshot::IsEnabled )
    return 0;
  v9 = (unsigned int)a4;
  v10 = a3;
  v11 = a2;
  v12 = this;
  if ( !CTRPluginFramework::Screenshot::_mode
    && !(CTRPluginFramework::Screenshot::Hotkeys & ~CTRPluginFramework::Controller::GetKeysDown(this)) )
  {
    CTRPluginFramework::Screenshot::_mode = CTRPluginFramework::Screenshot::Screens;
    if ( CTRPluginFramework::Task::Status((CTRPluginFramework::Task *)&CTRPluginFramework::Screenshot::_task) & 3 )
      CTRPluginFramework::Task::Wait((CTRPluginFramework::Task *)&CTRPluginFramework::Screenshot::_task);
    CTRPluginFramework::Task::Start((CTRPluginFramework::Task *)&CTRPluginFramework::Screenshot::_task);
  }
  if ( !(CTRPluginFramework::Screenshot::_mode & 3) )
  {
    if ( v12 )
    {
      if ( (unsigned int)(CTRPluginFramework::Screenshot::_display - 1) <= 0x76 )
      {
        CTRPluginFramework::ScreenImpl::Acquire(
          CTRPluginFramework::ScreenImpl::Bottom,
          v11,
          (unsigned int)v10,
          v9,
          a5,
          0);
        v19 = 0;
        CTRPluginFramework::Renderer::SetTarget(0);
        ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(
          &v20,
          " - %03d.bmp",
          CTRPluginFramework::Screenshot::_filecount - 1);
        v16 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(
                &v20,
                0,
                &ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v21, v16);
        CTRPluginFramework::Renderer::DrawString(
          v21,
          0,
          &v19,
          CTRPluginFramework::Color::White,
          CTRPluginFramework::Color::ForestGreen);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v21);
        v17 = (CTRPluginFramework::Process *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v20);
        v18 = CTRPluginFramework::Process::GetHandle(v17);
        svcFlushProcessDataCache(v18, v11, 320 * v9);
        ++CTRPluginFramework::Screenshot::_display;
      }
      if ( (unsigned int)(CTRPluginFramework::Screenshot::_display - 131) <= 0x76 )
      {
        CTRPluginFramework::ScreenImpl::Acquire(
          CTRPluginFramework::ScreenImpl::Bottom,
          v11,
          (unsigned int)v10,
          v9,
          a5,
          0);
        v21 = 0;
        CTRPluginFramework::Renderer::SetTarget(0);
        CTRPluginFramework::Renderer::DrawString(
          "Screenshot: An error occured",
          0,
          &v21,
          CTRPluginFramework::Color::Red,
          CTRPluginFramework::Color::White);
        ++CTRPluginFramework::Screenshot::_display;
      }
    }
    return 0;
  }
  if ( v12 )
    v13 = 0;
  else
    v13 = CTRPluginFramework::Screenshot::_mode & 1;
  if ( v13 )
  {
    CTRPluginFramework::ScreenImpl::Acquire(CTRPluginFramework::ScreenImpl::Top, v11, (unsigned int)v10, v9, a5, 1);
    CTRPluginFramework::Screenshot::_mode &= 0xFFFFFFFE;
  }
  v14 = (signed int)v12;
  if ( v12 )
    v14 = 1;
  if ( v14 & ((unsigned int)CTRPluginFramework::Screenshot::_mode >> 1) )
  {
    CTRPluginFramework::ScreenImpl::Acquire(CTRPluginFramework::ScreenImpl::Bottom, v11, (unsigned int)v10, v9, a5, 1);
    CTRPluginFramework::Screenshot::_mode &= 0xFFFFFFFD;
  }
  if ( CTRPluginFramework::Screenshot::_mode & 3 )
    return v6;
  CTRPluginFramework::Screenshot::_mode |= 8u;
  v7 = CTRPluginFramework::SystemImpl::IsNew3DS ^ 1;
  if ( CTRPluginFramework::SystemImpl::IsNew3DS != 1 )
  {
    if ( v12 )
      v15 = (CTRPluginFramework::ScreenImpl **)&CTRPluginFramework::ScreenImpl::Top;
    else
      v15 = (CTRPluginFramework::ScreenImpl **)&CTRPluginFramework::ScreenImpl::Bottom;
    CTRPluginFramework::ScreenImpl::Acquire(*v15);
  }
  LightEvent_Signal(&CTRPluginFramework::Screenshot::_readyEvent);
  if ( !v7 )
    return v6;
  LightEvent_Wait(&CTRPluginFramework::Screenshot::_resumeEvent);
  LightEvent_Clear(&CTRPluginFramework::Screenshot::_resumeEvent);
  return v7;
}
// 4: using guessed type int CTRPluginFramework::Screenshot::Screens;
// 8: using guessed type int CTRPluginFramework::Screenshot::Hotkeys;
// 28: using guessed type int ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E;
// 40: using guessed type int CTRPluginFramework::Screenshot::_filecount;
// 5C: using guessed type int CTRPluginFramework::Screenshot::_display;
// 60: using guessed type int CTRPluginFramework::Screenshot::_mode;
// 70: using guessed type char CTRPluginFramework::Screenshot::IsEnabled;
// 794: using guessed type int __fastcall LightEvent_Wait(_DWORD);
// 798: using guessed type int __fastcall LightEvent_Clear(_DWORD);
// 7A8: using guessed type int __fastcall LightEvent_Signal(_DWORD);
// 7B0: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...);
// 7B8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 7EC: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 7F0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(_DWORD, _DWORD, _DWORD);
// 7F4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 7F8: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 800: using guessed type int __fastcall svcFlushProcessDataCache(_DWORD, _DWORD, _DWORD);

//----- (000004E0) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screenshot::UpdateFileCount(CTRPluginFramework::Screenshot *this)
{
  int v1; // r0
  const void **v2; // r5
  const void **v3; // r6
  size_t v4; // r2
  int v5; // r0
  __int64 i; // r4
  void *v8[2]; // [sp+4h] [bp-BCh]
  int v9; // [sp+Ch] [bp-B4h]
  char v10; // [sp+10h] [bp-B0h]
  void *s2; // [sp+28h] [bp-98h]
  int v12; // [sp+2Ch] [bp-94h]
  char v13; // [sp+40h] [bp-80h]
  char *v14; // [sp+58h] [bp-68h]
  int v15; // [sp+5Ch] [bp-64h]
  char v16; // [sp+60h] [bp-60h]
  char v17; // [sp+70h] [bp-50h]

  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
    &v10,
    &ZN18CTRPluginFramework10Screenshot4PathB5cxx11E);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::pop_back(&v10);
  CTRPluginFramework::Directory::Directory(&v17, &v10, 0);
  v8[0] = 0;
  v8[1] = 0;
  v9 = 0;
  v14 = &v16;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
  v15 = 4;
  v14[4] = 0;
  CTRPluginFramework::Directory::ListFiles(&v17, v8, &v14);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
  CTRPluginFramework::Screenshot::_filecount = 0;
  ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(&v14, " - %03d.bmp", 0);
  v1 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(
         &v14,
         0,
         &ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&s2, v1);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
  v2 = (const void **)v8[0];
  v3 = (const void **)v8[1];
  while ( v3 != v2 )
  {
    v4 = (size_t)v2[1];
    if ( v4 == v12 && (!v4 || !memcmp(*v2, s2, v4)) )
    {
      ++CTRPluginFramework::Screenshot::_filecount;
      ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(&v13, " - %03d.bmp");
      v5 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(
             &v13,
             0,
             &ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v14, v5);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(&s2, &v14);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v13);
    }
    v2 += 6;
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&s2);
  for ( i = *(_QWORD *)v8; HIDWORD(i) != (_DWORD)i; LODWORD(i) = i + 24 )
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(i);
  if ( v8[0] )
    operator delete(v8[0]);
  CTRPluginFramework::Directory::~Directory((CTRPluginFramework::Directory *)&v17);
  return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v10);
}
// 28: using guessed type int ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E;
// 40: using guessed type int CTRPluginFramework::Screenshot::_filecount;
// 44: using guessed type int ZN18CTRPluginFramework10Screenshot4PathB5cxx11E;
// 7B0: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...);
// 7B8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 7BC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 7F0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(_DWORD, _DWORD, _DWORD);
// 7F4: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
// 81C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::pop_back(_DWORD);
// 820: using guessed type int __fastcall CTRPluginFramework::Directory::Directory(_DWORD, _DWORD, _DWORD);
// 824: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void);
// 828: using guessed type int __fastcall CTRPluginFramework::Directory::ListFiles(_DWORD, _DWORD, _DWORD);
// 830: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=(_DWORD, _DWORD);

//----- (00000684) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screenshot::Initialize(CTRPluginFramework::Screenshot *this)
{
  CTRPluginFramework::Screenshot *v1; // r0

  LightEvent_Init(&CTRPluginFramework::Screenshot::_readyEvent, 1);
  v1 = (CTRPluginFramework::Screenshot *)LightEvent_Init(&CTRPluginFramework::Screenshot::_resumeEvent, 1);
  return CTRPluginFramework::Screenshot::UpdateFileCount(v1);
}
// 838: using guessed type int __fastcall LightEvent_Init(_DWORD, _DWORD);

//----- (000006B0) --------------------------------------------------------
int GLOBAL__sub_I__ZN18CTRPluginFramework10Screenshot9IsEnabledE()
{
  CTRPluginFramework::Screenshot::Timer = CTRPluginFramework::Time::Zero;
  ZN18CTRPluginFramework10Screenshot4PathB5cxx11E = (int)&byte_4C;
  dword_48 = 0;
  byte_4C = 0;
  _aeabi_atexit(
    &ZN18CTRPluginFramework10Screenshot4PathB5cxx11E,
    &std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string,
    &_dso_handle);
  ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E = (int)&byte_30;
  dword_2C = 0;
  byte_30 = 0;
  _aeabi_atexit(
    &ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E,
    &std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string,
    &_dso_handle);
  CTRPluginFramework::Clock::Clock((CTRPluginFramework::Clock *)&CTRPluginFramework::Screenshot::_timer);
  CTRPluginFramework::Task::Task(
    (CTRPluginFramework::Task *)&CTRPluginFramework::Screenshot::_task,
    (int (__cdecl *)(void *))CTRPluginFramework::Screenshot::TaskCallback,
    0,
    -1);
  return _aeabi_atexit(&CTRPluginFramework::Screenshot::_task, &CTRPluginFramework::Task::~Task, &_dso_handle);
}
// 28: using guessed type int ZN18CTRPluginFramework10Screenshot6PrefixB5cxx11E;
// 2C: using guessed type int dword_2C;
// 30: using guessed type char byte_30;
// 44: using guessed type int ZN18CTRPluginFramework10Screenshot4PathB5cxx11E;
// 48: using guessed type int dword_48;
// 4C: using guessed type char byte_4C;
// 83C: using guessed type int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD);
// 854: using guessed type _DWORD __cdecl CTRPluginFramework::Task::~Task(CTRPluginFramework::Task *__hidden this);

// ALL OK, 5 function(s) have been successfully decompiled
