// IsNetFilePathExist.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "shlwapi.h"
#pragma comment(lib, "Shlwapi")
using namespace std;
int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		printf("请输入参数!");
		return 0;
	}

	for(int i = 0; i < argc;i++){
		printf("%s\n",argv[i]);
	}

	for (int i = 1; i < argc; i++) 
	{
		if( PathFileExistsA( argv[i] ) )
		{
			cout << argv[i] ;
			printf(" Exist\n");
		}
		else
		{
			cout << argv[i] ;
			printf(" doesn't Exist\n");
		}
	}
	
	return 0;
}

