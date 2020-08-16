/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::RemoveFormat(int a1, unsigned __int8 **a2);
int *__fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(int *a1, const char *a2);
signed int __fastcall CTRPluginFramework::ActionReplay_WriteToFile(int a1, int a2);
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD); weak
// int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD); weak
// size_t strlen(const char *s);
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_create(_DWORD, _DWORD, _DWORD); weak
// int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(_DWORD, _DWORD, _DWORD); weak
// int __fastcall CTRPluginFramework::LineWriter::operator<<(_DWORD, _DWORD); weak
// int __fastcall ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(_DWORD); weak
// _DWORD CTRPluginFramework::MenuFolderImpl::ItemsCount(CTRPluginFramework::MenuFolderImpl *__hidden this); idb
// int __fastcall CTRPluginFramework::MenuFolderImpl::operator[](_DWORD, _DWORD); weak
// int __fastcall ZNK18CTRPluginFramework6ARCode8ToStringB5cxx11Ev(_DWORD, _DWORD); weak

//-------------------------------------------------------------------------
// Data declarations

_UNKNOWN unk_47C; // weak


//----- (00000004) --------------------------------------------------------
int __fastcall CTRPluginFramework::RemoveFormat(int a1, unsigned __int8 **a2)
{
  int v2; // r5
  unsigned __int8 **v3; // r6
  unsigned __int8 *i; // r4
  int v5; // r1
  char v7; // [sp+8h] [bp-38h]

  *(_DWORD *)a1 = a1 + 8;
  v2 = a1;
  v3 = a2;
  *(_DWORD *)(a1 + 4) = 0;
  *(_BYTE *)(a1 + 8) = 0;
  for ( i = *a2; i != &v3[1][(_DWORD)*v3]; ++i )
  {
    v5 = *i;
    if ( v5 == 10 )
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(v2, &unk_47C);
    }
    else if ( v5 == 27 )
    {
      ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(&v7, "~#%02X%02X%02X~", i[1], i[2], i[3]);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(v2, &v7);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v7);
      i += 3;
    }
    else
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v2);
    }
  }
  return v2;
}
// 4B0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD);
// 4B4: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...);
// 4B8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(_DWORD, _DWORD);
// 4BC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 4C0: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(_DWORD);

//----- (000000C8) --------------------------------------------------------
int *__fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(int *a1, const char *a2)
{
  int *v2; // r4
  const char *v3; // r5
  size_t v4; // r0
  int v5; // r6
  int v6; // r0
  int v7; // r3
  int *result; // r0
  int v9; // r3
  int v10; // r2
  int v11; // [sp+4h] [bp-14h]

  *a1 = (int)(a1 + 2);
  v2 = a1;
  v3 = a2;
  v4 = strlen(a2);
  v5 = (int)&v3[v4];
  v11 = v4;
  if ( v4 > 0xF )
  {
    v6 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_create(v2, &v11, 0);
    v7 = v11;
    *v2 = v6;
    v2[2] = v7;
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(*v2, v3, v5);
  result = v2;
  v9 = v11;
  v10 = *v2;
  v2[1] = v11;
  *(_BYTE *)(v10 + v9) = 0;
  return result;
}
// 4C8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_create(_DWORD, _DWORD, _DWORD);
// 4CC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(_DWORD, _DWORD, _DWORD);

//----- (00000140) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::ActionReplay_WriteToFile(int a1, int a2)
{
  int v2; // r4
  unsigned int v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r7
  int v8; // r0
  int v9; // r7
  int v10; // r0
  int v11; // r0
  int v12; // r7
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r4
  int v17; // r0
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v21; // r5
  int v22; // r5
  int v23; // r5
  int v24; // r0
  int v25; // r5
  int v26; // r8
  int v27; // r7
  int v28; // r0
  int v29; // r0
  unsigned int i; // r7
  __int64 v31; // r2
  int v32; // r0
  int v33; // r10
  int v34; // r0
  int v35; // r5
  int v36; // r4
  int v37; // r4
  int v38; // r0
  int v39; // r0
  int v40; // [sp+0h] [bp-68h]
  char v41; // [sp+18h] [bp-50h]
  char v42; // [sp+30h] [bp-38h]

  v2 = a2;
  if ( !a2 )
    return 0;
  v4 = *(unsigned __int8 *)(a2 + 57);
  v5 = a1;
  if ( *(_BYTE *)(a2 + 57) )
  {
    if ( !*(_DWORD *)(a2 + 8) )
      return 0;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v42, "[");
    v21 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
    CTRPluginFramework::RemoveFormat((int)&v41, (unsigned __int8 **)(v2 + 4));
    v22 = CTRPluginFramework::LineWriter::operator<<(v21, &v41);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v40, "]");
    v23 = CTRPluginFramework::LineWriter::operator<<(v22, &v40);
    v24 = ((int (*)(void))ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev)();
    CTRPluginFramework::LineWriter::operator<<(v23, v24);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v40);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v41);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
    v25 = *(_DWORD *)(v2 + 132);
    v26 = *(_DWORD *)(v2 + 136);
    if ( v25 == v26 )
      return 0;
    do
    {
      ZNK18CTRPluginFramework6ARCode8ToStringB5cxx11Ev(&v42, v25);
      v27 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
      v28 = ((int (*)(void))ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev)();
      CTRPluginFramework::LineWriter::operator<<(v27, v28);
      v29 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
      if ( (unsigned int)*(_QWORD *)(v25 + 12) != *(_QWORD *)(v25 + 12) >> 32 )
      {
        for ( i = 0; ; i += 2 )
        {
          v31 = *(_QWORD *)(v25 + 12);
          if ( i >= (HIDWORD(v31) - (signed int)v31) >> 2 )
            break;
          ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(
            &v42,
            "%08X %08X",
            *(_DWORD *)(v31 + 4 * i),
            *(_DWORD *)(v31 + 4 * i + 4));
          v32 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
          v33 = v32;
          v34 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v32);
          CTRPluginFramework::LineWriter::operator<<(v33, v34);
          v29 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
        }
      }
      v25 += 48;
    }
    while ( v26 != v25 );
    if ( *(_DWORD *)(v2 + 32) )
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v42, "{");
      v35 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
      CTRPluginFramework::RemoveFormat((int)&v41, (unsigned __int8 **)(v2 + 28));
      v36 = CTRPluginFramework::LineWriter::operator<<(v35, &v41);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v40, "}");
      v37 = CTRPluginFramework::LineWriter::operator<<(v36, &v40);
      v38 = ((int (*)(void))ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev)();
      CTRPluginFramework::LineWriter::operator<<(v37, v38);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v40);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v41);
      v29 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
    }
    v39 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v29);
    CTRPluginFramework::LineWriter::operator<<(v5, v39);
  }
  else
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v42, "[++");
    v6 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
    CTRPluginFramework::RemoveFormat((int)&v41, (unsigned __int8 **)(v2 + 4));
    v7 = CTRPluginFramework::LineWriter::operator<<(v6, &v41);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v40, "++]");
    v8 = CTRPluginFramework::LineWriter::operator<<(v7, &v40);
    v9 = v8;
    v10 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v8);
    v11 = CTRPluginFramework::LineWriter::operator<<(v9, v10);
    v12 = v11;
    v13 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v11);
    CTRPluginFramework::LineWriter::operator<<(v12, v13);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v40);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v41);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
    while ( CTRPluginFramework::MenuFolderImpl::ItemsCount((CTRPluginFramework::MenuFolderImpl *)v2) > v4 )
    {
      v14 = CTRPluginFramework::MenuFolderImpl::operator[](v2, v4);
      CTRPluginFramework::ActionReplay_WriteToFile(v5, v14);
      ++v4;
    }
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v42, "[--]");
    v15 = CTRPluginFramework::LineWriter::operator<<(v5, &v42);
    v16 = v15;
    v17 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v15);
    v18 = CTRPluginFramework::LineWriter::operator<<(v16, v17);
    v19 = v18;
    v20 = ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(v18);
    CTRPluginFramework::LineWriter::operator<<(v19, v20);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v42);
  }
  return 1;
}
// 4B4: using guessed type int ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz(_DWORD, const char *, ...);
// 4BC: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
// 4D0: using guessed type int __fastcall CTRPluginFramework::LineWriter::operator<<(_DWORD, _DWORD);
// 4D4: using guessed type int __fastcall ZN18CTRPluginFramework10LineWriter4endlB5cxx11Ev(_DWORD);
// 4DC: using guessed type int __fastcall CTRPluginFramework::MenuFolderImpl::operator[](_DWORD, _DWORD);
// 4E0: using guessed type int __fastcall ZNK18CTRPluginFramework6ARCode8ToStringB5cxx11Ev(_DWORD, _DWORD);

// ALL OK, 3 function(s) have been successfully decompiled