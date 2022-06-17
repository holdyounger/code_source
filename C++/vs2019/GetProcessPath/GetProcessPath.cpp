// GetProcessPath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>	//进程快照函数头文件
#include <Psapi.h>
#include <stdio.h>
#include <string>
#include <atlstr.h>
#include <locale>
#include <codecvt>

#pragma comment (lib,"Psapi.lib")

#define PRODUCT_UNINST_KEY _T("Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\TrustAgent")

using namespace std;

//获取客户端安装信息
std::string GetInstalledPath()
{
	USES_CONVERSION;
	BOOL bRet = FALSE;

	HKEY hKey;
	CString strCov;
	std::string strExePath = "";
	TCHAR szLocation[MAX_PATH] = { '\0' };
	DWORD dwSize = sizeof(DWORD);
	DWORD dwIndex = 0;
	DWORD dwType = REG_SZ;
	LONG lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, PRODUCT_UNINST_KEY, 0, KEY_READ, &hKey);

	if (ERROR_SUCCESS != lRet)
	{
		goto _END_;
	}

	lRet = RegQueryValueEx(hKey, TEXT("InstallDir"), 0, &dwType, NULL, &dwSize);
	lRet = RegQueryValueEx(hKey, TEXT("InstallDir"), NULL, &dwType, (LPBYTE)&szLocation, &dwSize);
	cout << "RegQueryValueEx returns " << lRet << "dwSize = " << dwSize;

	if (ERROR_SUCCESS != lRet)
	{
		goto _END_;
	}

	strCov.Format(_T("%s"), szLocation);
	if (wcslen(szLocation))
	{
		strExePath = W2A(strCov.GetBuffer());
		strCov.ReleaseBuffer();
	}

_END_:
	if (hKey)
	{
		RegCloseKey(hKey);
		hKey = nullptr;
	}

	return strExePath;
}

BOOL GetProcessFullPath(DWORD dwPID, TCHAR pszFullPath[MAX_PATH], __out std::string& str)
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (!hProcess)
	{
		cout << "Query Process With PID Failed, GetLastError()=" << GetLastError() << " PID:" << dwPID;
		str = "";
	}
	else
	{
		cout << "OpenProcess Process With PID SUCCESS, PID:" << dwPID;
	}

	char filePath[MAX_PATH];
	DWORD ret = GetModuleFileNameExA(hProcess, NULL, filePath, MAX_PATH);
	std::string file = filePath;

	if (hProcess)
	{
		CloseHandle(hProcess);
		hProcess = NULL;
	}

	str = ret == 0 ? "" : file;
	return true;
}

BOOL IsExistTrustAgentPro()
{
	int countProcess = 0;	//当前进程数量计数变量
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // 创建进程快照
	PROCESSENTRY32W currentProcess;	// 用来接收 hProcessSnap 的信息

	std::string strPath = GetInstalledPath(); // 安装路径
	strPath.append("\\").append("trustagent.exe");

	currentProcess.dwSize = sizeof(currentProcess);		//在使用这个结构之前，先设置它的大小
	HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//给系统内的所有进程拍一个快照

	if (hProcess == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot()调用失败!\n");
		return -1;
	}

	bool bMore = Process32First(hProcessSnap, &currentProcess);	//获取第一个进程信息
	while (bMore) {
		std::string str;
		TCHAR szProcessName[MAX_PATH] = { 0 };

		GetProcessFullPath(currentProcess.th32ProcessID, szProcessName, str);
		
		if (str == strPath)
		{
			return TRUE;
		}

		bMore = Process32Next(hProcessSnap, &currentProcess);	//遍历下一个
		countProcess++;
	}

	CloseHandle(hProcess);	//清除hProcess句柄

	return FALSE;
}
int main()
{
	IsExistTrustAgentPro();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
