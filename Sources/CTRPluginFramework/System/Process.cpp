#include "CTRPluginFramework/System/Process.hpp"

namespace CTRPluginFramework
{
    Handle Process::GetHandle(void)
    {
      return ProcessImpl::ProcessHandle;
    }

    u32 Process::GetProcessID(void)
    {
      return ProcessImpl::ProcessId;
    }

    u64 Process::GetTitleID(void)
    {
      return ProcessImpl::TitleId;
    }

    void Process::GetTitleID(std::string &output)
    {
        char *s = new char[0x10u];
        sprintf(s, "%016llX", ProcessImpl::TitleId);
        output = "";
        for(int i = 0; i < 0x10; i++)
            output += s[i];
        delete s;
    }

    void Process::GetName(std::string &output)
    {
      output = "";
      for(int i = 0; i < 8; i++)
        output += (char)ProcessImpl::CodeSet[80+i];
    }

    u16 Process::GetVersion(void)
    {
      u64 titleId;
      AM_TitleEntry titleInfo;
      if ( AM_GetTitleInfo(MEDIATYPE_GAME_CARD, 1, &titleId, &titleInfo) < 0 )
        return titleInfo.version;
      return 0;
    }

    u32 Process::GetTextSize(void)
    {
      return (ProcessImpl::CodeSet[68] | (ProcessImpl::CodeSet[69] << 8) | (ProcessImpl::CodeSet[70] << 16)) << 12;
    }

    bool Process::IsPaused(void)
    {
      return ProcessImpl::IsPaused;
    }

    void Process::Pause(void)
    {
      return ProcessImpl::Pause(0);
    }

    void Process::Play(const u32 frames)
    {
      OSDImpl::ResumeFrame(frames);
      ProcessImpl::Play(0);
    }

    bool Process::Patch(u32 addr, u32 patch, void *original = nullptr)
    {
      return ProcessImpl::PatchProcess(addr, patch, original);
    }

    bool Process::ProtectMemory(u32  addr, u32 size, int perm)
    {
      return svcControlProcess(ProcessImpl::ProcessImpl, ProcessOp::PROCESSOP_GET_ALL_HANDLES, 1, 0);
    }

    bool Process::ProtectRegion(u32 addr, int perm)
    {
      PageInfo pageInfo;
      MemInfo memInfo;
      if ( svcQueryProcessMemory(&memInfo, &pageInfo, ProcessImpl::ProcessHandle, addr) < 0 )
        return false;
      if ( memInfo.base_addr > addr || base_addr.base_addr < addr )
        return false;
      retrun Process::ProtectMemory(&memInfo, memInfo.size, perm);
    }

    bool Process::CopyMemory(void *dst, const void *src, u32 size)
    {
      if(!ProcessImpl::IsValidAddress(&dst) || !!ProcessImpl::IsValidAddress(&src))
        return false;
      svcFlushProcessDataCache(ProcessImpl::ProcessHandle, src, size);
      svcInvalidateProcessDataCache(ProcessImpl::ProcessHandle, dst, size);
      memcpy((void *)dst, (void *)src, (size_t)size);
      svcFlushProcessDataCache(ProcessImpl::ProcessHandle, dst, size);
      return true;
    }

    bool Process::CheckRegion(u32 address, u32& size, u32 perm)
    {
      ProcessImpl::GetMemRegion(address, perm);
      if ( address == ProcessImpl::InvalidRegion[0] )
        return ProcessImpl::InvalidRegion[1] != size;
      return true;
    }

    bool Process::Write64(u32 address, u64 value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(u64*)address = value;
        return true;
      }
      return false
    }

    bool Process::Write32(u32 address, u32 value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(u32*)address = value;
        return true;
      }
      return false
    }

    bool Process::Write16(u32 address, u16 value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(u16*)address = value;
        return true;
      }
      return false
    }

    bool Process::Write8(u32 address, u8 value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(u8*)address = value;
        return true;
      }
      return false
    }

    bool Process::WriteFloat(u32 address, float value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(float*)address = value;
        return true;
      }
      return false
    }

    bool Process::WriteDouble(u32 address, double value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        *(double*)address = value;
        return true;
      }
      return false
    }

    bool Process::Read64(u32 address, u64 &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(u64*)address;
        return true;
      }
      return false
    }

    bool Process::Read32(u32 address, u32 &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(u32*)address;
        return true;
      }
      return false
    }

    bool Process::Read16(u32 address, u16 &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(u16*)address;
        return true;
      }
      return false
    }

    bool Process::Read8(u32 address, u8 &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(u8*)address;
        return true;
      }
      return false
    }

    bool Process::ReadFloat(u32 address, float &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(float*)address;
        return true;
      }
      return false
    }

    bool Process::ReadDouble(u32 address, double &value)
    {
      if(ProcessImpl::IsValidAddress(address))
      {
        value = *(double*)address;
        return true;
      }
      return false
    }

/*
    signed int ConvertString(_WORD *a1, int a2, int a3)
    {
      _WORD *v3; // r4
      int v4; // r6
      unsigned int v5; // r5
      int v6; // r0
      int v8; // r0
      int v9; // r0
      char *v10; // r3
      __int16 v11; // t1
      int v12; // [sp+4h] [bp-34h]
      char v13; // [sp+8h] [bp-30h]

      v3 = a1;
      v4 = a2;
      v5 = a3 & 0xFFFFFFFE;
      while ( 1 )
      {
        v6 = decode_utf8(&v12, v4);
        if ( v6 == -1 )
          return 0;
        v4 += v6;
        v8 = encode_utf16(&v13, v12);
        v5 -= v8;
        if ( !v5 )
          break;
        v9 = (int)&v3[v8];
        v10 = &v13;
        while ( v3 != (_WORD *)v9 )
        {
          v11 = *(_WORD *)v10;
          v10 += 2;
          *v3 = v11;
          ++v3;
        }
        if ( !v12 )
          return 1;
      }
      *v3 = 0;
      return 1;
    }

    signed int ConvertString(int *a1, int a2, int a3, int a4)
    {
      int *v5; // r5
      int v6; // r6
      unsigned int v7; // r4
      unsigned int v8; // r0
      unsigned int v9; // r1
      int *v10; // r2
      int v11; // r3
      bool v12; // cf
      int v13; // [sp+4h] [bp-14h]

      v13 = a2;
      if ( a4 == 1 )
        return ConvertString(a1, a2, a3);
      v5 = a1;
      v6 = a2;
      v7 = a3 & 0xFFFFFFFC;
      while ( 1 )
      {
        v8 = decode_utf8(&v13, v6);
        if ( v8 == -1 )
          return 0;
        v7 -= 4;
        v9 = v8;
        v6 += v8;
        if ( !v7 )
          break;
        v10 = v5;
        v11 = v13;
        while ( 1 )
        {
          v12 = v8-- >= 1;
          if ( !v12 )
            break;
          *v10 = v11;
          ++v10;
        }
        v5 += v9;
        if ( !v11 )
          return 1;
      }
      *v5 = 0;
      return 1;
    }
    int Process::ReadString(ProcessImpl *a1, unsigned int a2, int a3, int a4)
    {
      ProcessImpl *v4; // r4
      unsigned int v5; // r7
      int v6; // r5
      int v7; // r8
      int v8; // r6
      int v9; // r0
      int v10; // r8
      int v11; // t1
      bool v12; // zf
      unsigned int v14; // r5
      unsigned int v15; // r5
      int v16; // r0
      int v17; // r0
      unsigned int v18; // r8
      int *v19; // r9
      bool v20; // cf
      int v21; // t1
      bool v22; // zf
      int v23; // r9
      int v24; // t1
      unsigned int v25; // r8
      int *v26; // r9
      int v27; // t1
      int v28; // [sp+4h] [bp-34h]
      int v29; // [sp+8h] [bp-30h]

      v4 = a1;
      v5 = a2;
      v6 = a3;
      v7 = a4;
      v8 = ProcessImpl::IsValidAddress(a1, a2);
      if ( v8 )
      {
        if ( v7 )
        {
          if ( v7 == 1 )
          {
            v15 = v6 & 0xFFFFFFFE;
            v28 = 0;
            while ( 1 )
            {
              v16 = decode_utf16(&v28, v4);
              if ( v16 == -1 )
                break;
              v17 = 2 * v16;
              v4 = (ProcessImpl *)((char *)v4 + v17);
              v15 -= v17;
              v18 = encode_utf8(&v29, v28);
              if ( v18 == -1 )
                break;
              if ( v28 )
              {
                v19 = &v29;
                while ( 1 )
                {
                  v20 = v18-- >= 1;
                  if ( !v20 )
                    break;
                  v21 = *(unsigned __int8 *)v19;
                  v19 = (int *)((char *)v19 + 1);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v21);
                }
                v22 = v15 == 0;
                if ( v15 )
                  v22 = v28 == 0;
                if ( !v22 )
                  continue;
              }
              return v8;
            }
          }
          else
          {
            v14 = (unsigned int)v4 + (v6 & 0xFFFFFFFC);
            while ( 1 )
            {
              v24 = *(_DWORD *)v4;
              v4 = (ProcessImpl *)((char *)v4 + 4);
              v23 = v24;
              v25 = encode_utf8(&v29, v24);
              if ( v25 == -1 )
                break;
              if ( v23 )
              {
                v26 = &v29;
                while ( 1 )
                {
                  v20 = v25-- >= 1;
                  if ( !v20 )
                    break;
                  v27 = *(unsigned __int8 *)v26;
                  v26 = (int *)((char *)v26 + 1);
                  std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v27);
                }
                if ( v4 != (ProcessImpl *)v14 )
                  continue;
              }
              return v8;
            }
          }
        }
        else
        {
          v29 = 0;
          while ( 1 )
          {
            v9 = decode_utf8(&v29, v4);
            if ( v9 == -1 )
              break;
            v6 -= v9;
            if ( v29 )
            {
              v10 = (int)v4 + v9;
              while ( v4 != (ProcessImpl *)v10 )
              {
                v11 = *(unsigned __int8 *)v4;
                v4 = (ProcessImpl *)((char *)v4 + 1);
                std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::push_back(v5, v11);
              }
              v12 = v6 == 0;
              if ( v6 )
                v12 = v29 == 0;
              if ( !v12 )
                continue;
            }
            return v8;
          }
        }
      }
      return 0;
    }

    signed int Process::WriteString(ProcessImpl *a1, unsigned int a2, int a3)
    {
      int *v3; // r4
      unsigned int v4; // r6
      int v5; // r5
      signed int result; // r0
      int v7; // r12
      _BYTE *v8; // r1
      int v9; // r12
      int v10; // r4
      int v11; // r2

      v3 = (int *)a1;
      v4 = a2;
      v5 = a3;
      result = ProcessImpl::IsValidAddress(a1, a2);
      if ( result )
      {
        v7 = *(_DWORD *)(v4 + 4);
        if ( v7 )
        {
          v8 = *(_BYTE **)v4;
          if ( v5 )
          {
            v11 = v7 + 1;
            if ( v5 == 1 )
              result = ConvertString(v3, (int)v8, 2 * v11);
            else
              result = ConvertString(v3, (int)v8, 4 * v11, v5);
          }
          else
          {
            v9 = (int)&v8[v7];
            v10 = (char *)v3 - v8;
            while ( v8 != (_BYTE *)v9 )
            {
              v8[v10] = *v8;
              ++v8;
            }
          }
        }
        else
        {
          result = 0;
        }
      }
      return result;
    }

    signed int Process::WriteString(ProcessImpl *a1, unsigned int a2, int a3, int a4)
    {
      int *v4; // r4
      unsigned int v5; // r7
      int v6; // r5
      int v7; // r6
      signed int result; // r0
      int v9; // r12
      char *v10; // r1
      int v11; // r12
      int v12; // r4
      int v13; // r5
      char *v14; // r3
      char v15; // r2
      char v16; // t1

      v4 = (int *)a1;
      v5 = a2;
      v6 = a3;
      v7 = a4;
      result = ProcessImpl::IsValidAddress(a1, a2);
      if ( result )
      {
        v9 = *(_DWORD *)(v5 + 4);
        if ( v9 )
        {
          v10 = *(char **)v5;
          if ( v7 )
          {
            if ( v7 == 1 )
              result = ConvertString(v4, (int)v10, v6);
            else
              result = ConvertString(v4, (int)v10, v6, v7);
          }
          else
          {
            v11 = (int)&v10[v9];
            v12 = (char *)v4 - v10;
            v13 = (int)&v10[v6];
            while ( 1 )
            {
              v14 = &v10[v12];
              if ( (char *)v11 == v10 )
                break;
              v16 = *v10++;
              v15 = v16;
              if ( v10 == (char *)v13 )
              {
                *v14 = 0;
                return result;
              }
              *v14 = v15;
            }
          }
        }
        else
        {
          result = 0;
        }
      }
      return result;
    }

*/
}
