#include "CTRPluginFramework/System/Task.hpp"

namespace CTRPluginFramework
{

Task *Task::Task(Task *this, int (__cdecl *a2)(void *), void *a3, int a4)
{
  Task *v4; // r4
  int v5; // r8
  int (__cdecl *v6)(void *); // r7
  void *v7; // r6
  unsigned int *v8; // r0
  unsigned int *v9; // r5
  void *v10; // r0
  unsigned int v11; // r3

  v4 = this;
  v5 = a4;
  v6 = a2;
  v7 = a3;
  v8 = (unsigned int *)operator new(0x20u);
  v9 = v8;
  v10 = memset(v8, 0, 0x20u);
  *(_DWORD *)v4 = v9;
  v9[2] = -1;
  __mcr(15, 0, (unsigned int)v10, 7, 10, 5);
  do
    v11 = __ldrex(v9);
  while ( __strex(v11 + 1, v9) );
  __mcr(15, 0, (unsigned int)v10, 7, 10, 5);
  *(_DWORD *)(*(_DWORD *)v4 + 8) = v5;
  *(_DWORD *)(*(_DWORD *)v4 + 20) = v6;
  *(_DWORD *)(*(_DWORD *)v4 + 16) = v7;
  LightEvent_Init(*(_DWORD *)v4 + 24, 1);
  return v4;
}
// 19C: using guessed type int LightEvent_Init(_DWORD, _DWORD);

//----- (00000088) --------------------------------------------------------
unsigned int **Task::Task(unsigned int **result, unsigned int **a2)
{
  unsigned int *v2; // r3
  unsigned int v3; // r2

  v2 = *a2;
  *result = *a2;
  __mcr(15, 0, (unsigned int)result, 7, 10, 5);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 + 1, v2) );
  __mcr(15, 0, (unsigned int)result, 7, 10, 5);
  return result;
}

//----- (000000B0) --------------------------------------------------------
_DWORD *Task::Task(_DWORD *result, _DWORD *a2)
{
  *result = *a2;
  *a2 = 0;
  return result;
}

//----- (000000C4) --------------------------------------------------------
Task *Task::~Task(Task *this)
{
  unsigned int *v1; // r3
  Task *v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r2

  v1 = *(unsigned int **)this;
  v2 = this;
  if ( *(_DWORD *)this )
  {
    __mcr(15, 0, (unsigned int)this, 7, 10, 5);
    do
    {
      v3 = __ldrex(v1);
      v4 = v3 - 1;
    }
    while ( __strex(v4, v1) );
    __mcr(15, 0, (unsigned int)this, 7, 10, 5);
    if ( !v4 )
      operator delete(*(void **)this);
  }
  return v2;
}

int Task::Start(Task *this)
{
  const Task *v2;
  if ( !*(u32 *)this )
    return -1;
  v1 = this;
  LightEvent_Clear(*(u32 *)this + 24);
  return Scheduler::Schedule(this, v2);
}
// 1A4: using guessed type int LightEvent_Clear(_DWORD);

//----- (0000013C) --------------------------------------------------------
signed int Task::Wait(Task *this, int a2)
{
  int v2; // r3
  Task *v4; // r4

  v2 = *(_DWORD *)this;
  if ( !*(_DWORD *)this )
    return -1;
  if ( !(*(_DWORD *)(v2 + 4) & 0xFFFFFFFB) )
    return *(_DWORD *)(v2 + 12);
  v4 = this;
  LightEvent_Wait(v2 + 24, a2, *(_DWORD *)(v2 + 4) & 0xFFFFFFFB);
  return *(_DWORD *)(*(_DWORD *)v4 + 12);
}
// 1AC: using guessed type int LightEvent_Wait(_DWORD, _DWORD, _DWORD);

//----- (00000180) --------------------------------------------------------
signed int Task::Status(Task *this)
{
  signed int result; // r0

  if ( *(_DWORD *)this )
    result = *(_DWORD *)(*(_DWORD *)this + 4);
  else
    result = -1;
  return result;
}
}
