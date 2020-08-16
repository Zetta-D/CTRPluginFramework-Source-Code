/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU8(int result, unsigned int a2, signed int a3, _DWORD *a4);
int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU16(int result, unsigned int a2, signed int a3, _DWORD *a4);
_DWORD *__fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU32(_DWORD *result, unsigned int a2, signed int a3, int **a4);
bool __fastcall CTRPluginFramework::AlmostEqualRelative(CTRPluginFramework *this, float a2, float a3, float a4);
unsigned int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedFloat(unsigned int result, float a2, signed int a3, float *a4);


//----- (00000004) --------------------------------------------------------
int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU8(int result, unsigned int a2, signed int a3, _DWORD *a4)
{
  unsigned __int8 *v4; // r12
  int v5; // lr
  unsigned __int8 *v6; // r12
  unsigned int v7; // lr
  unsigned __int8 *v8; // r12
  int v9; // lr
  unsigned __int8 *v10; // r12
  unsigned int v11; // lr
  unsigned __int8 *v12; // r12
  unsigned int v13; // lr
  unsigned __int8 *v14; // r12
  unsigned int v15; // lr

  if ( a3 == 2048 )
  {
    while ( 1 )
    {
      v10 = *(unsigned __int8 **)(result + 56);
      if ( (unsigned int)v10 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v11 = *v10;
      if ( *(unsigned __int8 *)(result + 1384) < v11 )
      {
        *a4 = v10;
        a4[1] = v11;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      ++*(_DWORD *)(result + 56);
    }
  }
  else if ( a3 > 2048 )
  {
    switch ( a3 )
    {
      case 0x2000:
        while ( 1 )
        {
          v12 = *(unsigned __int8 **)(result + 56);
          if ( (unsigned int)v12 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v13 = *v12;
          if ( *(unsigned __int8 *)(result + 1384) > v13 )
          {
            *a4 = v12;
            a4[1] = v13;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          ++*(_DWORD *)(result + 56);
        }
        break;
      case 0x4000:
        while ( 1 )
        {
          v14 = *(unsigned __int8 **)(result + 56);
          if ( (unsigned int)v14 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v15 = *v14;
          if ( *(unsigned __int8 *)(result + 1384) >= v15 )
          {
            *a4 = v14;
            a4[1] = v15;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          ++*(_DWORD *)(result + 56);
        }
        break;
      case 0x1000:
        while ( 1 )
        {
          v6 = *(unsigned __int8 **)(result + 56);
          if ( (unsigned int)v6 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v7 = *v6;
          if ( *(unsigned __int8 *)(result + 1384) <= v7 )
          {
            *a4 = v6;
            a4[1] = v7;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          ++*(_DWORD *)(result + 56);
        }
        break;
    }
  }
  else if ( a3 == 512 )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int8 **)(result + 56);
      if ( (unsigned int)v8 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v9 = *(unsigned __int8 *)(result + 1384);
      if ( v9 == *v8 )
      {
        *a4 = v8;
        a4[1] = v9;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      ++*(_DWORD *)(result + 56);
    }
  }
  else if ( a3 == 1024 )
  {
    while ( 1 )
    {
      v4 = *(unsigned __int8 **)(result + 56);
      if ( (unsigned int)v4 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v5 = *v4;
      if ( *(unsigned __int8 *)(result + 1384) != v5 )
      {
        *a4 = v4;
        a4[1] = v5;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      ++*(_DWORD *)(result + 56);
    }
  }
  return result;
}

//----- (00000294) --------------------------------------------------------
int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU16(int result, unsigned int a2, signed int a3, _DWORD *a4)
{
  unsigned __int16 *v4; // r12
  int v5; // lr
  unsigned __int16 *v6; // r12
  unsigned int v7; // lr
  unsigned __int16 *v8; // r12
  int v9; // lr
  unsigned __int16 *v10; // r12
  unsigned int v11; // lr
  unsigned __int16 *v12; // r12
  unsigned int v13; // lr
  unsigned __int16 *v14; // r12
  unsigned int v15; // lr

  if ( a3 == 2048 )
  {
    while ( 1 )
    {
      v10 = *(unsigned __int16 **)(result + 56);
      if ( (unsigned int)v10 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v11 = *v10;
      if ( *(unsigned __int16 *)(result + 1384) < v11 )
      {
        *a4 = v10;
        a4[1] = v11;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      *(_DWORD *)(result + 56) += 2;
    }
  }
  else if ( a3 > 2048 )
  {
    switch ( a3 )
    {
      case 0x2000:
        while ( 1 )
        {
          v12 = *(unsigned __int16 **)(result + 56);
          if ( (unsigned int)v12 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v13 = *v12;
          if ( *(unsigned __int16 *)(result + 1384) > v13 )
          {
            *a4 = v12;
            a4[1] = v13;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          *(_DWORD *)(result + 56) += 2;
        }
        break;
      case 0x4000:
        while ( 1 )
        {
          v14 = *(unsigned __int16 **)(result + 56);
          if ( (unsigned int)v14 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v15 = *v14;
          if ( *(unsigned __int16 *)(result + 1384) >= v15 )
          {
            *a4 = v14;
            a4[1] = v15;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          *(_DWORD *)(result + 56) += 2;
        }
        break;
      case 0x1000:
        while ( 1 )
        {
          v6 = *(unsigned __int16 **)(result + 56);
          if ( (unsigned int)v6 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
            break;
          v7 = *v6;
          if ( *(unsigned __int16 *)(result + 1384) <= v7 )
          {
            *a4 = v6;
            a4[1] = v7;
            ++*(_DWORD *)(result + 64);
            ++*(_DWORD *)(result + 12);
            a4 += 2;
          }
          *(_DWORD *)(result + 56) += 2;
        }
        break;
    }
  }
  else if ( a3 == 512 )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int16 **)(result + 56);
      if ( (unsigned int)v8 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v9 = *(unsigned __int16 *)(result + 1384);
      if ( v9 == *v8 )
      {
        *a4 = v8;
        a4[1] = v9;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      *(_DWORD *)(result + 56) += 2;
    }
  }
  else if ( a3 == 1024 )
  {
    while ( 1 )
    {
      v4 = *(unsigned __int16 **)(result + 56);
      if ( (unsigned int)v4 > a2 || *(_DWORD *)(result + 64) >= *(_DWORD *)(result + 60) )
        break;
      v5 = *v4;
      if ( *(unsigned __int16 *)(result + 1384) != v5 )
      {
        *a4 = v4;
        a4[1] = v5;
        ++*(_DWORD *)(result + 64);
        ++*(_DWORD *)(result + 12);
        a4 += 2;
      }
      *(_DWORD *)(result + 56) += 2;
    }
  }
  return result;
}

//----- (0000053C) --------------------------------------------------------
_DWORD *__fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedU32(_DWORD *result, unsigned int a2, signed int a3, int **a4)
{
  int *v4; // r12
  int *v5; // lr
  int *v6; // r12
  int *v7; // lr
  int *v8; // r12
  int *v9; // lr
  int *v10; // r12
  int *v11; // lr
  int *v12; // r12
  int *v13; // lr
  int *v14; // r12
  int *v15; // lr

  if ( a3 == 2048 )
  {
    while ( 1 )
    {
      v10 = (int *)result[14];
      if ( (unsigned int)v10 > a2 || result[16] >= result[15] )
        break;
      v11 = (int *)*v10;
      if ( result[346] < (unsigned int)*v10 )
      {
        *a4 = v10;
        a4[1] = v11;
        ++result[16];
        ++result[3];
        a4 += 2;
      }
      result[14] += 4;
    }
  }
  else if ( a3 > 2048 )
  {
    switch ( a3 )
    {
      case 0x2000:
        while ( 1 )
        {
          v12 = (int *)result[14];
          if ( (unsigned int)v12 > a2 || result[16] >= result[15] )
            break;
          v13 = (int *)*v12;
          if ( result[346] > (unsigned int)*v12 )
          {
            *a4 = v12;
            a4[1] = v13;
            ++result[16];
            ++result[3];
            a4 += 2;
          }
          result[14] += 4;
        }
        break;
      case 0x4000:
        while ( 1 )
        {
          v14 = (int *)result[14];
          if ( (unsigned int)v14 > a2 || result[16] >= result[15] )
            break;
          v15 = (int *)*v14;
          if ( result[346] >= (unsigned int)*v14 )
          {
            *a4 = v14;
            a4[1] = v15;
            ++result[16];
            ++result[3];
            a4 += 2;
          }
          result[14] += 4;
        }
        break;
      case 0x1000:
        while ( 1 )
        {
          v6 = (int *)result[14];
          if ( (unsigned int)v6 > a2 || result[16] >= result[15] )
            break;
          v7 = (int *)*v6;
          if ( result[346] <= (unsigned int)*v6 )
          {
            *a4 = v6;
            a4[1] = v7;
            ++result[16];
            ++result[3];
            a4 += 2;
          }
          result[14] += 4;
        }
        break;
    }
  }
  else if ( a3 == 512 )
  {
    while ( 1 )
    {
      v8 = (int *)result[14];
      if ( (unsigned int)v8 > a2 || result[16] >= result[15] )
        break;
      v9 = (int *)result[346];
      if ( v9 == (int *)*v8 )
      {
        *a4 = v8;
        a4[1] = v9;
        ++result[16];
        ++result[3];
        a4 += 2;
      }
      result[14] += 4;
    }
  }
  else if ( a3 == 1024 )
  {
    while ( 1 )
    {
      v4 = (int *)result[14];
      if ( (unsigned int)v4 > a2 || result[16] >= result[15] )
        break;
      v5 = (int *)*v4;
      if ( result[346] != *v4 )
      {
        *a4 = v4;
        a4[1] = v5;
        ++result[16];
        ++result[3];
        a4 += 2;
      }
      result[14] += 4;
    }
  }
  return result;
}

//----- (000007CC) --------------------------------------------------------
bool __fastcall CTRPluginFramework::AlmostEqualRelative(CTRPluginFramework *this, float a2, float a3, float a4)
{
  float v4; // s0
  float v5; // s1
  float v6; // s2
  float v7; // s15
  float v8; // s0
  float v9; // s1

  v7 = v4 - v5;
  v8 = fabsf(v4);
  v9 = fabsf(v5);
  if ( v8 >= v9 )
    v9 = v8;
  return (float)(v9 * v6) >= fabsf(v7);
}

//----- (00000800) --------------------------------------------------------
unsigned int __fastcall CTRPluginFramework::Search32::FirstSearchSpecifiedFloat(unsigned int result, float a2, signed int a3, float *a4)
{
  int v4; // r12
  float *v5; // r4
  int v6; // r5
  float *v7; // r6
  float v8; // r2
  float v9; // s14
  int v10; // s1
  int v11; // r5
  float *v12; // r6
  float v13; // r2
  float v14; // s14
  int v15; // s1
  int v16; // r12
  int v17; // r12
  int v18; // r12
  float v19; // s15
  float v20; // s15
  float v21; // s15
  float v22; // s15

  if ( a3 == 2048 )
    v4 = result + 1376;
  v5 = (float *)result;
  if ( a3 == 2048 )
  {
    while ( 1 )
    {
      result = *((_DWORD *)v5 + 14);
      if ( result > LODWORD(a2) || *((_DWORD *)v5 + 16) >= *((_DWORD *)v5 + 15) )
        break;
      v20 = *(float *)result;
      if ( *(float *)(v4 + 8) < *(float *)result )
      {
        *(_DWORD *)a4 = result;
        a4[1] = v20;
        ++*((_DWORD *)v5 + 16);
        ++*((_DWORD *)v5 + 3);
        a4 += 2;
      }
      *((_DWORD *)v5 + 14) += 4;
    }
  }
  else if ( a3 > 2048 )
  {
    switch ( a3 )
    {
      case 0x2000:
        v16 = result + 1376;
        while ( 1 )
        {
          result = *((_DWORD *)v5 + 14);
          if ( result > LODWORD(a2) || *((_DWORD *)v5 + 16) >= *((_DWORD *)v5 + 15) )
            break;
          v21 = *(float *)result;
          if ( *(float *)(v16 + 8) > *(float *)result )
          {
            *(_DWORD *)a4 = result;
            a4[1] = v21;
            ++*((_DWORD *)v5 + 16);
            ++*((_DWORD *)v5 + 3);
            a4 += 2;
          }
          *((_DWORD *)v5 + 14) += 4;
        }
        break;
      case 0x4000:
        v17 = result + 1376;
        while ( 1 )
        {
          result = *((_DWORD *)v5 + 14);
          if ( result > LODWORD(a2) || *((_DWORD *)v5 + 16) >= *((_DWORD *)v5 + 15) )
            break;
          v22 = *(float *)result;
          if ( *(float *)(v17 + 8) >= *(float *)result )
          {
            *(_DWORD *)a4 = result;
            a4[1] = v22;
            ++*((_DWORD *)v5 + 16);
            ++*((_DWORD *)v5 + 3);
            a4 += 2;
          }
          *((_DWORD *)v5 + 14) += 4;
        }
        break;
      case 0x1000:
        v18 = result + 1376;
        while ( 1 )
        {
          result = *((_DWORD *)v5 + 14);
          if ( result > LODWORD(a2) || *((_DWORD *)v5 + 16) >= *((_DWORD *)v5 + 15) )
            break;
          v19 = *(float *)result;
          if ( *(float *)(v18 + 8) <= *(float *)result )
          {
            *(_DWORD *)a4 = result;
            a4[1] = v19;
            ++*((_DWORD *)v5 + 16);
            ++*((_DWORD *)v5 + 3);
            a4 += 2;
          }
          *((_DWORD *)v5 + 14) += 4;
        }
        break;
    }
  }
  else if ( a3 == 512 )
  {
    v6 = result + 1376;
    while ( 1 )
    {
      v7 = (float *)*((_DWORD *)v5 + 14);
      if ( (unsigned int)v7 > LODWORD(a2) )
        break;
      result = *((_DWORD *)v5 + 16);
      v8 = v5[15];
      if ( result >= LODWORD(v8) )
        break;
      v9 = *v7;
      if ( fabsf(*v7) <= 3.4028e38 )
      {
        v10 = *(_DWORD *)(v6 + 8);
        result = CTRPluginFramework::AlmostEqualRelative((CTRPluginFramework *)result, a2, v8, *(float *)&a4);
        if ( result )
        {
          *(_DWORD *)a4 = v7;
          a4[1] = v9;
          ++*((_DWORD *)v5 + 16);
          ++*((_DWORD *)v5 + 3);
          a4 += 2;
        }
      }
      *((_DWORD *)v5 + 14) += 4;
    }
  }
  else if ( a3 == 1024 )
  {
    v11 = result + 1376;
    while ( 1 )
    {
      v12 = (float *)*((_DWORD *)v5 + 14);
      if ( (unsigned int)v12 > LODWORD(a2) )
        break;
      result = *((_DWORD *)v5 + 16);
      v13 = v5[15];
      if ( result >= LODWORD(v13) )
        break;
      v14 = *v12;
      if ( fabsf(*v12) > 3.4028e38
        || (v15 = *(_DWORD *)(v11 + 8),
            (result = CTRPluginFramework::AlmostEqualRelative((CTRPluginFramework *)result, a2, v13, *(float *)&a4)) == 0) )
      {
        *(_DWORD *)a4 = v12;
        a4[1] = v14;
        ++*((_DWORD *)v5 + 16);
        ++*((_DWORD *)v5 + 3);
        a4 += 2;
      }
      *((_DWORD *)v5 + 14) += 4;
    }
  }
  return result;
}

// ALL OK, 5 function(s) have been successfully decompiled