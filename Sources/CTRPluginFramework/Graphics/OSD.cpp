/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::Screen::GetFramebuffer(CTRPluginFramework::Screen *this, unsigned int a2, unsigned int a3, int a4);
int __fastcall CTRPluginFramework::Screen::Draw(unsigned __int8 *a1, _DWORD *a2, int a3, int a4, _DWORD *a5, _DWORD *a6);
int __fastcall CTRPluginFramework::Screen::DrawSysfont(unsigned __int8 *a1, _DWORD *a2, int a3, int a4, _DWORD *a5);
int __fastcall CTRPluginFramework::Screen::DrawRect(unsigned __int8 *a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7);
int __fastcall CTRPluginFramework::Screen::DrawPixel(unsigned __int8 *a1, int a2, int a3, int a4);
int __fastcall CTRPluginFramework::Screen::ReadPixel(CTRPluginFramework::Screen *a1, unsigned int a2, unsigned int a3, int *a4, bool a5);
signed int __fastcall CTRPluginFramework::OSD::Notify(CTRPluginFramework::OSDImpl *a1);
int __fastcall CTRPluginFramework::OSD::Stop(CTRPluginFramework::OSD *this, bool (__cdecl *a2)(const CTRPluginFramework::Screen *));
int __fastcall CTRPluginFramework::OSD::GetTextWidth(int a1, CTRPluginFramework::Renderer **a2);
void *__fastcall CTRPluginFramework::OSD::GetTopScreen(CTRPluginFramework::OSD *this);
void *__fastcall CTRPluginFramework::OSD::GetBottomScreen(CTRPluginFramework::OSD *this);
int __fastcall CTRPluginFramework::OSD::SwapBuffers(CTRPluginFramework::OSD *this);
void __fastcall std::vector<bool (*)(CTRPluginFramework::Screen const&),std::allocator<bool (*)(CTRPluginFramework::Screen const&)>>::_M_realloc_insert<bool (* const&)(CTRPluginFramework::Screen const&)>(_DWORD *a1, _BYTE *a2, _DWORD *a3);
int __fastcall CTRPluginFramework::OSD::Run(CTRPluginFramework::OSD *this, bool (__cdecl *a2)(const CTRPluginFramework::Screen *), int a3);
// int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawPixel(_DWORD, _DWORD, _DWORD); weak
// int ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE(void); weak
// _DWORD CTRPluginFramework::OSDImpl::Lock(CTRPluginFramework::OSDImpl *__hidden this); idb
// _DWORD CTRPluginFramework::OSDImpl::Unlock(CTRPluginFramework::OSDImpl *__hidden this); idb
// _DWORD __cdecl operator new(unsigned int); idb
// int CTRPluginFramework::OSDImpl::OSDMessage::OSDMessage(void); weak
// int std::__detail::_List_node_base::_M_hook(void); weak
// _DWORD __cdecl CTRPluginFramework::Renderer::GetTextSize(CTRPluginFramework::Renderer *__hidden this, const char *); weak
// _DWORD __cdecl CTRPluginFramework::Renderer::LinuxFontSize(CTRPluginFramework::Renderer *__hidden this, const char *); idb
// _DWORD __cdecl CTRPluginFramework::ScreenImpl::SwapBuffer(CTRPluginFramework::ScreenImpl *__hidden this, bool, bool); idb
// int __fastcall gspWaitForEvent(_DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::OSDImpl::UpdateScreens(CTRPluginFramework::OSDImpl *__hidden this); idb
// void *memmove(void *dest, const void *src, size_t n);
// void *memcpy(void *dest, const void *src, size_t n);
// void __cdecl operator delete(void *); idb

//-------------------------------------------------------------------------
// Data declarations

// extern __thread _UNKNOWN CTRPluginFramework::PrivColor::FromFramebuffer; weak
// extern _DWORD ZN18CTRPluginFramework7OSDImpl13NotificationsB5cxx11E[3]; idb
// extern int *CTRPluginFramework::OSDImpl::Callbacks[3]; idb
// extern _UNKNOWN CTRPluginFramework::OSDImpl::TopScreen; weak
// extern _UNKNOWN CTRPluginFramework::OSDImpl::BottomScreen; weak
// extern _UNKNOWN CTRPluginFramework::ScreenImpl::Bottom; weak
// extern _UNKNOWN CTRPluginFramework::ScreenImpl::Top; weak


//----- (00000004) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::GetFramebuffer(CTRPluginFramework::Screen *this, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r8
  int v5; // r7
  unsigned int v7; // r4
  unsigned int v8; // r5
  unsigned int v9; // r6
  int v10; // r0
  unsigned int v11; // r1

  v4 = *(unsigned __int8 *)this;
  if ( a4 )
  {
    if ( !*(_BYTE *)this )
      return 0;
    if ( !*((_BYTE *)this + 1) )
      return *((unsigned __int8 *)this + 1);
    v5 = *((_DWORD *)this + 2);
  }
  else
  {
    v5 = *((_DWORD *)this + 1);
  }
  v7 = *((_DWORD *)this + 4);
  v8 = a2;
  v9 = a3;
  v10 = *((_DWORD *)this + 3) / v7;
  if ( v4 )
    v11 = 400;
  else
    v11 = 320;
  if ( v8 >= v11 )
    v8 = v11;
  if ( a3 >= 0xF0 )
    v9 = 240;
  return v5 + v7 * (239 - v9 + v10 * v8);
}

//----- (00000084) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::Draw(unsigned __int8 *a1, _DWORD *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  _DWORD *v6; // r4
  int v7; // r5
  int v8; // r0
  int v10; // [sp+Ch] [bp-14h]

  v6 = a2;
  v7 = a3;
  v8 = *a1;
  v10 = a4;
  CTRPluginFramework::Renderer::SetTarget(v8);
  CTRPluginFramework::Renderer::DrawString(*v6, v7, &v10, *a5, *a6);
  return v10;
}
// 54C: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 550: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (000000D0) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::DrawSysfont(unsigned __int8 *a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r0
  _DWORD *v6; // r4
  int v7; // r5
  int v9; // [sp+Ch] [bp-14h]

  v5 = *a1;
  v6 = a2;
  v7 = a3;
  v9 = a4;
  CTRPluginFramework::Renderer::SetTarget(v5);
  CTRPluginFramework::Renderer::DrawSysString(*v6, v7, &v9, 400, *a5, 0);
  return v9;
}
// 54C: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 554: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000128) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::DrawRect(unsigned __int8 *a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7)
{
  int v7; // r4
  int v8; // r5
  int v9; // r6

  v7 = a2;
  v8 = a3;
  v9 = a4;
  CTRPluginFramework::Renderer::SetTarget(*a1);
  return CTRPluginFramework::Renderer::DrawRect(v7, v8, v9, a5, a6, a7, 1);
}
// 54C: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 558: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000170) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::DrawPixel(unsigned __int8 *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  int v6; // r6

  v4 = a2;
  v5 = a3;
  v6 = a4;
  CTRPluginFramework::Renderer::SetTarget(*a1);
  return CTRPluginFramework::Renderer::DrawPixel(v4, v5, v6);
}
// 54C: using guessed type int __fastcall CTRPluginFramework::Renderer::SetTarget(_DWORD);
// 55C: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawPixel(_DWORD, _DWORD, _DWORD);

//----- (0000019C) --------------------------------------------------------
int __fastcall CTRPluginFramework::Screen::ReadPixel(CTRPluginFramework::Screen *a1, unsigned int a2, unsigned int a3, int *a4, bool a5)
{
  int *v5; // r4
  int v6; // r5
  int result; // r0

  v5 = a4;
  v6 = CTRPluginFramework::Screen::GetFramebuffer(a1, a2, a3, a5);
  if ( &ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE )
    ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE();
  result = (*(int (__fastcall **)(int))((char *)&CTRPluginFramework::PrivColor::FromFramebuffer + __mrc(15, 0, 13, 0, 3)))(v6);
  *v5 = result;
  return result;
}
// 560: using guessed type int ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE(void);

//----- (000001E8) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::OSD::Notify(CTRPluginFramework::OSDImpl *a1)
{
  CTRPluginFramework::OSDImpl *v1; // r0
  signed int result; // r0
  int v3; // r5
  CTRPluginFramework::OSDImpl *v4; // r0

  v1 = (CTRPluginFramework::OSDImpl *)CTRPluginFramework::OSDImpl::Lock(a1);
  if ( ZN18CTRPluginFramework7OSDImpl13NotificationsB5cxx11E[2] <= 0x31u )
  {
    v3 = operator new(0x30u);
    CTRPluginFramework::OSDImpl::OSDMessage::OSDMessage();
    *(_DWORD *)(operator new(0xCu) + 8) = v3;
    v4 = (CTRPluginFramework::OSDImpl *)std::__detail::_List_node_base::_M_hook();
    ++ZN18CTRPluginFramework7OSDImpl13NotificationsB5cxx11E[2];
    CTRPluginFramework::OSDImpl::Unlock(v4);
    result = 0;
  }
  else
  {
    CTRPluginFramework::OSDImpl::Unlock(v1);
    result = -1;
  }
  return result;
}
// 570: using guessed type int CTRPluginFramework::OSDImpl::OSDMessage::OSDMessage(void);
// 574: using guessed type int std::__detail::_List_node_base::_M_hook(void);

//----- (00000264) --------------------------------------------------------
int __fastcall CTRPluginFramework::OSD::Stop(CTRPluginFramework::OSD *this, bool (__cdecl *a2)(const CTRPluginFramework::Screen *))
{
  CTRPluginFramework::OSD *v2; // r4
  int *v3; // r2
  int *v4; // r1
  signed int i; // r0
  int *v6; // r3
  int *v7; // r2
  CTRPluginFramework::OSD *v8; // t1
  int v9; // r2

  v2 = this;
  CTRPluginFramework::OSDImpl::Lock(this);
  v3 = CTRPluginFramework::OSDImpl::Callbacks[0];
  v4 = CTRPluginFramework::OSDImpl::Callbacks[1];
  for ( i = ((char *)v4 - (char *)CTRPluginFramework::OSDImpl::Callbacks[0]) >> 4; ; --i )
  {
    v6 = v3;
    if ( i <= 0 )
      break;
    if ( (CTRPluginFramework::OSD *)*v3 == v2 )
      goto LABEL_6;
    if ( (CTRPluginFramework::OSD *)v3[1] == v2 )
    {
      v6 = v3 + 1;
      goto LABEL_6;
    }
    if ( (CTRPluginFramework::OSD *)v3[2] == v2 )
    {
      v6 = v3 + 2;
      goto LABEL_6;
    }
    v3 += 4;
    if ( (CTRPluginFramework::OSD *)v6[3] == v2 )
    {
      v6 += 3;
      goto LABEL_6;
    }
  }
  v9 = v4 - v3;
  if ( v9 != 2 )
  {
    if ( v9 != 3 )
    {
      if ( v9 != 1 )
      {
        v6 = CTRPluginFramework::OSDImpl::Callbacks[1];
        goto LABEL_6;
      }
      goto LABEL_21;
    }
    if ( (CTRPluginFramework::OSD *)*v6 == v2 )
      goto LABEL_6;
    ++v6;
  }
  if ( (CTRPluginFramework::OSD *)*v6 == v2 )
    goto LABEL_6;
  ++v6;
LABEL_21:
  if ( (CTRPluginFramework::OSD *)*v6 != v2 )
  {
    v6 = CTRPluginFramework::OSDImpl::Callbacks[1];
    goto LABEL_24;
  }
LABEL_6:
  if ( v4 != v6 )
  {
    v7 = v6 + 1;
    while ( v4 != v7 )
    {
      v8 = (CTRPluginFramework::OSD *)*v7;
      ++v7;
      i = (signed int)v8;
      if ( v8 != v2 )
      {
        *v6 = i;
        ++v6;
      }
    }
  }
LABEL_24:
  if ( CTRPluginFramework::OSDImpl::Callbacks[1] != v6 )
    CTRPluginFramework::OSDImpl::Callbacks[1] = v6;
  return CTRPluginFramework::OSDImpl::Unlock((CTRPluginFramework::OSDImpl *)i);
}

//----- (00000370) --------------------------------------------------------
int __fastcall CTRPluginFramework::OSD::GetTextWidth(int a1, CTRPluginFramework::Renderer **a2)
{
  int result; // r0

  if ( a1 )
    result = CTRPluginFramework::Renderer::GetTextSize(*a2, (const char *)a2);
  else
    result = CTRPluginFramework::Renderer::LinuxFontSize(*a2, (const char *)a2);
  return result;
}
// 580: using guessed type _DWORD __cdecl CTRPluginFramework::Renderer::GetTextSize(CTRPluginFramework::Renderer *__hidden this, const char *);

//----- (0000039C) --------------------------------------------------------
void *__fastcall CTRPluginFramework::OSD::GetTopScreen(CTRPluginFramework::OSD *this)
{
  return &CTRPluginFramework::OSDImpl::TopScreen;
}

//----- (000003A8) --------------------------------------------------------
void *__fastcall CTRPluginFramework::OSD::GetBottomScreen(CTRPluginFramework::OSD *this)
{
  return &CTRPluginFramework::OSDImpl::BottomScreen;
}

//----- (000003B4) --------------------------------------------------------
int __fastcall CTRPluginFramework::OSD::SwapBuffers(CTRPluginFramework::OSD *this)
{
  CTRPluginFramework::OSDImpl *v1; // r0

  CTRPluginFramework::ScreenImpl::SwapBuffer(CTRPluginFramework::ScreenImpl::Bottom, 1, 0);
  CTRPluginFramework::ScreenImpl::SwapBuffer(CTRPluginFramework::ScreenImpl::Top, 1, 0);
  v1 = (CTRPluginFramework::OSDImpl *)gspWaitForEvent(2, 1);
  return CTRPluginFramework::OSDImpl::UpdateScreens(v1);
}
// 594: using guessed type int __fastcall gspWaitForEvent(_DWORD, _DWORD);

//----- (00000408) --------------------------------------------------------
void __fastcall std::vector<bool (*)(CTRPluginFramework::Screen const&),std::allocator<bool (*)(CTRPluginFramework::Screen const&)>>::_M_realloc_insert<bool (* const&)(CTRPluginFramework::Screen const&)>(_DWORD *a1, _BYTE *a2, _DWORD *a3)
{
  _BYTE *v3; // r7
  _BYTE *v4; // r10
  int v5; // r4
  int v6; // r3
  unsigned __int8 v7; // cf
  unsigned int v8; // r4
  _DWORD *v9; // r8
  _BYTE *v10; // r9
  _DWORD *v11; // r11
  size_t v12; // r5
  char *v13; // r6
  char *v14; // r5
  int v15; // r5

  v3 = (_BYTE *)*a1;
  v4 = (_BYTE *)a1[1];
  v5 = (signed int)&v4[-*a1] >> 2;
  if ( v5 )
    v6 = (signed int)&v4[-*a1] >> 2;
  else
    v6 = 1;
  v7 = __CFADD__(v5, v6);
  v8 = v5 + v6;
  v9 = a1;
  v10 = a2;
  v11 = a3;
  v12 = a2 - v3;
  if ( v7 || v8 > 0x3FFFFFFF )
  {
    v8 = 0x3FFFFFFF;
  }
  else if ( !v8 )
  {
    v13 = 0;
    goto LABEL_8;
  }
  v13 = (char *)operator new(4 * v8);
LABEL_8:
  *(_DWORD *)&v13[v12] = *v11;
  if ( v10 != v3 )
    memmove(v13, v3, v12);
  v14 = &v13[v12 + 4];
  if ( v10 != v4 )
    memcpy(v14, v10, v4 - v10);
  v15 = (int)&v14[v4 - v10];
  if ( v3 )
    operator delete(v3);
  *v9 = v13;
  v9[1] = v15;
  v9[2] = &v13[4 * v8];
}

//----- (000004CC) --------------------------------------------------------
int __fastcall CTRPluginFramework::OSD::Run(CTRPluginFramework::OSD *this, bool (__cdecl *a2)(const CTRPluginFramework::Screen *), int a3)
{
  CTRPluginFramework::OSDImpl *v3; // r0
  int *v4; // r1
  CTRPluginFramework::OSDImpl **v5; // r2
  CTRPluginFramework::OSDImpl *v6; // r12
  CTRPluginFramework::OSDImpl *v8; // [sp+4h] [bp-Ch]
  int v9; // [sp+8h] [bp-8h]

  v9 = a3;
  v8 = this;
  CTRPluginFramework::OSDImpl::Lock(this);
  v3 = v8;
  v4 = CTRPluginFramework::OSDImpl::Callbacks[1];
  v5 = (CTRPluginFramework::OSDImpl **)CTRPluginFramework::OSDImpl::Callbacks[0];
  while ( v4 != (int *)v5 )
  {
    v6 = *v5;
    ++v5;
    if ( v8 == v6 )
      return CTRPluginFramework::OSDImpl::Unlock(v3);
  }
  if ( v4 == CTRPluginFramework::OSDImpl::Callbacks[2] )
  {
    std::vector<bool (*)(CTRPluginFramework::Screen const&),std::allocator<bool (*)(CTRPluginFramework::Screen const&)>>::_M_realloc_insert<bool (* const&)(CTRPluginFramework::Screen const&)>(
      CTRPluginFramework::OSDImpl::Callbacks,
      v4,
      &v8);
  }
  else
  {
    *v4 = (int)v8;
    ++CTRPluginFramework::OSDImpl::Callbacks[1];
  }
  return CTRPluginFramework::OSDImpl::Unlock(v3);
}

// ALL OK, 14 function(s) have been successfully decompiled
