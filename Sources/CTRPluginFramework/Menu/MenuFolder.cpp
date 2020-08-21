#include "CTRPluginFramework/Menu/MenuFolder.hpp"
#include "CTRPluginFrameworkImpl/Menu/MenuItem.hpp"

namespace CTRPluginFramework
{
    /* 
        ***TO DO***
    	void UseTopSeparator(Separator type = Separator::Filled) const;
    	void UseBottomSeparator(Separator type = Separator::Filled) const;
    	-> MenuFolderImpl
    */

    MenuFolder::MenuFolder(const std::string &name, const std::string &note)
    {
    	_item = std::make_unique<MenuFolder>(new MenuFolder(name, note));
    }

    MenuFolder::MenuFolder(const std::string &name, const std::vector<MenuEntry *> &entries)
    {
    	_item = std::make_unique<MenuFolder>(new MenuFolder(name, ""));
    	for(const auto &entry : entries)
    		_item->Append(entries);
    }

    MenuFolder::MenuFolder(const std::string &name, const std::string &note, const std::vector<MenuEntry *> &entries)
    {
    	_item = std::make_unique<MenuFolder>(new MenuFolder(name, note));
    	for(const auto &entry : entries)
    		_item->Append(entries);
    }

    void MenuFolder::Hide(void) const
    {
    	_item->Hide();
    }

    void MenuFolder::Show(void) const
    {
    	_item->Show();
    }

    bool MenuFolder::IsVisible(void) const
    {
    	return (_item->_isVisible >> 4) & 1; // 56
    }

    void MenuFolder::Append(MenuEntry *item) const
    {
    	_item->Append(item);
    }

    void MenuFolder::Append(MenuFolder *item) const
    {
    	_item->Append(item);
    }

    std::vector<MenuEntry *> MenuFolder::GetEntryList(void) const
    {
    	return	_item->GetEntryList();
    }

    std::vector<MenuFolder *> MenuFolder::GetFolderList(void) const
    {
    	return	_item->GetFolderList();
    }

    std::string &MenuFolder::Name(void) const
    {
    	return _item->_name; // 4
    }

    std::string &MenuFolder::Note(void) const
    {
    	return _item->_note; // 28
    }

    u32 MenuFolder::ItemsCount(void) const
    {
    	return _item->ItemsCount();
    }

    void MenuFolder::Clear(void) const
    {
    	_item->Clear();
    }

    void MenuFolder::Remove(u32 startIndex, u32 count, bool destroy) const
    {
    	_item->Remove(startIndex, count, destroy);
    }

    MenuFolder *MenuFolder::operator += (const MenuEntry *entry)
    {
    	_item->Append(entry);
    	return this;
    }

    MenuFolder *MenuFolder::operator -= (const MenuEntry *entry)
    {
    	_item->Remove(entry);
    	return this;
    }

    MenuFolder *MenuFolder::operator += (const MenuFolder *folder)
    {
    	_item->Append(folder);
    	return this;
    }

    MenuFolder *MenuFolder::operator -= (const MenuFolder *folder)
    {
    	_item->Remove(folder);
    	return this;
    }

    void MenuFolder::UseTopSeparator(Separator type = Separator::Filled) const
    {
        int v1; // r2
        char v2; // r3

        v1 = *(_DWORD *)(result + 4);
        v2 = *(_BYTE *)(v1 + 56) & 0xFE;
        if ( HIDWORD(result) )
            v2 |= 1u;
        *(_BYTE *)(v1 + 56) = v2;
        HIDWORD(result) = HIDWORD(result) == 2;
        *(_BYTE *)(*(_DWORD *)(result + 4) + 56) = *(_BYTE *)(*(_DWORD *)(result + 4) + 56) & 0xFB | 4 * BYTE4(result);
        return result;
    }

    void MenuFolder::UseBottomSeparator(Separator type = Separator::Filled) const
    {
        char v1; // r12

        v1 = BYTE4(result);
        if ( HIDWORD(result) )
            v1 = 1;
        HIDWORD(result) = HIDWORD(result) == 2;
        *(_BYTE *)(*(_DWORD *)(result + 4) + 56) = *(_BYTE *)(*(_DWORD *)(result + 4) + 56) & 0xFD | 2 * v1;
        *(_BYTE *)(*(_DWORD *)(result + 4) + 56) = *(_BYTE *)(*(_DWORD *)(result + 4) + 56) & 0xFB | 4 * BYTE4(result);
        return result;
    }
}
