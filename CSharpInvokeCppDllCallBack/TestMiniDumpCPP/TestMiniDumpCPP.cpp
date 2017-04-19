// TestMiniDumpCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CppDll/CppDll/minidumper.h"


int _tmain(int argc, _TCHAR* argv[])
{
  CMiniDumper dump(true);
  char *p = NULL;
  memcpy(p, "HELLO", strlen("HELLO"));
  return 0;
}

