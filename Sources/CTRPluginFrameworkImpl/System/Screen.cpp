#include "BMPImage.hpp"
#include "Preferences.hpp"
#include "OSD.hpp"
#include "svc.h"
#include "PrivColor.hpp"
#include "vram.h"
#include "System.hpp"
#include "gspgpu.h"

namespace CTRPluginFramework
{

	class ScreenImpl
	{
	private:
		u8 _isTop; // 60
		u8 _format; // 61
		u16 _width; // 22
		u16 _height; // 23
		u32 _stride; // 12
		u32 _rowSize; // 13
		u32 _bytesPerPixel; // 14
		u16 _w22; // 22
		u32 _d10; // 10
		u32 _d7;	// 7
		u32 _d8;	// 8
        u32 _d0; // 0
        static int Top, Bottom;
	};

	char algn_1;
	_UNKNOWN _topBuf, _botBuf;
	int ScreenImpl::Top, ScreenImpl::Bottom;
	_UNKNOWN loc_140, loc_190;
	u8 _bpp[3] = { 4u, 3u, 2u }; 

	BMPImage * CreateBMP(CTRPluginFramework *this, u32 a2, u32 a3)
	{
		CTRPluginFramework *v3; // r5
		u32 v4; // r6
		BMPImage *v5; // r4
		char v6; // r7
		int v7; // r0
		char v8; // r5
		int v10; // [sp+4h] [bp-34h]
		int *v11; // [sp+8h] [bp-30h]
		int v12; // [sp+Ch] [bp-2Ch]
		int v13; // [sp+10h] [bp-28h]

		v3 = this;
		v4 = a2;
		v5 = (BMPImage *)operator new(0x34u);
		BMPImage::BMPImage(v5, (u32)v3, v4, 0);
		if ( !BMPImage::data(v5) )
		{
			v6 = SystemImpl::v6;
			if ( !SystemImpl::v6 )
			{
				Preferences::UnloadBackgrounds(0);
				BMPImage::~BMPImage(v5);
				operator delete((void *)v5);
				v5 = (BMPImage *)operator new(0x34u);
				BMPImage::BMPImage(v5, (u32)v3, v4, v6);
				v7 = BMPImage::data(v5);
				v8 = v7;
				if ( !v7 )
				{
					v11 = &v13;
					v10 = 48;
					v11 = (int *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_create(
												 &v11,
												 &v10,
												 0);
					v13 = v10;
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars();
					v12 = v10;
					*((u8 *)v11 + v10) = v8;
					OSD::Notify(&v11, &Color::White, &Color::Black);
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v11);
				}
			}
		}
		return v5;
	}

	u32 FromPhysicalToVirtual(u32 address)
	{
		if ( address - 402653184 <= 0x8000000 )
			return address + 0x7000000;
		if ( address - 0x20000000 > 0x10000000 )
			return 0;
		svcGetProcessInfo(&address, Process::GetHandle(), 20);
		if ( address == -268435456 )
			result = address + 0x10000000;
		return 0;
	}

	int	GetBPP(u32 a1)
	{
		return (a1 > 4) ? 3 : _bpp[a1];
	}

	int	ScreenImpl::ScreenImpl(int result, u32 a2, u32 a3, bool a4)
	{
		*(u32 *)result = a2;
		*(u32 *)(result + 4) = a3;
		_d8 = a2 + 120;
		_width = 0;
		_height = 0;
		_stride = 0;
		_rowSize = 0;
		_isTop = a4;
		_format = 0;
	}

	int	ScreenImpl::Initialize(ScreenImpl *this)
	{
		int result; // r0

		ScreenImpl::ScreenImpl((int)&_topBuf, 0x90400400, 0x90202204, 1);
		ScreenImpl::Top = (int)&_topBuf;
		result = ScreenImpl::ScreenImpl((int)&_botBuf, 0x90400500, 0x90202A04, 0);
		ScreenImpl::Bottom = (int)&_botBuf;
		return result;
	}

	int	ScreenImpl::Fade(ScreenImpl *this, float a2, int a3)
	{
		int v3; // r1
		signed int v4; // r3
		int v5; // r5
		signed int v6; // r4
		int result; // r0
		int v8; // r6
		int ( *v9)(int, int); // r7
		double v10; // r2
		int v11; // r0
		int v12; // [sp+4h] [bp-24h]

		if ( _d10 )
			v4 = 8;
		else
			v4 = 12;
		v5 = *(u32 *)((char *)this + v4 + 4);
		v6 = _stride * _w22 / _bytesPerPixel);
		result = PrivColor::SetFormat(_format, v3, a3);
		v8 = __mrc(15, 0, 13, 0, 3);
		while ( v6 > 0 )
		{
			if ( &ZTHN18CTRPluginFramework9PrivColor13ToFramebufferE )
				result = ZTHN18CTRPluginFramework9PrivColor13ToFramebufferE(result);
			v9 = *(int ( **)(int, int))((char *)&PrivColor::ToFramebuffer + v8);
			if ( &ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE )
				ZTHN18CTRPluginFramework9PrivColor15FromFramebufferE(result);
			--v6;
			v12 = (*(int ( **)(int))((char *)&PrivColor::FromFramebuffer + v8))(v5);
			v11 = Color::Fade((Color *)&v12, v10);
			result = v9(v5, v11);
			v5 = result;
		}
		return result;
	}

	signed int	ScreenImpl::Acquire(ScreenImpl *this, u32 a2)
	{
		u32 *v2; // r5
		int v3; // r7
		int v4; // r6
		u32 v5; // r7
		u32 v6; // r6
		ScreenImpl *v7; // r4
		u32 v8; // r3
		u32 v9; // r2
		u8 *v10; // r2
		u32 v11; // r0
		int v12; // r0
		int v13; // r1
		int v14; // r3
		u32 *v15; // r5
		CTRPluginFramework *v16; // r0
		signed int v17; // r3
		int v18; // r0
		signed int v19; // r3

		v2 = *(u32 **)this;
		v3 = *(u32 *)(*(u32 *)this + 104);
		_d7 = v3;
		v4 = v2[27];
		v5 = v3 | 0x80000000;
		_d8 = v4;
		v6 = v4 | 0x80000000;
		if ( v5 == v6 )
			return 1;
		v7 = this;
		_d10 = **((u32 **)this + 2) & 1;
		v8 = v2[28] & 7;
		if ( v8 > 4 )
			a2 = 3;
		_format = v8;
		v9 = v2[23];
		_height = v9;
		v10 = (u8 *)(v9 >> 16);
		_w22 = (u16)v10;
		if ( v8 <= 4 )
			v10 = _bpp;
		v11 = v2[36];
		if ( v8 <= 4 )
			a2 = v10[v8];
		_stride = v11;
		_bytesPerPixel = a2;
		v12 = v11 / a2;
		v14 = _isTop;
		_rowSize = v12;
		*((u32 *)v7 + 3) = v5;
		*((u32 *)v7 + 4) = v6;
		if ( v14 )
		{
			*((u32 *)v7 + 5) = v5;
			*((u32 *)v7 + 6) = v6;
			v2[37] = v2[26];
			*(u32 *)(*(u32 *)v7 + 152) = *(u32 *)(*(u32 *)v7 + 108);
		}
		v15 = (u32 *)(_stride * _w22);
		if ( !*((u32 *)v7 + 9) )
		{
			v16 = (CTRPluginFramework *)vramAlloc(_stride * _w22, v13);
			*((u32 *)v7 + 9) = v16;
			if ( v16 )
			{
				if ( _d10 )
					v17 = 8;
				else
					v17 = 12;
				memcpy32(v16, *(u32 **)((char *)v7 + v17 + 4), v15, (u32)v7 + v17);
			}
		}
		v18 = _d10;
		if ( v18 )
			v19 = 8;
		else
			v19 = 12;
		memcpy32(
			*((CTRPluginFramework **)v7 + v18 + 3),
			*(u32 **)((char *)v7 + v19 + 4),
			v15,
			(u32)v7 + v19);
		return 0;
	}

	u32	ScreenImpl::Acquire(ScreenImpl *this, int a2, u32 a3, u32 a4, u32 a5, bool a6)
	{
		u32 v6; // r6
		u32 *v7; // r5
		u8 *v8; // r3
		u32 v9; // r1
		bool v10; // cf
		bool v11; // zf
		ScreenImpl *v12; // r4
		u32 result; // r0
		int v14; // r1
		u32 *v15; // r1
		u32 v16; // r2
		u32 v17; // r2

		v6 = a4;
		v7 = (u32 *)a2;
		v8 = (u8 *)&algn_1;
		_d10 = 1;
		v9 = a5 & 7;
		v10 = v9 >= 4;
		v11 = v9 == 4;
		_format = v9;
		if ( v9 <= 4 )
			v8 = _bpp;
		else
			v9 = 3u;
		v12 = this;
		if ( v11 || !v10 )
			v9 = v8[v9];
		_stride = v6;
		*((u32 *)_bytesPerPixel) = v9;
		result = v6 / v9;
		v14 = *(u32 *)v12;
		_rowSize = result;
		*((u32 *)v12 + 3) = v7;
		*((u32 *)v12 + 5) = a3;
		v15 = (u32 *)((v14 + 92) | 0x80000000);
		v16 = *v15;
		_height = *v15;
		v17 = v16 >> 16;
		_w22 = v17;
		if ( a6 )
		{
			result = *((u32 *)v12 + 9);
			if ( result )
				result = (u32)memcpy32(		 (CTRPluginFramework *)result,		 v7,		 (u32 *)(v6 * v17),		 (u32)v8);
		}
		return result;
	}

	char * ScreenImpl::Copy(ScreenImpl *this)
	{
		int v1; // r3
		u32 **v2; // r1
		u32 v3; // r3

		v1 = _d10;
		v2 = (u32 **)((char *)this + 4 * v1);
		if ( v1 )
			v3 = 8;
		else
			v3 = 12;
		return memcpy32(
						 *(CTRPluginFramework **)((char *)this + v3 + 4),
						 v2[3],
						 (u32 *)(_stride * _w22),
						 v3);
	}

	int	ScreenImpl::IsTopScreen(ScreenImpl *this)
	{
		return _isTop;
	}

	int	ScreenToBMP_BGR8(int result, Pixel *a2, u32 a3, u8 *a4, u32 a5, u32 a6)
	{
		u32 v6; // r5
		int v7; // r1
		int v8; // lr
		u8 *v9; // r4
		u8 *v10; // r12
		char v11; // r7

		v6 = a3 + 720;
		v7 = 3 * ((u32)a2 + (u32)a4);
		while ( a3 != v6 )
		{
			v8 = result;
			v9 = a4;
			v10 = (u8 *)a3;
			while ( 1 )
			{
				v8 += 3;
				if ( !v9 )
					break;
				--v9;
				*(u8 *)(v8 - 3) = *v10;
				*(u8 *)(v8 - 2) = v10[1];
				v11 = v10[2];
				v10 += a5;
				*(u8 *)(v8 - 1) = v11;
			}
			a3 += 3;
			result += v7;
		}
		return result;
	}

	int	ScreenToBMP_RGBA8(int result, Pixel *a2, u32 a3, u8 *a4, u32 a5, u32 a6)
	{
		u32 v6; // r5
		int v7; // r1
		u8 *v8; // r12
		int v9; // lr
		u8 *v10; // r4
		char v11; // r7

		v6 = a3 + 960;
		v7 = 3 * ((u32)a2 + (u32)a4);
		while ( a3 != v6 )
		{
			v8 = (u8 *)a3;
			v9 = result;
			v10 = a4;
			while ( 1 )
			{
				v9 += 3;
				if ( !v10 )
					break;
				--v10;
				*(u8 *)(v9 - 3) = v8[1];
				*(u8 *)(v9 - 2) = v8[2];
				v11 = v8[3];
				v8 += a5;
				*(u8 *)(v9 - 1) = v11;
			}
			a3 += 4;
			result += v7;
		}
		return result;
	}

	int	ScreenToBMP_RGB565(int result, Pixel *a2, u32 a3, u8 *a4, u32 a5, u32 a6)
	{
		u32 v6; // r6
		int v7; // r1
		int v8; // lr
		u8 *v9; // r7
		u16 *v10; // r8
		int v11; // t1

		v6 = a3 + 480;
		v7 = 3 * ((u32)a2 + (u32)a4);
		while ( a3 != v6 )
		{
			v8 = result;
			v9 = a4;
			v10 = (u16 *)a3;
			while ( 1 )
			{
				v8 += 3;
				if ( !v9 )
					break;
				v11 = *v10;
				v10 = (u16 *)((char *)v10 + (a5 & 0xFFFFFFFE));
				--v9;
				*(u8 *)(v8 - 3) = 8 * v11;
				*(u8 *)(v8 - 2) = (v11 >> 3) & 0xFC;
				*(u8 *)(v8 - 1) = BYTE1(v11) & 0xF8;
			}
			a3 += 2;
			result += v7;
		}
		return result;
	}

	int	ScreenToBMP_RGB5A1(int result, Pixel *a2, u32 a3, u8 *a4, u32 a5, u32 a6)
	{
		u32 v6; // r7
		int v7; // r1
		int v8; // lr
		u8 *v9; // r4
		u16 *v10; // r8
		int v11; // t1

		v6 = a3 + 480;
		v7 = 3 * ((u32)a2 + (u32)a4);
		while ( a3 != v6 )
		{
			v8 = result;
			v9 = a4;
			v10 = (u16 *)a3;
			while ( 1 )
			{
				v8 += 3;
				if ( !v9 )
					break;
				v11 = *v10;
				v10 = (u16 *)((char *)v10 + (a5 & 0xFFFFFFFE));
				--v9;
				*(u8 *)(v8 - 3) = 4 * v11 & 0xF8;
				*(u8 *)(v8 - 2) = (v11 >> 3) & 0xF8;
				*(u8 *)(v8 - 1) = BYTE1(v11) & 0xF8;
			}
			a3 += 2;
			result += v7;
		}
		return result;
	}

	int	ScreenToBMP_RGBA4(int result, Pixel *a2, u32 a3, u8 *a4, u32 a5, u32 a6)
	{
		u32 v6; // r6
		int v7; // r1
		int v8; // lr
		u8 *v9; // r7
		u16 *v10; // r8
		int v11; // t1

		v6 = a3 + 480;
		v7 = 3 * ((u32)a2 + (u32)a4);
		while ( a3 != v6 )
		{
			v8 = result;
			v9 = a4;
			v10 = (u16 *)a3;
			while ( 1 )
			{
				v8 += 3;
				if ( !v9 )
					break;
				v11 = *v10;
				v10 = (u16 *)((char *)v10 + (a5 & 0xFFFFFFFE));
				--v9;
				*(u8 *)(v8 - 3) = v11 & 0xF0;
				*(u8 *)(v8 - 2) = (v11 >> 4) & 0xF0;
				*(u8 *)(v8 - 1) = BYTE1(v11) & 0xF0;
			}
			a3 += 2;
			result += v7;
		}
		return result;
	}

	Pixel * ScreenImpl::ScreenToBMP(ScreenImpl *this, Pixel *a2, u32 a3)
	{
		ScreenImpl *v3; // r3
		Pixel *result; // r0
		u32 v5; // r12
		u32 v6; // r2
		signed int v7; // r2
		Pixel *v8; // r1
		int v9; // r12
		Pixel *v10; // [sp+4h] [bp-Ch]

		v10 = a2;
		v3 = this;
		result = a2;
		if ( a2 )
		{
			v5 = a3;
			v6 = *((u32 *)v3 + 9);
			if ( !v6 )
			{
				if ( _d10 )
					v7 = 8;
				else
					v7 = 12;
				v6 = *(u32 *)((char *)v3 + v7 + 4);
			}
			v8 = (Pixel *)v5;
			v9 = _format;
			if ( _format )
			{
				switch ( v9 )
				{
					case 1:
						result = (Pixel *)ScreenToBMP_BGR8(		(int)result,		v8,		v6,		(u8 *)_w22,		_stride,		(u32)v10);
						break;
					case 2:
						result = (Pixel *)ScreenToBMP_RGB565(		(int)result,		v8,		v6,		(u8 *)_w22,		_stride,		(u32)v10);
						break;
					case 3:
						result = (Pixel *)ScreenToBMP_RGB5A1(		(int)result,		v8,		v6,		(u8 *)_w22,		_stride,		(u32)v10);
						break;
					case 4:
						result = (Pixel *)ScreenToBMP_RGBA4(		(int)result,		v8,		v6,		(u8 *)_w22,		_stride,		(u32)v10);
						break;
				}
			}
			else
			{
				result = (Pixel *)ScreenToBMP_RGBA8((int)result,v8,v6,(u8 *)_w22,_stride,(u32)v10);
			}
		}
		return result;
	}

	BMPImage * ScreenImpl::Screenshot(ScreenImpl *this, int a2, BMPImage *a3)
	{
		BMPImage *v3; // r4
		int v4; // r5
		Pixel *v5; // r1
		ScreenImpl *v6; // r0
		int v8; // r6

		v3 = (BMPImage *)a2;
		if ( this == (ScreenImpl *)&algn_1 )
		{
			if ( !a2 )
				v3 = CreateBMP((CTRPluginFramework *)&loc_190, 0xF0u, (u32)a3);
			v4 = ScreenImpl::Top;
	LABEL_5:
			v5 = (Pixel *)BMPImage::data(v3);
			v6 = (ScreenImpl *)v4;
			goto LABEL_6;
		}
		if ( this == (ScreenImpl *)2 )
		{
			if ( !a2 )
				v3 = CreateBMP((CTRPluginFramework *)&loc_140, 0xF0u, (u32)a3);
			v4 = ScreenImpl::Bottom;
			goto LABEL_5;
		}
		if ( !a2 )
			v3 = CreateBMP((CTRPluginFramework *)&loc_190, 0x1E0u, (u32)a3);
		v8 = BMPImage::data(v3);
		ScreenImpl::ScreenToBMP(
			(ScreenImpl *)ScreenImpl::Bottom,
			(Pixel *)(v8 + 120),
			0x50u);
		v5 = (Pixel *)(v8 + 288000);
		v6 = (ScreenImpl *)ScreenImpl::Top;
	LABEL_6:
		ScreenImpl::ScreenToBMP(v6, v5, 0);
		return v3;
	}

	int	ScreenImpl::Is3DEnabled(ScreenImpl *this)
	{
		int v1; // r3
		char *v2; // r0
		int v3; // r3
		int v4; // r0
		bool v5; // zf

		v1 = *((u8 *)_isTop);
		if ( *((u8 *)_isTop) )
		{
			v2 = (char *)this + 4 * (_d10 == 0);
			v3 = *((u32 *)v2 + 5);
			v4 = *((u32 *)v2 + 3);
			v5 = v4 == v3;
			if ( v4 != v3 )
				v5 = v3 == 0;
			if ( v5 )
				v1 = 0;
			else
				v1 = MEMORY[0x1FF81080] > 0.0;
		}
		return v1;
	}

	void ScreenImpl::Flush(void) const
	{
		u32 size = _stride * _w22;
		svcFlushProcessDataCache(Process::GetHandle(), _d0 + *(_d10 + 3), size);
		svcFlushProcessDataCache(Process::GetHandle(), *(u32 *)(_d0 + (_d10 ? 8 : 12) + 4), size);
		if ( ScreenImpl::Is3DEnabled() )
		{
			svcFlushProcessDataCache(Process::GetHandle(), _d0 + _d10 + 5, size);
			svcFlushProcessDataCache(Process::GetHandle(), *(u32 *)(_d0 + (_d10 ? 16 : 20) + 4), size);
		}
	}

	Process * ScreenImpl::Invalidate(ScreenImpl *this)
	{
		ScreenImpl *v1; // r4
		int v2; // r5
		int v3; // r0
		Process *v4; // r0
		int v5; // r0
		signed int v6; // r3
		Process *result; // r0
		int v8; // r0
		Process *v9; // r0
		int v10; // r0
		signed int v11; // r3

		v1 = this;
		v2 = _stride * _w22;
		v3 = Process::GetHandle(this);
		v4 = (Process *)svcInvalidateProcessDataCache(v3, *((u32 *)v1 + *(_d10 + 3), v2);
		v5 = Process::GetHandle(v4);
		if ( _d10 )
			v6 = 8;
		else
			v6 = 12;
		svcInvalidateProcessDataCache(v5, *(u32 *)((char *)v1 + v6 + 4), v2);
		result = (Process *)ScreenImpl::Is3DEnabled(v1);
		if ( result )
		{
			v8 = Process::GetHandle(result);
			v9 = (Process *)svcInvalidateProcessDataCache(v8,*((u32 *)v1 + _d10 + 5),v2);
			v10 = Process::GetHandle(v9);
			if ( _d10 )
				v11 = 16;
			else
				v11 = 20;
			result = (Process *)svcInvalidateProcessDataCache(v10, *(u32 *)((char *)v1 + v11 + 4), v2);
		}
		return result;
	}

	int	ScreenImpl::Flash(ScreenImpl *this, Color *a2)
	{
		ScreenImpl *v2; // r6
		signed int v3; // r4
		int v4; // r5
		int result; // r0

		v2 = this;
		v3 = 100;
		v4 = Color::ToU32(a2) & 0xFFFFFF | 0x1000000;
		do
		{
			**((u32 **)v2 + 1) = v4;
			result = svcSleepThread(5000000);
			--v3;
		}
		while ( v3 );
		**((u32 **)v2 + 1) = 0;
		return result;
	}

	Process * ScreenImpl::Clean(ScreenImpl *this)
	{
		Process *result; // r0
		u32 *v2; // r5
		u32 *v3; // r5

		result = (Process *)System::v6(this);
		if ( result )
		{
			__mcr(15, 0, 0, 7, 10, 4);
			v2 = *(u32 **)(ScreenImpl::Top + 36);
			if ( v2 )
			{
				memcpy32(
					*(CTRPluginFramework **)(ScreenImpl::Top + 12),
					*(u32 **)(ScreenImpl::Top + 36),
					(u32 *)(*(u32 *)(ScreenImpl::Top + 48)
												 * *(u16 *)(ScreenImpl::Top + 44)),
					ScreenImpl::Top);
				memcpy32(
					*(CTRPluginFramework **)(ScreenImpl::Top + 16),
					v2,
					(u32 *)(*(u32 *)(ScreenImpl::Top + 48)
												 * *(u16 *)(ScreenImpl::Top + 44)),
					ScreenImpl::Top);
			}
			v3 = *(u32 **)(ScreenImpl::Bottom + 36);
			if ( v3 )
			{
				memcpy32(
					*(CTRPluginFramework **)(ScreenImpl::Bottom + 12),
					*(u32 **)(ScreenImpl::Bottom + 36),
					(u32 *)(*(u32 *)(ScreenImpl::Bottom + 48)
												 * *(u16 *)(ScreenImpl::Bottom + 44)),
					ScreenImpl::Bottom);
				memcpy32(
					*(CTRPluginFramework **)(ScreenImpl::Bottom + 16),
					v3,
					(u32 *)(*(u32 *)(ScreenImpl::Bottom + 48)
												 * *(u16 *)(ScreenImpl::Bottom + 44)),
					ScreenImpl::Bottom);
			}
			ScreenImpl::Flush((ScreenImpl *)ScreenImpl::Top);
			result = ScreenImpl::Flush((ScreenImpl *)ScreenImpl::Bottom);
		}
		return result;
	}

	char * ScreenImpl::SwapBuffer(ScreenImpl *this, bool a2, int a3)
	{
		ScreenImpl *v3; // r4
		signed int v4; // r3
		int v5; // r5
		char *result; // r0
		bool v7; // zf
		u32 *v8; // r3
		u32 v9; // r1
		u32 v10; // r1
		signed int v11; // r0

		v3 = this;
		if ( _d10 )
			v4 = 8;
		else
			v4 = 12;
		v5 = a3;
		result = (char *)svcFlushDataCacheRange(
											 *(u32 *)((char *)this + v4 + 4),
											 _stride * _w22);
		v7 = _d10 == 0;
		_d10 = v7;
		v8 = (u32 *)*((u32 *)v3 + 2);
		v9 = *v8;
		if ( v7 )
			v10 = v9 | 1;
		else
			v10 = v9 & 0xFFFFFFFE;
		*v8 = v10;
		if ( _isTop )
		{
			*(u32 *)(*(u32 *)v3 + 104) = _d7;
			*(u32 *)(*(u32 *)v3 + 108) = _d8;
			*(u32 *)(*(u32 *)v3 + 148) = *(u32 *)(*(u32 *)v3 + 104);
			*(u32 *)(*(u32 *)v3 + 152) = *(u32 *)(*(u32 *)v3 + 108);
			if ( !v5 )
				return result;
			if ( _isTop )
			{
				v11 = 3;
	LABEL_12:
				gspWaitForEvent(v11, 1);
				return ScreenImpl::Copy(v3);
			}
	LABEL_11:
			v11 = 2;
			goto LABEL_12;
		}
		if ( v5 )
			goto LABEL_11;
		return result;
	}

	char * ScreenImpl::ApplyFading(ScreenImpl *this, int a2, int a3)
	{
		int v3; // r2

		ScreenImpl::Fade((ScreenImpl *)ScreenImpl::Top, 0.0, a3);
		ScreenImpl::Fade(
			(ScreenImpl *)ScreenImpl::Bottom,
			0.0,
			v3);
		__mcr(15, 0, 0, 7, 10, 4);
		ScreenImpl::SwapBuffer(
			(ScreenImpl *)ScreenImpl::Top,
			1,
			1);
		return ScreenImpl::SwapBuffer(
						 (ScreenImpl *)ScreenImpl::Bottom,
						 1,
						 1);
	}

	u16	ScreenImpl::GetFormat(void) const
	{
		return _format;
	}

	u16	ScreenImpl::GetWidth(void) const
	{
		return _width;
	}

	u16	ScreenImpl::GetHeight(void) const
	{
		return _height;
	}

	u32	ScreenImpl::GetStride(void) const
	{
		return _stride;
	}

	u32	ScreenImpl::GetRowSize(void) const
	{
		return _rowSize;
	}

	u32	ScreenImpl::GetBytesPerPixel(void) const 
	{
		return _bytesPerPixel;
	}

	int	ScreenImpl::GetFramebufferSize(ScreenImpl *this)
	{
		return _stride * _w22);
	}

	int	ScreenImpl::GetFramebufferInfos(int result, u32 *a2, u32 *a3, u8 &format)
	{
		*a2 = *(u32 *)(result + 48);
		*a3 = *(u32 *)(result + 56);
		format = _format;
		return result;
	}

	int	ScreenImpl::GetLeftFramebuffer(int a2)
	{
		int v2; // r3

		v2 = _d10;
		if ( !a2 )
			v2 = v2 == 0;
		return *((u32 *)this + v2 + 3);
	}

	int	ScreenImpl::GetLeftFramebuffer(ScreenImpl *this, int a2, int a3)
	{
		int v3; // r1
		int v6; // r1
		signed int v7; // r3

        int top = _isTop ? 400 : 320;
		int v3 = a2 & ~(a2 >> 31);
        int height = a3 & ~(a3 >> 31) >= 240 : 240 : a3 & ~(a3 >> 31);
		if ( top >= v3 )
			top = v3;
		return *(u32 *)((char *)this + (_d10 ? 8 : 12) + 4) + _bytesPerPixel * (239 - height + _rowSize * top);
	}

	int	ScreenImpl::GetRightFramebuffer(bool useRightFb)
	{
		int v2;
		if (!_isTop)
			return _isTop;
		return *((u32 *)this + (!useRightFb ? _d10 == 0 : _d10) + 5);
	}

	u32	ScreenImpl::GetRightFramebuffer(u16 width, u16 height)
	{
		if ( !_isTop) ) return _isTop;
		return *(u32 *)((u8*)this + (_d10 ? 16 : 20) + 4) + _bytesPerPixel * (239 - (height & ~(height >> 31) >= 240 ? 240 : height & ~(height >> 31)) 
        + _rowSize * (width & ~(width >> 31) >= 400 ? 400 : width & ~(width >> 31)));
	}

	int	ScreenImpl::GetPosFromAddress(u32 address, int *a3, int *a4)
	{
		u32 v6;
		int v7;
		int v8;
		int result;
		v6 = address - *(u32 *)((char *)this + (_d10 ? 8 : 12) + 4);
		v7 = v6 / (_bytesPerPixel * _rowSize);
		*a3 = v7;
		v8 = _rowSize - 1 + _rowSize * v7 - v6 / _bytesPerPixel;
		*a4 = v8;
		result = 240 - _rowSize + v8;
		*a4 = result;
		return result;
	}

}
