#include "CTRPluginFrameworkImpl/Graphics/PrivColor.hpp"
#include "CTRPluginFrameworkImpl/Graphics/Renderer.hpp"

namespace CTRPluginFramework
{
    void Icon::DrawAbout(void)
    {
    	Icon::DrawImg(About15, 15, 15);
    }

    void Icon::DrawCapsLockOn(bool pressed)
    {
    	Icon::DrawImg(pressed ? CapsLockOnFilled15 : CapsLockOn15, 15, 15);
    }

    void Icon::DrawCentreOfGravity(void)
    {
    	Icon::DrawImg(CentreofGravity15, 15, 15);
    }

    void Icon::DrawCheckBox(bool pressed)
    {
    	Icon::DrawImg(pressed ? CheckedCheckbox : UnCheckedCheckbox, 15, 15);
    }

    void Icon::DrawClearSymbol(bool pressed)
    {
    	Icon::DrawImg(pressed ? ClearSymbolFilled15 : ClearSymbol15, 15, 15);
    }

    void Icon::DrawClipboard(bool pressed)
    {
    	Icon::DrawImg(pressed ? ClipboardFilled25 : Clipboard25, 25, 25);
    }

    void Icon::DrawClose(bool pressed)
    {
    	Icon::DrawImg(pressed ? CloseWindowFilled20 : CloseWindow20, 20, 20);
    }

    void Icon::DrawController(void)
    {
    	Icon::DrawImg(Controller15, 15, 15);
    }

    void Icon::DrawCut(bool pressed)
    {
    	Icon::DrawImg(pressed ? CutFilled25 : Cut25, 25, 25);
    }

    void Icon::DrawDuplicate(bool pressed)
    {
    	Icon::DrawImg(pressed ? DuplicateFilled25 : Duplicate25, 25, 25);
    }

    void Icon::DrawEdit(bool pressed)
    {
    	Icon::DrawImg(pressed ? EditFilled25 : Edit25, 25, 25);
    }

    void Icon::DrawEnterKey(bool pressed)
    {
    	Icon::DrawImg(pressed ? EnterKeyFilled15 : EnterKey15, 15, 15);
    }

    void Icon::DrawFolder(void)
    {
    	Icon::DrawImg(FolderFilled, 15, 15);
    }

    void Icon::DrawAddFavorite(bool pressed)
    {
    	Icon::DrawImg(pressed ? AddFavoriteFilled25 : AddFavorite25, 25, 25);
    }

    void Icon::DrawFavorite(void)
    {
    	Icon::DrawImg(Star15, 15, 15);
    }

    void Icon::DrawFile(void)
    {
    	Icon::DrawImg(File15, 15, 15);
    }

    void Icon::DrawGameController(bool pressed)
    {
    	Icon::DrawImg(pressed ? GameControllerFilled25 : GameController25, 25, 25);
    }

    void Icon::DrawGrid(void)
    {
    	Icon::DrawImg(Grid15, 15, 15);
    }

    void Icon::DrawInfo(bool pressed)
    {
    	Icon::DrawImg(pressed ? InfoFilled25 : Info25, 25, 25);
    }

    void Icon::DrawGuide(void)
    {
    	Icon::DrawImg(UserManualFilled15, 15, 15);
    }

    int Icon::DrawHandCursor(void)
    {
    	Icon::DrawImg(HandCursor15, 15, 15);
    }

    void Icon::DrawHappyFace(bool pressed)
    {
    	Icon::DrawImg(pressed ? HappyFilled15 : Happy15, 15, 15);
    }

    void Icon::DrawKeyboard(bool pressed)
    {
    	Icon::DrawImg(pressed ? KeyboardFilled25 : Keyboard25, 25, 25);
    }

    void Icon::DrawMore(void)
    {
    	Icon::DrawImg(More15, 15, 15);
    }

    void Icon::DrawPlus(bool pressed)
    {
    	Icon::DrawImg(pressed ? PlusFilled25 : Plus25, 25, 25);
    }

    void Icon::DrawRAM(void)
    {
    	Icon::DrawImg(RAM15, 15, 15);
    }

    void Icon::DrawRestart(void)
    {
    	Icon::DrawImg(Restart15, 15, 15);
    }

    void Icon::DrawRocket(void)
    {
    	Icon::DrawImg(Rocket40, 40, 40);
    }

    void Icon::DrawSave(void)
    {
    	Icon::DrawImg(Save25, 25, 25);
    }

    void Icon::DrawSearch(void)
    {
    	Icon::DrawImg(Search15, 15, 15);
    }

    void Icon::DrawSettings(void)
    {
    	Icon::DrawImg(Settings15, 15, 15);
    }

    void Icon::DrawShutdown(void)
    {
    	Icon::DrawImg(Shutdown15, 15, 15);
    }

    void Icon::DrawTools(void)
    {
    	Icon::DrawImg(Maintenance15, 15, 15);
    }

    void Icon::DrawTrash(bool pressed)
    {
    	Icon::DrawImg(pressed ? TrashFilled25 : Trash25, 25, 25);
    }

    void Icon::DrawUnsplash(void)
    {
    	Icon::DrawImg(Unsplash15, 15, 15);
    }

    // Not finish

    void Icon::DrawImg(Icon *this, u8 *a2, int a3, int a4, int a5, int a6)
    {
    	int a3; // r6
    	u8 *a2; // r4
    	Thread thread = threadGetCurrent(); // r0
    	bool v9; // zf
    	u32 *context = thread->handle ? thread->renderCtx : Renderer::hookContext; // r0
    	int v11; // r6
    	ScreenImpl **screen; // r5
    	int leftFrameBuffer; // r7
    	int frameBufferInfos; // r0
    	int v15; // r8
    	Icon *v16; // r10
    	int v17; // r11
    	int v18; // r5
    	int v19; // r9
    	unsigned int v20; // r2
    	char v21; // r1
    	bool v22; // cf
    	bool v23; // zf
    	int v24; // r3
    	int v26; // [sp+0h] [bp-58h]
    	int v27; // [sp+4h] [bp-54h]
    	int a4; // [sp+8h] [bp-50h]
    	int mrc; // [sp+Ch] [bp-4Ch]
    	Icon *this; // [sp+14h] [bp-44h]
    	char v31; // [sp+1Bh] [bp-3Dh]
    	int v32; // [sp+1Ch] [bp-3Ch]
    	unsigned int v33; // [sp+20h] [bp-38h]
    	int color; // [sp+24h] [bp-34h]
    	int v35; // [sp+28h] [bp-30h]
    	int v36; // [sp+2Ch] [bp-2Ch]

    	color = -16777216;
    	v11 = ;
    	if ( context[0] )
    	{
    		if ( context[0] != 1 )
    			return a2;
    		screen = ScreenImpl::Top;
    	}
    	else
    		screen = ScreenImpl::Bottom;
    	leftFrameBuffer = ScreenImpl::GetLeftFramebuffer(*screen, (int)a2, a3 + a5);
    	frameBufferInfos = ScreenImpl::GetFramebufferInfos(*screen, &v32, &v33, &v31);
    	LOBYTE(v27) = 0;
    	mrc = __mrc(15, 0, 13, 0, 3);
    	while ( leftFrameBuffer )
    	{
    		v15 = 0;
    		v16 = this;
    		while ( v15 < a4 )
    		{
    			v17 = 0;
    			v18 = (int)v16 + 4;
    			v19 = leftFrameBuffer + v32 * v15;
    			while ( a5 > v17 )
    			{
    				v20 = *(u8 *)(v18 - 4);
    				LOBYTE(color) = *(_BYTE *)(v18 - 1);
    				v21 = *(_BYTE *)(v18 - 2);
    				v22 = v20 >= 0x19;
    				v23 = v20 == 25;
    				HIBYTE(color) = v20;
    				BYTE1(color) = v21;
    				if ( v20 <= 0x19 )
    					v20 = v33;
    				if ( v23 || !v22 )
    					v19 += v20;
    				BYTE2(color) = *(_BYTE *)(v18 - 3);
    				if ( !v23 && v22 )
    				{
    					PrivColor::FromFramebuffer(frameBufferInfos);
    					frameBufferInfos = PrivColor::ToFramebuffer( v19, Color::Blend(color, BlendMode::Alpha));
    					v19 = frameBufferInfos;
    				}
    				++v17;
    				v18 += 4;
    			}
    			++v15;
    			v16 = (Icon *)((char *)v16 + 4 * (a5 & ~(a5 >> 31)));
    		}
    		if ( v26 == 1 )
    			v24 = ((u8)v27 ^ 1) & 1;
    		else
    			v24 = 0;
    		if ( !v24 || !ScreenImpl::Is3DEnabled(ScreenImpl::Top) )
    		{
    			a2 += a4;
    			return a2;
    		}
    		frameBufferInfos = ScreenImpl::GetRightFramebuffer(ScreenImpl::Top, (int)a2, a3 + a5);
    		leftFrameBuffer = frameBufferInfos;
    	}
    }

}
