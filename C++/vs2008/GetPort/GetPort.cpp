// GetPort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

// getPort.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
// Need to link with Iphlpapi.lib and Ws2_32.lib
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <algorithm>

#include <set>
#include <vector>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

#define _WINSOCK_DEPRECATED_NO_WARNINGS

/* Note: could also use malloc() and free() */
vector<DWORD> g_Ports;

int main()
{

	int iRet = 0;
	int nNum = 0; // TCP���ӵ���Ŀ

	PMIB_TCPTABLE_OWNER_PID pTcpTable(NULL);
	DWORD dwSize(0);
	GetExtendedTcpTable(pTcpTable, &dwSize, TRUE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
	pTcpTable = (MIB_TCPTABLE_OWNER_PID *)new char[dwSize];//���·��仺����


	if (NO_ERROR != GetExtendedTcpTable(pTcpTable, &dwSize, TRUE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0))
	{
		delete pTcpTable;
		pTcpTable = NULL;
		{
			iRet = -1;
			goto _END_;
		}
	}

	// TCP���ӵ���Ŀ
	nNum = (int)pTcpTable->dwNumEntries;

	for (int i = 0; i < nNum; i++)
	{
		g_Ports.push_back(htons(pTcpTable->table[i].dwLocalPort));
	}

_END_:
	if (pTcpTable != NULL)
	{
		free(pTcpTable);
		pTcpTable = NULL;
	}

	std::sort(g_Ports.begin(), g_Ports.end());

	if (pTcpTable != NULL) {
		FREE(pTcpTable);
		pTcpTable = NULL;
	}

	int ii = 0;
	bool flag = false;

	cout << "num of all ports" << g_Ports.size() << endl;
	return 0;
}


// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

