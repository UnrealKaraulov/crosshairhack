#include <Windows.h>
#include <filesystem>
std::string rawname;

DWORD WINAPI dwMainThread(LPVOID)
{
	LoadLibraryA(rawname.c_str());
	return TRUE;
}

HRESULT __stdcall DllMain(HMODULE _hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		char tmp[MAX_PATH + 1];
		GetModuleFileNameA(_hModule, tmp, MAX_PATH + 1);
		std::string tmp2 = tmp;
		size_t lastindex = tmp2.find_last_of(".");
		rawname = tmp2.substr(0, lastindex) + ".dll";
		CreateThread(0, 0, dwMainThread, 0, 0, 0);
	}
	return 1;
}

