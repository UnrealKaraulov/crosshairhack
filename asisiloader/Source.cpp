#include <Windows.h>
#include <filesystem>
std::string rawname;
HMODULE loaded_library;
HANDLE thread;

DWORD WINAPI dwMainThread(LPVOID)
{
	Sleep(1000);
	LoadLibraryA(rawname.c_str());
	return TRUE;
}

char tmp[MAX_PATH + 1];
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved)  // reserved
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		GetModuleFileNameA(hinstDLL, tmp, MAX_PATH + 1);
		LoadLibraryA(tmp);
		std::string tmp2 = tmp;
		size_t lastindex = tmp2.find_last_of(".");
		rawname = tmp2.substr(0, lastindex) + ".dll";
		thread = CreateThread(0, 0, dwMainThread, 0, 0, 0);
	}
	if (fdwReason == DLL_PROCESS_DETACH)
	{
		TerminateThread(thread, 0);
		if (loaded_library)
			FreeLibrary(loaded_library);
	}
	return 1;
}

