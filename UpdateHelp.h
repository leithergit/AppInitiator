#pragma once
#include "stdafx.h"
#define GetLastErrorMsg(dwErrorCode,szLastErrorMsg) {\
	dwErrorCode = GetLastError();\
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,\
	NULL,\
	dwErrorCode,\
	MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),\
	(LPTSTR) &szLastErrorMsg,\
	0,\
	NULL);\
}
void *RegisterAppWnd(HWND hAppWnd);
void UnRegisterAppWnd(void *);
bool GetAppHwnd(TCHAR *szApppath,HWND &hAppWnd);
void ReleaseShareMemory(void *p);
void * CreateShareMemory(LPCTSTR szEntry = NULL);
void *OpenShareMemory(HANDLE &);
void CloseShareMemory(HANDLE &,void *pShareSection);
DWORD Session0CreateUserProcess(LPCTSTR lpApplicationName,	LPCTSTR lpCommandLine,	LPCTSTR lpCurrentDirectory ) ;
bool ServiceStop(LPCTSTR szService);
bool ServiceStart(LPCTSTR szService,int argc,LPCTSTR *szArgv);
bool IsServieInstalled(LPCTSTR szService);
