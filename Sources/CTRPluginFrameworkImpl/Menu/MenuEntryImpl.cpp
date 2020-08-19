#include "CTRPluginFrameworkImpl/Menu/MenuEntryImpl.hpp"

namespace CTRPluginFramework
{

	_DWORD (*off_490[2])(MenuItem *__hidden this) =
	{
		&MenuItem::~MenuItem,
		&MenuItem::~MenuItem
	}; // weak
	_DWORD (*off_4A4[2])(MenuEntryImpl *__hidden this) =
	{
		&MenuEntryImpl::~MenuEntryImpl,
		&MenuEntryImpl::~MenuEntryImpl
	}; // weak
	_UNKNOWN unk_4B8; // weak
	// extern _UNKNOWN MenuItem::_uidCounter; weak


	class MenuItem
	{
	private:
		std::string note; // 28
	};

	class MenuEntryImpl
	{

	private:
		MenuEntry *menuEntry; //27
		u32 _id; // 112
		u8 _flags; // 100
		void *_arg; // 116

		std::string str; // 76
	};

	std::string MenuItem::GetNote(void) const
	{
		return note;
	}

	void MenuEntryImpl::Disable(int result) const
	{
		_flags = _flags & 0xFC | 2;
	}

	MenuItem::~MenuItem() { } // delete strings

	MenuEntryImpl::~MenuEntryImpl()
	{
		MenuItem::~MenuItem();
	}

	int MenuEntryImpl::GetNote(HotkeyManager **a1)
	{
		MenuItem *v1; // r4
		HotkeyManager *v2; // r0
		unsigned int v4; // r3
		unsigned int v5; // r2
		unsigned int v6; // r2
		int v7; // r0
		int v8; // [sp+0h] [bp-58h]
		int *v9; // [sp+18h] [bp-40h]
		int v10; // [sp+1Ch] [bp-3Ch]
		unsigned int v11; // [sp+20h] [bp-38h]
		int *v12; // [sp+30h] [bp-28h]
		int v13; // [sp+34h] [bp-24h]
		unsigned int v14; // [sp+38h] [bp-20h]

		v1 = (MenuItem *)a1;
		v2 = a1[27];
		if ( !v2 || !HotkeyManager::Count(v2) )
			return (int)v1 + 28;
		if ( !*((_DWORD *)v1 + 20) || MenuItem::HasNoteChanged(v1) )
		{
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v9, (char *)v1 + 28);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v9, &unk_4B8);
			ZN18CTRPluginFramework13HotkeyManager8ToStringB5cxx11Ev(&v12, *((_DWORD *)v1 + 27));
			v4 = v10 + v13;
			if ( v9 == (int *)&v11 )
				v5 = 15;
			else
				v5 = v11;
			if ( v4 <= v5 || (v12 != (int *)&v14 ? (v6 = v14) : (v6 = 15), v4 > v6) )
				v7 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::append(&v9, &v12);
			else
				v7 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::insert(&v12, 0, &v9);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(&v8, v7);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::operator=((char *)v1 + 76, &v8);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v8);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v12);
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v9);
		}
		return (int)v1 + 76;
	}

	int MenuEntryImpl::MenuEntryImpl(int a1, int a2, int a3, int a4)
	{
		int v4; // r4
		int v5; // r6
		__int16 v6; // r12
		char v7; // r2

		v4 = a1;
		v5 = a4;
		*(_DWORD *)a1 = off_490;
		*(_DWORD *)(v4 + 4) = v4 + 12;
		*(_DWORD *)(v4 + 28) = v4 + 36;
		*(_DWORD *)(a1 + 52) = ++MenuItem::_uidCounter;
		v6 = *(_WORD *)(a1 + 56);
		*(_DWORD *)(a1 + 8) = 0;
		*(_WORD *)(a1 + 56) = (unsigned __int8)(v6 & 0x80) | 0x110;
		*(_BYTE *)(a1 + 12) = 0;
		*(_DWORD *)(a1 + 32) = 0;
		*(_BYTE *)(a1 + 36) = 0;
		*(_DWORD *)(a1 + 60) = 0;
		*(_DWORD *)(a1 + 64) = 0;
		*(_DWORD *)a1 = off_4A4;
		*(_DWORD *)(v4 + 76) = v4 + 84;
		*(_DWORD *)(a1 + 80) = 0;
		*(_BYTE *)(a1 + 84) = 0;
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(a1 + 4);
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v4 + 28);
		v7 = *(_BYTE *)(v4 + 100);
		*(_DWORD *)(v4 + 68) = 0;
		*(_DWORD *)(v4 + 72) = 0;
		*(_DWORD *)(v4 + 116) = 0;
		*(_DWORD *)(v4 + 104) = -1;
		*(_BYTE *)(v4 + 100) = v7 & 0xF0;
		*(_DWORD *)(v4 + 112) = -1;
		*(_DWORD *)(v4 + 108) = v5;
		return v4;
	}
	// 490: using guessed type _DWORD (*off_490[2])(MenuItem *__hidden this);
	// 4A4: using guessed type _DWORD (*off_4A4[2])(MenuEntryImpl *__hidden this);
	// 4E8: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(_DWORD);

	//----- (00000290) --------------------------------------------------------
	int MenuEntryImpl::MenuEntryImpl(int a1, int a2, int a3, int a4, int a5)
	{
		int v5; // r4
		int v6; // r6
		__int16 v7; // r12
		char v8; // r3

		v5 = a1;
		*(_DWORD *)a1 = off_490;
		*(_DWORD *)(v5 + 4) = v5 + 12;
		*(_DWORD *)(v5 + 28) = v5 + 36;
		v6 = a3;
		*(_DWORD *)(a1 + 52) = ++MenuItem::_uidCounter;
		v7 = *(_WORD *)(a1 + 56);
		*(_DWORD *)(a1 + 8) = 0;
		*(_WORD *)(a1 + 56) = (unsigned __int8)(v7 & 0x80) | 0x110;
		*(_BYTE *)(a1 + 12) = 0;
		*(_DWORD *)(a1 + 32) = 0;
		*(_BYTE *)(a1 + 36) = 0;
		*(_DWORD *)(a1 + 60) = 0;
		*(_DWORD *)(a1 + 64) = 0;
		*(_DWORD *)a1 = off_4A4;
		*(_DWORD *)(v5 + 76) = v5 + 84;
		*(_DWORD *)(a1 + 80) = 0;
		*(_BYTE *)(a1 + 84) = 0;
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(a1 + 4);
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_assign(v5 + 28);
		v8 = *(_BYTE *)(v5 + 100);
		*(_DWORD *)(v5 + 68) = v6;
		*(_BYTE *)(v5 + 100) = v8 & 0xF0;
		*(_DWORD *)(v5 + 72) = 0;
		*(_DWORD *)(v5 + 116) = 0;
		*(_DWORD *)(v5 + 104) = -1;
		*(_DWORD *)(v5 + 112) = -1;
		*(_DWORD *)(v5 + 108) = a5;
		return v5;
	}

	void MenuEntryImpl::SetRadio(int id) const
	{
		_id = id;
		_flags |= 4;
	}

	void MenuEntryImpl::SetArg(void *arg) const
	{
		_arg = arg;
	}

	int MenuEntryImpl::GetArg(MenuEntryImpl *this)
	{
		return *((_DWORD *)this + 29);
	}

	bool MenuEntryImpl::WasJustActivated(void) const
	{
		bool result = flags & 1;
		if (result)
			result = (flags >> 1) & 1;
		return result;
	}

	bool MenuEntryImpl::IsActivated(void) const
	{
		return flags & 1;
	}

	MenuEntry *MenuEntryImpl::AsMenuEntry(void)
	{
		return menuEntry;
	}

	int MenuEntryImpl::_TriggerState(int result)
	{
		u8 f(_flags & 0xFC);
		if ( (_flags & 1) == 0 )
			f |= 3u;
		else
			_flags = f;
		if ( (_flags & 1) == 0 )
			_flags = f;
		else
			result = 0;
		if ( (_flags & 1) == 0 )
			result = 1;
		return result;
	}

	//----- (000003D4) --------------------------------------------------------
	int MenuEntryImpl::Enable(int result)
	{
		MenuEntryImpl *v1; // r1
		PluginMenuExecuteLoop *v2; // r2

		if ( !(_flags & 1) )
		{
			result = MenuEntryImpl::_TriggerState(result);
			if ( *((_DWORD *)v2 + 17) )
				result = PluginMenuExecuteLoop::Add(v2, v1);
		}
		return result;
	}

	bool MenuEntryImpl::_MustBeRemoved(void) const
	{
		return _flags & 1 ? false : (_flags >> 1) & 1 ^ 1;
	}

	int MenuEntryImpl::_Execute(void)
	{
		int v2; // r6
		int v3; // r4

		// run menuEntry
		if ( !(_flags & 1) )
		{
			if ( (_flags & 1) | ((_flags >> 1) & 1) ^ 1 )
				return MenuEntryImpl::_MustBeRemoved();
			goto LABEL_5;
		}
		if ( _flags & 2 )
	LABEL_5:
			_flags &= 0xFDu;
		return MenuEntryImpl::_MustBeRemoved();
	}

}
