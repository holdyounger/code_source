// SM3_Demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "sm3.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	sm3_context sm3Ctx;
	string str = "123456123123123123123123123123";
	unsigned char msgbuf[] = "abc";
	unsigned char output[32];
	unsigned char outputhmac[32];
	

	sm3_starts(&sm3Ctx);
	sm3_update(&sm3Ctx, msgbuf, str.size());
	sm3_finish(&sm3Ctx, output);

	cout << "Msg = " << msgbuf << endl;

	cout << "sm3_finish result \t=";
	for (int i = 0; i < 32; i++)
		printf("%02x", output[i]);

	cout << endl;
	printf("sm3Ctx.buffer \t\t=");
	for (int i = 0; i < 64; i++)
		printf("%02x", sm3Ctx.buffer[i]);
	cout << endl;

	cout << "--------------------" << endl;

	sm3(msgbuf, _countof(msgbuf), outputhmac);

	printf("sm3Ctx.hmac.buffer \t=");
	for (int i = 0; i < 32; i++)
		printf("%02x", outputhmac[i]);
	cout << endl;
	return 0;
}

