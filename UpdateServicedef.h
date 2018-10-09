#pragma once
#include <Windows.h>
#include <WinDef.h>
#include <Tchar.h>
#include <WTypes.h>

#define		_MinTime_2014_01_01_00_00_00	1388505600
#pragma pack(push)
#pragma pack(1)
typedef struct _VersionInfo
{
	WORD	nSize;
	TCHAR	szFilename[MAX_PATH];
	TCHAR	szDirectory[MAX_PATH];
	TCHAR	szCommandLine[128];
	TCHAR	szRemoteDir[MAX_PATH];
	TCHAR	szVersion[16];
	TCHAR	szService[128];	
	TCHAR	szOperation[128];		// Run,Service,Register;
	TCHAR	szArgv[128];
	int		nOpLevel;
	TCHAR	szMD5[36];
	BOOL	bService;
	BOOL	bDownloaded;			// if Download success it be TRUE else FALSE;
}VersionInfo;

// information for the software to update
typedef	struct __SoftWareUpdateInfo 
{
	WORD	nSize;
	TCHAR	szSoftWare[128];
	TCHAR	szFtpServer[128];
	WORD	nPort;	
	TCHAR	szInstallDir[MAX_PATH];	
	TCHAR	szAccount[32];
	TCHAR	szPassowrd[32];	
	BOOL	bAutoUpdate;			// if be ture it will update automaticly
	BOOL	bExistNewVersion;		// new version has been download
	time_t	tLastUpdate;			// last update time	
}SoftWareUpdateInfo;
#pragma pack(pop)