// CreateService.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <WinSvc.h>
#include <winioctl.h>
#pragma comment(lib, "Advapi32.lib")


BOOL WLMiniSecMod_Install();

int g_dwLanguage = 1;

int _tmain(int argc, _TCHAR* argv[])
{
	printf("-------------Start Create-------------\n");
	WLMiniSecMod_Install();
	printf("-------------Start Created SUCCESS-------------\n");
	return 0;
}


BOOL WLMiniSecMod_Install()
{
	BOOL bResult = FALSE;
	//�򿪷�����ƹ�����
	SC_HANDLE hSCM = ::OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (hSCM == NULL)
	{
		printf(("Couldn't open service manager wlminisecmod, 0x%x\n"), GetLastError());
		return bResult;
	}

	// Get the executable file path
	TCHAR szFilePath[MAX_PATH] = {_T("system32\\drivers\\wlminisecmod.sys")};

	LPCTSTR lpszServiceName = _T("wlminisecmod");
	LPCTSTR lpszDisplayName = _T("Wnt mini white list");
	DWORD	dwServiceType = SERVICE_FILE_SYSTEM_DRIVER;	// �����ڶ������̵ķ������
	DWORD	dwStartType = SERVICE_DEMAND_START;				// �ɷ�����ƹ�����(SCM)�����ķ���
	DWORD	dwErrorControl = SERVICE_ERROR_NORMAL;			// �����������򽫰Ѹô����¼���¼���־�в����ؼ���ִ��
	DWORD	dwOrder = 0;

	//��������
	SC_HANDLE hService = ::CreateService(hSCM,
		lpszServiceName,
		lpszDisplayName,
		SERVICE_ALL_ACCESS,
		dwServiceType,
		dwStartType,
		dwErrorControl,
		szFilePath,
		_T("FSFilter Activity Monitor"),
		&dwOrder,
		_T("FltMgr"),
		NULL,
		NULL
		);

	goto END:
	if (hService == NULL)
	{
		::CloseServiceHandle(hSCM);

		if(ERROR_SERVICE_EXISTS != ::GetLastError())
		{
			printf(("Couldn't create service manager wlminisecmod, errno:%d\n"), GetLastError());


                if (1 == g_dwLanguage)
                {
                    MessageBoxEx(NULL, _T("Failed to create a service, restart the operating system and try again! "),  _T("wlminisecmod"), MB_OK, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
                }
                else
                {

                    MessageBoxEx(NULL, _T("��������ʧ��,��������ϵͳ�����ԣ�"),  _T("wlminisecmod"), MB_OK, MAKELANGID(LANG_CHINESE_SIMPLIFIED, SUBLANG_CHINESE_SIMPLIFIED));
                }
			

			return bResult;
		}
		else
		{
			bResult = TRUE;
			printf(("wlminisecmod is exist, Couldn't create service manager\n"));
			return bResult;
		}

		return bResult;
	}
	else
	{
		/*--���������ʲô���壿
		if (!::ChangeServiceConfig(
			hService,
			dwServiceType,
			dwStartType,
			dwErrorControl,
			szFilePath,
			_T("FSFilter Activity Monitor"),
			&dwOrder,
			_T(""),
			NULL,
			NULL,
			lpszDisplayName))
		{
			WriteError(_T("ChangeServiceConfig WlMinisecmod Error:%d"), GetLastError());
		}
		*/

		//����minifilterר��ע������Instance
		HKEY	hKey = NULL;
		DWORD	dwData = 0;
		WCHAR	wszTemp[MAX_PATH] = {0};

		swprintf(wszTemp, MAX_PATH,L"SYSTEM\\CurrentControlSet\\Services\\%ws\\Instances", lpszServiceName);
		if(RegCreateKeyEx(HKEY_LOCAL_MACHINE,wszTemp,0,L"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,(LPDWORD)&dwData) != ERROR_SUCCESS)
		{
			printf(("wlMiniSecMod  Create Instance Failed, 0x%x\n"), GetLastError());
			goto DONE;
		}
		else
		{
			printf(("wlMiniSecMod  Create Instance SUCCESS\n"));
		}

		//�ݶ�Ĭ��Instance�ͷ���ͬ��
		if(RegSetValueEx(hKey,L"DefaultInstance",0,REG_SZ,(CONST BYTE*)lpszServiceName,(DWORD)wcslen(lpszServiceName) * sizeof(WCHAR)) != ERROR_SUCCESS)
		{
			printf(("wlMiniSecMod  Create DefaultInst  Failed, 0x%x\n"), GetLastError());
			RegCloseKey(hKey);
			goto DONE;
		}
		else
		{
			printf(("wlMiniSecMod  Create DefaultInst SUCCESS\n"));
		}

		RegFlushKey(hKey);
		RegCloseKey(hKey);

		//���Altitude��flag

		swprintf(wszTemp, MAX_PATH,L"%ws\\%ws",wszTemp, lpszServiceName);

		if(RegCreateKeyEx(HKEY_LOCAL_MACHINE,wszTemp,0,L"",REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&hKey,(LPDWORD)&dwData)!=ERROR_SUCCESS)
		{
			printf(("wlMiniSecMod  Create Instance subkey  Failed, 0x%x\n"), GetLastError());
			goto DONE;
		}
		else
		{
			printf(("wlMiniSecMod  Create Instance subkey SUCCESS\n"));
		}

		// ע������������Altitude ֵ
		PWCHAR pwszAltitude = L"368329";  //���ֵ��Ҫ��������

		if(RegSetValueEx(hKey,L"Altitude",0,REG_SZ,(CONST BYTE*)pwszAltitude,(DWORD)wcslen(pwszAltitude) * sizeof(WCHAR)) != ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			goto DONE;
		}
		else
		{
			printf(("wlMiniSecMod  set Instance subkey [Altitude] SUCCESS\n"));
		}

		// ע������������Flags ֵ
		dwData=0x0;
		if(RegSetValueEx(hKey,L"Flags",0,REG_DWORD,(CONST BYTE*)&dwData,sizeof(DWORD))!=ERROR_SUCCESS)
		{
			RegCloseKey(hKey);
			goto DONE;
		}
		else
		{
			printf(("wlMiniSecMod  set Instance subkey [Flags] SUCCESS\n"));
		}

		//everything is ok !

		RegFlushKey(hKey);
		RegCloseKey(hKey);

		bResult = TRUE;


	}

DONE:
	if(hService != NULL)
	{
		::CloseServiceHandle(hService);
		hService = NULL;
	}
	
	if(hSCM != NULL)
	{
		::CloseServiceHandle(hSCM);
		hSCM = NULL;
	}

	printf("Release Handle SUCCESS\n");
	return bResult;
}