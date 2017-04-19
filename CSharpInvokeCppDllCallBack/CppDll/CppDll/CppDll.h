#ifndef CPP_H_
#define CPP_H_
#ifdef CPPLIB
#define CPPLIB extern "C" _declspec(dllimport) 
#else
#define CPPLIB extern "C" _declspec(dllexport) 
#endif
//CPPLIB int AddCalc(int plus1, int plus2);
//You can also write like this:
//extern "C" {
//_declspec(dllexport) int AddCalc(int plus1, int plus2);
//};
#endif