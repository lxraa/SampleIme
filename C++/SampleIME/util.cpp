#include "stdafx.h"
#include "util.h"




BOOL Util::GetProcessModuleInfo(DWORD pid, std::vector<MODULEINFO>& moduleInfoList) {
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
	if (hProcess == NULL)
	{
		MessageBox(NULL, TEXT("[!] Get process handle(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ) failed"), TEXT("error"), MB_OK);
		return FALSE;
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		DWORD numModules = cbNeeded / sizeof(HMODULE);
		for (DWORD i = 0; i < numModules; ++i)
		{
			MODULEINFO moduleInfo;
			if (GetModuleInformation(hProcess, hMods[i], &moduleInfo, sizeof(moduleInfo)))
			{
				moduleInfoList.push_back(moduleInfo);
			}
			else
			{
				WCHAR buffer[400];
				swprintf_s(buffer, sizeof(buffer), TEXT("[!] Get process module %d information failed"), i);
				MessageBox(NULL, buffer, TEXT("error"), MB_OK);
			}
		}
	}
	else
	{
		MessageBox(NULL, TEXT("[!] Enumerate process modules failed"), TEXT("error"), MB_OK);
		
		CloseHandle(hProcess);
		return FALSE;
	}

	CloseHandle(hProcess);

	return TRUE;
}


BOOL Util::IsValidHandle(HANDLE h) {
	return (h != NULL && h != INVALID_HANDLE_VALUE);
}