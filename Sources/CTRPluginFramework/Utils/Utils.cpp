#include "Utils.hpp"
#include <cstdarg>
#include <cstring>
#include <random>

std::string GetName_msg; // weak
  _UNKNOWN unk_1AC2; // weak
  _UNKNOWN unk_1AD3; // weak

namespace CTRPluginFramework
{
  u32 g_rng; // weak
  
  std::string Utils::Format(const char *fmt, ...)
  {
    char *s;
    const char *varg_r1;
    va_list varg_r2;
    va_start(varg_r2, fmt);
    varg_r1 = fmt;
    memset(s, 0, 0x100u);
    vsnprintf(s, 0x100u, varg_r1, varg_r2);
    std::string str = s;
    return str;
  }

  std::string  Utils::ToHex(u32 value)
  {
    std::string str;
    char s[8];
    sprintf(s, "%08X", value);
    str = s;
    return str;
  }

  std::string  Utils::ToString(float fpval, int precision)
  {
    return Utils::Format("%.*e", precision, fpval);
  }

  u32 Utils::Random(void)
  {
    return Utils::Random(0, 0);
  }

  u32 Utils::Random(u32 min, u32 max)
  {
    u32 v3, v5, v7, res;

    if ( !min )
      min = -1;
    v3 = min - g_rng;
    v4 = this;
    if ( v3 == -1 )
      res = std::mersenne_twister_engine<unsigned int,32u,624u,397u,31u,2567483615u,11u,4294967295u,7u,2636928640u,15u,4022730752u,18u,1812433253u>::operator()((int)&g_rng);
    else
    {
      v5 = 0xFFFFFFFF / (v3 + 1);
      do
        v7 = std::mersenne_twister_engine<unsigned int,32u,624u,397u,31u,2567483615u,11u,4294967295u,7u,2636928640u,15u,4022730752u,18u,1812433253u>::operator()((int)&g_rng);
      while ( v5 * (v3 + 1) <= v7 );
      res = v7 / v5;
    }
    return u32(res);
  }

  u32 Utils::GetSize(const std::string &str)
  {
    size_t v1; // r5
    u8 *ptr;
    int v4;
    ssize_t res;
    u32 out;
    u8 *s;

    size = str.size();
    if (size)
    {
      memcpy((void*)s, (void*)str, size);
      ptr = (u8 *)s;
      while (true)
      {
        v4 = (u8)(*ptr);
        if (!*ptr)
          break;
        if ( v4 == 24 )
          ++ptr;
        else if ( v4 == 27 )
          ptr += 4;
        else
        {
          res = decode_utf8(&out, ptr);
          if ( res == -1 )
            return size;
          ptr += res;
          ++size;
        }
      }
    }
    return size;
  }

  int Utils::FilePicker(std::string &out, const std::string &filter)
  {
    return SDExplorerInternal(out, filter, 0);
  }

  int Utils::DirectoryPicker(std::string &out)
  {
    return SDExplorerInternal(out, (const char*)unk_1A5C, 1);
  }

  u32 Utils::RemoveLastChar(std::string &str)
  {
    size_t size; // r4
    u8 *ptr, *s; // r4
    int v5; // r0
    int v6; // r3
    int v7; // r3
    u32 out; // [sp+4h] [bp-114h]
    char v12; // [sp+Bh] [bp-10Dh]

    size = *(_DWORD *)(a1 + 4);
    v2 = (const void **)a1;
    memset(s, 0, 0x100u);
    if ( v1 )
    {
      memcpy((void*)s, (void*)str, size);
      ptr = (char *)s;
      v5 = 0;
      out = 0;
      while ( 1 )
      {
        v6 = (u8)*ptr;
        if ( !*ptr )
          return 0;
        if ( v6 == 24 )
        {
          if ( !ptr[1] )
            goto LABEL_13;
          v7 = (int)(ptr + 1);
          ++v5;
        }
        else if ( v6 == 27 )
        {
          if ( ptr[1] && ptr[2] && ptr[3] && !ptr[4] )
          {
  LABEL_13:
            if ( v5 )
              ptr -= v5;
            *ptr = 0;
            goto LABEL_16;
          }
          v7 = (int)(ptr + 4);
          v5 += 4;
        }
        else
        {
          v5 = decode_utf8(&out, ptr);
          if ( v5 == -1 )
            return 0;
          v7 = (int)&ptr[v5];
          if ( !ptr[v5] )
          {
            *ptr = 0;
  LABEL_16:
            v2 = s;
            return out;
          }
        }
        v4 = (char *)v7;
      }
    }
    return 0;
  }

  bool  GetName(u32 &output)
  {
    Keyboard keyboard(GetName_msg);
    return keyboard.Open(output) != -1;
  }

  u32 std::mersenne_twister_engine<unsigned int,32u,624u,397u,31u,2567483615u,11u,4294967295u,7u,2636928640u,15u,4022730752u,18u,1812433253u>::seed(u32 *result, u64 value)
  {
    u32 v2; // r2
    u32 *v3; // r1
    int v4; // r3

    *result = value;
    v2 = 1;
    v3 = result;
    do
    {
      v3[1] = v2++ + 1812433253 * (*v3 ^ (*v3 >> 30));
      ++v3;
    }
    while ( v2 != 624 );
    result[624] = 624;
    return result;
  }

  u32 InitializeRandomEngine(void)
  {
    return std::mersenne_twister_engine<unsigned int,32u,624u,397u,31u,2567483615u,11u,4294967295u,7u,2636928640u,15u,4022730752u,18u,1812433253u>::seed(&g_rng, svcGetSystemTick());
  }

  int ListFolders(MenuFolderImpl *a1, int a2, int a3)
  {

  }

}

int __fastcall ListFolders(MenuFolderImpl *a1, int a2, int a3)
{
  MenuFolderImpl *v3; // r4
  int v4; // r7
  int v5; // r6
  int res; // r5
  int v7; // r5
  int v8; // r9
  int i; // r5
  int v10; // r8
  int v12; // r6
  int v13; // r8
  int v14; // r5
  int v15; // r0
  int v16; // r8
  int j; // r5
  int v18; // r6
  std::stirng title; // [sp+8h] [bp-B0h]
  int v20 = 0; // [sp+Ch] [bp-ACh]
  int v21 = 0; // [sp+10h] [bp-A8h]
  int v22 = 0; // [sp+14h] [bp-A4h]
  std::string path; // [sp+18h] [bp-A0h]
  u32 v24; // [sp+1Ch] [bp-9Ch]
  std::string message; // [sp+48h] [bp-70h]
  std::string output; // [sp+60h] [bp-58h]

  menu = a1;
  v4 = a2;
  v5 = a3;
  path = (char *)a1 + 28
  Directory directory(output)
  if ( MenuFolderImpl::ItemsCount(menu) )
    MenuFolderImpl::Clear(menu);
  res = Directory::Open(output, &path, 0);
  if ( res )
  {
    (MessageBox::MessageBox("Error", Utils::Format("%08X - %s" , res, path)))();
  }
  if ( v24 > 1 && *(_BYTE *)(path + v24 - 1) != 47 )
    path += "/";
  output = unk_1A5C;
  v7 = Directory::ListDirectories(&v27, &v20, path);
  if ( v7 > 0 )
  {
    v8 = v21;
    for ( i = v20; i != v8; i += 24 )
    {
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(path, i);
      v10 = new u32[0x64u];
      MenuFolderImpl::MenuFolderImpl();
      MenuFolderImpl::Append(v3, v10, 0);
    }
  }
  if ( v5 )
  {
    v12 = v20;
    v13 = v21;
    if ( v20 != v21 )
    {
      v14 = v20;
      do
      {
        v15 = v14;
        v14 += 24;
      }
      while ( v13 != v14 );
      v21 = v12;
    }
    if ( Directory::ListFiles(&v27, &v20, v4) > 0 )
    {
      v16 = v21;
      for ( j = v20; j != v16; j += 24 )
      {
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
          (int *)&v26,
          (const char *)&unk_1A5C);
        v18 = operator new(0x78u);
        MenuEntryImpl::MenuEntryImpl();
        MenuFolderImpl::Append(v3, v18, 0);
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v26);
      }
    }
  }
  std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::~vector((void **)&v20);
  Directory::~Directory((Directory *)&v27);
  return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v23);
}

//----- (00001130) --------------------------------------------------------
int __fastcall SDExplorerInternal(int a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r7
  int v5; // r8
  MenuFolderImpl *v6; // r4
  const char *v7; // r1
  Process *v8; // r0
  TMLongCard v9; // r9
  MenuFolderImpl *v10; // r0
  int v11; // r4
  int v12; // r10
  Time *v13; // r1
  int v14; // r0
  unsigned int v15; // r4
  bool v16; // cf
  int v17; // r4
  MenuFolderImpl *v18; // r11
  bool v19; // r1
  unsigned int v20; // r1
  signed int v21; // r4
  MenuFolderImpl *v23; // r0
  MenuFolderImpl *v24; // r11
  int v25; // r0
  int v26; // ST0C_4
  int v27; // r0
  unsigned int v28; // r1
  unsigned int v29; // r0
  const char *v30; // r1
  int v31; // r0
  int v32; // r0
  MenuFolderImpl *v33; // [sp+14h] [bp-264h]
  char v34; // [sp+18h] [bp-260h]
  char v35; // [sp+1Ch] [bp-25Ch]
  char v36; // [sp+20h] [bp-258h]
  Event v37; // [sp+2Ch] [bp-24Ch]
  char *v38; // [sp+50h] [bp-228h]
  int v39; // [sp+54h] [bp-224h]
  char v40; // [sp+58h] [bp-220h]
  char *v41; // [sp+68h] [bp-210h]
  int v42; // [sp+6Ch] [bp-20Ch]
  char v43; // [sp+70h] [bp-208h]
  char v44; // [sp+80h] [bp-1F8h]
  char v45; // [sp+98h] [bp-1E0h]
  int v46; // [sp+B0h] [bp-1C8h]
  int v47; // [sp+B4h] [bp-1C4h]
  int v48; // [sp+B8h] [bp-1C0h]
  char v49; // [sp+C8h] [bp-1B0h]
  void *v50[13]; // [sp+ECh] [bp-18Ch]
  Time v51[6]; // [sp+120h] [bp-158h]
  char v52; // [sp+138h] [bp-140h]
  char v53; // [sp+150h] [bp-128h]
  char v54; // [sp+168h] [bp-110h]
  char v55; // [sp+180h] [bp-F8h]
  char v56; // [sp+198h] [bp-E0h]

  v3 = a2;
  v4 = a1;
  v5 = a3;
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)v50, "/");
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
    (int *)v51,
    (const char *)&unk_1A5C);
  Menu::Menu(&v56, v50, v51, &Icon::DrawFile);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v51);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v50);
  v6 = (MenuFolderImpl *)Menu::GetRootFolder((Menu *)&v56);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
    (int *)&v37.eventType,
    (const char *)&unk_1AC2);
  v7 = "\nStart : Select the current folder\n";
  if ( !v5 )
    v7 = " / Select file\n";
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(&v37.eventType, v7);
  v8 = (Process *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(
                                        &v37.eventType,
                                        &unk_1AD3);
  v9 = v37.eventType;
  Process::Pause(v8);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=((char *)v6 + 28, "/");
  v10 = v6;
  v11 = 0;
  ListFolders(v10, v3, v5 ^ 1);
  EventManager::EventManager((EventManager *)v50);
  Clock::Clock((Clock *)&v36);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
    (int *)v51,
    "Create folder");
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v52, "Create file");
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v53, "Rename");
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v54, "Delete");
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v55, "Cancel");
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v12 = operator new(0x78u);
  v46 = v12;
  v48 = v12 + 120;
  do
  {
    v13 = &v51[v11];
    v14 = v12 + v11 * 4;
    v11 += 6;
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v14, v13);
  }
  while ( v11 != 30 );
  v47 = v12 + 120;
  SubMenu::SubMenu(&v49, &v46);
  std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::~vector((void **)&v46);
  v15 = 4;
  do
  {
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v51[6 * v15]);
    v16 = v15-- >= 1;
  }
  while ( v16 );
  do
  {
    while ( 1 )
    {
      if ( !EventManager::PollEvent((EventManager *)v50, &v37) )
      {
        v17 = -6;
        break;
      }
      if ( !SubMenu::IsOpen((SubMenu *)&v49) )
      {
        v17 = Menu::ProcessEvent(&v56, &v37, &v33);
        if ( v17 != -6 )
          break;
      }
      SubMenu::ProcessEvent((SubMenu *)&v49, &v37);
      if ( v5 && !LOBYTE(v37.modifiers) && v37.modifierMask == 8 )
      {
        v17 = -2;
        break;
      }
    }
    if ( SubMenu::IsOpen((SubMenu *)&v49) )
    {
      v17 = SubMenu::operator()(&v49);
      v23 = (MenuFolderImpl *)Menu::GetFolder((Menu *)&v56);
      v38 = &v40;
      v24 = v23;
      v39 = 0;
      v40 = 0;
      v41 = &v43;
      v42 = 0;
      v43 = 0;
      if ( v17 >= 0 )
      {
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(&v38, (char *)v23 + 28);
        if ( std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::compare(&v38, "/") )
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(&v38, "/");
        if ( v17 )
        {
          if ( v17 == 1 )
          {
            if ( !GetName((int)&v41) )
              goto LABEL_32;
            std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v51, &v38);
            std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(v51, &v41);
            File::Create(v51);
            goto LABEL_30;
          }
          if ( v17 != 2 )
          {
            if ( v17 == 3 )
            {
              v33 = (MenuFolderImpl *)Menu::GetSelectedItem((Menu *)&v56);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
                (int *)&v44,
                "Do you really want to delete the ");
              if ( *((_BYTE *)v33 + 57) == 1 )
                v30 = "file";
              else
                v30 = "folder";
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v44, v30);
              v31 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v44, " : ");
              v32 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(
                      v31,
                      (char *)v33 + 4);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(v32, " ?");
              Color::operator std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>(
                &v46,
                (unsigned __int8 *)&Color::Orange);
              operator<<(v51, &v46, "Warning");
              MessageBox::MessageBox(&v34, v51, &v44);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v51);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v46);
              if ( MessageBox::operator()(&v34) )
              {
                std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator+=(
                  &v38,
                  (char *)v33 + 4);
                if ( *((_BYTE *)v33 + 57) == 1 )
                  v25 = File::Remove(&v38);
                else
                  v25 = Directory::Remove(&v38);
                if ( v25 < 0 )
                {
                  v26 = v25;
                  Color::operator std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>(
                    (int *)&v45,
                    (unsigned __int8 *)&Color::Red);
                  operator<<(&v46, &v45, "Error");
                  ZN18CTRPluginFramework5Utils6FormatB5cxx11EPKcz((int *)v51, "Operation failed: %08X", v26);
                  MessageBox::MessageBox(&v35, &v46, v51);
                  MessageBox::operator()(&v35);
                  MessageBox::~MessageBox((MessageBox *)&v35);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v51);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v46);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v45);
                }
                else
                {
                  Color::operator std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>(
                    (int *)&v45,
                    (unsigned __int8 *)&Color::LimeGreen);
                  operator<<(&v46, &v45, "Info");
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
                    (int *)v51,
                    "Operation succeeded");
                  MessageBox::MessageBox(&v35, &v46, v51);
                  MessageBox::operator()(&v35);
                  MessageBox::~MessageBox((MessageBox *)&v35);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v51);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v46);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v45);
                  ListFolders(v24, v3, v5 ^ 1);
                }
              }
              MessageBox::~MessageBox((MessageBox *)&v34);
              std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v44);
            }
            else if ( v17 == 4 )
            {
              v17 = -4;
            }
            goto LABEL_32;
          }
          v33 = (MenuFolderImpl *)Menu::GetSelectedItem((Menu *)&v56);
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(&v41, (char *)v33 + 4);
          if ( GetName((int)&v41) )
          {
            std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(&v41, 0, &v38);
            std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v38, &v41);
            if ( *((_BYTE *)v33 + 57) == 1 )
              File::Rename(&v38, &v41);
            else
              Directory::Rename();
            goto LABEL_31;
          }
        }
        else if ( GetName((int)&v41) )
        {
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v51, &v38);
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(v51, &v41);
          Directory::Create(v51);
LABEL_30:
          std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v51);
LABEL_31:
          ListFolders(v24, v3, v5 ^ 1);
          goto LABEL_32;
        }
      }
LABEL_32:
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v41);
      std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v38);
      goto LABEL_20;
    }
    if ( v17 == -3 )
    {
      v18 = v33;
      if ( !MenuFolderImpl::ItemsCount(v33) )
        ListFolders(v18, v3, v5 ^ 1);
    }
LABEL_20:
    Clock::Restart((Clock *)v51);
    Menu::Update((Menu *)&v56, v51);
    Menu::Draw((Menu *)&v56);
    SubMenu::Draw((SubMenu *)&v49);
    Renderer::SetTarget(0);
    Window::Draw((Window *)&Window::BottomWindow);
    v51[0] = 55;
    Renderer::DrawSysStringReturn(
      v9,
      50,
      v51,
      300,
      Preferences::Settings[4],
      200);
    Renderer::EndFrame(0, v19);
  }
  while ( (v17 & 0xFFFFFFFD) != -4 );
  if ( v17 == -4 )
  {
    Process::Play(0, v20);
    v21 = -1;
  }
  else
  {
    v27 = Menu::GetFolder((Menu *)&v56);
    std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v4, v27 + 28);
    if ( !v5 )
    {
      if ( std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::compare(v4, "/") )
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(v4, "/");
      v29 = Menu::GetSelectedItem((Menu *)&v56);
      v28 = v29;
      if ( v29 )
        std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(v4, v29 + 4);
    }
    Process::Play(0, v28);
    v21 = 0;
  }
  SubMenu::~SubMenu((SubMenu *)&v49);
  std::_Deque_base<Event,std::allocator<Event>>::~_Deque_base(v50);
  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v37.eventType);
  Menu::~Menu((Menu *)&v56);
  return v21;
}