// CppDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "CppDll.h"
#include <iostream>
#include "minidumper.h"

using namespace std;

CMiniDumper dump(true);
//����
typedef bool (CALLBACK *Receive)(char *pBuf, int nBufSize);
Receive m_RecInfoCall ;  //�ظ���Ϣ�Ļص�����

//���ûص�����
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
	m_RecInfoCall(pChar,3);		//�ص�ִ��

	return add_result;
}

