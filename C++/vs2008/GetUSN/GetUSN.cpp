// GetUSN.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

#pragma comment(lib, "Kernel32.lib")

void getUSN()
{
	HANDLE		fileHd;
	HANDLE		ExistingCompletionPort;
	ULONG_PTR	CompletionKey;
	DWORD		NumberOfConcurrentThreads;
	HANDLE		hRet;

	fileHd = (HANDLE)CreateFileA((LPCSTR)"G:\\1.bat", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	if(fileHd == INVALID_HANDLE_VALUE)
	{
		fileHd = NULL;
		MessageBoxA(NULL, "Can not open the file", "Playwav", MB_OK);
	}
	else
	{
		MessageBoxA(NULL, "Open the file", "Playwav", MB_OK);
	}

	hRet = CreateIoCompletionPort(fileHd, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads);

	printf("ExistingCompletionPort(%d)\nCompletionKey(%d)\nNumberOfConcurrentThreads(%d)\n", ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads);
	

}


int _tmain(int argc, _TCHAR* argv[])
{
	getUSN();
	return 0;
}

