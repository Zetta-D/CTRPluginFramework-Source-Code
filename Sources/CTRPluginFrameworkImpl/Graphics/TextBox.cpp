/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int CTRPluginFramework::Drawable::operator()();
int __fastcall CTRPluginFramework::TextBox::Draw(int result);
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::~TextBox(CTRPluginFramework::TextBox *this);
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::~TextBox(CTRPluginFramework::TextBox *this);
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::TextBox(CTRPluginFramework::TextBox *this);
int __fastcall CTRPluginFramework::TextBox::Open(int result);
int __fastcall CTRPluginFramework::TextBox::Close(int result);
int __fastcall CTRPluginFramework::TextBox::IsOpen(CTRPluginFramework::TextBox *this);
int __fastcall CTRPluginFramework::TextBox::ProcessEvent(__int64 this, int a2);
int __fastcall CTRPluginFramework::TextBox::DrawConst(CTRPluginFramework::TextBox *this);
unsigned __int8 *__fastcall CTRPluginFramework::TextBox::_GetWordWidth(CTRPluginFramework::TextBox *this, unsigned __int8 *a2, float *a3);
unsigned __int8 *__fastcall CTRPluginFramework::CutWordWidth(CTRPluginFramework *this, unsigned __int8 *a2, float *a3, float a4, int a5, unsigned __int8 *a6);
unsigned int __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::_M_check_len(_DWORD *a1, unsigned int a2, const char *a3);
char *__fastcall std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(void *src, _BYTE *a2, char *a3);
void __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back(void **a1, _DWORD *a2);
void __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::emplace_back<unsigned char *>(void **a1, _DWORD *a2);
void __fastcall CTRPluginFramework::TextBox::_GetTextInfos(CTRPluginFramework::TextBox *this);
_DWORD *__fastcall CTRPluginFramework::TextBox::TextBox(_DWORD *a1, int a2, int a3, _DWORD *a4);
int __fastcall CTRPluginFramework::TextBox::Update(int a1, int a2, int a3);
// _DWORD CTRPluginFramework::BMPImage::GetDimensions(CTRPluginFramework::BMPImage *__hidden this); idb
// int __fastcall CTRPluginFramework::BMPImage::Draw(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawLine(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawRect2(_DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// void __cdecl operator delete(void *); idb
// _DWORD CTRPluginFramework::Clock::Clock(CTRPluginFramework::Clock *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Milliseconds(CTRPluginFramework *__hidden this, int); idb
// _DWORD __cdecl CTRPluginFramework::Clock::HasTimePassed(CTRPluginFramework::Clock *__hidden this, Time); idb
// _DWORD CTRPluginFramework::Clock::Restart(CTRPluginFramework::Clock *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Font::GetGlyph(CTRPluginFramework::Font *__hidden this, unsigned __int8 **); idb
// _DWORD CTRPluginFramework::Glyph::Width(CTRPluginFramework::Glyph *__hidden this); idb
// void __cdecl __noreturn std::__throw_length_error(const char *); idb
// void *memmove(void *dest, const void *src, size_t n);
// void __noreturn std::__throw_bad_alloc(void); idb
// _DWORD __cdecl operator new(unsigned int); idb
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

_DWORD (__fastcall *off_D9C[2])(CTRPluginFramework::TextBox *__hidden this) =
{
  &CTRPluginFramework::TextBox::~TextBox,
  &CTRPluginFramework::TextBox::~TextBox
}; // weak
// extern _UNKNOWN CTRPluginFramework::Preferences::topBackgroundImage; weak
// extern _DWORD CTRPluginFramework::Preferences::Settings[6]; idb
// extern _UNKNOWN CTRPluginFramework::Color::White; weak
// extern _UNKNOWN CTRPluginFramework::RendererPriv::g_customColor; weak
// extern _UNKNOWN CTRPluginFramework::Color::Silver; weak
// extern _UNKNOWN CTRPluginFramework::Color::DimGrey; weak


//----- (00000004) --------------------------------------------------------
int CTRPluginFramework::Drawable::operator()()
{
  return 0;
}

//----- (00000010) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::Draw(int result)
{
  unsigned int v1; // r3
  int v2; // r3
  int v3; // r7
  int v4; // r4
  _DWORD *v5; // r0
  int v6; // r3
  int v7; // r5
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r9
  int v14; // r12
  int v15; // ST04_4
  int v16; // r0
  int v17; // r1
  int v18; // r5
  int v19; // r7
  int v20; // r6
  int v21; // r5
  unsigned int v22; // r1
  int v23; // r3
  int v24; // [sp+Ch] [bp-2Ch]

  v1 = (*(_DWORD *)(result + 8) - *(_DWORD *)(result + 4)) >> 2;
  if ( *(_DWORD *)(result + 80) >= v1 )
    *(_DWORD *)(result + 80) = 0;
  v2 = v1 - 1;
  v3 = *(_DWORD *)(result + 80) + *(_DWORD *)(result + 84);
  if ( v3 >= v2 )
    v3 = v2;
  v4 = result;
  if ( *(_BYTE *)(result + 78) )
  {
    if ( CTRPluginFramework::Preferences::topBackgroundImage
      && (v5 = (_DWORD *)CTRPluginFramework::BMPImage::GetDimensions(CTRPluginFramework::Preferences::topBackgroundImage),
          *v5 <= *(_DWORD *)(v4 + 52))
      && v5[1] <= *(_DWORD *)(v4 + 56) )
    {
      result = CTRPluginFramework::BMPImage::Draw(CTRPluginFramework::Preferences::topBackgroundImage, v4 + 44);
    }
    else
    {
      CTRPluginFramework::Renderer::DrawRect2(v4 + 44, &CTRPluginFramework::Preferences::Settings[8]);
      result = CTRPluginFramework::Renderer::DrawRect(v4 + 60, &CTRPluginFramework::Preferences::Settings[10], 0);
    }
  }
  v6 = *(_DWORD *)(v4 + 48);
  v7 = *(_DWORD *)(v4 + 44);
  v24 = v6 + 5;
  v8 = v7 + 5;
  v9 = v8 + *(_DWORD *)(v4 + 52) - 10;
  if ( *(_DWORD *)(v4 + 20) )
  {
    v11 = CTRPluginFramework::Renderer::DrawSysString(
            *(_DWORD *)(v4 + 16),
            v8,
            &v24,
            v9,
            CTRPluginFramework::Preferences::Settings[5],
            0);
    v12 = v11 - v8 + 30;
    if ( v11 + 30 > v9 )
      v12 = v9 - v8;
    result = CTRPluginFramework::Renderer::DrawLine(v8, v24, v12, &CTRPluginFramework::Color::White, 1);
    v10 = v24 + 7;
  }
  else
  {
    v10 = v6 + 10;
  }
  v24 = v10;
  v13 = *(_DWORD *)(v4 + 80);
  CTRPluginFramework::RendererPriv::g_customColor = CTRPluginFramework::Preferences::Settings[4];
  while ( v13 < v3 )
  {
    v14 = *(_DWORD *)(v4 + 4);
    v15 = *(_DWORD *)(v14 + 4 * v13 + 4);
    v16 = *(_DWORD *)(v14 + 4 * v13++);
    result = CTRPluginFramework::Renderer::DrawSysString(
               v16,
               v8,
               &v24,
               v9,
               CTRPluginFramework::RendererPriv::g_customColor,
               v15);
  }
  if ( *(_BYTE *)(v4 + 77) )
  {
    v17 = *(_DWORD *)(v4 + 48);
    v18 = *(_DWORD *)(v4 + 44) + *(_DWORD *)(v4 + 52);
    v24 = v17 + 5;
    v19 = v18 - 8;
    CTRPluginFramework::Renderer::DrawLine(
      v18 - 8,
      v17 + 6,
      1,
      &CTRPluginFramework::Color::Silver,
      *(_DWORD *)(v4 + 88) - 2);
    v20 = v18 - 7;
    CTRPluginFramework::Renderer::DrawLine(v18 - 7, v24, 1, &CTRPluginFramework::Color::Silver, *(_DWORD *)(v4 + 88));
    v21 = v18 - 6;
    CTRPluginFramework::Renderer::DrawLine(
      v21,
      v24 + 1,
      1,
      &CTRPluginFramework::Color::Silver,
      *(_DWORD *)(v4 + 88) - 2);
    v22 = (signed int)*(float *)(v4 + 104) + v24;
    if ( v22 >= *(_DWORD *)(v4 + 96) )
      v22 = *(_DWORD *)(v4 + 96);
    v23 = *(_DWORD *)(v4 + 92);
    v24 = v22;
    CTRPluginFramework::Renderer::DrawLine(v19, v22 + 1, 1, &CTRPluginFramework::Color::DimGrey, v23 - 2);
    CTRPluginFramework::Renderer::DrawLine(v20, v24, 1, &CTRPluginFramework::Color::DimGrey, *(_DWORD *)(v4 + 92));
    result = CTRPluginFramework::Renderer::DrawLine(
               v21,
               v24 + 1,
               1,
               &CTRPluginFramework::Color::DimGrey,
               *(_DWORD *)(v4 + 92) - 2);
  }
  return result;
}
// DD0: using guessed type int __fastcall CTRPluginFramework::BMPImage::Draw(_DWORD, _DWORD);
// DD4: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawSysString(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// DD8: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawLine(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// DDC: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect2(_DWORD, _DWORD);
// DE0: using guessed type int __fastcall CTRPluginFramework::Renderer::DrawRect(_DWORD, _DWORD, _DWORD);
// DFC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (00000300) --------------------------------------------------------
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::~TextBox(CTRPluginFramework::TextBox *this)
{
  CTRPluginFramework::TextBox *v1; // r4
  void *v2; // r0

  v1 = this;
  *(_DWORD *)this = off_D9C;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose((char *)this + 16);
  v2 = (void *)*((_DWORD *)v1 + 1);
  if ( v2 )
    operator delete(v2);
  return v1;
}
// D9C: using guessed type _DWORD (__fastcall *off_D9C[2])(CTRPluginFramework::TextBox *__hidden this);
// DFC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (00000330) --------------------------------------------------------
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::~TextBox(CTRPluginFramework::TextBox *this)
{
  CTRPluginFramework::TextBox *v1; // r4

  v1 = this;
  CTRPluginFramework::TextBox::~TextBox(this);
  operator delete((void *)v1);
  return v1;
}

//----- (0000034C) --------------------------------------------------------
CTRPluginFramework::TextBox *__fastcall CTRPluginFramework::TextBox::TextBox(CTRPluginFramework::TextBox *this)
{
  CTRPluginFramework::TextBox *v1; // r4
  CTRPluginFramework::TextBox *result; // r0

  *(_DWORD *)this = off_D9C;
  *((_QWORD *)this + 2) = (unsigned int)this + 24;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_BYTE *)this + 24) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_WORD *)this + 38) = 0;
  *((_BYTE *)this + 79) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  v1 = this;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  CTRPluginFramework::Clock::Clock((CTRPluginFramework::TextBox *)((char *)this + 112));
  result = v1;
  *((_BYTE *)v1 + 78) = 1;
  return result;
}
// D9C: using guessed type _DWORD (__fastcall *off_D9C[2])(CTRPluginFramework::TextBox *__hidden this);

//----- (000003E0) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::Open(int result)
{
  *(_BYTE *)(result + 76) = 1;
  return result;
}

//----- (000003EC) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::Close(int result)
{
  *(_BYTE *)(result + 76) = 0;
  return result;
}

//----- (000003F8) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::IsOpen(CTRPluginFramework::TextBox *this)
{
  return *((unsigned __int8 *)this + 76);
}

//----- (00000400) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::ProcessEvent(__int64 this, int a2)
{
  int v2; // r5
  signed int v3; // r3
  int v4; // r4
  bool v5; // zf
  Time v6; // r1
  int v7; // r7
  unsigned int v8; // r3
  float v9; // s15
  float v10; // s14
  float v11; // s15
  Time v13; // r1
  int v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  CTRPluginFramework::Clock *v18; // r6
  Time v19; // r1
  unsigned int v20; // r3
  float v21; // s14
  float v22; // s15
  CTRPluginFramework::Clock *v23; // r6
  Time v24; // r1
  unsigned int v25; // r3
  float v26; // s15
  __int64 v27; // [sp+0h] [bp-20h]
  int v28; // [sp+8h] [bp-18h]

  v27 = this;
  v28 = a2;
  v2 = *(unsigned __int8 *)(this + 76);
  if ( !*(_BYTE *)(this + 76) || *(_BYTE *)HIDWORD(this) != 1 )
    return v2;
  v3 = *(_DWORD *)(HIDWORD(this) + 4);
  v4 = this;
  if ( v3 == 64 )
    goto LABEL_23;
  if ( v3 > 64 )
  {
    if ( v3 == 0x4000000 )
    {
      v18 = (CTRPluginFramework::Clock *)(this + 112);
      CTRPluginFramework::Milliseconds((CTRPluginFramework *)&v27, 100);
      v7 = CTRPluginFramework::Clock::HasTimePassed(v18, v19);
      if ( !v7 )
        return v2;
      v20 = *(_DWORD *)(v4 + 80);
      if ( v20 <= 1 )
        goto LABEL_27;
      v21 = *(float *)(v4 + 104);
      v22 = *(float *)(v4 + 100) + *(float *)(v4 + 100);
      *(_DWORD *)(v4 + 80) = v20 - 2;
      v11 = v21 - v22;
      goto LABEL_26;
    }
    if ( v3 <= 0x4000000 )
    {
      v5 = v3 == 128;
      goto LABEL_9;
    }
    if ( v3 == 0x8000000 )
    {
      v23 = (CTRPluginFramework::Clock *)(this + 112);
      CTRPluginFramework::Milliseconds((CTRPluginFramework *)&v27, 100);
      v7 = CTRPluginFramework::Clock::HasTimePassed(v23, v24);
      if ( !v7 )
        return v2;
      v25 = *(_DWORD *)(v4 + 80);
      if ( v25 >= ((*(_DWORD *)(v4 + 8) - *(_DWORD *)(v4 + 4)) >> 2) - *(_DWORD *)(v4 + 84) )
        goto LABEL_27;
      v26 = *(float *)(v4 + 100);
      *(_DWORD *)(v4 + 80) = v25 + 2;
      v9 = v26 + v26;
      v10 = *(float *)(v4 + 104);
      goto LABEL_14;
    }
    if ( v3 != 0x40000000 )
      return v2;
LABEL_23:
    CTRPluginFramework::Milliseconds((CTRPluginFramework *)&v27, 100);
    v7 = CTRPluginFramework::Clock::HasTimePassed((CTRPluginFramework::Clock *)(v4 + 112), v13);
    if ( !v7 )
      return v2;
    v14 = *(_DWORD *)(v4 + 80);
    if ( v14 )
    {
      v11 = *(float *)(v4 + 104) - *(float *)(v4 + 100);
      *(_DWORD *)(v4 + 80) = v14 - 1;
      goto LABEL_26;
    }
    goto LABEL_27;
  }
  if ( v3 == 2 )
  {
    v2 = 0;
    *(_BYTE *)(this + 76) = 0;
    return v2;
  }
  if ( v3 > 2 )
  {
    if ( v3 == 16 )
    {
      v16 = *(unsigned __int8 *)(this + 79);
      if ( *(_BYTE *)(this + 79) )
      {
        HIDWORD(this) = *(_DWORD *)(this + 8) - *(_DWORD *)(this + 4);
        v17 = ((SHIDWORD(this) >> 2) - *(_DWORD *)(this + 84)) & ~(((SHIDWORD(this) >> 2) - *(_DWORD *)(this + 84)) >> 31);
        *(float *)(this + 104) = (float)(unsigned int)((SHIDWORD(this) >> 2) - *(_DWORD *)(this + 84))
                               * *(float *)(this + 100);
        *(_DWORD *)(this + 80) = v17;
        v2 = v16;
      }
    }
    else if ( v3 == 32 )
    {
      v15 = *(unsigned __int8 *)(this + 79);
      if ( *(_BYTE *)(this + 79) )
      {
        *(_DWORD *)(this + 104) = 0;
        v2 = v15;
        *(_DWORD *)(this + 80) = 0;
      }
    }
    return v2;
  }
  v5 = v3 == 2147483648;
LABEL_9:
  if ( v5 )
  {
    CTRPluginFramework::Milliseconds((CTRPluginFramework *)&v27, 100);
    v7 = CTRPluginFramework::Clock::HasTimePassed((CTRPluginFramework::Clock *)(v4 + 112), v6);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v4 + 80);
      if ( v8 < ((*(_DWORD *)(v4 + 8) - *(_DWORD *)(v4 + 4)) >> 2) - *(_DWORD *)(v4 + 84) )
      {
        v9 = *(float *)(v4 + 104);
        v10 = *(float *)(v4 + 100);
        *(_DWORD *)(v4 + 80) = v8 + 1;
LABEL_14:
        v11 = v10 + v9;
LABEL_26:
        *(float *)(v4 + 104) = v11;
      }
LABEL_27:
      CTRPluginFramework::Clock::Restart((CTRPluginFramework::Clock *)&v27);
      return v7;
    }
  }
  return v2;
}

//----- (00000648) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::DrawConst(CTRPluginFramework::TextBox *this)
{
  return (*(int (**)(void))(*(_DWORD *)this + 8))();
}

//----- (00000654) --------------------------------------------------------
unsigned __int8 *__fastcall CTRPluginFramework::TextBox::_GetWordWidth(CTRPluginFramework::TextBox *this, unsigned __int8 *a2, float *a3)
{
  float v3; // s0
  float *v5; // r4
  int v6; // r5
  unsigned __int8 *v7; // r3
  CTRPluginFramework::Glyph *v8; // r0
  unsigned __int8 *v9; // [sp+4h] [bp-14h]
  float *v10; // [sp+8h] [bp-10h]

  v10 = a3;
  v9 = a2;
  *a3 = 0.0;
  if ( !a2 || !*a2 )
    return 0;
  v5 = a3;
  while ( 1 )
  {
    v6 = *v9;
    switch ( v6 )
    {
      case 10:
        return v9;
      case 24:
        v7 = v9 + 1;
        goto LABEL_12;
      case 27:
        v7 = v9 + 4;
LABEL_12:
        v9 = v7;
        break;
      default:
        v8 = (CTRPluginFramework::Glyph *)CTRPluginFramework::Font::GetGlyph(
                                            (CTRPluginFramework::Font *)&v9,
                                            (unsigned __int8 **)a2);
        if ( !v8 )
          return 0;
        CTRPluginFramework::Glyph::Width(v8);
        v3 = *v5 + v3;
        *v5 = v3;
        if ( v6 == 32 )
          return v9;
        break;
    }
  }
}

//----- (000006EC) --------------------------------------------------------
unsigned __int8 *__fastcall CTRPluginFramework::CutWordWidth(CTRPluginFramework *this, unsigned __int8 *a2, float *a3, float a4, int a5, unsigned __int8 *a6)
{
  float v6; // s0
  unsigned __int8 *v8; // r5
  unsigned __int8 *v9; // r4
  int v10; // r6
  unsigned __int8 *v11; // r4
  CTRPluginFramework::Glyph *v12; // r0
  float v13; // s15

  *(_DWORD *)a2 = 0;
  if ( !this || !*(_BYTE *)this )
    return 0;
  v8 = a2;
  while ( 1 )
  {
    v9 = a6;
    v10 = *a6;
    switch ( v10 )
    {
      case 10:
        return a6;
      case 24:
        v11 = a6 + 1;
        goto LABEL_11;
      case 27:
        v11 = a6 + 4;
LABEL_11:
        a6 = v11;
        break;
      default:
        v12 = (CTRPluginFramework::Glyph *)CTRPluginFramework::Font::GetGlyph(
                                             (CTRPluginFramework::Font *)&a6,
                                             (unsigned __int8 **)a2);
        if ( !v12 )
          return 0;
        CTRPluginFramework::Glyph::Width(v12);
        v13 = v6 + *(float *)v8;
        *(float *)v8 = v13;
        if ( v10 == 32 )
          return a6;
        if ( v13 > v6 )
          return v9;
        break;
    }
  }
}

//----- (000007A0) --------------------------------------------------------
unsigned int __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::_M_check_len(_DWORD *a1, unsigned int a2, const char *a3)
{
  unsigned int v3; // r3
  int v4; // r0
  unsigned __int8 v5; // cf
  unsigned int result; // r0
  signed int v7; // r2

  v3 = (a1[1] - *a1) >> 2;
  if ( 0x3FFFFFFF - v3 < a2 )
    std::__throw_length_error(a3);
  if ( a2 >= v3 )
    v4 = a2;
  else
    v4 = (a1[1] - *a1) >> 2;
  v5 = __CFADD__(v3, v4);
  result = v3 + v4;
  if ( v5 )
    v7 = 1;
  else
    v7 = 0;
  if ( v7 | (result > 0x3FFFFFFF) )
    result = 0x3FFFFFFF;
  return result;
}

//----- (000007F8) --------------------------------------------------------
char *__fastcall std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(void *src, _BYTE *a2, char *a3)
{
  char *v3; // r3
  size_t v4; // r4

  v3 = a3;
  v4 = a2 - (_BYTE *)src;
  if ( a2 != src )
    v3 = (char *)memmove(a3, src, v4);
  return &v3[v4];
}

//----- (00000828) --------------------------------------------------------
void __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back(void **a1, _DWORD *a2)
{
  __int64 v2; // r4
  void **v3; // r6
  _DWORD *v4; // r9
  unsigned int v5; // r0
  void *v6; // r7
  int v7; // r10
  int v8; // r8
  char *v9; // r0

  HIDWORD(v2) = a1[1];
  v3 = a1;
  if ( (void *)HIDWORD(v2) == a1[2] )
  {
    v4 = a2;
    v5 = std::vector<unsigned char *,std::allocator<unsigned char *>>::_M_check_len(a1, 1u, "vector::_M_realloc_insert");
    v6 = *v3;
    LODWORD(v2) = v5;
    v7 = HIDWORD(v2) - (_DWORD)*v3;
    v8 = 4 * v5;
    if ( v5 )
    {
      if ( v5 > 0x3FFFFFFF )
        std::__throw_bad_alloc();
      LODWORD(v2) = operator new(4 * v5);
    }
    *(_DWORD *)(v2 + v7) = *v4;
    v9 = std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(
           v6,
           (_BYTE *)HIDWORD(v2),
           (char *)v2);
    HIDWORD(v2) = std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(
                    (void *)HIDWORD(v2),
                    (_BYTE *)HIDWORD(v2),
                    v9 + 4);
    if ( v6 )
      operator delete(v6);
    *(_QWORD *)v3 = v2;
    v3[2] = (void *)(v2 + v8);
  }
  else
  {
    *(_DWORD *)HIDWORD(v2) = *a2;
    a1[1] = (char *)a1[1] + 4;
  }
}

//----- (000008E4) --------------------------------------------------------
void __fastcall std::vector<unsigned char *,std::allocator<unsigned char *>>::emplace_back<unsigned char *>(void **a1, _DWORD *a2)
{
  __int64 v2; // r4
  void **v3; // r6
  _DWORD *v4; // r9
  unsigned int v5; // r0
  void *v6; // r7
  int v7; // r10
  int v8; // r8
  char *v9; // r0

  HIDWORD(v2) = a1[1];
  v3 = a1;
  if ( (void *)HIDWORD(v2) == a1[2] )
  {
    v4 = a2;
    v5 = std::vector<unsigned char *,std::allocator<unsigned char *>>::_M_check_len(a1, 1u, "vector::_M_realloc_insert");
    v6 = *v3;
    LODWORD(v2) = v5;
    v7 = HIDWORD(v2) - (_DWORD)*v3;
    v8 = 4 * v5;
    if ( v5 )
    {
      if ( v5 > 0x3FFFFFFF )
        std::__throw_bad_alloc();
      LODWORD(v2) = operator new(4 * v5);
    }
    *(_DWORD *)(v2 + v7) = *v4;
    v9 = std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(
           v6,
           (_BYTE *)HIDWORD(v2),
           (char *)v2);
    HIDWORD(v2) = std::__copy_move<true,true,std::random_access_iterator_tag>::__copy_m<unsigned char *>(
                    (void *)HIDWORD(v2),
                    (_BYTE *)HIDWORD(v2),
                    v9 + 4);
    if ( v6 )
      operator delete(v6);
    *(_QWORD *)v3 = v2;
    v3[2] = (void *)(v2 + v8);
  }
  else
  {
    *(_DWORD *)HIDWORD(v2) = *a2;
    a1[1] = (char *)a1[1] + 4;
  }
}

//----- (000009A0) --------------------------------------------------------
void __fastcall CTRPluginFramework::TextBox::_GetTextInfos(CTRPluginFramework::TextBox *this)
{
  float v1; // s16
  int v2; // r3
  void **v3; // r5
  CTRPluginFramework::TextBox *v4; // r4
  float v5; // s16
  CTRPluginFramework *i; // r3
  float v7; // s17
  CTRPluginFramework *v8; // r1
  _BOOL4 v9; // r3
  unsigned __int8 *v10; // r0
  float *v11; // r2
  float v12; // r3
  __int64 v13; // r2
  CTRPluginFramework *v14; // [sp+0h] [bp-20h]
  float v15; // [sp+4h] [bp-1Ch]

  v1 = (float)*((signed int *)this + 17);
  v2 = *((_DWORD *)this + 1);
  if ( v2 != *((_DWORD *)this + 2) )
    *((_DWORD *)this + 2) = v2;
  v3 = (void **)((char *)this + 4);
  v4 = this;
  v14 = (CTRPluginFramework *)**((_DWORD **)this + 10);
  v5 = v1 - 12.0;
  std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back((void **)this + 1, &v14);
  if ( *(unsigned __int8 *)v14 != 239 || *((unsigned __int8 *)v14 + 1) != 187 || *((unsigned __int8 *)v14 + 2) != 191 )
    goto LABEL_8;
  for ( i = (CTRPluginFramework *)((char *)v14 + 3); ; i = (CTRPluginFramework *)((char *)v14 + 1) )
  {
    v14 = i;
LABEL_8:
    if ( *(_BYTE *)v14 != 10 )
      break;
    std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back(v3, &v14);
  }
LABEL_10:
  if ( v14 && *(_BYTE *)v14 )
  {
    v7 = 0.0;
    if ( *(_BYTE *)v14 == 10 )
      v14 = (CTRPluginFramework *)((char *)v14 + 1);
    v8 = v14;
    while ( 1 )
    {
      v9 = v7 >= v5;
      if ( !v8 )
        v9 = 1;
      if ( v9 )
        goto LABEL_20;
      v14 = v8;
      v10 = CTRPluginFramework::TextBox::_GetWordWidth(v4, (unsigned __int8 *)v8, &v15);
      v8 = (CTRPluginFramework *)v10;
      if ( v15 > v5 )
      {
        v14 = (CTRPluginFramework *)CTRPluginFramework::CutWordWidth(
                                      v14,
                                      (unsigned __int8 *)&v15,
                                      v11,
                                      v12,
                                      (int)v14,
                                      (unsigned __int8 *)LODWORD(v15));
LABEL_20:
        std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back(v3, &v14);
        goto LABEL_10;
      }
      v7 = v7 + v15;
      if ( !v10 )
        break;
      if ( *v10 == 10 && v5 > v7 || v5 <= v7 )
        goto LABEL_20;
    }
    if ( v5 <= v7 )
      std::vector<unsigned char *,std::allocator<unsigned char *>>::push_back(v3, &v14);
  }
  v13 = *(_QWORD *)((char *)v4 + 4);
  if ( HIDWORD(v13) != (_DWORD)v13 )
  {
    if ( *(_DWORD *)(HIDWORD(v13) - 4) )
    {
      v15 = 0.0;
      std::vector<unsigned char *,std::allocator<unsigned char *>>::emplace_back<unsigned char *>(v3, &v15);
    }
  }
}

//----- (00000B68) --------------------------------------------------------
_DWORD *__fastcall CTRPluginFramework::TextBox::TextBox(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r4
  int v5; // r7
  _DWORD *v6; // r5
  _DWORD *v7; // r12
  int v8; // r1
  int v9; // r2
  int v10; // r3
  __int64 v11; // r0
  __int64 v12; // r2
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r3
  int v16; // r1
  float v17; // s13
  signed int v18; // r3
  int v19; // r2
  _DWORD *result; // r0

  v4 = a1;
  v5 = a3;
  v6 = a4;
  a1[1] = 0;
  *a1 = off_D9C;
  a1[2] = 0;
  a1[3] = 0;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(a1 + 4);
  v4[10] = v5;
  v7 = v4 + 11;
  v8 = v6[1];
  v9 = v6[2];
  v10 = v6[3];
  *v7 = *v6;
  v7[1] = v8;
  v7[2] = v9;
  v7[3] = v10;
  HIDWORD(v11) = v6[1] + 2;
  LODWORD(v12) = v6[2] - 4;
  HIDWORD(v12) = v6[3] - 4;
  LODWORD(v11) = *v6 + 2;
  *(_QWORD *)(v4 + 15) = v11;
  *(_QWORD *)(v4 + 17) = v12;
  CTRPluginFramework::Clock::Clock((CTRPluginFramework::Clock *)(v4 + 28));
  v4[20] = 0;
  *((_BYTE *)v4 + 76) = 0;
  v13 = v6[3];
  v14 = v13 - 10;
  if ( v13 - 10 < 0 )
    v14 = v13 + 5;
  v4[21] = (v14 >> 4) - 1;
  CTRPluginFramework::TextBox::_GetTextInfos((CTRPluginFramework::TextBox *)v4);
  v15 = (v4[2] - v4[1]) >> 2;
  if ( v4[21] < v15 )
  {
    v16 = v4[14] - 10;
    v17 = (float)v16 / (float)(signed int)(16 * (v15 + 1));
    v18 = (signed int)(float)((float)v16 * v17);
    if ( v18 < 5 )
      v18 = 5;
    v19 = v4[12];
    v4[23] = v18;
    v4[24] = v19 + 5 + v16 - v18;
    v4[26] = 0;
    *((float *)v4 + 25) = v17 * 16.0;
    v4[22] = v16;
    *((_BYTE *)v4 + 77) = 1;
  }
  else
  {
    v4[21] = v15;
    *((_BYTE *)v4 + 77) = 0;
  }
  result = v4;
  *((_WORD *)v4 + 39) = 257;
  return result;
}
// D9C: using guessed type _DWORD (__fastcall *off_D9C[2])(CTRPluginFramework::TextBox *__hidden this);
// E2C: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD);

//----- (00000CAC) --------------------------------------------------------
int __fastcall CTRPluginFramework::TextBox::Update(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int result; // r0
  int v10; // r3
  char v11; // r3
  float v12; // s15
  float v13; // s13
  signed int v14; // r3
  int v15; // r2

  v3 = a1;
  v4 = a3;
  v5 = a2;
  *(_DWORD *)(a1 + 80) = 0;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(a1 + 16);
  v6 = *(_DWORD *)(v3 + 56);
  *(_DWORD *)(v3 + 40) = v4;
  v7 = v6 - 10;
  if ( v6 - 10 < 0 )
    v7 = v6 + 5;
  v8 = v7 >> 4;
  *(_DWORD *)(v3 + 84) = v8;
  if ( *(_DWORD *)(v5 + 4) )
    *(_DWORD *)(v3 + 84) = v8 - 1;
  CTRPluginFramework::TextBox::_GetTextInfos((CTRPluginFramework::TextBox *)v3);
  v10 = (*(_DWORD *)(v3 + 8) - *(_DWORD *)(v3 + 4)) >> 2;
  if ( (unsigned int)(v10 - 1) > *(_DWORD *)(v3 + 84) )
  {
    result = *(_DWORD *)(v3 + 56) - 10;
    v12 = (float)result;
    v13 = v12 / (float)(16 * (v10 - 1));
    v14 = (signed int)(float)(v12 * v13);
    if ( v14 < 5 )
      v14 = 5;
    *(_DWORD *)(v3 + 104) = 0;
    v15 = *(_DWORD *)(v3 + 48);
    *(_DWORD *)(v3 + 92) = v14;
    *(_DWORD *)(v3 + 96) = v15 + 5 + result - v14;
    *(float *)(v3 + 100) = v13 * 16.0;
    v11 = 1;
    *(_DWORD *)(v3 + 88) = result;
  }
  else
  {
    *(_DWORD *)(v3 + 84) = v10;
    v11 = 0;
  }
  *(_BYTE *)(v3 + 77) = v11;
  return result;
}
// E30: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD);

// ALL OK, 19 function(s) have been successfully decompiled