// get_FirewallEnabled.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <netfw.h>
#include <Windows.h>  
#include <assert.h>

HRESULT WindowsFirewallInitialize(OUT INetFwProfile** fwProfile)  
{  
	HRESULT hr = S_OK;  
	INetFwMgr *fwMgr = NULL;  
	INetFwPolicy *fwPolicy = NULL;  

	assert(fwProfile != NULL);  

	*fwProfile = NULL;  

	hr = CoCreateInstance(  
		__uuidof(NetFwMgr),  
		NULL,  
		CLSCTX_INPROC_SERVER,  
		__uuidof(INetFwMgr),  
		(void **)&fwMgr);  

	if (FAILED(hr))  
	{  
		printf("CoCreateInstance failed: 0x%08lx\n", hr);  
		goto error;  
	}  

	hr = fwMgr->get_LocalPolicy(&fwPolicy);  
	if (FAILED(hr))  
	{  
		printf("get_localPolicy failed: 0x%08lx\n", hr);  
		goto error;  
	}  

	hr = fwPolicy->get_CurrentProfile(fwProfile);  
	if (FAILED(hr))  
	{  
		printf("get_CurrentProfile failed: 0x%08lx\n", hr);  
		goto error;  
	}  

error:  
	if (fwPolicy != NULL)  
	{  
		fwPolicy->Release();  
	}  

	if (fwMgr != NULL)  
	{  
		fwMgr->Release();  
	}  

	return hr;  
}  

void getFireWallStatus()
{
	HRESULT hr = S_OK;
	HRESULT comInit = E_FAIL;  
	INetFwProfile *iNetFwProFile = NULL;
	INetFwProfile *fwProfile = NULL;
	VARIANT_BOOL fwEnabled;

	comInit = CoInitializeEx(  
		0,  
		COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

	hr = E_NOTINTERFACE;

	printf("GetLastError(%d)",GetLastError());
	if (comInit != RPC_E_CHANGED_MODE)  
	{
		hr = comInit;  
		if (FAILED(hr))  
		{  
			printf("GetLastError(%d)\n",GetLastError());
			printf("CoInitializeEx failed: 0x%08lx\n", hr);  
			return;
		}  
	} 

	hr = WindowsFirewallInitialize(&fwProfile);  
	if (FAILED(hr))  
	{  
		printf("WindowsFirewallInitialize failed: 0x%08lx\n", hr);  
		return;
	}  

	assert(fwProfile != NULL);  

	hr = fwProfile->get_FirewallEnabled(&fwEnabled);  
	if (FAILED(hr))  
	{  
		printf("get_FirewallEnabled failed: 0x%08lx\n", hr);  
		return;
	} 


	if (fwEnabled != VARIANT_FALSE)  
	{  
		printf("The firewall is on.\n");  
	}  
	else  
	{  
		printf("The firewall is off.\n");  
	}  

}


int _tmain(int argc, _TCHAR* argv[])
{

	getFireWallStatus();
	return 0;
}

