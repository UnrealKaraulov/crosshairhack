// openglhack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MinHook.h"
#pragma comment(lib,"libMinHook.x86.lib")

////////////////////////////////
//		Typedefs			//
////////////////////////////////
typedef void ( APIENTRY *glBegin_t )( GLenum );
typedef void ( APIENTRY *glEnd_t )( void );
typedef void ( APIENTRY *glClear_t )( GLbitfield );
typedef void ( APIENTRY *glVertex3f_t )( GLfloat x, GLfloat y, GLfloat z );
typedef void ( APIENTRY *glEnable_t )( GLenum );

glBegin_t pglBegin = NULL;
glEnd_t pglEnd = NULL;
glClear_t pglClear = NULL;
glClear_t pglClear_ptr = NULL;
glVertex3f_t pglVertex3f = NULL;
glEnable_t pglEnable = NULL;
#define IsKeyPressed(CODE) ((GetAsyncKeyState(CODE) & 0x8000) > 0)



////////////////////////////////
//		BOOLS			   //
////////////////////////////////
BOOL bAsusWallHack = 0;
BOOL bxqzwh = 0;
BOOL bxqzwh2 = 0;


BOOL otherhack = 0;

BOOL bFlash = 0;
BOOL bSmoke = 0;
GLfloat coords[ 4 ];

bool bDrawnWorld = false; // отрисовывается ли мир?
bool bDrawingEnts = false; // отрисовываются ли энтити?
BOOL Found_An_Entity = FALSE;
bool nosky = false;

bool crosshairhack = false;


GLenum oldenum = 0;


typedef void (APIENTRY* glBegin_t)(GLenum mode);
glBegin_t pglBegin_t = NULL;
glBegin_t pglBegin_t_ptr = NULL;


void APIENTRY Hooked_glBegin( GLenum mode )
{
	////////////////////////////////
	//		 Hotkeys			//
	////////////////////////////////

	////////////////////////////////
	//	   Wallhack Codes	   //
	////////////////////////////////

	bFlash = 0;
	bSmoke = 0;
	nosky = false;
	if ( bAsusWallHack )	//Asus Wallhack
	{
		if ( ( mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN )
			&& Found_An_Entity == FALSE )
		{
			glDepthRange( 0.0f, 0.5f );
			Found_An_Entity = TRUE;
		}

		if ( ( mode == GL_POLYGON || mode == GL_TRIANGLES || mode == GL_QUADS || mode == GL_QUAD_STRIP )
			&& Found_An_Entity == TRUE )
		{
			glDepthRange( 0.0f, 1.0f );
			Found_An_Entity = FALSE;
		}
	}

	if ( bxqzwh )		  //XQZ Wallhack
	{
		if ( !( mode == GL_TRIANGLES || mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN || mode == GL_QUADS ) )
		{
			GLfloat curcol[ 4 ];
			glGetFloatv( GL_CURRENT_COLOR, curcol );
			glDisable( GL_DEPTH_TEST );
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
			glColor4f( curcol[ 0 ], curcol[ 1 ], curcol[ 2 ], 0.5f );
			glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
		}
	}

	if ( bxqzwh2 )
	{
		if ( !bDrawingEnts && bDrawnWorld )
		{
			if ( mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN )
			{
				bDrawingEnts = true;
				glClear( GL_DEPTH_BUFFER_BIT );
			}
		}
	}

	if ( otherhack )
	{
		if ( mode == GL_QUADS )
		{
			nosky = true;
			GLfloat smokecol[ 4 ];
			glGetFloatv( GL_CURRENT_COLOR, smokecol );
			if ( smokecol[ 3 ] > 0.7 )
			{
				if ( ( smokecol[ 0 ] == smokecol[ 1 ] ) && ( smokecol[ 0 ] == smokecol[ 2 ] ) && ( smokecol[ 0 ] != 0.0 ) && ( smokecol[ 0 ] != 1.0 ) )
				{
					bSmoke = 1;
				}
				else
				{
					bSmoke = 0;
				}

				
				if ( smokecol[ 0 ] >= 0.98 && smokecol[ 1 ] >= 0.98 && smokecol[ 2 ] >= 0.98 )
				{
					( *glGetFloatv )( GL_VIEWPORT, coords );
					bFlash = 1;
				}
				else
				{
					bFlash = 0;
				}
			}


		}


	}


	pglBegin_t_ptr( mode );
	oldenum = mode;
}

typedef void ( APIENTRY *glVertex2f_t )( GLfloat x, GLfloat y );
glVertex2f_t pglVertex2f = NULL;
glVertex2f_t pglVertex2f_ptr = NULL;

typedef void ( APIENTRY *glVertex3fv_t )( const GLfloat *v );
glVertex3fv_t pglVertex3fv = NULL;
glVertex3fv_t pglVertex3fv_ptr = NULL;


void APIENTRY hooked_glVertex2f( GLfloat x, GLfloat y )
{
	if ( bFlash == 1 )
	{
		if ( y == coords[ 3 ] )
		{
			return;
		}
	}

	pglVertex2f_ptr( x, y );
}


void APIENTRY hooked_glVertex3fv( const GLfloat *v )
{
	bDrawnWorld = true;

	if ( bSmoke == 1 || nosky )
	{
		return;
	}
	pglVertex3fv_ptr( v );
}

void APIENTRY Hooked_glClear( GLbitfield mask )
{
	if ( mask == GL_DEPTH_BUFFER_BIT && ( bSmoke == 1 || bFlash == 1 || bAsusWallHack || bxqzwh ) )
	{
		pglClear_ptr( GL_COLOR_BUFFER_BIT );
		glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	}
	pglClear_ptr( mask );
}




struct backupmemory
{
	BYTE * dst;
	BYTE * mem;
	int size;
};

std::vector<backupmemory> memlist;

void* DetourFunc(PBYTE src, const BYTE* dst, const int len)
{
	BYTE* jmp = (BYTE*)malloc(len + 5);
	DWORD dwBack;

	VirtualProtect(jmp, len + 5, PAGE_EXECUTE_READWRITE, &dwBack);
	VirtualProtect(src, len, PAGE_READWRITE, &dwBack);

	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = (BYTE)0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = (BYTE)0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;

	for (int i = 5; i < len; i++)
		src[i] = 0x90;

	VirtualProtect((PBYTE)src, len, dwBack, &dwBack);
	return(jmp - len);
}


void RestoreMemory( )
{
	for ( auto s : memlist )
	{
		DWORD dwback;
		VirtualProtect( s.dst, s.size, PAGE_EXECUTE_READWRITE, &dwback );
		memcpy( s.dst, s.mem, s.size );
		VirtualProtect( s.dst, s.size, dwback, &dwback );
	}
}

string generate( int max_length ) {
	string possible_characters = "йцукфываячсменгшпролитьщдзхъжбю";
	random_device rd;
	mt19937 engine( rd( ) );
	uniform_int_distribution<> dist( 0, possible_characters.size( ) - 1 );
	string ret = "";
	for ( int i = 0; i < max_length; i++ ) {
		int random_index = dist( engine ); //get index between 0 and possible_characters.size()-1
		ret += possible_characters[ random_index ];
	}
	return ret;
}

HMODULE hModule = NULL;
char tmp2[MAX_PATH + 1];
char tmp5[MAX_PATH + 1];


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


	pglVertex3fv = (glVertex3fv_t)(LPVOID)GetProcAddress(hmOpenGL, "glVertex3fv");

	VirtualProtect(pglVertex3fv, 12, PAGE_EXECUTE_READWRITE, &olprot);

	MH_CreateHook(pglVertex3fv, &hooked_glVertex3fv, reinterpret_cast<void**>(&pglVertex3fv_ptr));
	MH_EnableHook(pglVertex3fv);

	VirtualProtect(pglVertex3fv, 12, olprot, &olprot);



	pglVertex2f = (glVertex2f_t)(LPVOID)GetProcAddress(hmOpenGL, "glVertex2f");

	VirtualProtect(pglVertex2f, 12, PAGE_EXECUTE_READWRITE, &olprot);

	MH_CreateHook(pglVertex2f, &hooked_glVertex2f, reinterpret_cast<void**>(&pglVertex2f_ptr));
	MH_EnableHook(pglVertex2f);

	VirtualProtect(pglVertex2f, 12, olprot, &olprot);


	pglClear = (glClear_t)(LPVOID)GetProcAddress(hmOpenGL, "glClear");

	
	VirtualProtect(pglClear, 12, PAGE_EXECUTE_READWRITE, &olprot);

	MH_CreateHook(pglClear, &Hooked_glClear, reinterpret_cast<void**>(&pglClear_ptr));
	MH_EnableHook(pglClear);

	VirtualProtect(pglClear, 12, olprot, &olprot);

	/*


	char tmp[ MAX_PATH + 1 ];
	GetModuleFileNameA( hModule, tmp, MAX_PATH + 1 );
	GetModuleFileNameA( hModule, tmp5, MAX_PATH + 1 );


	for ( int i = MAX_PATH; i > 0; i-- )
	{
		if ( tmp[ i ] == '\\' || tmp[ i ] == '/' )
		{
			tmp[ i ] = '\0';
			break;
		}
	}

	string newname = generate( 10 + ( rand( ) % 4 ) );

	sprintf_s( tmp2, "%s\\..\\%s.txt", tmp, newname.c_str( ) );
	MoveFileA( tmp5, tmp2 );
	*/

	while ( true )
	{
		Sleep( 25 );

		int MaxTimer = 0;

		if ( IsKeyPressed( VK_F1 ) )
		{
			while ( IsKeyPressed( VK_F1 ) )
			{
				MaxTimer--;
				Sleep( 100 );
			}

			if ( MaxTimer <= 0 )
			{
				bAsusWallHack = !bAsusWallHack;
				if ( bAsusWallHack )
				{
					Beep( 700, 300 );
				}
				else
				{
					Beep( 1200, 300 );
				}
			}
		}
		MaxTimer = 0;
		if ( IsKeyPressed( VK_F2 ) )
		{
			while ( IsKeyPressed( VK_F2 ) )
			{
				MaxTimer--;
				Sleep( 100 );
			}
			if ( MaxTimer <= 0 )
			{
				bxqzwh = !bxqzwh;
				if ( bxqzwh )
				{
					Beep( 700, 300 );
				}
				else
				{
					Beep( 1200, 300 );
				}
			}
		}
		MaxTimer = 0;
		if ( IsKeyPressed( VK_F3 ) )
		{
			while ( IsKeyPressed( VK_F3 ) )
			{
				MaxTimer--;
				Sleep( 100 );
			}
			if ( MaxTimer <= 0 )
			{
				otherhack = !otherhack;
				if ( otherhack )
				{
					Beep( 700, 300 );
				}
				else
				{
					Beep( 1200, 300 );
				}
			}
		}


		MaxTimer = 0;
		if ( IsKeyPressed(VK_F4) )
		{
			while ( IsKeyPressed(VK_F4) )
			{
				MaxTimer--;
				Sleep( 100 );
			}
			if ( MaxTimer <= 0 )
			{
				crosshairhack = !crosshairhack;
				if ( crosshairhack )
				{
					Beep( 700, 300 );
				}
				else
				{
					Beep( 1200, 300 );
				}
			}
		}

		while ( IsKeyPressed( VK_F1 ) )
		{

		}

		while ( IsKeyPressed( VK_F2 ) )
		{

		}

		while (IsKeyPressed(VK_F3))
		{

		}

		while (IsKeyPressed(VK_F4))
		{

		}
	}

	return 1;
}

void fnExit2(void)
{
	MoveFileA(tmp2, tmp5);
}


HRESULT __stdcall DllMain( HMODULE _hModule, DWORD dwReason, LPVOID lpReserved )
{
	if ( dwReason == DLL_PROCESS_ATTACH )
	{
		hModule = _hModule;
		char tmp[ MAX_PATH + 1 ];
		GetModuleFileNameA( hModule, tmp, MAX_PATH + 1 );
		LoadLibraryA( tmp );
		CreateThread( 0, 0, dwMainThread, 0, 0, 0 );
		//atexit(fnExit2);
	}
	if ( dwReason == DLL_PROCESS_DETACH )
		RestoreMemory( );
	return 1;
}



