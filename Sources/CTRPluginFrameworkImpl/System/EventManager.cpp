/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

CTRPluginFramework::EventManager *__fastcall CTRPluginFramework::EventManager::EventManager(CTRPluginFramework::EventManager *this);
int __fastcall std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::_M_push_back_aux<CTRPluginFramework::Event const&>(void **a1, int *a2);
int __fastcall std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back(int a1, int *a2);
int __fastcall CTRPluginFramework::EventManager::PushEvent(CTRPluginFramework::EventManager *this, const Event *a2);
int __fastcall CTRPluginFramework::EventManager::ProcessEvents(CTRPluginFramework::EventManager *this, int a2, __int64 a3);
signed int __fastcall CTRPluginFramework::EventManager::PopEvent(__int64 this, int a2);
signed int __fastcall CTRPluginFramework::EventManager::PollEvent(__int64 this);
signed int __fastcall CTRPluginFramework::EventManager::WaitEvent(__int64 this);
// _DWORD __cdecl operator new(unsigned int); idb
// void *memmove(void *dest, const void *src, size_t n);
// void __noreturn std::__throw_bad_alloc(void); idb
// void __cdecl operator delete(void *); idb
// _DWORD CTRPluginFramework::Controller::Update(CTRPluginFramework::Controller *__hidden this); idb
// int __fastcall CTRPluginFramework::Controller::IsKeyPressed(_DWORD); weak
// int __fastcall CTRPluginFramework::Controller::IsKeyDown(_DWORD); weak
// int __fastcall CTRPluginFramework::Controller::IsKeyReleased(_DWORD); weak
// int __fastcall hidTouchRead(_DWORD); weak
// _DWORD __cdecl CTRPluginFramework::Milliseconds(CTRPluginFramework *__hidden this, int); idb
// _DWORD __cdecl CTRPluginFramework::Sleep(CTRPluginFramework *__hidden this, Time); idb

//-------------------------------------------------------------------------
// Data declarations

char CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh = '\x01'; // weak
char CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching; // weak
int CTRPluginFramework::EventManager::ProcessEvents(void)::firstTouch; // weak


//----- (00000008) --------------------------------------------------------
CTRPluginFramework::EventManager *__fastcall CTRPluginFramework::EventManager::EventManager(CTRPluginFramework::EventManager *this)
{
  CTRPluginFramework::EventManager *v1; // r4
  int v2; // r0
  int v3; // r6
  unsigned int v4; // r5
  int v5; // r7
  int v6; // r0

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  v1 = this;
  *((_DWORD *)this + 1) = 8;
  v2 = operator new(0x20u);
  v3 = v2;
  v4 = (unsigned int)(*((_DWORD *)v1 + 1) - 1) >> 1;
  v5 = v2 + 4 * v4;
  *(_DWORD *)v1 = v2;
  v6 = operator new(0x1F8u);
  *(_DWORD *)(v3 + 4 * v4) = v6;
  *((_DWORD *)v1 + 3) = v6;
  *((_DWORD *)v1 + 7) = v6;
  *((_DWORD *)v1 + 2) = v6;
  *((_DWORD *)v1 + 6) = v6;
  *((_DWORD *)v1 + 5) = v5;
  *((_DWORD *)v1 + 4) = v6 + 504;
  *((_DWORD *)v1 + 9) = v5;
  *((_DWORD *)v1 + 8) = v6 + 504;
  return v1;
}

//----- (00000098) --------------------------------------------------------
int __fastcall std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::_M_push_back_aux<CTRPluginFramework::Event const&>(void **a1, int *a2)
{
  void **v2; // r4
  unsigned int v3; // r3
  _BYTE *v4; // r2
  _BYTE *v5; // r0
  int *v6; // r7
  void **v7; // r1
  int v8; // r6
  int v9; // r5
  void **v10; // r5
  int v11; // r3
  size_t v12; // r2
  void **v13; // r0
  char *v14; // r3
  int v15; // r6
  char *v16; // r3
  _DWORD *v17; // r5
  int *v18; // r3
  int result; // r0
  int v20; // r1
  int v21; // r2
  _DWORD *v22; // r3
  int v23; // r3
  signed int v24; // r8
  unsigned int v25; // r8
  char *v26; // r0
  const void *v27; // r1
  int v28; // r2
  void *v29; // r9

  v2 = a1;
  v3 = (unsigned int)a1[1];
  v4 = a1[9];
  v5 = *a1;
  v6 = a2;
  if ( v3 - ((v4 - v5) >> 2) <= 1 )
  {
    v7 = (void **)v2[5];
    v8 = (v4 - (_BYTE *)v7) >> 2;
    v9 = v8 + 2;
    if ( v3 <= 2 * (v8 + 2) )
    {
      if ( v3 )
        v24 = v3;
      else
        v24 = 1;
      v25 = v3 + 2 + v24;
      if ( v25 > 0x3FFFFFFF )
        std::__throw_bad_alloc();
      v26 = (char *)operator new(4 * v25);
      v27 = v2[5];
      v28 = (int)v2[9] + 4;
      v29 = v26;
      v10 = (void **)&v26[4 * ((v25 - v9) >> 1)];
      if ( v27 != (const void *)v28 )
        memmove(v10, v27, v28 - (_DWORD)v27);
      operator delete(*v2);
      *v2 = v29;
      v2[1] = (void *)v25;
      goto LABEL_6;
    }
    v10 = (void **)&v5[4 * ((v3 - v9) >> 1)];
    v11 = (int)(v4 + 4);
    v12 = v4 + 4 - (_BYTE *)v7;
    if ( v7 <= v10 )
    {
      if ( v7 != (void **)v11 )
      {
        v13 = (void **)((char *)v10 + 4 * (v8 + 1) - v12);
        goto LABEL_10;
      }
    }
    else if ( v7 != (void **)v11 )
    {
      v13 = v10;
LABEL_10:
      memmove(v13, v7, v12);
      goto LABEL_6;
    }
LABEL_6:
    v2[5] = v10;
    v14 = (char *)*v10;
    v15 = v8 + 0x40000000;
    v2[3] = *v10;
    v2[4] = v14 + 504;
    v2[9] = &v10[v15];
    v16 = (char *)v10[v15];
    v2[7] = v16;
    v2[8] = v16 + 504;
  }
  v17 = v2[9];
  v17[1] = operator new(0x1F8u);
  v18 = (int *)v2[6];
  result = *v6;
  v20 = v6[1];
  v21 = v6[2];
  *v18 = *v6;
  v18[1] = v20;
  v18[2] = v21;
  v22 = v2[9];
  v2[9] = v22 + 1;
  v23 = v22[1];
  v2[7] = (void *)v23;
  v2[8] = (void *)(v23 + 504);
  v2[6] = (void *)v23;
  return result;
}

//----- (000001F8) --------------------------------------------------------
int __fastcall std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back(int a1, int *a2)
{
  int *v2; // r12
  int v3; // r3
  int result; // r0
  int v5; // t0
  int v6; // r1
  int v7; // r2

  v2 = *(int **)(a1 + 24);
  if ( v2 == (int *)(*(_DWORD *)(a1 + 32) - 12) )
    return std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::_M_push_back_aux<CTRPluginFramework::Event const&>(
             (void **)a1,
             a2);
  v3 = a1;
  result = *a2;
  v5 = (int)(a2 + 1);
  v6 = a2[1];
  v7 = *(_DWORD *)(v5 + 4);
  *v2 = result;
  v2[1] = v6;
  v2[2] = v7;
  *(_DWORD *)(v3 + 24) += 12;
  return result;
}

//----- (00000234) --------------------------------------------------------
int __fastcall CTRPluginFramework::EventManager::PushEvent(CTRPluginFramework::EventManager *this, const Event *a2)
{
  return std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back(
           (int)this,
           (int *)a2);
}

//----- (00000240) --------------------------------------------------------
int __fastcall CTRPluginFramework::EventManager::ProcessEvents(CTRPluginFramework::EventManager *this, int a2, __int64 a3)
{
  int v3; // r6
  CTRPluginFramework::EventManager *v4; // r4
  int result; // r0
  __int64 v6; // r2
  signed int v7; // r1
  bool v8; // zf
  int v9; // r3
  int v10; // r6
  int v11; // r5
  char v12; // r3
  signed int v13; // r7
  signed int v14; // r8
  _BOOL4 v15; // r6
  _BOOL4 v16; // r5
  CTRPluginFramework::EventManager *v17; // [sp+0h] [bp-28h]
  int v18; // [sp+4h] [bp-24h]
  __int64 v19; // [sp+8h] [bp-20h]

  v17 = this;
  v18 = a2;
  v19 = a3;
  v3 = 0;
  v4 = this;
  CTRPluginFramework::Controller::Update(this);
  do
  {
    if ( CTRPluginFramework::Controller::IsKeyPressed(1 << v3) )
    {
      LOBYTE(v18) = 0;
      LODWORD(v19) = 1 << v3;
      std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
    }
    if ( CTRPluginFramework::Controller::IsKeyDown(1 << v3) )
    {
      LOBYTE(v18) = 1;
      LODWORD(v19) = 1 << v3;
      std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
    }
    if ( CTRPluginFramework::Controller::IsKeyReleased(1 << v3) )
    {
      LOBYTE(v18) = 2;
      LODWORD(v19) = 1 << v3;
      std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
    }
    ++v3;
  }
  while ( v3 != 32 );
  hidTouchRead(&v17);
  result = CTRPluginFramework::Controller::IsKeyDown(0x100000);
  if ( result )
  {
    LODWORD(v6) = (unsigned __int16)v17;
    HIDWORD(v6) = HIWORD(v17);
    result = (unsigned __int8)CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching;
    if ( *((unsigned __int16 *)v4 + 20) != (unsigned __int16)v17
      || *((unsigned __int16 *)v4 + 21) != HIWORD(v17)
      || !CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching )
    {
      v7 = (signed int)v17;
      v8 = CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching == 0;
      *((_DWORD *)v4 + 10) = v17;
      if ( result )
        v7 = 6;
      else
        LOBYTE(result) = 5;
      if ( v8 )
        CTRPluginFramework::EventManager::ProcessEvents(void)::firstTouch = v7;
      else
        LOBYTE(v18) = v7;
      if ( v8 )
        LOBYTE(v18) = result;
      CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching = 1;
      v19 = v6;
      result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
      *((_DWORD *)v4 + 10) = v17;
    }
    return result;
  }
  if ( !CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching )
    return result;
  LOBYTE(v18) = 7;
  v9 = *((unsigned __int16 *)v4 + 20);
  CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching = 0;
  LODWORD(v19) = v9;
  HIDWORD(v19) = *((unsigned __int16 *)v4 + 21);
  result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
  v10 = (unsigned __int16)CTRPluginFramework::EventManager::ProcessEvents(void)::firstTouch
      - *((unsigned __int16 *)v4 + 20);
  v11 = HIWORD(CTRPluginFramework::EventManager::ProcessEvents(void)::firstTouch) - *((unsigned __int16 *)v4 + 21);
  LOBYTE(v18) = 8;
  if ( abs(v10) <= 50 && abs(v11) <= 50 )
    return result;
  if ( v10 > 50 )
  {
    v12 = 2;
LABEL_31:
    LOBYTE(v19) = v12;
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
    goto LABEL_32;
  }
  if ( (v10 + 50 < 0) ^ __OFADD__(v10, 50) )
  {
    v12 = 1;
    goto LABEL_31;
  }
LABEL_32:
  if ( (v11 + 50 < 0) ^ __OFADD__(v11, 50) )
  {
    LOBYTE(v19) = 4;
LABEL_36:
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
    goto LABEL_37;
  }
  if ( v11 > 50 )
  {
    LOBYTE(v19) = 8;
    goto LABEL_36;
  }
LABEL_37:
  if ( (v10 + 50 < 0) ^ __OFADD__(v10, 50) )
    v13 = 1;
  else
    v13 = 0;
  if ( (v11 + 50 < 0) ^ __OFADD__(v11, 50) )
    v14 = 1;
  else
    v14 = 0;
  if ( v13 & v14 )
  {
    LOBYTE(v19) = 5;
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
  }
  v15 = v10 > 50;
  if ( v14 & v15 )
  {
    LOBYTE(v19) = 6;
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
  }
  v16 = v11 > 50;
  if ( v13 & v16 )
  {
    LOBYTE(v19) = 9;
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
  }
  if ( v15 && v16 )
  {
    LOBYTE(v19) = 10;
    result = std::deque<CTRPluginFramework::Event,std::allocator<CTRPluginFramework::Event>>::push_back((int)v4, &v18);
  }
  return result;
}
// 2: using guessed type char CTRPluginFramework::EventManager::ProcessEvents(void)::isTouching;
// 4: using guessed type int CTRPluginFramework::EventManager::ProcessEvents(void)::firstTouch;
// 5F8: using guessed type int __fastcall CTRPluginFramework::Controller::IsKeyPressed(_DWORD);
// 5FC: using guessed type int __fastcall CTRPluginFramework::Controller::IsKeyDown(_DWORD);
// 600: using guessed type int __fastcall CTRPluginFramework::Controller::IsKeyReleased(_DWORD);
// 604: using guessed type int __fastcall hidTouchRead(_DWORD);

//----- (000004DC) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::EventManager::PopEvent(__int64 this, int a2)
{
  int v2; // r7
  _DWORD *v3; // r6
  int v4; // r4
  __int64 v5; // r2
  int v6; // r1
  __int64 v7; // r2
  _DWORD *v8; // r3
  signed int result; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r3
  __int64 v15; // [sp+0h] [bp-20h]
  int v16; // [sp+8h] [bp-18h]

  v15 = this;
  v16 = a2;
  v2 = a2;
  LODWORD(v5) = (unsigned __int8)CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh;
  v3 = (_DWORD *)HIDWORD(this);
  v4 = this;
  HIDWORD(this) = *(_DWORD *)(this + 24);
  HIDWORD(v5) = *(_DWORD *)(this + 8);
  if ( CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh )
  {
    if ( HIDWORD(this) == HIDWORD(v5) )
    {
      CTRPluginFramework::EventManager::ProcessEvents((CTRPluginFramework::EventManager *)this, SHIDWORD(this), v5);
      if ( v2 )
      {
        while ( *(_DWORD *)(v4 + 8) == *(_DWORD *)(v4 + 24) )
        {
          CTRPluginFramework::Milliseconds((CTRPluginFramework *)&v15, 10);
          CTRPluginFramework::Sleep((CTRPluginFramework *)v15, HIDWORD(v15));
          CTRPluginFramework::EventManager::ProcessEvents((CTRPluginFramework::EventManager *)v4, v6, v7);
        }
      }
    }
  }
  else if ( HIDWORD(this) == HIDWORD(v5) )
  {
    CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh = 1;
  }
  v8 = *(_DWORD **)(v4 + 8);
  if ( *(_DWORD **)(v4 + 24) == v8 )
    return 0;
  v10 = v8[1];
  v11 = v8[2];
  *v3 = *v8;
  v3[1] = v10;
  v3[2] = v11;
  v12 = *(_DWORD *)(v4 + 8);
  if ( v12 == *(_DWORD *)(v4 + 16) - 12 )
  {
    operator delete(*(void **)(v4 + 12));
    v14 = *(_DWORD *)(v4 + 20);
    *(_DWORD *)(v4 + 20) = v14 + 4;
    v13 = *(_DWORD *)(v14 + 4);
    *(_DWORD *)(v4 + 12) = v13;
    *(_DWORD *)(v4 + 16) = v13 + 504;
  }
  else
  {
    v13 = v12 + 12;
  }
  *(_DWORD *)(v4 + 8) = v13;
  result = 1;
  if ( *(_DWORD *)(v4 + 24) == *(_DWORD *)(v4 + 8) )
    CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh = 0;
  return result;
}
// 1: using guessed type char CTRPluginFramework::EventManager::PopEvent(CTRPluginFramework::Event &,bool)::refresh;

//----- (000005D4) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::EventManager::PollEvent(__int64 this)
{
  return CTRPluginFramework::EventManager::PopEvent(this, 0);
}

//----- (000005DC) --------------------------------------------------------
signed int __fastcall CTRPluginFramework::EventManager::WaitEvent(__int64 this)
{
  return CTRPluginFramework::EventManager::PopEvent(this, 1);
}

// ALL OK, 8 function(s) have been successfully decompiled