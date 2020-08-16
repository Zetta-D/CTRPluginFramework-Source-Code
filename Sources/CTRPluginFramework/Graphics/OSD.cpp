#include "CTRPluginFramework/Graphics/OSD.hpp"

namespace CTRPluginFramework {
   
u8 *Screen::GetFramebuffer(u32 posX, u32 posY, bool useRightFb) const
{
	u32 frameBuffer;
	u32 top = IsTop ? 400 : 320;
	if (useRightFb)
	{
		if ( !IsTop || !Is3DEnabled)
			return nullptr;
		frameBuffer = RightFramebuffer;
	}
	else
		frameBuffer = LeftFramebuffer;
	if ( posX >= top )
		posX = top;
	if ( posY >= 0xF0 )
		posY = 240;
	return (u8*)(frameBuffer + BytesPerPixel * (239 - posY + (Stride / BytesPerPixel) * posX));
}

u32 Screen::Draw(const std::string &str, u32 posX, u32 posY, const Color &foreground, const Color &background) const
{
	Renderer::SetTarget();
	Renderer::DrawString(str, posX, posY, foreground, background);
	return posY + 10;
}

u32 Screen::DrawSysfont(const std::string &str, u32 posX, u32 posY, const Color &foreground) const
{
	Renderer::SetTarget();
	Renderer::DrawString(str, posX, posY, foreground);
	return posY + 16;
}

void Screen::DrawRect(u32 posX, u32 posY, u32 width, u32 height, const Color &color, bool filled) const
{
	Renderer::SetTarget();
	Renderer::DrawRect(posX, posY, width, height, color, filled, 1);
}

void Screen::DrawPixel(u32 posX, u32 posY, const Color &color) const
{
	Renderer::SetTarget();
	Renderer::DrawPixel(posX, posY, color);
}

void Screen::ReadPixel(u32 posX, u32 posY, Color &pixel, bool fromRightFb) const
{
	pixel = PrivColor::FromFramebuffer(Screen::GetFramebuffer(posX, posY, pixel, fromRightFb));
}

int OSD::Notify(const std::string &str, const Color &foreground, const Color &background)
{
	OSDImpl::Lock();
	if ( OSDImpl::Notifications[2] <= 0x31u )
	{
		OSDImpl::OSDMessage::OSDMessage(str, foreground, background);
		++OSDImpl::Notifications[2];
		OSDImpl::Unlock();
	}
	else
	{
		OSDImpl::Unlock();
		return -1;
	}
	return 0;
}

void		 OSD::Stop(OSDCallback cb)
{
	signed int i; // r0
	int *v7; // r2
	OSD *v8; // t1
	int v9; // r2

	OSDImpl::Lock(this);
	for (i = ((char *)OSDImpl::Callbacks[1] - (char *)OSDImpl::Callbacks[0]) >> 4; ; --i )
	{
		if ( i <= 0 )
			break;
		if ( (OSD *)*OSDImpl::Callbacks[0] == cb.IsTop )
			goto LABEL_6;
		if ( (OSD *)OSDImpl::Callbacks[0][1] == cb.IsTop )
		{
			OSDImpl::Callbacks[0] = OSDImpl::Callbacks[0] + 1;
			goto LABEL_6;
		}
		if ( (OSD *)OSDImpl::Callbacks[0][2] == cb.IsTop )
		{
			OSDImpl::Callbacks[0] = OSDImpl::Callbacks[0] + 2;
			goto LABEL_6;
		}
		OSDImpl::Callbacks[0] += 4;
		if ( (OSD *)OSDImpl::Callbacks[0][3] == cb.IsTop )
		{
			OSDImpl::Callbacks[0] += 3;
			goto LABEL_6;
		}
	}
	v9 = OSDImpl::Callbacks[1] - OSDImpl::Callbacks[0];
	if ( v9 != 2 )
	{
		if ( v9 != 3 )
		{
			if ( v9 != 1 )
			{
				OSDImpl::Callbacks[0] = OSDImpl::Callbacks[1];
				goto LABEL_6;
			}
			goto LABEL_21;
		}
		if ( (OSD *)*OSDImpl::Callbacks[0] == cb.IsTop )
			goto LABEL_6;
		++OSDImpl::Callbacks[0];
	}
	if ( (OSD *)*OSDImpl::Callbacks[0] == cb.IsTop )
		goto LABEL_6;
	++OSDImpl::Callbacks[0];
LABEL_21:
	if ( (OSD *)*OSDImpl::Callbacks[0] != cb.IsTop )
	{
		OSDImpl::Callbacks[0] = OSDImpl::Callbacks[1];
		goto LABEL_24;
	}
LABEL_6:
	if ( OSDImpl::Callbacks[1] != OSDImpl::Callbacks[0] )
	{
		v7 = OSDImpl::Callbacks[0] + 1;
		while ( OSDImpl::Callbacks[1] != v7 )
		{
			v8 = (OSD *)*v7;
			++v7;
			i = (signed int)v8;
			if ( v8 != cb.IsTop )
			{
				*OSDImpl::Callbacks[0] = i;
				++OSDImpl::Callbacks[0];
			}
		}
	}
LABEL_24:
	if ( OSDImpl::Callbacks[1] != OSDImpl::Callbacks[0] )
		OSDImpl::Callbacks[1] = OSDImpl::Callbacks[0];
	return OSDImpl::Unlock((OSDImpl *)i);
}


float		GetTextWidth(bool sysfont, const std::string& text)
{
	if (sysfont)
		return Renderer::GetTextSize(text);
	return Renderer::LinuxFontSize(text);
}

const Screen&		GetTopScreen(void)
{
	return OSDImpl::TopScreen;
}

const Screen&		GetBottomScreen(void)
{
	return OSDImpl::BottomScreen;
}

void OSD::SwapBuffers(void)
{
	ScreenImpl::SwapBuffer(ScreenImpl::Bottom, 1, 0);
	ScreenImpl::SwapBuffer(ScreenImpl::Top, 1, 0);
	gspWaitForEvent(GSPGPU_EVENT_VBlank0, 1);
	OSDImpl::UpdateScreens();
}

/*void std::vector<bool (*)(Screen const&),std::allocator<bool (*)(Screen const&)>>::_M_realloc_insert<bool (* const&)(Screen const&)>(_DWORD *a1, _BYTE *a2, _DWORD *a3)
{
	_BYTE *v3; // r7
	_BYTE *v4; // r10
	int v5; // r4
	int v6; // r3
	unsigned __int8 v7; // cf
	u32 v8; // r4
	_DWORD *v9; // r8
	_BYTE *v10; // r9
	_DWORD *v11; // r11
	size_t v12; // r5
	char *v13; // r6
	char *v14; // r5
	int v15; // r5

	v3 = (_BYTE *)*a1;
	v4 = (_BYTE *)a1[1];
	v5 = (signed int)&v4[-*a1] >> 2;
	if ( v5 )
		v6 = (signed int)&v4[-*a1] >> 2;
	else
		v6 = 1;
	v7 = __CFADD__(v5, v6);
	v8 = v5 + v6;
	v9 = a1;
	v10 = a2;
	v11 = a3;
	v12 = a2 - v3;
	if ( v7 || v8 > 0x3FFFFFFF )
	{
		v8 = 0x3FFFFFFF;
	}
	else if ( !v8 )
	{
		v13 = 0;
		goto LABEL_8;
	}
	v13 = (char *)operator new(4 * v8);
LABEL_8:
	*(_DWORD *)&v13[v12] = *v11;
	if ( v10 != v3 )
		memmove(v13, v3, v12);
	v14 = &v13[v12 + 4];
	if ( v10 != v4 )
		memcpy(v14, v10, v4 - v10);
	v15 = (int)&v14[v4 - v10];
	if ( v3 )
		operator delete(v3);
	*v9 = v13;
	v9[1] = v15;
	v9[2] = &v13[4 * v8];
}*/

void		 Run(OSDCallback cb) // bool(*)(const Screen &screen)
{
	OSDImpl *v3; // r0
	int *v4; // r1
	OSDImpl **v5; // r2
	OSDImpl *v6; // r12
	OSDImpl *v8; // [sp+4h] [bp-Ch]
	int v9; // [sp+8h] [bp-8h]

	v9 = a3;
	v8 = this;
	OSDImpl::Lock(this);
	v5 = (OSDImpl **)OSDImpl::Callbacks[0];
	while ( OSDImpl::Callbacks[1] != (int *)v5 )
	{
		v6 = *v5;
		++v5;
		if ( v8 == v6 )
			return OSDImpl::Unlock();
	}
	if ( OSDImpl::Callbacks[1] == OSDImpl::Callbacks[2] )
	{
		std::vector<bool (*)(Screen const&),std::allocator<bool (*)(Screen const&)>>::_M_realloc_insert<bool (* const&)(Screen const&)>(
			OSDImpl::Callbacks,
			OSDImpl::Callbacks[1],
			&v8);
	}
	else
	{
		OSDImpl::Callbacks[1] = (int)v8;
		++OSDImpl::Callbacks[1];
	}
	return OSDImpl::Unlock();
}

}
