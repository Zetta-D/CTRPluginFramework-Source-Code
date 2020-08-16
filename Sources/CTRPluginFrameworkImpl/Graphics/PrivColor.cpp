#include "CTRPluginFrameworkImpl/Graphics/PrivColor.hpp"

namespace CTRPluginFramework {

  int PrivColor::_ReadRGBA8 = 3855618050;
  extern u8 r, g, b, a;
  extern char Renderer::hookContext[];

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

  void PrivColor::_WriteRGB565Clamp(Renderer * a1, int a2) {
    u8 * v4 = (u8 * ) a2;
    ScreenImpl::GetPosFromAddress(Renderer::GetContext(a1)[1], (u32) a1, (int * ) & a1, & a2);
    _tls_init();
    if (Rect < int > ::Contains((int * )((char * ) & PrivColor::_ReadRGBA8 + __mrc(15, 0, 13, 0, 3)), (int) a1, a2) != 0) {
      a1[0] = 8 * v4[1] & 0xE0 | (v4[2] >> 3);
      a1[1] = BYTE1(( * v4 << 8) & 0xF800 | 8 * v4[1] & 0x7E0 | ((u32) v4[2] >> 3));
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
}