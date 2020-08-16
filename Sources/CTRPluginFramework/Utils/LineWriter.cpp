/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::LineWriter(CTRPluginFramework::LineWriter *this, CTRPluginFramework::File *a2);
int *__fastcall ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(unsigned int a1);
int __fastcall CTRPluginFramework::LineWriter::Flush(int result);
CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::~LineWriter(CTRPluginFramework::LineWriter *this);
CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::operator<<(CTRPluginFramework::LineWriter *this, int a2);
int __fastcall CTRPluginFramework::LineWriter::Close(CTRPluginFramework::LineWriter *this);
// _DWORD __cdecl CTRPluginFramework::Heap::Alloc(CTRPluginFramework::Heap *__hidden this, unsigned int); idb
// int __fastcall _cxa_guard_acquire(_DWORD); weak
// int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void); weak
// int __fastcall _cxa_guard_release(_DWORD); weak
// int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD); weak
// _DWORD CTRPluginFramework::File::IsOpen(CTRPluginFramework::File *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::File::Write(CTRPluginFramework::File *__hidden this, const void *, unsigned int); idb
// _DWORD CTRPluginFramework::File::Flush(CTRPluginFramework::File *__hidden this); idb
// _DWORD __cdecl CTRPluginFramework::Heap::Free(CTRPluginFramework::Heap *__hidden this, void *); idb
// _DWORD CTRPluginFramework::File::Close(CTRPluginFramework::File *__hidden this); idb

//-------------------------------------------------------------------------
// Data declarations

char ZGVZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end; // weak
int ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end; // weak
int dword_C; // weak
char algn_10[16]; // weak
// extern _UNKNOWN _dso_handle; weak
// extern _UNKNOWN std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string; weak


//----- (00000020) --------------------------------------------------------
CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::LineWriter(CTRPluginFramework::LineWriter *this, CTRPluginFramework::File *a2)
{
  CTRPluginFramework::LineWriter *v2; // r4

  v2 = this;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = CTRPluginFramework::Heap::Alloc((CTRPluginFramework::Heap *)0x1000, (unsigned int)a2);
  return v2;
}

//----- (00000048) --------------------------------------------------------
int *__fastcall ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(unsigned int a1)
{
  __mcr(15, 0, a1, 7, 10, 5);
  if ( !(ZGVZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end & 1)
    && _cxa_guard_acquire(&ZGVZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end) )
  {
    ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end = (int)algn_10;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
    dword_C = 2;
    *(_BYTE *)(ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end + 2) = 0;
    _cxa_guard_release(&ZGVZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end);
    _aeabi_atexit(
      &ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end,
      &std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::~basic_string,
      &_dso_handle);
  }
  return &ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end;
}
// 4: using guessed type char ZGVZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end;
// 8: using guessed type int ZZN18CTRPluginFramework10LineWriter4endlB5cxx11EvE3end;
// C: using guessed type int dword_C;
// 1B8: using guessed type int __fastcall _cxa_guard_acquire(_DWORD);
// 1BC: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void);
// 1C0: using guessed type int __fastcall _cxa_guard_release(_DWORD);
// 1C4: using guessed type int __fastcall _aeabi_atexit(_DWORD, _DWORD, _DWORD);

//----- (000000C8) --------------------------------------------------------
int __fastcall CTRPluginFramework::LineWriter::Flush(int result)
{
  int v1; // r4

  if ( *(_DWORD *)(result + 4) )
  {
    v1 = result;
    result = CTRPluginFramework::File::IsOpen(*(CTRPluginFramework::File **)result);
    if ( result )
    {
      CTRPluginFramework::File::Write(*(CTRPluginFramework::File **)v1, *(const void **)(v1 + 8), *(_DWORD *)(v1 + 4));
      result = CTRPluginFramework::File::Flush(*(CTRPluginFramework::File **)v1);
      *(_DWORD *)(v1 + 4) = 0;
    }
  }
  return result;
}

//----- (00000110) --------------------------------------------------------
CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::~LineWriter(CTRPluginFramework::LineWriter *this)
{
  CTRPluginFramework::LineWriter *v1; // r4
  void *v2; // r1

  v1 = this;
  CTRPluginFramework::LineWriter::Flush((int)this);
  CTRPluginFramework::Heap::Free(*((CTRPluginFramework::Heap **)v1 + 2), v2);
  return v1;
}

//----- (0000012C) --------------------------------------------------------
CTRPluginFramework::LineWriter *__fastcall CTRPluginFramework::LineWriter::operator<<(CTRPluginFramework::LineWriter *this, int a2)
{
  int v2; // r2
  CTRPluginFramework::LineWriter *v3; // r4
  char *v4; // r5
  _BYTE *v5; // r3
  int v6; // r6
  char v7; // r7
  char v8; // t1

  v2 = *(_DWORD *)(a2 + 4);
  v3 = this;
  if ( v2 )
  {
    v4 = *(char **)a2;
    v5 = (_BYTE *)(*((_DWORD *)this + 2) + *((_DWORD *)this + 1));
    v6 = *(_DWORD *)a2 + v2;
    while ( v4 != (char *)v6 )
    {
      v8 = *v4++;
      v7 = v8;
      if ( *((_DWORD *)v3 + 1) > 0xFFFu )
      {
        CTRPluginFramework::LineWriter::Flush((int)v3);
        v5 = (_BYTE *)*((_DWORD *)v3 + 2);
      }
      *v5++ = v7;
      ++*((_DWORD *)v3 + 1);
    }
  }
  return v3;
}

//----- (00000198) --------------------------------------------------------
int __fastcall CTRPluginFramework::LineWriter::Close(CTRPluginFramework::LineWriter *this)
{
  CTRPluginFramework::File **v1; // r4

  v1 = (CTRPluginFramework::File **)this;
  CTRPluginFramework::LineWriter::Flush((int)this);
  return CTRPluginFramework::File::Close(*v1);
}

// ALL OK, 6 function(s) have been successfully decompiled
