#include "CTRPluginFrameworkImpl/System/MMU.hpp"

const void *HookL2Table;
int dword_1200;

u32 L2MMUTable__CreateL2Table(int x)
{
  dword_1200 = x & 0xFFFFF000 | 0xDB6;
  return svcConvertVAToPA(HookL2Table, false) & 0x7FFFFC00 | 1;
}

u32 L1Descriptor__GetType(u32 x)
{
  if ( !(x & 3) || (x & 3) == 1 )
    return x & 3;
  if ( (x & 3) != 2 )
    return 4;
  if ( x & 0x40000 )
    return 3;
  return 2;
}

int L2Descriptor__GetType(u32 x)
{
  if ( (x & 3) == 1 )
    return 5;
  if ( x & 2 )
    return 6;
  return 0;
}

int L2MMUTable__RWXForAll(u32 *x)
{
  int i(0), res(0);
  u32 y(0);
  do
  {
    res = L2Descriptor__GetType(x[i]);
    if ( res == 5 )
      y &= 0x7DCF;
    else
    {
      if ( res != 6 )
        goto ADDI;
      y &= 0xFFFFFDCE;
    }
    y |= 0x30u;
    x[i] = __ROR4__(v5 >> 16, 16);
ADDI:
    ++i;
  }
  while ( i != 256 );
  return res;
}

u32 L1MMUTable__RWXForAll(u32 *x)
{
  int i(0);
  u32 res(0), y(0);
  do
  {
    res = L1Descriptor__GetType(x[i]);
    switch ( res )
    {
      case 2u:
        y &= 0x73EF;
LABEL_9:
        y |= 0xC00u;
        x[i] = __ROR4__(y >> 16, 16);
        break;
      case 3u:
        y &= 0xFFFFF3EF;
        goto LABEL_9;
      case 1u:
        res = L2MMUTable__RWXForAll((u32 *)((((y >> 10) & 0x1FFFFF) << 10) - 0x40000000));
        break;
    }
    ++i;
  }
  while ( i != 0x400 );
  return res;
}

int L1MMUTable__MapHookWrappers(s64 out, int a2)
{
  u32 v6(0);
  int table(0), res(0);

  svcGetProcessInfo(&out, 0xFFFF8001, 0x10009);
  switch (L1Descriptor__GetType(*(u32 *)(a2 + 4 * (out >> 20))))
  {
    case 2u:
      table = v6 >> 20 << 20;
      break;
    case 3u:
      table = v6 & 0xFF000000;
      break;
    case 1u:
      table = v6 & 0x7FFFFC00;
      break;
    default:
      svcBreak(USERBREAK_PANIC);
      break;
  }
  res = L2MMUTable__CreateL2Table(table);
  *(u32 *)(a2 + 120) = res;
  return res;
}
