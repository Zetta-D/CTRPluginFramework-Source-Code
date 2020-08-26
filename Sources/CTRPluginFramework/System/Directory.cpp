#include "CTRPluginFramework/System/Directory.hpp"

namespace CTRPluginFramework
{
   /* To Do:
      - DirectoryEntry Functions
   */

	int Directory::Close(void) const
	{
		int res(0);
		Lock *lock = new Lock(_mutex);
		if ( _isOpen )
		{
			res = FSDIR_Close(_handle);
			if ( res >= 0 )
			{
				res = 0;
				_isOpen = false;
			}
		}
		else
			res = -2;
		lock->~Lock();
		return res;
	}

	int Directory::OpenFile(File &output, const std::string &path, int mode = File::RW) const
	{
		if ( !_isOpen )
			return -2;
		return File::Open(output, path[0] == "/" ? _path + path : "/" + _path + path, mode);
	}

	std::string Directory::GetName(void) const
	{
		std::size_t pos = _path.rfind("/");
		return pos != std::string::npos ? _path.substr(pos + 1) : _path
	}

	std::string Directory::GetFullName(void) const
	{
		return _path;
	}

	bool Directory::IsOpen(void) const
	{
		return _isOpen; // 28
	}

	Directory::Directory(void) : _path(""), _handle(0), _isOpen(false) { }

	Directory::~Directory()
	{
		std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>::clear(_list);
		Directory::Close();
		_mutex.~Mutex();
	}

	int Directory::ChangeWorkingDirectory(const std::string &path)
	{
		int fs(0);
		FSPath fsPath = new FSPath(&fs, path);
		int res(fs);
		if (fs)
			res = -1;
		else
		{
			Lock *lock = new Lock(fsPath->FSMutex);
			fsPath->CurrentWorkingDirectory = path;
			if ( path[0] != "/" )
				fsPath->CurrentWorkingDirectory += "/";
			lock->~Lock();
		}
		delete fsPath;
		return res;
	}

	int Directory::Create(const std::string &path)
	{
		int res, ret, fs;
		FSPath *fsPath = new FSPath(&fs, &path);
		if ( fs )
			res = -1;
		else
		{
			fsPath();
			ret = FSUSER_CreateDirectory(_sdmcArchive, *(FS_Path *)&path, fs);
			res = ret == -937409346 ? 1 : ret & (ret >> 31);
		}
		delete fsPath;
		return res;
	}

	int Directory::Remove(const std::string &path);
	{
		int res, ret, fs;
		FSPath *fsPath = new FSPath(&fs, &path);
		if ( fs )
			res = -1;
		else
		{
			fsPath();
			ret = FSUSER_CreateDirectory(_sdmcArchive, *(FS_Path *)&path);
			res = ret & (ret >> 31);
		}
		delete fsPath;
		return res;
	}

	int Directory::Rename(const std::string &oldPath, const std::string &newPath);
	{
		int res, ret, fs, fs2;
		FSPath *fsPath = new FSPath(&fs, oldPath);
		FSPath *fsPath2 = new FSPath(&fs, newPath);
		if ( fs | fs2 )
			res = -1;
		else
		{
			fsPath();
			fsPath2();
			FSUSER_RenameDirectory(_sdmcArchive, *(FS_Path *)&oldPath, _sdmcArchive, *(FS_Path *)&newPath);
			res = ret & (ret >> 31);
		}
		delete fsPath, fsPath2;
		return res;
	}

	int Directory::IsExists(const std::string &path);
	{
		int res(0), fs(0);
		FSPath *fsPath = new FSPath(&fs, &path);
		if ( fs )
			res = -1;
		else
		{
			fsPath();
			if(FSUSER_OpenDirectory(&_handle, _sdmcArchive, *(FS_Path *)&path) >= 0)
			{
				FSDIR_Close(_handle);
				res = 1;
			}
		}
		delete fsPath;
		return res;
	}

	int Directory::Open(Directory &output, const std::string &path, bool create)
	{
		Lock *lock = new Lock(_mutex);
		if ( _isOpen )
			Directory::Close();
	}

	int Directory::Open(int a1, int a2, int a3)
	{
		Handle handle;
		std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>::clear(output._list);
		FSPath *fsPath = new FSPath(&fs, &path);
		if ( fs )
			res = -1;
		else
		{
			fsPath();
			res = FSUSER_OpenDirectory(&handle, _sdmcArchive, *(FS_Path *)&path);
			if ( res >= 0 || create && Directory::Create(path) == 0 && SUSER_OpenDirectory(&handle, _sdmcArchive, *(FS_Path *)&path) >= 0)
			{
				fsPath->SdmcFixPath(path);
				output._handle = handle;
		 		_isOpen = true;
			}
		}
		 lock->~Lock(); 
	}

	Directory::Directory(const std::string &path, bool create = false)
	{
		Directory::Directory();
		Directory::Open(path, create);
	}

	DirectoryEntry::DirectoryEntry(u32 attrib, u8 *name)
	{
		attributes = attrib;
		name = reinterpret_cast<char*>(name);
	}


	int std::__adjust_heap<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,Directory::DirectoryEntry,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(int a1, int a2, int a3, _DWORD *a4)
	{
		_DWORD *v4; // r9
		int v5; // r11
		int v6; // r6
		int v7; // r7
		int v8; // r5
		int i; // r4
		int v10; // r8
		int j; // r5
		char v13; // [sp+Ch] [bp-44h]
		char v14; // [sp+10h] [bp-40h]

		v4 = a4;
		v5 = (a3 - 1) / 2;
		v6 = a1;
		v7 = a2;
		v8 = a3;
		for ( i = a2; v5 > i; i = v10 )
		{
			v10 = 2 * (i + 1);
			if ( Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
						 v6 + 56 * (i + 1),
						 v6 + 28 * (v10 - 1)) )
			{
				--v10;
			}
			Directory::DirectoryEntry::operator=((_DWORD *)(v6 + 28 * i), (_DWORD *)(v6 + 28 * v10));
		}
		if ( !(v8 & 1) && i == (v8 - 2) / 2 )
		{
			Directory::DirectoryEntry::operator=((_DWORD *)(v6 + 28 * i), (_DWORD *)(v6 + 28 * (2 * i + 1)));
			i = 2 * i + 1;
		}
		Directory::DirectoryEntry::DirectoryEntry(&v13, v4);
		for ( j = (i - 1) / 2;
					v7 < i
			 && Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
						v6 + 28 * j,
						(int)&v13);
					j = (j - 1) / 2 )
		{
			Directory::DirectoryEntry::operator=((_DWORD *)(v6 + 28 * i), (_DWORD *)(v6 + 28 * j));
			i = j;
		}
		Directory::DirectoryEntry::operator=((_DWORD *)(v6 + 28 * i), &v13);
		return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v14);
	}

	int std::__pop_heap<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(_DWORD *a1, int a2, _DWORD *a3)
	{
		_DWORD *v3; // r5
		_DWORD *v4; // r6
		int v5; // r4
		int v7; // [sp+0h] [bp-48h]
		char v8; // [sp+4h] [bp-44h]
		char v9; // [sp+1Ch] [bp-2Ch]
		char v10; // [sp+20h] [bp-28h]

		v3 = a1;
		v4 = a3;
		v5 = a2;
		Directory::DirectoryEntry::DirectoryEntry(&v7, a3);
		Directory::DirectoryEntry::operator=(v4, v3);
		Directory::DirectoryEntry::DirectoryEntry(&v9, &v7);
		std::__adjust_heap<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,Directory::DirectoryEntry,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
			(int)v3,
			0,
			-1227133513 * ((v5 - (signed int)v3) >> 2),
			&v9);
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v10);
		return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v8);
	}
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (00000DC4) --------------------------------------------------------
	int std::__unguarded_linear_insert<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Val_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(_DWORD *a1)
	{
		_DWORD *v1; // r4
		int v2; // r4
		_BOOL4 v3; // r0
		_DWORD *v4; // r6
		_DWORD *v5; // r5
		char v7; // [sp+4h] [bp-2Ch]
		char v8; // [sp+8h] [bp-28h]

		v1 = a1;
		Directory::DirectoryEntry::DirectoryEntry(&v7, a1);
		v2 = (int)(v1 - 7);
		while ( 1 )
		{
			v3 = Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
						 (int)&v7,
						 v2);
			v4 = (_DWORD *)v2;
			v5 = (_DWORD *)(v2 + 28);
			v2 -= 28;
			if ( !v3 )
				break;
			Directory::DirectoryEntry::operator=(v5, v4);
		}
		Directory::DirectoryEntry::operator=(v5, &v7);
		return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v8);
	}
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (00000E2C) --------------------------------------------------------
	int std::__insertion_sort<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(int result, _DWORD *a2)
	{
		_DWORD *v2; // r8
		_DWORD *v3; // r5
		_DWORD *i; // r4
		_DWORD *v5; // r7
		int j; // r6
		_DWORD *v7; // r0
		char v8; // [sp+4h] [bp-3Ch]
		char v9; // [sp+8h] [bp-38h]

		if ( (_DWORD *)result != a2 )
		{
			v2 = a2;
			v3 = (_DWORD *)result;
			for ( i = (_DWORD *)(result + 28); ; i += 7 )
			{
				v5 = i;
				if ( v2 == i )
					break;
				if ( Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
							 (int)i,
							 (int)v3) )
				{
					Directory::DirectoryEntry::DirectoryEntry(&v8, i);
					for ( j = -1227133513 * (i - v3); j > 0; --j )
					{
						v7 = v5;
						v5 -= 7;
						Directory::DirectoryEntry::operator=(v7, v5);
					}
					Directory::DirectoryEntry::operator=(v3, &v8);
					result = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v9);
				}
				else
				{
					result = std::__unguarded_linear_insert<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Val_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(i);
				}
			}
		}
		return result;
	}
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (00000ED8) --------------------------------------------------------
	int std::swap<Directory::DirectoryEntry>(_DWORD *a1, _DWORD *a2)
	{
		_DWORD *v2; // r4
		_DWORD *v3; // r5
		char v5; // [sp+4h] [bp-2Ch]
		char v6; // [sp+8h] [bp-28h]

		v2 = a2;
		v3 = a1;
		Directory::DirectoryEntry::DirectoryEntry(&v5, a1);
		Directory::DirectoryEntry::operator=(v3, v2);
		Directory::DirectoryEntry::operator=(v2, &v5);
		return std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v6);
	}
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (00000F1C) --------------------------------------------------------
	int std::__introsort_loop<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(int result, char *a2, int a3, int a4)
	{
		char *v4; // r5
		int v5; // r8
		int v6; // r9
		char *v7; // r6
		int v8; // r7
		int v9; // r4
		int v10; // r7
		bool v11; // zf
		bool v12; // nf
		unsigned __int8 v13; // vf
		int v14; // r4
		int v15; // r1
		char *v16; // r1
		char *v17; // r4
		char *v18; // r11
		int v19; // r3
		int v20; // ST04_4
		_BOOL4 v21; // r0
		char v22; // [sp+8h] [bp-60h]
		char v23; // [sp+Ch] [bp-5Ch]
		char v24; // [sp+24h] [bp-44h]
		char v25; // [sp+28h] [bp-40h]

		v4 = (char *)result;
		v5 = a3;
		v6 = a4;
		v7 = a2;
		v8 = result + 28;
	LABEL_2:
		if ( v7 - v4 > 448 )
		{
			v9 = -1227133513 * ((v7 - v4) >> 2);
			if ( !v5 )
			{
				v10 = (v9 - 2) >> 1;
				while ( 1 )
				{
					Directory::DirectoryEntry::DirectoryEntry(&v22, &v4[28 * v10]);
					Directory::DirectoryEntry::DirectoryEntry(&v24, &v22);
					std::__adjust_heap<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,Directory::DirectoryEntry,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
						(int)v4,
						v10,
						-1227133513 * ((v7 - v4) >> 2),
						&v24);
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v25);
					if ( !v10 )
						break;
					--v10;
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v23);
				}
				for ( result = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v23);
							;
							result = std::__pop_heap<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
												 v4,
												 (int)v7,
												 v7) )
				{
					v13 = __OFSUB__(v7 - v4, 28);
					v11 = v7 - v4 == 28;
					v12 = v7 - v4 - 28 < 0;
					v7 -= 28;
					if ( (unsigned __int8)(v12 ^ v13) | v11 )
						break;
				}
				return result;
			}
			v14 = (int)&v4[28 * (v9 >> 1)];
			--v5;
			v15 = (int)(v7 - 28);
			if ( Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
						 v8,
						 v14) )
			{
				if ( Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
							 v14,
							 v15) )
				{
	LABEL_12:
					v16 = (char *)v14;
	LABEL_17:
					std::swap<Directory::DirectoryEntry>(v4, v16);
					v17 = (char *)v8;
					v18 = v7;
					while ( 1 )
					{
						if ( !Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
										(int)v17,
										(int)v4) )
						{
							v19 = (int)(v18 - 28);
							do
							{
								v18 = (char *)v19;
								v20 = v19;
								v21 = Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
												(int)v4,
												v19);
								v19 = v20 - 28;
							}
							while ( v21 );
							if ( v17 >= v18 )
							{
								result = std::__introsort_loop<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
													 v17,
													 v7,
													 v5,
													 v6);
								v7 = v17;
								goto LABEL_2;
							}
							std::swap<Directory::DirectoryEntry>(v17, v18);
						}
						v17 += 28;
					}
				}
				if ( Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
							 v8,
							 (int)(v7 - 28)) )
				{
	LABEL_14:
					v16 = v7 - 28;
					goto LABEL_17;
				}
			}
			else if ( !Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
									 v8,
									 v15) )
			{
				if ( !Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(
								v14,
								(int)(v7 - 28)) )
					goto LABEL_12;
				goto LABEL_14;
			}
			v16 = (char *)v8;
			goto LABEL_17;
		}
		return result;
	}
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (000010F8) --------------------------------------------------------
	signed int Directory::_List(Directory *this)
	{
		Directory *v1; // r4
		unsigned int v2; // r1
		void *v3; // r1
		Heap *v4; // r6
		unsigned int v5; // r7
		Heap *v6; // r5
		int v7; // r0
		_DWORD *v8; // r0
		char *v9; // r4
		void *v10; // r1
		signed int v11; // r4
		int v12; // r5
		char *v13; // r7
		unsigned int v15; // [sp+4h] [bp-104Ch]
		char v16; // [sp+8h] [bp-1048h]
		int v17; // [sp+10h] [bp-1040h]
		char v18; // [sp+14h] [bp-103Ch]
		char v19; // [sp+2Ch] [bp-1024h]
		char v20; // [sp+30h] [bp-1020h]

		v1 = this;
		Lock lock = Lock(_mutex);
		v4 = (Heap *)Heap::Alloc((Heap *)0xD7A0, v2);
		v15 = 0;
		if ( !v4 )
			goto LABEL_23;
		while ( FSDIR_Read(_handle, &v15, 100, v4) >= 0 && v15 )
		{
			v5 = 0;
			v6 = v4;
			while ( v15 > v5 )
			{
				v7 = utf16_to_utf8(&v19, v6, 4096);
				if ( v7 != -1 )
				{
					*(&v20 + v7 - 4) = 0;
					v17 = *((_DWORD *)v6 + 135);
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string((int *)&v18, &v19);
					v8 = (_DWORD *)*((_DWORD *)v1 + 12);
					if ( v8 == *((_DWORD **)v1 + 13) )
					{
						std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>::_M_realloc_insert<Directory::DirectoryEntry>(
							(int)v1 + 44,
							*((char **)v1 + 12),
							(int)&v17);
					}
					else
					{
						Directory::DirectoryEntry::DirectoryEntry(v8, &v17);
						*((_DWORD *)v1 + 12) += 28;
					}
					std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(&v18);
				}
				++v5;
				v6 = (Heap *)((char *)v6 + 552);
			}
		}
		v12 = *((_DWORD *)v1 + 11);
		v13 = (char *)*((_DWORD *)v1 + 12);
		if ( (char *)v12 != v13 )
		{
			std::__introsort_loop<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,int,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
				v12,
				v13,
				2 * (31 - __clz(-1227133513 * ((signed int)&v13[-v12] >> 2))),
				0);
			if ( (signed int)&v13[-v12] <= 448 )
			{
				std::__insertion_sort<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
					v12,
					v13);
			}
			else
			{
				v9 = (char *)(v12 + 448);
				std::__insertion_sort<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Iter_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(
					v12,
					(_DWORD *)(v12 + 448));
				while ( v13 != v9 )
				{
					std::__unguarded_linear_insert<__gnu_cxx::__normal_iterator<Directory::DirectoryEntry *,std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>>,__gnu_cxx::__ops::_Val_comp_iter<Directory::_List(void)const::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}>>(v9);
					v9 += 28;
				}
			}
			Heap::Free(v4, v10);
			v11 = 0;
		}
		else
		{
	LABEL_23:
			Heap::Free(v4, v3);
			v11 = -1;
		}
		lock.~Lock();
		return v11;
	}

	int Directory::ListFiles(int a1, int a2, int a3)
	{
		int v3; // r4
		_DWORD *v4; // r7
		int v5; // r8
		int v6; // r4
		int v7; // r10
		int v8; // r6
		int v9; // r9
		int i; // r4
		int v12; // [sp+0h] [bp-28h]
		int v13; // [sp+4h] [bp-24h]

		v12 = a1;
		v13 = a2;
		v3 = a1;
		v4 = (_DWORD *)a2;
		v5 = a3;
		Lock lock = Lock(_mutex)
		if ( *(_BYTE *)(v3 + 28) )
		{
			v7 = *(_DWORD *)(v5 + 4);
			if ( *(_DWORD *)(v3 + 48) == *(_DWORD *)(v3 + 44) )
				Directory::_List((Directory *)v3);
			v8 = -1431655765 * ((v4[1] - *v4) >> 3);
			v9 = *(_DWORD *)(v3 + 48);
			for ( i = *(_DWORD *)(v3 + 44) + 4; v9 != i - 4; i += 28 )
			{
				if ( !(*(_DWORD *)(i - 4) & 1)
					&& (!v7 || std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::find(i, v5, 0) != -1) )
				{
					std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::push_back(
						(int)v4,
						i);
				}
			}
			v6 = -1431655765 * ((v4[1] - *v4) >> 3) - v8;
		}
		else
		{
			v6 = -2;
		}
		lock.~Lock();
		return v6;
	}
	// 14B0: using guessed type _DWORD __cdecl Lock::Lock(Lock *__hidden this, Mutex *);
	// 1530: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::find(_DWORD, _DWORD, _DWORD);

	//----- (0000138C) --------------------------------------------------------
	int Directory::ListDirectories(int a1, int a2, int a3)
	{
		int v3; // r4
		_DWORD *v4; // r7
		int v5; // r8
		int v6; // r4
		int v7; // r9
		int v8; // r6
		int v9; // r10
		int i; // r4
		int v12; // [sp+0h] [bp-28h]
		int v13; // [sp+4h] [bp-24h]

		v12 = a1;
		v13 = a2;
		v3 = a1;
		v4 = (_DWORD *)a2;
		v5 = a3;
		Lock lock = Lock(_mutex);
		if ( *(_BYTE *)(v3 + 28) )
		{
			v7 = *(_DWORD *)(v5 + 4);
			if ( *(_DWORD *)(v3 + 48) == *(_DWORD *)(v3 + 44) )
				Directory::_List((Directory *)v3);
			v8 = -1431655765 * ((v4[1] - *v4) >> 3);
			v9 = *(_DWORD *)(v3 + 48);
			for ( i = *(_DWORD *)(v3 + 44) + 4; v9 != i - 4; i += 28 )
			{
				if ( *(_DWORD *)(i - 4) & 1
					&& (!v7 || std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::find(i, v5, 0) != -1) )
				{
					std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::push_back(
						(int)v4,
						i);
				}
			}
			v6 = -1431655765 * ((v4[1] - *v4) >> 3) - v8;
		}
		else
		{
			v6 = -2;
		}
		lock.~Lock();
		return v6;
	}

	bool __spoils<R0,R2,R3,R12> Directory::_List(void)::{lambda(Directory::DirectoryEntry const&,Directory::DirectoryEntry const&)#1}::operator() constconst(int a1, int a2)
	{
		int v2; // r5
		int v3; // r4
		int v4; // r6
		int v5; // r0
		bool v6; // zf
		_BOOL4 v7; // r3
		unsigned int v9; // [sp+0h] [bp-18h]
		unsigned int v10; // [sp+4h] [bp-14h]

		v9 = a1;
		v2 = *(_DWORD *)(a1 + 4);
		v3 = *(_DWORD *)(a2 + 4);
		do
		{
			v4 = decode_utf8(&v9, v2);
			v5 = decode_utf8(&v10, v3);
			v6 = v4 == -1;
			if ( v4 != -1 )
				v6 = v5 == -1;
			if ( v6 )
				break;
			v7 = v9 == 0;
			if ( v10 != v9 )
				v7 = 1;
			v2 += v4;
			v3 += v5;
		}
		while ( !v7 );
		return v9 < v10;
	}
	// 149C: using guessed type int decode_utf8(_DWORD, _DWORD);

	//----- (00000074) --------------------------------------------------------
	int *std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(int *a1, const char *a2)
	{
		const char *v2; // r5
		int *v3; // r4
		size_t v4; // r0
		int v5; // r6
		int v6; // r0
		int v7; // r3
		int *result; // r0
		int v9; // r3
		int v10; // r2
		const char *v11; // [sp+4h] [bp-14h]

		v11 = a2;
		v2 = a2;
		*a1 = (int)(a1 + 2);
		if ( !a2 )
			std::__throw_logic_error("basic_string::_M_construct null not valid");
		v3 = a1;
		v4 = strlen(a2);
		v5 = (int)&v2[v4];
		v11 = (const char *)v4;
		if ( v4 > 0xF )
		{
			v6 = std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_create(v3, &v11, 0);
			v7 = (int)v11;
			*v3 = v6;
			v3[2] = v7;
		}
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_S_copy_chars(*v3, v2, v5);
		result = v3;
		v9 = (int)v11;
		v10 = *v3;
		v3[1] = (int)v11;
		*(_BYTE *)(v10 + v9) = 0;
		return result;
	}

	Directory::DirectoryEntry *Directory::DirectoryEntry::DirectoryEntry(Directory::DirectoryEntry *this, unsigned int a2, unsigned __int8 *a3)
	{
		Directory::DirectoryEntry *v3; // r4

		v3 = this;
		*(_DWORD *)this = a2;
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(
			(int *)this + 1,
			(const char *)a3);
		return v3;
	}

	u64 *std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>::clear(u64 *result)
	{
		__int64 v1; // r6
		u64 *v2; // r4
		int v3; // r5
		int v4; // r0

		v1 = *result;
		if ( (_DWORD)v1 != HIDWORD(v1) )
		{
			v2 = result;
			v3 = v1;
			do
			{
				v4 = v3 + 4;
				v3 += 28;
				result = (u64 *)std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v4);
			}
			while ( HIDWORD(v1) != v3 );
			*((_DWORD *)v2 + 1) = v1;
		}
		return result;
	}

	void std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::_M_realloc_insert<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&>(char **a1, char *a2, int a3)
	{
		char *v3; // r7
		char *v4; // r6
		int v5; // r4
		int v6; // r3
		unsigned __int8 v7; // cf
		unsigned int v8; // r4
		char **v9; // r8
		char *v10; // r9
		__int64 v11; // r10
		unsigned int v12; // r5
		char *v13; // r11
		int i; // r0
		int v15; // r5
		int v16; // r5
		int v17; // r11
		int v18; // r3
		int v19; // r2
		int v20; // ST04_4
		int v21; // ST00_4
		unsigned int v22; // r9
		char *v23; // r6
		int v24; // r9
		int v25; // r5
		int v26; // [sp+0h] [bp-30h]

		v3 = *a1;
		v4 = a1[1];
		v5 = -1431655765 * ((v4 - *a1) >> 3);
		if ( -1431655765 * ((v4 - *a1) >> 3) )
			v6 = -1431655765 * ((v4 - *a1) >> 3);
		else
			v6 = 1;
		v7 = __CFADD__(v5, v6);
		v8 = v5 + v6;
		v9 = a1;
		v10 = a2;
		HIDWORD(v11) = a3;
		v12 = a2 - v3;
		if ( v7 || v8 > 0xAAAAAAA )
		{
			v8 = 178956970;
			goto LABEL_21;
		}
		if ( v8 )
		{
	LABEL_21:
			LODWORD(v11) = operator new(24 * v8);
			goto LABEL_8;
		}
		LODWORD(v11) = 0;
	LABEL_8:
		std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v11 + v12, HIDWORD(v11));
		v13 = v3;
		for ( i = v11; ; i = v26 )
		{
			v26 = i + 24;
			if ( v10 == v13 )
				break;
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(i, v13);
			v13 += 24;
		}
		v15 = 178956971 * (v12 >> 3) & 0x1FFFFFFF;
		HIDWORD(v11) = 24 * v15 + 24;
		v16 = (int)&v3[24 * v15];
		v17 = v11 + HIDWORD(v11);
		v18 = v16;
		v19 = v17;
		while ( v4 != (char *)v18 )
		{
			v20 = v18;
			v21 = v19;
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(v19, v18);
			v19 = v21 + 24;
			v18 = v20 + 24;
		}
		v22 = 178956971 * ((unsigned int)&v4[-v16] >> 3);
		v23 = v3;
		v24 = 24 * (v22 & 0x1FFFFFFF);
		v25 = v16 + v24;
		HIDWORD(v11) = v17 + v24;
		while ( (char *)v25 != v23 )
		{
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v23);
			v23 += 24;
		}
		if ( v3 )
			operator delete(v3);
		*(u64 *)v9 = v11;
		v9[2] = (char *)(v11 + 24 * v8);
	}
	// 14BC: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
	// 14C8: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(_DWORD, _DWORD);
	// 14D0: using guessed type int std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(_DWORD);

	//----- (00000A40) --------------------------------------------------------
	void std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::push_back(int a1, int a2)
	{
		int v2; // r4

		if ( *(_DWORD *)(a1 + 4) == *(_DWORD *)(a1 + 8) )
		{
			std::vector<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>,std::allocator<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>>>::_M_realloc_insert<std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>> const&>(
				(char **)a1,
				*(char **)(a1 + 4),
				a2);
		}
		else
		{
			v2 = a1;
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::basic_string(*(_DWORD *)(a1 + 4), a2);
			*(_DWORD *)(v2 + 4) += 24;
		}
	}

	int FSPath::operator FS_Path(int result, _DWORD *a2)
	{
		int v2; // r3

		if ( *a2 )
		{
			*(_BYTE *)result = 1;
			v2 = 0;
			*(_DWORD *)(result + 4) = 0;
		}
		else
		{
			*(_BYTE *)result = 4;
			*(_DWORD *)(result + 4) = 2 * (a2[1] + 1);
			v2 = a2[2];
		}
		*(_DWORD *)(result + 8) = v2;
		return result;
	}

	void std::vector<Directory::DirectoryEntry,std::allocator<Directory::DirectoryEntry>>::_M_realloc_insert<Directory::DirectoryEntry>(int a1, char *a2, int a3)
	{
		char *v3; // r7
		_DWORD *v4; // r6
		int v5; // r4
		int v6; // r3
		unsigned __int8 v7; // cf
		unsigned int v8; // r4
		int v9; // r8
		char *v10; // r9
		__int64 v11; // r10
		unsigned int v12; // r5
		char *v13; // r11
		_DWORD *i; // r0
		int v15; // r5
		int v16; // r5
		_DWORD *v17; // r11
		_DWORD *v18; // r3
		_DWORD *v19; // r2
		_DWORD *v20; // ST04_4
		_DWORD *v21; // ST00_4
		unsigned int v22; // r9
		char *v23; // r6
		int v24; // r9
		int v25; // r5
		int v26; // [sp+0h] [bp-30h]

		v3 = *(char **)a1;
		v4 = *(_DWORD **)(a1 + 4);
		v5 = -1227133513 * (((signed int)v4 - *(_DWORD *)a1) >> 2);
		if ( -1227133513 * (((signed int)v4 - *(_DWORD *)a1) >> 2) )
			v6 = -1227133513 * (((signed int)v4 - *(_DWORD *)a1) >> 2);
		else
			v6 = 1;
		v7 = __CFADD__(v5, v6);
		v8 = v5 + v6;
		v9 = a1;
		v10 = a2;
		HIDWORD(v11) = a3;
		v12 = a2 - v3;
		if ( v7 || v8 > 0x9249249 )
		{
			v8 = 153391689;
			goto LABEL_21;
		}
		if ( v8 )
		{
	LABEL_21:
			LODWORD(v11) = operator new(28 * v8);
			goto LABEL_8;
		}
		LODWORD(v11) = 0;
	LABEL_8:
		Directory::DirectoryEntry::DirectoryEntry((_DWORD *)(v11 + v12), (_DWORD *)HIDWORD(v11));
		v13 = v3;
		for ( i = (_DWORD *)v11; ; i = (_DWORD *)v26 )
		{
			v26 = (int)(i + 7);
			if ( v10 == v13 )
				break;
			Directory::DirectoryEntry::DirectoryEntry(i, v13);
			v13 += 28;
		}
		v15 = 920350135 * (v12 >> 2) & 0x3FFFFFFF;
		HIDWORD(v11) = 28 * v15 + 28;
		v16 = (int)&v3[28 * v15];
		v17 = (_DWORD *)(v11 + HIDWORD(v11));
		v18 = (_DWORD *)v16;
		v19 = v17;
		while ( v4 != v18 )
		{
			v20 = v18;
			v21 = v19;
			Directory::DirectoryEntry::DirectoryEntry(v19, v18);
			v19 = v21 + 7;
			v18 = v20 + 7;
		}
		v22 = 920350135 * (((unsigned int)v4 - v16) >> 2);
		v23 = v3;
		v24 = 7 * (v22 & 0x3FFFFFFF);
		v25 = v16 + v24 * 4;
		HIDWORD(v11) = &v17[v24];
		while ( (char *)v25 != v23 )
		{
			std::__cxx11::basic_string<char,std::char_traits<char>,std::allocator<char>>::_M_dispose(v23 + 4);
			v23 += 28;
		}
		if ( v3 )
			operator delete(v3);
		*(u64 *)v9 = v11;
		*(_DWORD *)(v9 + 8) = v11 + 28 * v8;
	}

}
