// CppDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "CppDll.h"
#include <iostream>
#include "minidumper.h"

using namespace std;

CMiniDumper dump(true);
//声明
typedef bool (CALLBACK *Receive)(char *pBuf, int nBufSize);
Receive m_RecInfoCall ;  //回复信息的回调函数

//设置回调函数
extern "C"__declspec(dllexport)BOOL WINAPI SetCallback(Receive InfoReceive)
{
  dump.setPath(L"D:\\");
	m_RecInfoCall = InfoReceive;
	return TRUE;
} 

extern "C" __declspec(dllexport) int __stdcall AddCalc(int plus1, int plus2)
{
  //dump.setPath(L"D:\\Esri\\");
	int add_result = plus1 + plus2;
	char pChar[22];
	itoa(plus1,pChar,10);
  char *p = NULL;
  memcpy(p, "HELLO", strlen("HELLO"));
	m_RecInfoCall(pChar,3);		//回调执行

	return add_result;
}

