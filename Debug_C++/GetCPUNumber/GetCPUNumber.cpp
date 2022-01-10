// GetCPUNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;
unsigned core_count()  
{  
	unsigned count = 1; // 至少一个  
	SYSTEM_INFO si;  
	GetSystemInfo(&si);  
	count = si.dwNumberOfProcessors;  
	return count;  
}  

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned sz = core_count();
	cout << "The Number of CPU is " << sz << '.' << endl;
	system("pause");
	return 0;
}

