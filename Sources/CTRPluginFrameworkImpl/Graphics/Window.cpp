/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include "Preferences.hpp"

namespace CTRPluginFramework {


//-------------------------------------------------------------------------
// Data declarations

_UNKNOWN Window::BottomWindow; // weak
int dword_28; // weak
_UNKNOWN Window::TopWindow; // weak
int dword_34; // weak
int dword_38; // weak
_UNKNOWN unk_3C; // weak
_UNKNOWN unk_44; // weak
int dword_4C; // weak
int dword_50; // weak


//----- (00000054) --------------------------------------------------------
Window::~Window()
{
  int v2; // r0

  v2 = *((_DWORD *)this + 8);
  if ( v2 )
    (*(void (**)(void))(*(_DWORD *)v2 + 4))();
}

//----- (0000007C) --------------------------------------------------------
_DWORD * Window::Window(_DWORD *a1, int a2, int a3, int a4, int a5, char a6, int a7)
{
  _DWORD *v7; // r4
  int v8; // r5
  int v10; // [sp+0h] [bp-20h]
  int v11; // [sp+4h] [bp-1Ch]
  int v12; // [sp+8h] [bp-18h]
  int v13; // [sp+Ch] [bp-14h]

  v7 = a1;
  a1[3] = a5;
  a1[4] = a2 + 2;
  a1[7] = a5 - 4;
  a1[5] = a3 + 2;
  *a1 = a2;
  a1[1] = a3;
  a1[2] = a4;
  a1[6] = a4 - 4;
  a1[9] = a7;
  if ( a6 )
  {
    v10 = a4 - 25 + a2;
    v11 = a3 + 4;
    v12 = 20;
    v13 = 20;
    v8 = operator new(0x48u);
    Button::Button(v8, 8, &v10, &Icon::DrawClose);
    v7[8] = v8;
  }
  else
  {
    a1[8] = 0;
  }
  return v7;
}
// 3AC: using guessed type int __cdecl Button::Button(_DWORD, _DWORD, _DWORD, _DWORD);
// 3B0: using guessed type _DWORD __cdecl Icon::DrawClose(Icon *__hidden this, int, int, bool);

//----- (0000011C) --------------------------------------------------------
int  Window::Draw(Window *this)
{
  Window *v1; // r4
  int result; // r0

  v1 = this;
  if ( *((_DWORD *)this + 9) )
  {
    BMPImage::Draw(*((_DWORD *)this + 9), this);
  }
  else
  {
    Renderer::DrawRect2();
    Renderer::DrawRect((char *)v1 + 16, &Preferences::Settings[10], 0);
  }
  result = *((_DWORD *)v1 + 8);
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 8))();
  return result;
}
// 3B4: using guessed type int  BMPImage::Draw(_DWORD, _DWORD);
// 3B8: using guessed type int Renderer::DrawRect2(void);
// 3BC: using guessed type int  Renderer::DrawRect(_DWORD, _DWORD, _DWORD);

//----- (00000180) --------------------------------------------------------
int  Window::Draw(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r7
  int v4; // r5
  int v5; // r0
  int result; // r0
  int v7; // [sp+Ch] [bp-1Ch]

  v2 = a1;
  v3 = a2;
  if ( a1[9] )
  {
    BMPImage::Draw(a1[9], a1);
  }
  else
  {
    Renderer::DrawRect2();
    Renderer::DrawRect(v2 + 4, &Preferences::Settings[10], 0);
  }
  v7 = v2[1] + 5;
  v4 = *v2 + 10;
  v5 = Renderer::DrawSysString(*v3, v4, &v7, 330, Preferences::Settings[5], 0);
  Renderer::DrawLine(v4, v7, v5, &Preferences::Settings[5], 1);
  result = v2[8];
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 8))();
  return result;
}
// 3B4: using guessed type int  BMPImage::Draw(_DWORD, _DWORD);
// 3B8: using guessed type int Renderer::DrawRect2(void);
// 3BC: using guessed type int  Renderer::DrawRect(_DWORD, _DWORD, _DWORD);
// 3C4: using guessed type int  Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 3C8: using guessed type int  Renderer::DrawLine(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (00000258) --------------------------------------------------------
int  Window::DrawButton(Window *this)
{
  int result; // r0

  result = *((_DWORD *)this + 8);
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 8))();
  return result;
}

//----- (00000270) --------------------------------------------------------
int  Window::Update(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 32);
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 16))();
  return result;
}

//----- (00000288) --------------------------------------------------------
int  Window::MustClose(Window *this)
{
  int result; // r0

  result = *((_DWORD *)this + 8);
  if ( result )
    result = (*(int (**)(void))(*(_DWORD *)result + 12))();
  return result;
}

//----- (000002A0) --------------------------------------------------------
int  Window::Close(int result)
{
  Button *v1; // r3
  int v2; // r4

  v1 = *(Button **)(result + 32);
  if ( v1 )
  {
    v2 = result;
    Button::SetState(v1, 1);
    result = Button::Execute(*(Button **)(v2 + 32));
  }
  return result;
}

//----- (000002D0) --------------------------------------------------------
void  Window::UpdateBackgrounds(Window *this)
{
  dword_28 = Preferences::bottomBackgroundImage;
  dword_50 = Preferences::topBackgroundImage;
}
// 28: using guessed type int dword_28;
// 50: using guessed type int dword_50;

//----- (000002FC) --------------------------------------------------------
int GLOBAL__sub_I__ZN18CTRPluginFramework6Window12BottomWindowE()
{
  Window::Window(&Window::BottomWindow, 20, 20, 280, 200, 1, 0);
  _aeabi_atexit(&Window::BottomWindow, Window::~Window, &_dso_handle);
  Window::TopWindow = 85899345950LL;
  unk_3C = 94489280544LL;
  unk_44 = 841813590352LL;
  dword_34 = 340;
  dword_38 = 200;
  dword_50 = 0;
  dword_4C = 0;
  return _aeabi_atexit(&Window::TopWindow, Window::~Window, &_dso_handle);
}
// 34: using guessed type int dword_34;
// 38: using guessed type int dword_38;
// 4C: using guessed type int dword_4C;
// 50: using guessed type int dword_50;
// 3DC: using guessed type int  _aeabi_atexit(_DWORD, _DWORD, _DWORD);

// ALL OK, 10 function(s) have been successfully decompiled
}