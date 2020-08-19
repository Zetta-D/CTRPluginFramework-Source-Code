#include "CTRPluginFramework/Menu/MenuEntry.cpp"

namespace CTRPluginFramework 
{
    MenuEntry::MenuEntry(const std::string &name, const std::string &note)
    {
    	// init HotkeyManager //
    	_item = std::make_uniue<MenuEntryImpl>(new PluginMenuImpl(name, note));
    }

    MenuEntry::MenuEntry(const std::string &name, FuncPointer gameFunc, const std::string &note)
    {
    	// init HotkeyManager //
    	_item = std::make_uniue<MenuEntryImpl>(new PluginMenuImpl(name, gameFunc, note));
    }

    MenuEntry::MenuEntry(const std::string &name, FuncPointer gameFunc, FuncPointer menuFunc, const std::string &note)
    {
    	// init HotkeyManager //
    	_item = std::make_uniue<MenuEntryImpl>(new PluginMenuImpl(name, gameFunc, menuFunc, note));
    }

    MenuEntry::MenuEntry(int radioGroup, const std::string &name, FuncPointer gameFunc, const std::string &note)
    {
    	// init HotkeyManager //
    	_item = std::make_uniue<MenuEntryImpl>(new PluginMenuImpl(name, gameFunc, note));
    	_item->SetRadio(radioGroup);
    }

    MenuEntry::MenuEntry(int radioGroup, const std::string &name, FuncPointer gameFunc, FuncPointer menuFunc, const std::string &note)
    {
    	// init HotkeyManager //
    	_item = std::make_uniue<MenuEntryImpl>(new PluginMenuImpl(name, gameFunc, menuFunc, note));
    	_item->SetRadio(radioGroup);
    }

    MenuEntry::~MenuEntry()
    {
    	Hotkeys.~HotkeyManager();
    }

    void MenuEntry::Enable(void) const
    {
    	_item->Enable(); // 5 - 12
    }

    void MenuEntry::Disable(void) const
    {
    	_item->Disable(); // 5 - 16
    }

    void MenuEntry::Hide(void) const
    {
    	_item->MenuItem::Hide(_item); // 5
    }

    void MenuEntry::Show(void) const
    {
    	_item->MenuItem::Show(_item); // 5
    }

    void MenuEntry::SetRadio(int id) const
    {
    	_item->SetRadio(id);
    }

    void MenuEntry::SetArg(void *arg) const
    {
    	_item->SetArg(arg);
    }

    void *MenuEntry::SetArg(void) const
    {
    	_item->GetArg(arg);
    }

    bool MenuEntry::WasJustActivated(void) const
    {
    	return _item->WasJustActivated();
    }

    bool MenuEntry::IsActivated(void) const
    {
    	return _item->IsActivated();
    }

    bool MenuEntry::IsVisible(void) const
    {
    	return (_item->IsVisible >> 4) & 1; // 56
    }


    void MenuEntry::UseTopSeparator(Separator type) const // s64 result
    {
    	int v1; // r2
    	char v2; // r3
    	v1 = *(_DWORD *)(result + 20);
    	v2 = *(_BYTE *)(v1 + 56) & 0xFE;
    	if ( HIDWORD(result) )
    		v2 |= 1u;
    	*(_BYTE *)(v1 + 56) = v2;
    	HIDWORD(result) = HIDWORD(result) == 2;
    	*(_BYTE *)(*(_DWORD *)(result + 20) + 56) = *(_BYTE *)(*(_DWORD *)(result + 20) + 56) & 0xFB | 4 * BYTE4(result);
    	return result;
    }

    void MenuEntry::UseTopSeparator(Separator type) const // s64 result
    {
    	char v1; // r12
    	v1 = BYTE4(result);
    	if ( HIDWORD(result) )
    		v1 = 1;
    	HIDWORD(result) = HIDWORD(result) == 2;
    	*(_BYTE *)(*(_DWORD *)(result + 20) + 56) = *(_BYTE *)(*(_DWORD *)(result + 20) + 56) & 0xFD | 2 * v1;
    	*(_BYTE *)(*(_DWORD *)(result + 20) + 56) = *(_BYTE *)(*(_DWORD *)(result + 20) + 56) & 0xF7 | 8 * BYTE4(result);
    	return result;
    }

    //----- (000002B4) --------------------------------------------------------
    void MenuEntry::CanBeSelected(bool canBeSelected) const
    {
    	int v2; // r4

    	*(_BYTE *)(*(_DWORD *)(result + 20) + 100) = *(_BYTE *)(*(_DWORD *)(result + 20) + 100) & 0xF7 | 8 * ((canBeSelected ^ 1) & 1);
    	if ( !canBeSelected )
    	{
    		v2 = result;
    		result = CTRPluginFramework::MenuEntryImpl::IsActivated(*(CTRPluginFramework::MenuEntryImpl **)(result + 20));
    		if ( result )
    			result = (*(int (**)(void))(**(_DWORD **)(v2 + 20) + 16))();
    	}
    	return result;
    }

    void MenuEntry::SetGameFunc(FuncPointer func) const
    {
    	*(_DWORD *)(*(_DWORD *)(result + 20) + 68) = func;
    	return result;
    }

    void MenuEntry::SetMenuFunc(FuncPointer func) const
    {
    	*(_DWORD *)(*(_DWORD *)(result + 20) + 72) = func;
    	return result;
    }

    void		RefreshNote(void) const
    {
    	return _item->MenuItem::NoteChanged();
    }

    std::string &Name(void) const
    {
    	return *(_DWORD *)(a1 + 20) + 4;
    }

    std::string &Note(void) const
    {
    	return *(_DWORD *)(a1 + 20) + 28;
    }
}
