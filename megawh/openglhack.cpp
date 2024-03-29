// openglhack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MinHook.h"
#pragma comment(lib,"libMinHook.x86.lib")

////////////////////////////////
//		Typedefs			//
////////////////////////////////
typedef void ( APIENTRY *glBegin_t )( GLenum );
typedef void ( APIENTRY *glClear_t )( GLbitfield );

glBegin_t pglBegin = NULL;
glClear_t pglClear = NULL;
glClear_t pglClear_ptr = NULL;
#define IsKeyPressed(CODE) ((GetAsyncKeyState(CODE) & 0x8000) > 0)


BOOL bAsusWallHack = 0;

typedef void (APIENTRY* glBegin_t)(GLenum mode);
glBegin_t pglBegin_t = NULL;
glBegin_t pglBegin_t_ptr = NULL;


void APIENTRY Hooked_glBegin( GLenum mode )
{
	if ( mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN )
	{
		glDepthRange( 0.0f, 0.5f );
	}
	else
	{
		glDepthRange(0.0f, 1.0f);
	}
	pglBegin_t_ptr( mode );
}

void APIENTRY Hooked_glClear( GLbitfield mask )
{
	if ( mask == GL_DEPTH_BUFFER_BIT)
	{
		pglClear_ptr( GL_COLOR_BUFFER_BIT );
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	}
	pglClear_ptr( mask );
}

DWORD WINAPI dwMainThread( LPVOID )
{
	Sleep( 3000 );
	MH_Initialize();
	HMODULE hmOpenGL = LoadLibraryA("opengl32.dll");

	DWORD olprot;

	pglBegin_t = (glBegin_t)(GetProcAddress(hmOpenGL, "glBegin"));
	VirtualProtect(pglBegin_t, 12, PAGE_EXECUTE_READWRITE, &olprot);

	MH_CreateHook(pglBegin_t, &Hooked_glBegin, reinterpret_cast<void**>(&pglBegin_t_ptr));
	MH_EnableHook(pglBegin_t);

	VirtualProtect(pglBegin_t, 12, olprot, &olprot);
	FlushInstructionCache(GetCurrentProcess(), pglBegin_t, 12);


	pglClear = (glClear_t)(LPVOID)GetProcAddress(hmOpenGL, "glClear");

	
	VirtualProtect(pglClear, 12, PAGE_EXECUTE_READWRITE, &olprot);

	MH_CreateHook(pglClear, &Hooked_glClear, reinterpret_cast<void**>(&pglClear_ptr));
	MH_EnableHook(pglClear);

	VirtualProtect(pglClear, 12, olprot, &olprot);


	return 1;
}

HRESULT __stdcall DllMain( HMODULE _hModule, DWORD dwReason, LPVOID lpReserved )
{
	if ( dwReason == DLL_PROCESS_ATTACH )
	{
		char tmp[ MAX_PATH + 1 ];
		GetModuleFileNameA(_hModule, tmp, MAX_PATH + 1 );
		LoadLibraryA( tmp );
		CreateThread( 0, 0, dwMainThread, 0, 0, 0 );
	}
	return 1;
}



