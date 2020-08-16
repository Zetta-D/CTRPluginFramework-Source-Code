#include "CTRPluginFramework/Menu/PluginMenu.hpp"

namespace CTRPluginFramework
{

int g_runningInstance; // weak

//----- (00000008) --------------------------------------------------------
PluginMenu::PluginMenu(std::string name = "Cheats", std::string about = "")
{
  _DWORD *v1; // r4
  int v2; // r5

  v1 = a1;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  v2 = operator new(0x1B0u);
  PluginMenuImpl::PluginMenuImpl();
  v1[3] = v2;
  return v1;
}
// 2C8: using guessed type int PluginMenuImpl::PluginMenuImpl(void);

//----- (0000004C) --------------------------------------------------------
_DWORD PluginMenu::PluginMenu(_DWORD *a1, int a2, int a3, void (__fastcall *a4)(char **, int))
{
  int v4; // r8
  _DWORD *v5; // r4
  void (__fastcall *v6)(char **, int); // r6
  int v7; // r6
  PluginMenuImpl *v8; // r5
  char *v10; // [sp+0h] [bp-30h]
  int v11; // [sp+4h] [bp-2Ch]
  char v12; // [sp+8h] [bp-28h]

  v4 = a3;
  v5 = a1;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  v6 = a4;
  v10 = &v12;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
  v11 = 0;
  v12 = 0;
  v6(&v10, v4);
  v7 = operator new(0x1B0u);
  PluginMenuImpl::PluginMenuImpl();
  v8 = (PluginMenuImpl *)v5[3];
  v5[3] = v7;
  if ( v8 )
  {
    PluginMenuImpl::~PluginMenuImpl(v8);
    operator delete((void *)v8);
  }
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v10);
  return v5;
}
// 2C8: using guessed type int PluginMenuImpl::PluginMenuImpl(void);
// 2CC: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(void);
// 2D8: using guessed type int __fastcall std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

//----- (000000F4) --------------------------------------------------------
_DWORD PluginMenu::PluginMenu(_DWORD *a1, int a2, unsigned __int8 a3, __int16 a4, int a5)
{
  __int16 v5; // r4
  _DWORD *v6; // r5
  unsigned __int8 v7; // r7
  PluginMenuImpl *v8; // r6

  v5 = a4;
  v6 = a1;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  v7 = a3;
  v8 = (PluginMenuImpl *)operator new(0x1B0u);
  PluginMenuImpl::PluginMenuImpl();
  v6[3] = v8;
  PluginMenuImpl::AddPluginVersion(v8, (unsigned __int16)(v5 << 8) | v7 | (a5 << 16) & 0xFF0000);
  return v6;
}
// 2C8: using guessed type int PluginMenuImpl::PluginMenuImpl(void);

//----- (00000164) --------------------------------------------------------
PluginMenu PluginMenu::~PluginMenu(PluginMenu *this)
{
  void *v1; // r4
  PluginMenu *v2; // r5

  v1 = (void *)*((_DWORD *)this + 3);
  v2 = this;
  if ( v1 )
  {
    PluginMenuImpl::~PluginMenuImpl(*((PluginMenuImpl **)this + 3));
    operator delete(v1);
  }
  return v2;
}

//----- (00000190) --------------------------------------------------------
int __fastcall PluginMenu::Append(int result, int a2)
{
  if ( a2 )
    result = PluginMenuImpl::Append(*(_DWORD *)(result + 12), *(_DWORD *)(a2 + 20));
  return result;
}
// 2E0: using guessed type int __fastcall PluginMenuImpl::Append(_DWORD, _DWORD);

//----- (000001A4) --------------------------------------------------------
int __fastcall PluginMenu::Append(int result, int a2)
{
  if ( a2 )
    result = PluginMenuImpl::Append(*(_DWORD *)(result + 12), *(_DWORD *)(a2 + 4));
  return result;
}
// 2E0: using guessed type int __fastcall PluginMenuImpl::Append(_DWORD, _DWORD);

//----- (000001C0) --------------------------------------------------------
int __fastcall PluginMenu::operator+=(int result, void (*a2)(void))
{
  if ( a2 )
    result = PluginMenuImpl::Callback(*(PluginMenuImpl **)(result + 12), a2);
  return result;
}
// 2E4: using guessed type _DWORD __cdecl PluginMenuImpl::Callback(PluginMenuImpl *__hidden this, void (*)(void));

//----- (000001D0) --------------------------------------------------------
int __fastcall PluginMenu::operator-=(int result, void (*a2)(void))
{
  if ( a2 )
    result = PluginMenuImpl::RemoveCallback(
               *(PluginMenuImpl **)(result + 12),
               a2);
  return result;
}
// 2E8: using guessed type _DWORD __cdecl PluginMenuImpl::RemoveCallback(PluginMenuImpl *__hidden this, void (*)(void));

//----- (000001E4) --------------------------------------------------------
int __fastcall PluginMenu::Run(PluginMenu *this)
{
  int v1; // r3
  int v2; // r2
  int result; // r0

  **((_DWORD **)this + 3) = *(_DWORD *)this;
  v1 = *((_DWORD *)this + 3);
  v2 = *((_DWORD *)this + 1);
  g_runningInstance = (int)this;
  *(_DWORD *)(v1 + 4) = v2;
  *(_DWORD *)((*((_QWORD *)this + 1) >> 32) + 8) = *((_QWORD *)this + 1);
  result = PluginMenuImpl::Run(*((PluginMenuImpl **)this + 3));
  g_runningInstance = 0;
  return result;
}
// 4: using guessed type int g_runningInstance;

//----- (00000228) --------------------------------------------------------
PluginMenu PluginMenu::GetEntryList(PluginMenu *this, int a2)
{
  PluginMenu *v2; // r4

  v2 = this;
  PluginMenuImpl::GetRoot(*(PluginMenuImpl **)(a2 + 12));
  MenuFolderImpl::GetEntryList(v2);
  return v2;
}

//----- (0000024C) --------------------------------------------------------
PluginMenu PluginMenu::GetFolderList(PluginMenu *this, int a2)
{
  PluginMenu *v2; // r4

  v2 = this;
  PluginMenuImpl::GetRoot(*(PluginMenuImpl **)(a2 + 12));
  MenuFolderImpl::GetFolderList(v2);
  return v2;
}

//----- (00000270) --------------------------------------------------------
int __fastcall PluginMenu::SetHexEditorState(PluginMenu *this, int a2)
{
  return PluginMenuImpl::SetHexEditorState(*((_DWORD *)this + 3), a2);
}
// 2FC: using guessed type int __fastcall PluginMenuImpl::SetHexEditorState(_DWORD, _DWORD);

//----- (00000278) --------------------------------------------------------
int __fastcall PluginMenu::ShowWelcomeMessage(PluginMenu *this, bool a2)
{
  return PluginMenuImpl::ShowWelcomeMessage(*((PluginMenuImpl **)this + 3), a2);
}
// 300: using guessed type _DWORD __cdecl PluginMenuImpl::ShowWelcomeMessage(PluginMenuImpl *__hidden this, bool);

//----- (00000280) --------------------------------------------------------
int __fastcall PluginMenu::IsOpen(PluginMenu *this)
{
  return PluginMenuImpl::IsOpen(*((_DWORD *)this + 3));
}
// 304: using guessed type int __fastcall PluginMenuImpl::IsOpen(_DWORD);

//----- (00000288) --------------------------------------------------------
int __fastcall PluginMenu::WasOpened(PluginMenu *this)
{
  return PluginMenuImpl::WasOpened(*((_DWORD *)this + 3));
}
// 308: using guessed type int __fastcall PluginMenuImpl::WasOpened(_DWORD);

//----- (00000290) --------------------------------------------------------
int __fastcall PluginMenu::GetRunningInstance(PluginMenu *this)
{
  return g_runningInstance;
}
// 4: using guessed type int g_runningInstance;

//----- (000002A0) --------------------------------------------------------
int __fastcall PluginMenu::SynchronizeWithFrame(int result, bool a2)
{
  *(_BYTE *)(*(_DWORD *)(result + 12) + 12) = a2;
  return result;
}

//----- (000002AC) --------------------------------------------------------
int __fastcall ZN18CTRPluginFramework10PluginMenu5TitleB5cxx11Ev(int a1)
{
  return **(_DWORD **)(*(_DWORD *)(a1 + 12) + 24) + 4;
}
}