#pragma once
#include<vector>
#include<Psapi.h>
class Util
{
public:
	BOOL GetProcessModuleInfo(DWORD pid, std::vector<MODULEINFO>& moduleInfoList);
	BOOL IsValidHandle(HANDLE h);
};

