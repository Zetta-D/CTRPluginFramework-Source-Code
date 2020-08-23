#include "CTRPluginFrameworkImpl/Menu/PluginMenuExecuteLoop.hpp"

namespace CTRPluginFramework 
{

  class PluginMenuExecuteLoop
  {
  private:
    static LightLock _builtinLock;
    static LightLock _arLock;

  };

  int g_radioId;
  int PluginMenuExecuteLoop::_firstInstance;
  LightLock PluginMenuExecuteLoop::_builtinLock;
  LightLock PluginMenuExecuteLoop::_arLock;

  int PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const(int a1)
  {
    unsigned int v1; // r3
    int v2; // r4

    v1 = *(unsigned __int8 *)(a1 + 100);
    v2 = v1 & 1;
    if ( v1 & 1 )
    {
      v2 = (v1 >> 2) & 1;
      if ( v2 )
      {
        if ( *(_DWORD *)(a1 + 112) ==g_radioId )
        {
          v2 = (v1 >> 1) & 1;
          if ( v2 )
            *(_BYTE *)(a1 + 100) = v1 & 0xFC;
          else
           MenuEntryImpl::_TriggerState((MenuEntryImpl *)a1);
        }
        else
        {
          v2 = 0;
        }
      }
    }
    return v2;
  }
  // 4: using guessed type intg_radioId;

  //----- (0000006C) --------------------------------------------------------
  int PluginMenuExecuteLoop::PluginMenuExecuteLoop(int result)
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 4) = 0;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 0;
    *(_DWORD *)(result + 16) = 0;
    *(_DWORD *)(result + 20) = 0;
   PluginMenuExecuteLoop::_firstInstance = result;
    return result;
  }

  void PluginMenuExecuteLoop::Lock(void)
  {
    LightLock_Lock(&PluginMenuExecuteLoop::_builtinLock);
  }

  void PluginMenuExecuteLoop::Unlock(void)
  {
    LightLock_Unlock(&PluginMenuExecuteLoop::_builtinLock);
  }

  int PluginMenuExecuteLoop::RemoveAR(int result)
  {
    int v1; // r5
    int v2; // r4
    __int64 *v3; // r3
    __int64 i; // r6
    _DWORD *v5; // r3
    _DWORD *v6; // r2
    int *v7; // r1
    int *v8; // r3
    int *v9; // r2
    int v10; // t1
    int v11; // r2

    v1 =PluginMenuExecuteLoop::_firstInstance;
    if ( !PluginMenuExecuteLoop::_firstInstance || !result )
      return result;
    v2 = result;
    *(_BYTE *)(result + 100) &= 0xFCu;
    v3 = *(__int64 **)(result + 144);
    if ( v3 )
    {
      for ( i = *v3; HIDWORD(i) != (_DWORD)i; LODWORD(i) = i + 24 )
       Hook::Disable((Hook *)i);
      v5 = *(_DWORD **)(v2 + 144);
      if ( *v5 != v5[1] )
        v5[1] = *v5;
    }
    v6 = *(_DWORD **)(v1 + 12);
    v7 = *(int **)(v1 + 16);
    for ( result = ((char *)v7 - (char *)v6) >> 4; ; --result )
    {
      v8 = v6;
      if ( result <= 0 )
        break;
      if ( *v6 == v2 )
        goto LABEL_14;
      if ( v6[1] == v2 )
      {
        v8 = v6 + 1;
        goto LABEL_14;
      }
      if ( v6[2] == v2 )
      {
        v8 = v6 + 2;
        goto LABEL_14;
      }
      v6 += 4;
      if ( v8[3] == v2 )
      {
        v8 += 3;
        goto LABEL_14;
      }
    }
    v11 = v7 - v6;
    switch ( v11 )
    {
      case 2:
  LABEL_37:
        if ( *v8 == v2 )
          goto LABEL_14;
        ++v8;
  LABEL_29:
        if ( *v8 != v2 )
        {
          v8 = *(int **)(v1 + 16);
          goto LABEL_32;
        }
        goto LABEL_14;
      case 3:
        if ( *v8 == v2 )
          goto LABEL_14;
        ++v8;
        goto LABEL_37;
      case 1:
        goto LABEL_29;
    }
    v8 = *(int **)(v1 + 16);
  LABEL_14:
    if ( v7 != v8 )
    {
      v9 = v8 + 1;
      while ( v7 != v9 )
      {
        v10 = *v9;
        ++v9;
        result = v10;
        if ( v10 != v2 )
        {
          *v8 = result;
          ++v8;
        }
      }
    }
  LABEL_32:
    if ( *(int **)(v1 + 16) != v8 )
      *(_DWORD *)(v1 + 16) = v8;
    return result;
  }
  // 8: using guessed type intPluginMenuExecuteLoop::_firstInstance;

  //----- (0000020C) --------------------------------------------------------
  int PluginMenuExecuteLoop::ExecuteAR(PluginMenuExecuteLoop *this)
  {
    __int64 v1; // r4
    int result; // r0
    int v3; // t1
    int (*v4)(void); // r3

    if (PluginMenuExecuteLoop::_firstInstance )
    {
      v1 = *(_QWORD *)(PluginMenuExecuteLoop::_firstInstance + 12);
      while ( HIDWORD(v1) != (_DWORD)v1 )
      {
        v3 = *(_DWORD *)v1;
        LODWORD(v1) = v1 + 4;
        result = v3;
        v4 = *(int (**)(void))(v3 + 68);
        if ( v4 )
          result = v4();
      }
    }
    return result;
  }

  void PluginMenuExecuteLoop::LockAR(void)
  {
    LightLock_Lock(&PluginMenuExecuteLoop::_arLock);
  }

  void PluginMenuExecuteLoop::UnlockAR(void)
  {
    LightLock_Unlock(&PluginMenuExecuteLoop::_arLock);
  }

  int PluginMenuExecuteLoop::InitLocks(PluginMenuExecuteLoop *this)
  {
    LightLock_Init(&PluginMenuExecuteLoop::_arLock);
    return LightLock_Init(&PluginMenuExecuteLoop::_builtinLock);
  }

  void  std::vector<unsigned long,std::allocator<unsigned long>>::_M_realloc_insert<unsigned long const&>(_DWORD *a1, _BYTE *a2, _DWORD *a3)
  {
    _BYTE *v3; // r7
    _BYTE *v4; // r10
    int v5; // r4
    int v6; // r3
    unsigned __int8 v7; // cf
    unsigned int v8; // r4
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
  }

  void PluginMenuExecuteLoop::WriteEnabledCheatsToFile(int a1,File *a2)
  {
    _DWORD *v2; // r8
    int v3; // r11
    int v4; // r4
    int v5; // r5
   File *v6; // r10
    unsigned int v7; // r9
    int v8; // r7
    int v9; // r1
    int v10; // r6
    unsigned int i; // r5
    signed int v12; // r3
    int v13; // r2
    signed int v14; // [sp+0h] [bp-40h]
    int v15; // [sp+4h] [bp-3Ch]
    void *v16; // [sp+Ch] [bp-34h]
    char *v17; // [sp+10h] [bp-30h]
    char *v18; // [sp+14h] [bp-2Ch]

    v2 = (_DWORD *)PluginMenuExecuteLoop::_firstInstance;
    if (PluginMenuExecuteLoop::_firstInstance )
    {
      v3 = 0;
      v4 = a1;
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v5 = *(_DWORD *)(PluginMenuExecuteLoop::_firstInstance + 4)
         - *(_DWORD *)PluginMenuExecuteLoop::_firstInstance;
      v6 = a2;
      v7 = 0;
      v8 =File::Tell(a2);
      v10 = v9;
      for ( i = v5 >> 2; i; i -= v14 )
      {
        if ( v17 != v16 )
          v17 = (char *)v16;
        if ( i >= 0x3E8 )
          v12 = 1000;
        else
          v12 = i;
        v14 = v12;
        while ( v7 < (v2[1] - *v2) >> 2 )
        {
          v13 = *(_DWORD *)(*v2 + 4 * v7);
          if ( v13 )
          {
            if ( *(_BYTE *)(v13 + 57) == 1 )
            {
              v15 = *(_DWORD *)(*v2 + 4 * v7);
              if (MenuEntryImpl::IsActivated(*(MenuEntryImpl **)(*v2 + 4 * v7)) )
              {
                if ( v17 == v18 )
                {
                  std::vector<unsigned long,std::allocator<unsigned long>>::_M_realloc_insert<unsigned long const&>(
                    &v16,
                    v17,
                    (_DWORD *)(v15 + 52));
                }
                else
                {
                  *(_DWORD *)v17 = *(_DWORD *)(v15 + 52);
                  v17 += 4;
                }
              }
            }
          }
          ++v7;
        }
        if (File::Write(v6, v16, v17 - (_BYTE *)v16) )
          goto LABEL_21;
        v3 += (v17 - (_BYTE *)v16) >> 2;
      }
      *(_BYTE *)(v4 + 51) = HIBYTE(v3);
      *(_BYTE *)(v4 + 53) = BYTE1(v8);
      *(_BYTE *)(v4 + 54) = BYTE2(v8);
      *(_BYTE *)(v4 + 49) = BYTE1(v3);
      *(_BYTE *)(v4 + 52) = v8;
      *(_WORD *)(v4 + 56) = v10;
      *(_BYTE *)(v4 + 48) = v3;
      *(_BYTE *)(v4 + 50) = BYTE2(v3);
      *(_BYTE *)(v4 + 55) = HIBYTE(v8);
      *(_BYTE *)(v4 + 58) = BYTE2(v10);
      *(_BYTE *)(v4 + 59) = HIBYTE(v10);
  LABEL_21:
      if ( v16 )
        operator delete(v16);
    }
  }
  // 8: using guessed type intPluginMenuExecuteLoop::_firstInstance;

  //----- (000004E0) --------------------------------------------------------
  char * std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_erase(int a1, char *a2, char *a3)
  {
    char *v3; // r3
    _BYTE *v4; // r4
    _BYTE *v5; // r2
    int v6; // r5
    int v7; // r2
    char *result; // r0
    int v9; // r4

    v3 = a2;
    if ( a3 == a2 )
      return a2;
    v4 = a3;
    v5 = *(_BYTE **)(a1 + 4);
    v6 = a1;
    if ( v4 != v5 )
      v3 = (char *)memmove(a2, v4, v5 - v4);
    v7 = *(_DWORD *)(v6 + 4);
    result = v3;
    v9 = (int)&v3[v7 - (_DWORD)v4];
    if ( v9 != v7 )
      *(_DWORD *)(v6 + 4) = v9;
    return result;
  }

  //----- (0000053C) --------------------------------------------------------
  int PluginMenuExecuteLoop::operator()(int a1)
  {
   MenuEntryImpl **v1; // r4
   MenuEntryImpl **v2; // r7
    int v3; // r5
    int v4; // r6
   MenuEntryImpl *v5; // r0
   MenuEntryImpl *v6; // t1
    int v7; // r0
   MenuEntryImpl **v8; // r3
   MenuEntryImpl **v9; // r7
    int i; // r6
   MenuEntryImpl **v11; // r4
   MenuEntryImpl **v12; // r6
    int v13; // r0
   MenuEntryImpl *v14; // r3
    int v15; // r0
    int v16; // r3

    v1 = *(MenuEntryImpl ***)a1;
    v2 = *(MenuEntryImpl ***)(a1 + 4);
    if ( v2 == *(MenuEntryImpl ***)a1 )
      return 0;
    v3 = a1;
    v4 = 0;
    do
    {
      v6 = *v1;
      ++v1;
      v5 = v6;
      if ( *((_BYTE *)v6 + 57) == 1 )
      {
        v7 =MenuEntryImpl::_Execute(v5);
        if ( v7 )
          v4 = v7;
      }
    }
    while ( v2 != v1 );
    if ( !v4 )
      return 0;
    v8 = *(MenuEntryImpl ***)v3;
    v9 = *(MenuEntryImpl ***)(v3 + 4);
    for ( i = ((signed int)v9 - *(_DWORD *)v3) >> 4; ; --i )
    {
      v11 = v8;
      if ( i <= 0 )
        break;
      if (MenuEntryImpl::_MustBeRemoved(*v8) )
        goto LABEL_13;
      if (MenuEntryImpl::_MustBeRemoved(v11[1]) )
      {
        ++v11;
        goto LABEL_13;
      }
      if (MenuEntryImpl::_MustBeRemoved(v11[2]) )
      {
        v11 += 2;
        goto LABEL_13;
      }
      v15 =MenuEntryImpl::_MustBeRemoved(v11[3]);
      v8 = v11 + 4;
      if ( v15 )
      {
        v11 += 3;
        goto LABEL_13;
      }
    }
    v16 = v9 - v8;
    if ( v16 == 2 )
    {
  LABEL_35:
      if ( !MenuEntryImpl::_MustBeRemoved(*v11) )
      {
        ++v11;
  LABEL_29:
        if ( !MenuEntryImpl::_MustBeRemoved(*v11) )
          goto LABEL_30;
        goto LABEL_13;
      }
      goto LABEL_13;
    }
    if ( v16 != 3 )
    {
      if ( v16 != 1 )
      {
  LABEL_30:
        v11 = v9;
        goto LABEL_31;
      }
      goto LABEL_29;
    }
    if ( !MenuEntryImpl::_MustBeRemoved(*v11) )
    {
      ++v11;
      goto LABEL_35;
    }
  LABEL_13:
    if ( v9 != v11 )
    {
      v12 = v11 + 1;
      while ( v9 != v12 )
      {
        v13 =MenuEntryImpl::_MustBeRemoved(*v12);
        if ( !v13 )
          v14 = *v12;
        ++v12;
        if ( !v13 )
        {
          *v11 = v14;
          ++v11;
        }
      }
    }
  LABEL_31:
    std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_erase(
      v3,
      (char *)v11,
      *(char **)(v3 + 4));
    return 0;
  }

  void PluginMenuExecuteLoop::ExecuteBuiltin(void) const
  {
    if (PluginMenuExecuteLoop::_firstInstance )
      result =PluginMenuExecuteLoop::operator()(PluginMenuExecuteLoop::_firstInstance);
  }

  char *PluginMenuExecuteLoop::Remove(int a1)
  {
    int v1; // r3
    char *result; // r0
    _DWORD *v3; // r2
    int *v4; // r12
    int i; // lr
    int v6; // r1
    int *v7; // r2
    int v8; // lr
    int v9; // t1
    int v10; // r2

    v1 = a1;
    result = (char *)PluginMenuExecuteLoop::_firstInstance;
    if ( !PluginMenuExecuteLoop::_firstInstance
      || !v1
      || *(_DWORD *)PluginMenuExecuteLoop::_firstInstance == *(_DWORD *)(PluginMenuExecuteLoop::_firstInstance
                                                                                           + 4) )
    {
      return result;
    }
    *(_BYTE *)(v1 + 100) &= 0xFCu;
    v3 = *(_DWORD **)result;
    v4 = (int *)*((_DWORD *)result + 1);
    for ( i = ((signed int)v4 - *(_DWORD *)result) >> 4; ; --i )
    {
      v6 = (int)v3;
      if ( i <= 0 )
        break;
      if ( *v3 == v1 )
        goto LABEL_9;
      if ( v3[1] == v1 )
      {
        v6 = (int)(v3 + 1);
        goto LABEL_9;
      }
      if ( v3[2] == v1 )
      {
        v6 = (int)(v3 + 2);
        goto LABEL_9;
      }
      v3 += 4;
      if ( *(_DWORD *)(v6 + 12) == v1 )
      {
        v6 += 12;
        goto LABEL_9;
      }
    }
    v10 = v4 - v3;
    switch ( v10 )
    {
      case 2:
  LABEL_30:
        if ( v1 == *(_DWORD *)v6 )
          goto LABEL_9;
        v6 += 4;
  LABEL_24:
        if ( v1 != *(_DWORD *)v6 )
        {
          v6 = *((_DWORD *)result + 1);
          return std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_erase(
                   (int)result,
                   (char *)v6,
                   *((char **)result + 1));
        }
        goto LABEL_9;
      case 3:
        if ( *(_DWORD *)v6 == v1 )
          goto LABEL_9;
        v6 += 4;
        goto LABEL_30;
      case 1:
        goto LABEL_24;
    }
    v6 = *((_DWORD *)result + 1);
  LABEL_9:
    if ( v4 != (int *)v6 )
    {
      v7 = (int *)(v6 + 4);
      while ( v4 != v7 )
      {
        v9 = *v7;
        ++v7;
        v8 = v9;
        if ( v9 != v1 )
        {
          *(_DWORD *)v6 = v8;
          v6 += 4;
        }
      }
    }
    return std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_erase(
             (int)result,
             (char *)v6,
             *((char **)result + 1));
  }
  // 8: using guessed type intPluginMenuExecuteLoop::_firstInstance;

  //----- (000007D4) --------------------------------------------------------
  void  std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_realloc_insert<MenuEntryImpl * const&>(_DWORD *a1, _BYTE *a2, _DWORD *a3)
  {
    _BYTE *v3; // r7
    _BYTE *v4; // r10
    int v5; // r4
    int v6; // r3
    unsigned __int8 v7; // cf
    unsigned int v8; // r4
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
  }

  //----- (00000898) --------------------------------------------------------
  void PluginMenuExecuteLoop::Add(PluginMenuExecuteLoop *this,MenuEntryImpl *a2, int a3)
  {
    int v3; // r5
    int v4; // r7
    int *v5; // r2
   PluginMenuExecuteLoop **v6; // r6
   PluginMenuExecuteLoop *v7; // r1
    int i; // r7
   PluginMenuExecuteLoop **v9; // r4
    int *v10; // r7
    int v11; // r0
    int v12; // r3
    int v13; // r0
    int v14; // r3
    _BYTE *v15; // r1
   PluginMenuExecuteLoop *v16; // [sp+4h] [bp-1Ch]
    int v17; // [sp+8h] [bp-18h]

    v17 = a3;
    v16 = this;
    v3 =PluginMenuExecuteLoop::_firstInstance;
    if (PluginMenuExecuteLoop::_firstInstance && this )
    {
      v4 = *(_DWORD *)PluginMenuExecuteLoop::_firstInstance;
      v5 = *(int **)PluginMenuExecuteLoop::_firstInstance;
      v6 = *(PluginMenuExecuteLoop ***)PluginMenuExecuteLoop::_firstInstance;
      while ( *(PluginMenuExecuteLoop ***)(PluginMenuExecuteLoop::_firstInstance
                                                             + 4) != v6 )
      {
        v7 = *v6;
        ++v6;
        if ( this == v7 )
          return;
      }
      if ( !((*((_DWORD *)this + 28) != -1) & ((unsigned int)*((unsigned __int8 *)this + 100) >> 2)) )
        goto LABEL_32;
     g_radioId = *((_DWORD *)this + 28);
      for ( i = ((signed int)v6 - v4) >> 4; ; --i )
      {
        v9 = (PluginMenuExecuteLoop **)v5;
        if ( i <= 0 )
          break;
        if (PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const(*v5) )
          goto LABEL_13;
        if (PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const((int)v9[1]) )
        {
          ++v9;
          goto LABEL_13;
        }
        if (PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const((int)v9[2]) )
        {
          v9 += 2;
          goto LABEL_13;
        }
        v13 =PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const((int)v9[3]);
        v5 = (int *)(v9 + 4);
        if ( v13 )
        {
          v9 += 3;
          goto LABEL_13;
        }
      }
      v14 = ((char *)v6 - (char *)v5) >> 2;
      if ( v14 != 2 )
      {
        if ( v14 != 3 )
        {
          if ( v14 != 1 )
          {
  LABEL_30:
            v9 = v6;
            goto LABEL_31;
          }
          goto LABEL_29;
        }
        if (PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const(*v5) )
        {
  LABEL_13:
          if ( v6 != v9 )
          {
            v10 = (int *)(v9 + 1);
            while ( v6 != (PluginMenuExecuteLoop **)v10 )
            {
              v11 =PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const(*v10);
              if ( !v11 )
                v12 = *v10;
              ++v10;
              if ( !v11 )
              {
                *v9 = (PluginMenuExecuteLoop *)v12;
                ++v9;
              }
            }
          }
  LABEL_31:
          std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_erase(
            v3,
            (char *)v9,
            *(char **)(v3 + 4));
  LABEL_32:
          v15 = *(_BYTE **)(v3 + 4);
          if ( v15 == *(_BYTE **)(v3 + 8) )
          {
            std::vector<MenuEntryImpl *,std::allocator<MenuEntryImpl *>>::_M_realloc_insert<MenuEntryImpl * const&>(
              (_DWORD *)v3,
              v15,
              &v16);
          }
          else
          {
            *(_DWORD *)v15 = v16;
            *(_DWORD *)(v3 + 4) += 4;
          }
          return;
        }
        ++v9;
      }
      if ( !PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const((int)*v9) )
      {
        ++v9;
  LABEL_29:
        if ( !PluginMenuExecuteLoop::Add(MenuEntryImpl *)::{lambda(MenuEntryImpl *)#1}::operator() const((int)*v9) )
          goto LABEL_30;
        goto LABEL_13;
      }
      goto LABEL_13;
    }
  }
  // 4: using guessed type intg_radioId;
  // 8: using guessed type intPluginMenuExecuteLoop::_firstInstance;

  //----- (00000A48) --------------------------------------------------------
  void  std::vector<MenuEntryActionReplay *,std::allocator<MenuEntryActionReplay *>>::_M_realloc_insert<MenuEntryActionReplay * const&>(_DWORD *a1, _BYTE *a2, _DWORD *a3)
  {
    _BYTE *v3; // r7
    _BYTE *v4; // r10
    int v5; // r4
    int v6; // r3
    unsigned __int8 v7; // cf
    unsigned int v8; // r4
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
  }

  //----- (00000B0C) --------------------------------------------------------
  void PluginMenuExecuteLoop::AddAR(int a1, int a2, int a3)
  {
    int v3; // r3
    int *v4; // r1
    int *v5; // r2
    int v6; // r12
    int v7; // [sp+4h] [bp-Ch]
    int v8; // [sp+8h] [bp-8h]

    v8 = a3;
    v7 = a1;
    v3 =PluginMenuExecuteLoop::_firstInstance;
    if (PluginMenuExecuteLoop::_firstInstance && a1 )
    {
      v4 = *(int **)(PluginMenuExecuteLoop::_firstInstance + 16);
      v5 = *(int **)(PluginMenuExecuteLoop::_firstInstance + 12);
      while ( v4 != v5 )
      {
        v6 = *v5;
        ++v5;
        if ( a1 == v6 )
          return;
      }
      if ( v4 == *(int **)(PluginMenuExecuteLoop::_firstInstance + 20) )
      {
        std::vector<MenuEntryActionReplay *,std::allocator<MenuEntryActionReplay *>>::_M_realloc_insert<MenuEntryActionReplay * const&>(
          (_DWORD *)(PluginMenuExecuteLoop::_firstInstance + 12),
          v4,
          &v7);
      }
      else
      {
        *v4 = a1;
        *(_DWORD *)(v3 + 16) += 4;
      }
    }
  }
}
