#include "CTRPluginFrameworkImpl/Graphics/Button.hpp"
/*

private:

  u8 flag[2]; // 0x40 & 0x41
  u16 flagDraw[3]; // 0x4 & 0x6
  u32 _unknow; // 0x28
  int _unknow2; // 0xB
  string text; // 0x10*/

namespace CTRPluginFramework
{

Button::Update(bool,Vector<int> const&)::halfSecond; // weak
_UNKNOWN Button::Update(bool,Vector<int> const&)::halfSecond; // weak
_DWORD (__fastcall *off_5B4[2])(Button *__hidden this) = { &Button::~Button, &Button::~Button };


//----- (00000018) --------------------------------------------------------
Button *__fastcall Button::~Button(Button *this)
{
  Button *v1; // r4

  v1 = this;
  *(_DWORD *)this = off_5B4;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose((char *)this + 16);
  return v1;
}
// 5B4: using guessed type _DWORD (__fastcall *off_5B4[2])(Button *__hidden this);
// 5C8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (00000038) --------------------------------------------------------
Button *__fastcall Button::~Button(Button *this)
{
  Button *v1; // r4

  v1 = this;
  Button::~Button(this);
  operator delete((void *)v1);
  return v1;
}

//----- (00000054) --------------------------------------------------------
int __fastcall Button::operator()(int a1)
{
  int v1; // r3
  char v2; // r2

  v1 = (*(_BYTE *)(a1 + 64) >> 4) & 1;
  if ( (*(_BYTE *)(a1 + 64) >> 4) & 1 )
  {
    if ( *(_BYTE *)(a1 + 64) & 0x20 )
    {
      v1 = 0;
    }
    else
    {
      if ( !(*(_BYTE *)(a1 + 64) & 2) )
        *(_BYTE *)(a1 + 64) &= 0xBFu;
      v2 = *(_BYTE *)(a1 + 65);
      v1 = v2 & 1;
      *(_BYTE *)(a1 + 65) = v2 & 0xFE;
    }
  }
  return v1;
}

//----- (00000094) --------------------------------------------------------
int __fastcall Button::Draw(int result, int a2, int a3, int a4)
{
  unsigned int v4; // r2
  int v5; // r5
  int (__fastcall *v6)(_DWORD, _DWORD, int); // r3
  void *v7; // r1
  int (__fastcall *v8)(int); // r3
  int v9; // r12
  int v10; // r0
  int v11; // [sp+0h] [bp-20h]
  int v12; // [sp+4h] [bp-1Ch]
  int v13; // [sp+8h] [bp-18h]
  int v14; // [sp+Ch] [bp-14h]

  v11 = result;
  v12 = a2;
  v13 = a3;
  v14 = a4;
  v4 = *(unsigned __int8 *)(result + 64);
  if ( v4 & 0x10 )
  {
    v5 = result;
    if ( v4 & 1 && (v6 = *(int (__fastcall **)(_DWORD, _DWORD, int))(result + 12)) != 0 )
    {
      result = v6(*(unsigned __int16 *)(result + 4), *(unsigned __int16 *)(result + 6), (v4 >> 6) & 1);
    }
    else
    {
      if ( v4 & 0x20 )
      {
        v7 = &Color::Gray;
      }
      else if ( v4 >> 7 )
      {
        v7 = &Color::DimGrey;
      }
      else if ( v4 & 2 )
      {
        v7 = &Color::Gainsboro;
        if ( v4 & 0x40 )
          v7 = &Color::LimeGreen;
      }
      else
      {
        v7 = &Color::Gainsboro;
      }
      if ( (v4 >> 3) & 1 )
      {
        Renderer::DrawRoundedRectangle(result + 40, &Color::DarkGrey, v7);
      }
      else
      {
        Renderer::DrawRect(result + 40, v7, 1);
        Renderer::DrawRect(v5 + 40, &Color::DarkGrey, 0);
      }
      v8 = *(int (__fastcall **)(int))(v5 + 12);
      v9 = *(unsigned __int16 *)(v5 + 4);
      v14 = *(unsigned __int16 *)(v5 + 6);
      if ( v8 )
        v9 = v8(v9) + 3;
      v10 = *(_DWORD *)(v5 + 16);
      if ( *(_BYTE *)(v5 + 64) & 4 )
        result = Renderer::DrawSysString(
                   v10,
                   v9,
                   &v14,
                   *(unsigned __int16 *)(v5 + 8),
                   Color::Black,
                   0,
                   v13,
                   v14);
      else
        result = Renderer::DrawString(
                   v10,
                   v9,
                   &v14,
                   Color::Black,
                   v11,
                   v12,
                   v13,
                   v14);
    }
  }
  return result;
}
// 5D0: using guessed type int __fastcall Renderer::DrawRoundedRectangle(_DWORD, _DWORD, _DWORD);
// 5D4: using guessed type int __fastcall Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 5D8: using guessed type int __fastcall Renderer::DrawRect(_DWORD, _DWORD, _DWORD);
// 5DC: using guessed type int __fastcall Renderer::DrawString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);

//----- (000001DC) --------------------------------------------------------
signed int __fastcall Button::Update(signed int result, Time a2, int a3)
{
  signed int v3; // r4
  Time v4; // r5
  int *v5; // r7
  int v6; // r3
  int v7; // r6
  signed int v8; // lr
  int v9; // r1
  int v10; // r2
  int v11; // r3
  _BOOL4 v12; // r12
  int v13; // r1
  bool v14; // nf
  unsigned __int8 v15; // vf
  bool v16; // r3
  int v17; // [sp+0h] [bp-20h]
  Time v18; // [sp+4h] [bp-1Ch]
  int v19; // [sp+8h] [bp-18h]

  v17 = result;
  v18 = a2;
  v19 = a3;
  v3 = result;
  v4 = a2;
  v5 = (int *)a3;
  __mcr(15, 0, result, 7, 10, 5);
  if ( !(`guard variable for'Button::Update(bool,Vector<int> const&)::halfSecond & 1) )
  {
    result = _cxa_guard_acquire(&`guard variable for'Button::Update(bool,Vector<int> const&)::halfSecond);
    if ( result )
    {
      Seconds(
        (CTRPluginFramework *)&Button::Update(bool,Vector<int> const&)::halfSecond,
        *(float *)&a2);
      result = _cxa_guard_release(&`guard variable for'Button::Update(bool,Vector<int> const&)::halfSecond);
    }
  }
  v6 = *(unsigned __int8 *)(v3 + 64);
  if ( v6 & 0x10 && !(v6 & 0x20) )
  {
    if ( v4 | ((v6 ^ 0x80u) >> 7) )
    {
      if ( !(v6 & 2)
        || (result = Clock::HasTimePassed((Clock *)(v3 + 56), a2)) != 0 )
      {
        v7 = *v5;
        v8 = v5[1];
        v9 = *(_DWORD *)(v3 + 40);
        v10 = *(_DWORD *)(v3 + 44);
        if ( v9 < v9 + *(_DWORD *)(v3 + 48) )
        {
          v11 = *(_DWORD *)(v3 + 40);
          v9 += *(_DWORD *)(v3 + 48);
        }
        else
        {
          v11 = v9 + *(_DWORD *)(v3 + 48);
        }
        v12 = v7 >= v11;
        if ( v7 >= v9 )
          v12 = 0;
        result = *(_DWORD *)(v3 + 52);
        if ( v12 )
        {
          v13 = v10 + result;
          v15 = __OFSUB__(v10, v10 + result);
          v14 = -result < 0;
          if ( v10 >= v10 + result )
            result += v10;
          else
            result = *(_DWORD *)(v3 + 44);
          if ( v14 ^ v15 )
            v10 = v13;
          v16 = v8 >= result;
          if ( v8 >= v10 )
            v16 = 0;
          LOBYTE(v12) = v16 & v4;
        }
        *(_BYTE *)(v3 + 64) = *(_BYTE *)(v3 + 64) & 0x7F | ((_BYTE)v12 << 7);
      }
    }
    else
    {
      *(_BYTE *)(v3 + 64) = *(_BYTE *)(v3 + 64) & 0xBF | (((*(_BYTE *)(v3 + 64) >> 6) & 1 ^ 1) << 6);
      *(_WORD *)(v3 + 64) = *(_WORD *)(v3 + 64) & 0xFE7F | 0x100;
      result = Clock::Restart((Clock *)&v17);
    }
  }
  return result;
}
// 8: using guessed type char `guard variable for'Button::Update(bool,Vector<int> const&)::halfSecond;
// 5F8: using guessed type int __fastcall _cxa_guard_acquire(_DWORD);
// 600: using guessed type int __fastcall _cxa_guard_release(_DWORD);

//----- (00000330) --------------------------------------------------------
_DWORD *__fastcall Button::Button(_DWORD *a1, unsigned int a2, Renderer **a3, _DWORD *a4, int a5)
{
  float v5; // s0
  _DWORD *v6; // r4
  _DWORD *v7; // r5
  unsigned int v8; // r8
  Renderer **v9; // r7
  int v10; // r1
  int v11; // r2
  int v12; // r3
  _DWORD *v13; // r12
  unsigned int v14; // r3
  char v16; // r3
  int v17; // r2
  int v18; // r1
  __int16 v19; // r2
  float v20; // s0

  v6 = a1;
  v7 = a4;
  v8 = a2;
  *a1 = off_5B4;
  a1[3] = a5;
  v9 = a3;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(a1 + 4, a3);
  v10 = v7[1];
  v11 = v7[2];
  v12 = v7[3];
  v13 = v6 + 10;
  *v13 = *v7;
  v13[1] = v10;
  v13[2] = v11;
  v13[3] = v12;
  Clock::Clock((Clock *)(v6 + 14));
  v14 = (v8 >> 2) & 8 | v8 & 2 | (unsigned int)&Button::Update(bool,Vector<int> const&)::halfSecond;
  v6[16] = &Button::Update(bool,Vector<int> const&)::halfSecond;
  *((_BYTE *)v6 + 64) = v14;
  if ( v8 & 8 )
  {
    *((_BYTE *)v6 + 64) = v14 | 1;
    *((_WORD *)v6 + 2) = *v7;
    *((_WORD *)v6 + 3) = v7[1];
  }
  else
  {
    v16 = *((_BYTE *)v6 + 64);
    if ( v8 & 0x10 )
    {
      *((_BYTE *)v6 + 64) = v16 | 4;
      Renderer::GetTextSize(
        *v9,
        (const char *)&Button::Update(bool,Vector<int> const&)::halfSecond);
      v17 = v6[13] - 16;
    }
    else
    {
      v20 = (float)(unsigned int)v6[5];
      *((_BYTE *)v6 + 64) = v16 & 0xFB;
      v5 = v20 * 6.0;
      v17 = v6[13] - 10;
    }
    if ( a5 )
      v5 = v5 + 18.0;
    v18 = v6[12];
    *((_WORD *)v6 + 3) = v6[11] + (v17 >> 1);
    v19 = *((_WORD *)v6 + 20);
    *((_WORD *)v6 + 2) = v19 + ((v18 - (signed int)v5) >> 1);
    *((_WORD *)v6 + 4) = v19 + v18;
  }
  return v6;
}
// 5B4: using guessed type _DWORD (__fastcall *off_5B4[2])(Button *__hidden this);
// 60C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

//----- (00000454) --------------------------------------------------------
_DWORD *__fastcall Button::Button(_DWORD *a1, unsigned int a2, Renderer **a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // r4

  v5 = a1;
  Button::Button(a1, a2, a3, a4, a5);
  return v5;
}

//----- (00000474) --------------------------------------------------------
int __fastcall Button::Button(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r5
  _DWORD *v6; // r12
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3

  *(_DWORD *)(a1 + 12) = a4;
  *(_DWORD *)(a1 + 16) = a1 + 24;
  v4 = a1;
  v5 = a3;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)a1 = off_5B4;
  *(_BYTE *)(a1 + 24) = 0;
  v6 = (_DWORD *)(a1 + 40);
  v7 = a2;
  v8 = *a3;
  v9 = a3[1];
  v10 = a3[2];
  v11 = v5[3];
  *v6 = v8;
  v6[1] = v9;
  v6[2] = v10;
  v6[3] = v11;
  Clock::Clock((Clock *)(v4 + 56));
  v12 = (v7 >> 2) & 8 | v7 & 2 | 0x10;
  *(_DWORD *)(v4 + 64) = 16;
  *(_BYTE *)(v4 + 64) = v12;
  if ( v7 & 8 )
  {
    *(_BYTE *)(v4 + 64) = v12 | 1;
    *(_WORD *)(v4 + 4) = *v5;
    *(_WORD *)(v4 + 6) = v5[1];
  }
  return v4;
}
// 5B4: using guessed type _DWORD (__fastcall *off_5B4[2])(Button *__hidden this);

//----- (00000508) --------------------------------------------------------
int __fastcall Button::Button(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  int v4; // r4

  v4 = a1;
  Button::Button(a1, a2, a3, a4);
  return v4;
}

  void  Button::Enable(bool f)
  {
    flag[0] = flag[0] & 0xEF | 0x10 * f;
  }

  void  Button::Enable(void)
  {
    flag[0] |= 0x10;
  }

  void  Button::Disable(void)
  {
    flag[0] &= 0xEF;
  }

  void  Button::Lock(void)
  {
    flag[0] |= 0x20;
  }

  void  Button::Unlock(void)
  {
    flag[0] &= 0xDF;
  }

  void  Button::Execute(void)
  {
    flag[1] |= 1;
  }

  void  Button::SetState(bool f)
  {
    flag[0] = flag[0] & 0xBF | (f << 6);
  }

  u8  Button::GetState(bool f)
  {
    return (flag[0] >> 6) & 1;
  }

  bool  Button::operator()(void)
  {
    bool res = (flag[0] >> 4) & 1;
    if(res)
    {
      if(flag[0] & 0x20)
        res = false;
      else
      {
        if(!(flag[0] & 2))
          flag[0] &= 0xBF;
        res = flag[1] & 1;
        flag[1] = flag[1] & 0xFE;
      }
    }
    return res;
  }

  void  Button::Draw(void)
  {
    Color color;
    if(flag[0] & 0x10)
    {
      Foo(flagDraw[0], flagDraw[1], (flag[0] >> 6) & 1)
    }
    else
    {
      if(flag[0] & 0x20)
        color = Color::Gray;
      else if (flag[0] >> 7)
        color = Color::DimGrey;
      else if (flag[0] & 2)
      {
        color = Color::Gainsboro;
        if (flag[0] & 0x40)
          color = Color::LimeGreen;
      }
      else
        color = Color::Gainsboro;

      if ((flag[0] >> 4) & 1)
        Renderer::DrawRoundedRectangle(_unknow, Color::DarkGrey, color);
      else
      {
        Renderer::DrawRect(_unknow, color, 1);
        Renderer::DrawRect(_unknow, Color::DarkGrey, 0);
        int v8 = Foo(_unknow2);
        u16 v9 = flagDraw[0];
        u16 v14 = flagDraw[1];
        if(v8)
          v9 = v8(v9) + 3;
        if(flag[0] & 4)
          Renderer::DrawSysString(text, v9, &v14, flagDraw[2], Color::Black, 0, v13, v14);
        else
          Renderer::DrawString(text, v9, &v14, Color::Black, v11, v12, v13, v14);
        // text X Y foreground  
      }
    }
  }
  //v12, v13, v14 = parameters
}