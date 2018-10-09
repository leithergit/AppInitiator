#pragma once
#include <Windows.h>
#include <WinDef.h>
#include <Tchar.h>
#include <WTypes.h>
#include "UpdateServicedef.h"
#define _MAX_APP		16
#define _ShareMemName			_T("Global\\{AF1066F3-E0B6-4EA4-9D88-AC35F3B6166B}")
#define _MutexName				_T("Global\\{069105A3-7C6C-4CBE-AFA8-7E4C2F7D8382}")
#define _UpdateTipsHandleName	_T("Global\\{4FDB6016-C703-489F-B855-912FE346B32D}")
#define _UpdateTipsExitHandleName	_T("Global\\{5B2FB25E-D382-4FC1-9893-2B349F8ABB5A}")
#define	_UpdateServiceMutex		_T("Global\\{1F2A7A73-3902-4987-AE1E-B76411CF10AB}")
#define	_UpdateWndMutex			_T("Global\\{153236A2-B8B5-40C7-89A5-E858A9050AE7}")
#define	_UpdateAssist			_T("{B3935180-6384-4EF1-9997-F09306A56CB3}")
#define _UpdateAppCommandLine	_UpdateAssist
#define _UpdateConfigireMutex	_T("Global\\{DD63F623-98FC-4984-B179-D3580DE72051}")
#define _UpdateService			_T("DVO Update Service")
#define _UpdateDirectory		_T("\\Update.tmp")
#define _Max_Share_Mem	32*sizeof(CShareSection)
#define _POP_UPDATETIPS_FREQ	30*60
#pragma pack(push)
#pragma pack(1)
typedef struct _CAppInfo
{
	HWND	hAppWnd;
	TCHAR	szAppPath[MAX_PATH];	
	TCHAR	szTips[128];
	time_t	tSendPop;
	time_t	tRecvPop;	
}CAppInfo;
typedef struct _CAppWndSection
{
	UINT		nWndCount;
	CAppInfo	pAppArray[_MAX_APP];
}CAppWndSection;

typedef	struct _CShareSection
{	
	TCHAR		szUpdateTips[128];
	HWND		hAppWndTips;
	HANDLE		hUpdateTipsEvent;	// Event to notify the Update Service Windows there is a new Systemtray notify
	HANDLE		hAppWndTipsExit;	// Event to notify the Update Service Windows Exit;
	CAppWndSection		AppWndSecion;
	SoftWareUpdateInfo	SoftArray[_MAX_APP];
}CShareSection;

// typedef	union _CShareMem
// {	
// 	void			*pMemAddress;
// 	CShareSection	*pShareSection;	
// }CShareMem;

typedef struct _CRegisterWnd
{	
	HANDLE		hMemmap;
	CShareSection	*pShareSection;
	HWND		hAppWnd;
	HANDLE		hRegisterThread;
	CRITICAL_SECTION csReg;	
	bool		bRegThreadRun;
	int			nRegIndex;
	HANDLE		hMutex;		// Mutex protect the AppwndSection in pShareSection
}CRegisterWnd;

typedef struct _CShareMemoryMgr
{
	WORD		cbSize;
	HANDLE		hMemMap;	
	HANDLE		hMutex;		// Mutex protect the AppwndSection in pShareSection
	HANDLE		hUpdateTipsEvent;	// Event to nofity the UpdateConfigure there is a new Systemtray notify
	CShareSection	*pShareSection;
}CShareMemoryMgr;

#pragma pack(pop)
