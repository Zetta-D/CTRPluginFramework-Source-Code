#include "CTRPluginFrameworkImpl/Graphics/PrivColor.hpp"

int PrivColor::_ReadRGBA8 = 3855618050;
extern u8 r, g, b, a;
extern char Renderer::hookContext[];#include "CTRPluginFramework/System/File.hpp"

namespace CTRPluginFramework {

  //-------------------------------------------------------------------------
  // Data declarations

  int __fileHandle; // weak
  _UNKNOWN unk_B6C; // weak
  _UNKNOWN unk_B6D; // weak
  _UNKNOWN unk_B70; // weak
  _UNKNOWN unk_B72; // weak
  // extern _UNKNOWN ProcessImpl::IsPaused; weak
  // extern _UNKNOWN _sdmcArchive; weak

  //----- (00000008) --------------------------------------------------------
  int FSPath::operator FS_Path(int result, _DWORD * a2) {
    int v2; // r3

    if ( * a2) {
      *(_BYTE * ) result = 1;
      v2 = 0;
      *(_DWORD * )(result + 4) = 0;
    } else {
      *(_BYTE * ) result = 4;
      *(_DWORD * )(result + 4) = 2 * (a2[1] + 1);
      v2 = a2[2];
    }
    *(_DWORD * )(result + 8) = v2;
    return result;
  }

  int File::Close(void) const
  {
    int res;
    Lock::Lock(_mutex);
    if (_isOpen) {
      res = FSFILE_Close(_handle);
      if (res >= 0)
      {
        _path = ""
        _offset = 0
        _handle = 0;
        _mode = 0;
        _isOpen = false;
      }
    else
      res = -2;
    Lock::~Lock();
    return res;
  }

  int File::Read(void *buffer, u32 length) const
  {
    u32 read;
    int res;
    Lock::Lock(_mutex);
    if (_isOpen)
    {
      if (_mode & 1)
      {
        if (Process::CheckAddress(buffer))
        {
          if (lenght)
          {
            res = FSFILE_Read(_handle, &read, _offset, buffer, lenght);
            if (res >= 0)
            {
              res = 0;
              _offset += read;
            }
          }
        }
        else
          res = -4;
      } 
      else
        res = -3;
    else
      res = -2;
    Lock::~Lock();
    return res;
  }

  int File::Write(const void *data, u32 length)
  {
    int res;
    u32 write; 
    u64 size;
    Lock::Lock(_mutex);
    if (_isOpen)
    {
      if (_mode & 2)
      {
        if (Process::CheckAddress(buffer))
        {
          if (length)
          {
            FSFILE_GetSize(_handle, &size);
            if (!(_mode & 8) || (size >= 0))
            {
              res = FSFILE_Write(_handle, &write, _offset, data, length, FS_WRITE_FLUSH);
              if (res >= 0)
              {
                res = 0;
                _offset += write;
              }
            }
          }
          else
            res = 0;
        }
        else
          res = -4;
      }
      else
        res = -3;
    }
    else
      res = -2;
    Lock::~Lock();
    return res;
  }

  int File::WriteLine(std::string line)
  {
    return File::Write(static_cast<void*>(&line), line.size())
  }

  int File::Seek(s64 offset, SeekPos origin) const
  {
    int ptrSize(0);
    s64 size(0), off(0);
    Lock::Lock(_mutex);
    if (_isOpen)
    {
      if (origin == SET)
      {
        off = 0;
        if (offset < 0) goto LABEL_6;
      }
      else
      {
        if (origin)
        {
          if (origin != END)
          {
            LABEL_6: ptrSize = -4;
            goto LABEL_9;
          }
          ptrSize = FSFILE_GetSize(_handle, &size);
          if (ptrSize < 0) goto LABEL_9;
        }
        else
          off = _offset;
        if (offset < 0)
          if (-offset > off) goto LABEL_6;
      }
      ptrSize = 0;
      _offset = v9 + offset;
      goto LABEL_9;
    }
    ptrSize = -2;
    LABEL_9:
      Lock::~Lock();
    return ptrSize;
  }

  u64 File::Tell(void) const
  {
    return _offset;
  }

  void File::Rewind(void) const
  {
    Lock::Lock(_mutex);
    _offset = 0;
    Lock::~Lock();
  }

  int File::Flush(void) const
  {
    int res(0);
    Lock::Lock(_mutex);
    res = FSFILE_Flush(_handle);
    Lock::~Lock();
    return res;
  }

  u64 File::GetSize(void) const
  {
    u64 ret, size;
    int res;
    Lock::Lock(_mutex);
    if (_isOpen)
    {
      size = 0;
      res = FSFILE_GetSize(_handle, &size);
      if (res < 0)
        ret = res;
      else
        ret = size;
    else
      ret = -2;
    Lock::~Lock();
    return ret;
  }

  void File::SetPriority(u32 priority)
  {
    FSFILE_SetPriority(_handle, priority);
  }

 int File::Dump(u32 address, u32 lenght)
 {
    int res;
    u32 lenght, size, resWrite;
    Lock::Lock(_handle);
    if (_isOpen)
    {
      if ( _mode & 2)
      {
        if (Process::CheckAddress(address))
        {
          if (!ProcessImpl::IsPaused)
            ProcessImpl::Pause();
          Process::GetHandle(_handle);
          svcFlushProcessDataCache(_handle, address, lenght);
          do
          {
            size = (lenght >= 0x8000) ? 0x8000 : lenght;
            resWrite = File::Write((void*)address, size);
            lenght -= size;
            res = resWrite;
            address += size;
          }
          while (!(lenght ? resWrite >> 31 : 1));
          if (ProcessImpl::IsPaused)
            ProcessImpl::Play(0);
        }
        else
          res = -4;
      }
      else
        res = -3;
    }
    else
      res = -2;
    Lock::~Lock();
    return res;
  }

  signed int File::Inject(File * this, unsigned int a2, unsigned int a3) {
    File * v3; // r8
    Process * v4; // r7
    unsigned int v5; // r6
    unsigned int v6; // r2
    signed int v7; // r4
    int v8; // r10
    bool v9; // r1
    void * v10; // r9
    unsigned int v11; // r5
    _BOOL4 v12; // r3
    bool v13; // r1
    File * v15; // [sp+0h] [bp-28h]
    unsigned int v16; // [sp+4h] [bp-24h]

    v15 = this;
    v16 = a2;
    v3 = this;
    v4 = (Process * ) a2;
    v5 = a3;
    Lock::Lock((Lock * ) & v15, (File * )((char * ) this + 48));
    if ( * ((_BYTE * ) v3 + 44)) {
      if ( * ((_DWORD * ) v3 + 10) & 1) {
        v8 = Process::CheckAddress(v4, 3 u, v6);
        if (v8) {
          v10 = (void * ) operator new(0x40000 u);
          if (ProcessImpl::IsPaused)
            v8 = 0;
          else
            ProcessImpl::Pause(ProcessImpl::IsPaused, v9);
          do {
            if (v5 >= 0x40000)
              v11 = 0x40000;
            else
              v11 = v5;
            v7 = File::Read(v3, v10, v11);
            if (v7 < 0)
              break;
            if (!Process::Patch(v4, (unsigned int) v10, (void * ) v11, 0, (void * ) v15))
              v7 = -5;
            v5 -= v11;
            v12 = v5 == 0;
            if (v7)
              v12 = 1;
            v4 = (Process * )((char * ) v4 + v11);
          }
          while (!v12);
          operator delete(v10);
          if (v8)
            ProcessImpl::Play(0, v13);
        } else {
          v7 = -4;
        }
      } else {
        v7 = -3;
      }
    } else {
      v7 = -2;
    }
    Lock::~Lock((Lock * ) & v15);
    return v7;
  }
  // B74: using guessed type _DWORD __cdecl Lock::Lock(Lock *__hidden this, Mutex *);

  //----- (0000063C) --------------------------------------------------------
  bool File::IsOpen(void) const
  {
    return _isOpen;
  }

  //----- (00000644) --------------------------------------------------------
  int ZNK18CTRPluginFramework4File11GetFullNameB5cxx11Ev(int a1, int a2) {
    int v2; // r4

    v2 = a1;
    std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::basic_string(a1, a2);
    return v2;
  }
  // BC0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);

  //----- (00000658) --------------------------------------------------------
  int ZNK18CTRPluginFramework4File7GetNameB5cxx11Ev(int a1, int a2) {
    int v2; // r5
    int v3; // r4
    int v4; // r0

    v2 = a2;
    v3 = a1;
    v4 = std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::rfind(a2, & unk_B70, -1);
    if (v4 == -1)
      std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::basic_string(v3, v2);
    else
      std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::substr(v3, v2, v4 + 1, -1);
    return v3;
  }
  // BC0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
  // BC4: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::rfind(_DWORD, _DWORD, _DWORD);
  // BC8: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD);

  //----- (000006AC) --------------------------------------------------------
  int ZNK18CTRPluginFramework4File12GetExtensionB5cxx11Ev(int a1, int a2) {
    int v2; // r5
    int v3; // r4
    int v4; // r0

    v2 = a2;
    v3 = a1;
    v4 = std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::rfind(a2, & unk_B72, -1);
    if (v4 == -1) {
      *(_DWORD * ) v3 = v3 + 8;
      *(_DWORD * )(v3 + 4) = 0;
      *(_BYTE * )(v3 + 8) = 0;
    } else {
      std::__cxx11::basic_string < char, std::char_traits < char > , std::allocator < char >> ::substr(v3, v2, v4 + 1, -1);
    }
    return v3;
  }
  // BC4: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::rfind(_DWORD, _DWORD, _DWORD);
  // BC8: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::substr(_DWORD, _DWORD, _DWORD, _DWORD);

  //----- (00000708) --------------------------------------------------------
  File * File::File(File * this) {
    File * v1; // r4

    *(_DWORD * ) this = (char * ) this + 8;
    v1 = this;
    *((_DWORD * ) this + 1) = 0;
    *((_BYTE * ) this + 8) = 0;
    *((_DWORD * ) this + 6) = 0;
    *((_DWORD * ) this + 10) = 0;
    *((_QWORD * ) this + 4) = 0 LL;
    *((_BYTE * ) this + 44) = 0;
    Mutex::Mutex((File * )((char * ) this + 48));
    return v1;
  }

  //----- (0000074C) --------------------------------------------------------
  void ** std::_Vector_base < unsigned short, std::allocator < unsigned short >> ::~_Vector_base(void ** a1) {
    void ** v1; // r4
    void * v2; // r0

    v1 = a1;
    v2 = * a1;
    if (v2)
      operator delete(v2);
    return v1;
  }

  int File::Create(const std::string & path)
  {
    int res;
    FS_Path fsPath;
    const char * str = path;
    FSPath::FSPath(str, fsPath);
    if (!fsPath)
    {
      res = FSUSER_CreateFile(_sdmcArchive, fsPath, 0, 0);
      return res & (res >> 31);
    }
    return -1;
  }

  int File::Rename(const std::string & path, const std::string & newpath); {
    int res;
    FS_Archive dstArchive;
    FS_Path dstPath, fsPath, newfsPath;
    const char * _fspath;
    const char * _newfspath;

    _fspath = path.c_str();
    FSPath::FSPath(_fspath, fsPath);
    _newfspath = newpath.c_str();
    FSPath::FSPath(_newfspath, newfsPath);
    if (!(fsPath | newfsPath))
    {
      res = FSUSER_RenameFile(_sdmcArchive, _newfspath, dstArchive, dstPath)
      return res & (res >> 31);
    }
    return -1;
  }

  int File::Remove(const std::string & path)
  {
    int res;
    FS_Path fsPath;
    const char * str = path;
    FSPath::FSPath(str, fsPath);
    if (!fsPath) {
      res = FSUSER_DeleteFile(_sdmcArchive, fsPath);
      return res & (res >> 31);
    }
    return -1;
  }

  int File::Exists(const std::string & path)
  {
    FS_Path fsPath;
    const char * str = path;
    Handle handle;
    FSPath::FSPath( & str, & fsPath);
    if (!fsPath)
      if (FSUSER_OpenFile(&handle, _sdmcArchive, fsPath, 1, 0))
        return 1;
    return -1;
  }

  int File::Open(File &output, const std::string &path, int mode)
  int File::Open(File &output, const std::string &path, int mode = READ | WRITE | SYNC)
  int File::Open(int a1, int a2, int a3)
  {
    int output; // r4
    int v4; // r8
    int v5; // r6
    int v6; // r1
    int v7; // r2
    int v8; // r7
    int res; // r5
    __int64 v10; // r8
    Handle handle; // [sp+18h] [bp-58h]
    int v14; // [sp+24h] [bp-4Ch]
    char v15; // [sp+2Ch] [bp-44h]
    char v16; // [sp+38h] [bp-38h]
    int v17; // [sp+3Ch] [bp-34h]
    int v18; // [sp+40h] [bp-30h]

    output = a1;
    v4 = a2;
    v5 = a3;
    Lock::Lock(output._mutex);
    if (output._isOpen)
      output.Close()
    v16 = v4;
    FSPath::FSPath( & v14, & v16);
    v8 = v14;
    if (v14)
      res = -1;
    else
    {
      output = v4;
      FSPath::SdmcFixPath(output);
      v10 = ;
      FSPath::operator FS_Path((int) & v16, & v14);
      res = FSUSER_OpenFile(&handle, v17, _sdmcArchive, *(_DWORD * ) & v16, v17, v18, v5 & 7, v8);
      if (res >= 0)
      {
        output._handle = handle;
        output._mode = mode;
        output._offset = 0;
        output._isOpen = true;
        if (mode & 0x10)
          FSFILE_SetSize(handle, output.GetSize());
      }
    }
    Lock::~Lock();
    return res;
  }
  // B74: using guessed type _DWORD __cdecl Lock::Lock(Lock *__hidden this, Mutex *);
  // BC0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
  // BD0: using guessed type int FSPath::FSPath(_DWORD, _DWORD);
  // BD4: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);
  // BE8: using guessed type int FSUSER_OpenFile(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
  // BEC: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD, _DWORD);
  // BF0: using guessed type int FSPath::SdmcFixPath(_DWORD);
  // BF4: using guessed type int FSFILE_SetSize(void);

  //----- (00000B00) --------------------------------------------------------
  int File::File(int a1, int a2, int a3) {
    int v3; // r4
    int v4; // r5
    int v5; // r6
    int result; // r0

    *(_DWORD * ) a1 = a1 + 8;
    v3 = a1;
    *(_DWORD * )(a1 + 4) = 0;
    *(_BYTE * )(a1 + 8) = 0;
    *(_DWORD * )(a1 + 24) = 0;
    v4 = a2;
    v5 = a3;
    *(_QWORD * )(a1 + 32) = 0 LL;
    *(_DWORD * )(a1 + 40) = 0;
    *(_BYTE * )(a1 + 44) = 0;
    Mutex::Mutex((Mutex * )(a1 + 48));
    File::Open(v3, v4, v5);
    result = v3;
    __fileHandle = * (_DWORD * )(v3 + 24);
    return result;
  }
  // 4: using guessed type int __fileHandle;

  // ALL OK, 25 function(s) have been successfully decompiled
}

u32 PrivColor::_ReadBGR8(void) {
  return b | (g) << 8) | (r << 16) | 0xFF000000;
}

u32 PrivColor::_ReadRGB565(void) {
return ((r | (g) << 8)) << 19) & 0xF80000 | 32 * (r | (u16)(g) << 8)) & 0xFC00 | g) & 0xF8 | 0xFF000000;
}

u32 PrivColor::_ReadRGB5A1(void) {
return ((r | (g) << 8)) << 18) & 0xF80000 | 32 * (r | (u16)(g) << 8)) & 0xF800 | g) & 0xF8 | 0xFF000000;
}

u32 PrivColor::_ReadRGBA4(void) {
return (g) << 12) & 0xF000 | g) & 0xF0 | ((u8)(r & 0xF0) << 16) | 0xFF000000;
}

void PrivColor::_WriteRGBA8(u8 * color) {
  a = color[3];
  b = color[2];
  g = color[1];
  r = color[0];
}

void PrivColor::_WriteBGR8(u8 * color) {
  b = color[2];
  g = color[1];
  r = color[0];
}

void PrivColor::_WriteRGB565(u8 * color) {
  g = 8 * color[1] & 0xE0 | (color[2] >> 3);
  r = BYTE1((color[0] << 8) & 0xF800 | 8 * color[1] & 0x7E0 | ((u32) color[2] >> 3));
}

void PrivColor::_WriteRGB5A1(u8 * color) {
  a = 8 * color[1] & 0x7C0 | ((int) color[2] >> 2) & 0x3E | (color[0] << 8) & 0xF800 | 1;
}

void PrivColor::_WriteRGBA4(u8 * color) {
  a = color[2] & 0xF0 | 16 * color[1] & 0xF00 | (color[0] << 8) & 0xF000 | 0xF;
}

void * Renderer::GetContext(void) {
  Thread thread = threadGetCurrent();
  void * result;
  if (thread)
    result = (void * )(thread + 1148);
  else
    result = Renderer::hookContext;
  return result;
}

u8 * PrivColor::GetFormat(void) {
  return (u8 * ) __mrc(15, 0, 13, 0, 3);
}

void PrivColor::SetFormat(u8 set) {
  u8 * format = PrivColor::GetFormat();
  format[0] = set;
  switch (set) {
  case 0:
    format[1] = _ReadRGBA8();
    format[2] = !set ? _WriteRGBA8() : _ReadRGBA8();
  case 1:
    format[1] = _ReadBGR8();
    format[2] = !set ? _WriteBGR8() : _ReadBGR8();
  case 2:
    format[1] = _ReadRGB565();
    format[2] = !set ? _WriteRGB565() : _WriteRGB565Clamp();
  case 3:
    format[1] = _ReadRGB5A1();
    format[2] = !set ? _WriteRGB5A1() : _WriteRGB5A1Clamp();
  case 4:
    format[1] = _ReadRGBA4();
    format[2] = !set ? _WriteRGBA4() : _WriteRGBA4Clamp();
  }
}

void PrivColor::UseClamp(void) {
  PrivColor::SetFormat(_ReadRGBA8);
}

bool Rect < int > ::Contains(int * a1, int a2, int a3) {
  int v3 = a1[0], v4 = a1[1], v7 = 0, v9 = 0;
  if (a1[0] < (a1[0] + a1[2])) {
    v7 = a1[0];
    v3 = a1[0] + a1[2];
  } else
    v7 = a1[0] + a1[2];
  if ((a2 >= v3) ? 0 : a2 >= v7) {
    v9 = (v4 >= v4 + a1[3]) ? v4 + a1[3] : v4;
    v4 += (v4 < v4 + a1[3]) ? a1[3] : 0;
  }
  return (((u8)((a3 >= v9 ? v4 - a3 < 0 : a3 - v9 < 0) ^ (a3 >= v9 ? __OFSUB__(v4, a3) : __OFSUB__(a3, v9))) | (a3 >= v9 ? : v4 == a3 ? a3 == v9)) ? 0 : 1);
}

void _tls_init() {
  u8 * format = __mrc(15, 0, 13, 0, 3);
  u32 value = format[1];
  if (!value) {
    *(u32 * )(format + 4) = value;
    *(u8 * )(format + 1) = 1;
    *(u32 * )(format + 8) = value;
    *(u32 * )(format + 12) = value;
    *(u32 * )(format + 16) = value;
  }
}

void PrivColor::UseClamp(u8 a1, u32 * a2) {
  u8 * format = __mrc(15, 0, 13, 0, 3);
  format[0] = a1;
  _tls_init();
  *((u32 * ) format + 1) = * a2;
  *((u32 * ) format + 2) = a2[1];
  *((u32 * ) format + 3) = a2[2];
  *((u32 * ) format + 4) = a2[3];
  PrivColor::SetFormat( * format);
}

void PrivColor::_WriteRGBA8Clamp(Renderer * a1, int a2) {
  u8 * v4 = (u8 * ) a2;
  ScreenImpl::GetPosFromAddress(Renderer::GetContext(a1)[1], (u32) a1, (int * ) & a1, & a2);
  _tls_init();
  if (Rect < int > ::Contains((int * )((char * ) & PrivColor::_ReadRGBA8 + __mrc(15, 0, 13, 0, 3)), (int) a2, a2) != 0) {
    a1[0] = v4[3];
    a1[1] = v4[2];
    a1[2] = v4[1];
    a1[3] = v4[0];
  }
}

void PrivColor::_WriteBGR8Clamp(Renderer * a1, int a2) {
  u8 * v4 = (u8 * ) a2;
  ScreenImpl::GetPosFromAddress(Renderer::GetContext(a1)[1], (u32) a1, (int * ) & a1, & a2);
  _tls_init();
  if (Rect < int > ::Contains((int * )((char * ) & PrivColor::_ReadRGBA8() + __mrc(15, 0, 13, 0, 3)), (int) a1, a2) == 0) {
    a1[0] = v4[2];
    a1[1] = v4[1];
    a1[2] = v4[0];
  }
}
}

void PrivColor::_WriteRGB5A1Clamp(Renderer * a1, int a2) {
  u8 * v4 = (u8 * ) a2;
  ScreenImpl::GetPosFromAddress(Renderer::GetContext(a1)[1], (u32) a1, (int * ) & a1, & a2);
  _tls_init();
  if (Rect < int > ::Contains((int * )((char * ) & PrivColor::_ReadRGBA8 + __mrc(15, 0, 13, 0, 3)), (int) a1, a2) != 0) {
    a1[0] = 8 * v4[1] & 0xC0 | ((int) v4[2] >> 2) & 0x3E | 1;
    a1[1] = BYTE1(8 * v4[1] & 0x7C0 | ((int) v4[2] >> 2) & 0x3E | ( * v4 << 8) & 0xF800 | 1);
  }
}

void PrivColor::_WriteRGBA4Clamp(Renderer * a1, int a2) {
  u8 * v4 = (u8 * ) a2;
  ScreenImpl::GetPosFromAddress(Renderer::GetContext(a1)[1], (u32) a1, (int * ) & a1, & a2);
  _tls_init();
  if (Rect < int > ::Contains((int * )((char * ) & PrivColor::_ReadRGBA8 + __mrc(15, 0, 13, 0, 3)), (int) a1, a2) != 0) {
    a1[0] = v4[2] & 0xF0 | 0xF;
    a1[1] = BYTE1(v4[2] & 0xF0 | 16 * v4[1] & 0xF00 | ( * v4 << 8) & 0xF000 | 0xF);
  }
}
