
#define _WIN32_WINNT 0x0501 
#define WINVER 0x0501 
#define NTDDI_VERSION 0x05010000
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN

#include <SDKDDKVer.h>

#include <stdio.h>
#include <tchar.h>

#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>   

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <string>
#define IsKeyPressed(CODE) ((GetAsyncKeyState(CODE) & 0x8000) > 0)


#include <intrin.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")

#include "ini.h"


using namespace std;

typedef void ( APIENTRY *glBegin_t )( GLenum );

glBegin_t pglBegin = NULL;

GLfloat round_eps( GLfloat v, GLfloat eps )
{
	return floor( v / eps + 0.5f )*eps;
}

GLfloat round_nth( GLfloat v, int n )
{
	return round_eps( v, pow( 10.f, n ) );
}

int latestokayaddress = 0;

struct handle_data {
	unsigned long process_id;
	HWND window_handle;
};


BOOL is_main_window( HWND handle )
{
	return GetWindow( handle, GW_OWNER ) == ( HWND )0 && IsWindowVisible( handle );
}

BOOL CALLBACK enum_windows_callback( HWND handle, LPARAM lParam )
{
	handle_data& data = *( handle_data* )lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId( handle, &process_id );
	if ( data.process_id != process_id || !is_main_window( handle ) )
		return TRUE;
	data.window_handle = handle;
	return FALSE;
}

HWND find_main_window( unsigned long process_id )
{
	handle_data data;
	data.process_id = process_id;
	data.window_handle = 0;
	EnumWindows( enum_windows_callback, ( LPARAM )&data );
	return data.window_handle;
}

HWND GetCurrentWindow( )
{
	return find_main_window( GetCurrentProcessId( ) );
}

HWND MainWindowHandle = GetCurrentWindow( );

BOOL IsSameViewport( int * a1, int * a2 )
{
	return a1[ 0 ] == a2[ 0 ] &&
		a1[ 1 ] == a2[ 1 ] &&
		a1[ 2 ] == a2[ 2 ] &&
		a1[ 3 ] == a2[ 3 ];
}

int currentviewport[ 4 ];
int viewport[ 4 ];

GLint color1[ 4 ];
GLint color2[ 4 ];



GLfloat constradiuscircle = 15.0f;


GLfloat constpointsize = 2.7f;
GLfloat optimizedpointsize = 20.0f;

GLfloat constoffset = 2.7f;
GLfloat optimizedoffset = 20.0f;


GLfloat optimizedradius = 20.0f;
GLfloat optimizedradius_pre = 20.0f;





DWORD WINAPI OptimizerCrosshair( LPVOID )
{
	while ( true )
	{
		Sleep( 5 );
		optimizedradius_pre = constradiuscircle / 1440.0f * currentviewport[ 2 ];
		optimizedoffset = constoffset / 1440.0f * currentviewport[ 2 ];
		optimizedpointsize = constpointsize / 1440.0f * currentviewport[ 2 ];

		if ( IsKeyPressed( VK_LBUTTON ) )
		{
		//	optimizedpointsize *= 0.8f;
			optimizedradius_pre *= 1.35f;
		}

		if ( IsKeyPressed( VK_CONTROL ) )
		{
		//	optimizedpointsize *= 0.8f;
			optimizedradius_pre *= 0.85f;
		}

		if ( IsKeyPressed( 'W' ) || IsKeyPressed( 'S' ) || IsKeyPressed( 'A' ) || IsKeyPressed( 'D' ) )
		{
			optimizedradius_pre *= 1.5f;
		}


	}

	return 0;
}



DWORD WINAPI OptimizerCrosshair2( LPVOID )
{
	while ( true )
	{
		Sleep( 1 );

		if ( optimizedradius != optimizedradius_pre )
		{
			if ( optimizedradius_pre > optimizedradius )
			{
				optimizedradius += 0.1f;
			}

			if ( optimizedradius_pre < optimizedradius )
			{
				optimizedradius -= 0.1f;
			}
		}

	}

	return 0;
}


void DrawCircle( GLfloat cx, GLfloat cy, GLfloat r, int num_segments, int start_segment, int end_segment )
{
	GLfloat theta = 2 * 3.1415926f / GLfloat( num_segments );
	GLfloat tangetial_factor = tanf( theta );//calculate the tangential factor 

	GLfloat radial_factor = cosf( theta );//calculate the radial factor 

	GLfloat x = r;//we start at angle = 0 

	GLfloat y = 0;

	glBegin( GL_LINE_LOOP );
	for ( int ii = 0; ii < num_segments; ii++ )
	{
		if ( ii >= start_segment && ii < end_segment )
			glVertex2f( x + cx, y + cy );//output vertex 

										 //calculate the tangential vector 
										 //remember, the radial vector is (x, y) 
										 //to get the tangential vector we flip those coordinates and negate one of them 

		GLfloat tx = -y;
		GLfloat ty = x;

		//add the tangential vector 

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor 

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd( );
}

void DrawCircle( GLfloat cx, GLfloat cy, GLfloat r, int num_segments )
{
	GLfloat theta = 2 * 3.1415926f / GLfloat( num_segments );
	GLfloat tangetial_factor = tanf( theta );//calculate the tangential factor 

	GLfloat radial_factor = cosf( theta );//calculate the radial factor 

	GLfloat x = r;//we start at angle = 0 

	GLfloat y = 0;

	glBegin( GL_LINE_LOOP );
	for ( int ii = 0; ii < num_segments; ii++ )
	{
		glVertex2f( x + cx, y + cy );//output vertex 

									 //calculate the tangential vector 
									 //remember, the radial vector is (x, y) 
									 //to get the tangential vector we flip those coordinates and negate one of them 

		GLfloat tx = -y;
		GLfloat ty = x;

		//add the tangential vector 

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		//correct using the radial factor 

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd( );
}


void DrawArc( GLfloat cx, GLfloat cy, GLfloat r, GLfloat start_angle, GLfloat arc_angle, int num_segments )
{
	GLfloat theta = arc_angle / GLfloat( num_segments - 1 );//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	GLfloat tangetial_factor = tanf( theta );

	GLfloat radial_factor = cosf( theta );


	GLfloat x = r * cosf( start_angle );//we now start at the start angle
	GLfloat y = r * sinf( start_angle );

	glBegin( GL_LINE_STRIP );//since the arc is not a closed curve, this is a strip now

	for ( int ii = 0; ii < num_segments; ii++ )
	{
		glVertex2f( x + cx, y + cy );

		GLfloat tx = -y;
		GLfloat ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;
	}
	glEnd( );
}

int CrosshairType = 0; //  default+circle default+point point circle circle+point cross1 cross2 cross3

void SetCrosshairType( std::string s )
{
	if ( s == "default+circle" )
		CrosshairType = 0;
	else if ( s == "default+point" )
		CrosshairType = 1;
	else if ( s == "point" )
		CrosshairType = 2;
	else if ( s == "circle" )
		CrosshairType = 3;
	else if ( s == "circle+point" )
		CrosshairType = 4;
	else if ( s == "cross1" )
		CrosshairType = 5;
	else if ( s == "cross2" )
		CrosshairType = 6;
	else if ( s == "cross3" )
		CrosshairType = 7;
	else if ( s == "cross3" )
		CrosshairType = 9;

}

bool drawCrosshair( int okayaddress, GLint * currentColor )
{
	if ( currentColor[ 0 ] == 123 && currentColor[ 1 ] == 0 && currentColor[ 2 ] == 0 )
	{
		RECT winRect;
		GetClientRect( MainWindowHandle, &winRect );
		currentviewport[ 0 ] = 0;
		currentviewport[ 1 ] = 0;
		currentviewport[ 2 ] = winRect.right - winRect.left;
		currentviewport[ 3 ] = winRect.bottom - winRect.top;

		glGetIntegerv( GL_VIEWPORT, viewport );


		if ( IsSameViewport( currentviewport, viewport ) )
		{
			glPushMatrix( );

			GLfloat cx, cy, cross_len = 1.0f;


			cx = ( viewport[ 2 ] - viewport[ 0 ] ) / 2.0f;
			cy = ( viewport[ 3 ] - viewport[ 1 ] ) / 2.0f;

			glColor4f( color1[ 0 ] / 255.0f, color1[ 1 ] / 255.0f, color1[ 2 ] / 255.0f, color1[ 3 ] / 255.0f );

			if ( CrosshairType == 0 || CrosshairType == 3 || CrosshairType == 4 )
			{
				DrawArc( cx, cy, optimizedradius, 60, 30, 32 );
				DrawArc( cx, cy, optimizedradius, 330, 30, 32 );
				DrawArc( cx, cy, optimizedradius, 240, 30, 32 );
				DrawArc( cx, cy, optimizedradius, 150, 30, 32 );
			}
			else if ( CrosshairType == 5 )
			{
				DrawCircle( cx, cy, optimizedradius, 36, 3, 7 );
				DrawCircle( cx, cy, optimizedradius, 36, 12, 16 );
				DrawCircle( cx, cy, optimizedradius, 36, 21, 25 );
				DrawCircle( cx, cy, optimizedradius, 36, 30, 34 );
			}
			else if ( CrosshairType == 6 )
			{
				glLineWidth( optimizedpointsize );
				glBegin( GL_LINES );
				glVertex2f( cx - optimizedradius, cy );
				glVertex2f( cx + optimizedradius, cy );
				glVertex2f( cx, cy - optimizedradius );
				glVertex2f( cx, cy + optimizedradius );
				glEnd( );
			}
			else if ( CrosshairType == 7 )
			{
				glLineWidth( optimizedpointsize );
				glBegin( GL_LINES );
				//1 line
				glVertex2f( cx - optimizedradius - optimizedoffset, cy );
				glVertex2f( cx - optimizedoffset, cy );

				//2 line
				glVertex2f( cx + optimizedoffset, cy );
				glVertex2f( cx + optimizedradius + optimizedoffset, cy );


				//3 line
				glVertex2f( cx, cy - optimizedradius - optimizedoffset );
				glVertex2f( cx, cy - optimizedoffset );

				//4 line
				glVertex2f( cx, cy + optimizedoffset );
				glVertex2f( cx, cy + optimizedradius + optimizedoffset );

				glEnd( );
			}
			else if ( CrosshairType == 8 )
			{
				glLineWidth( optimizedpointsize );
				glBegin( GL_LINES );
				//1 line
				glVertex2f( cx - optimizedradius - optimizedoffset, cy );
				glVertex2f( cx - optimizedoffset, cy );

				//2 line
				glVertex2f( cx + optimizedoffset, cy );
				glVertex2f( cx + optimizedradius + optimizedoffset, cy );


				//3 line
				glVertex2f( cx, cy - optimizedradius - optimizedoffset );
				glVertex2f( cx, cy - optimizedoffset );

				//4 line
				glVertex2f( cx, cy + optimizedoffset );
				glVertex2f( cx, cy + optimizedradius + optimizedoffset );

				glEnd( );


				glPointSize( optimizedpointsize * 0.85 );
				glBegin( GL_POINTS );
				glVertex2f( cx, cy );
				glEnd( );
			}


			glColor4f( color2[ 0 ] / 255.0f, color2[ 1 ] / 255.0f, color2[ 2 ] / 255.0f, color2[ 3 ] / 255.0f );


			if ( CrosshairType == 1 || CrosshairType == 2 || CrosshairType == 4 || CrosshairType == 5 )
			{
				glPointSize( optimizedpointsize );
				glBegin( GL_POINTS );
				glVertex2f( cx, cy );
				glEnd( );
			}

			glPopMatrix( );

			if ( CrosshairType == 0 || CrosshairType == 1 )
			{
				glColor4f( color1[ 0 ] / 255.0f, color1[ 1 ] / 255.0f, color1[ 2 ] / 255.0f, color1[ 3 ] / 255.0f );
				return false;
			}

			return true;
		}
	}
	return false;
}

void APIENTRY Hooked_glBegin( GLenum mode )
{
	int retaddr = ( int )_ReturnAddress( );
	if ( mode == GL_QUADS )
	{
		GLfloat currentColor[ 4 ];
		GLint currentColorFix[ 4 ];
		glGetFloatv( GL_CURRENT_COLOR, currentColor );

		currentColorFix[ 3 ] = ( GLint )( 255 * currentColor[ 3 ] );
		currentColorFix[ 0 ] = ( GLint )( 255 * currentColor[ 0 ] );
		currentColorFix[ 1 ] = ( GLint )( 255 * currentColor[ 1 ] );
		currentColorFix[ 2 ] = ( GLint )( 255 * currentColor[ 2 ] );


		if ( drawCrosshair( retaddr, currentColorFix ) )
		{
			glColor4i( 0, 0, 0, 255 );
		}
	}
	pglBegin( mode );
}

struct backupmemory
{
	BYTE * dst;
	BYTE * mem;
	int size;
};

std::vector<backupmemory> memlist;




void *DetourFunc( BYTE *src, const BYTE *dst, const int len )
{
	int dstaddr = 0;
	if ( src[ 0 ] == 0xE9 )
	{
		dstaddr = *( int* )&src[ 1 ] + (int)(src ) + 5;
	}
	BYTE *jmp = ( BYTE* )malloc( len + 5 );
	DWORD dwback;

	BYTE * oldmem = new BYTE[ len ];
	memcpy( oldmem, src, len );

	backupmemory tmpbackupmemory;
	tmpbackupmemory.dst = src;
	tmpbackupmemory.mem = oldmem;


	tmpbackupmemory.size = len;
	memlist.push_back( tmpbackupmemory );

	VirtualProtect( src, len, PAGE_EXECUTE_READWRITE, &dwback );
	memcpy( jmp, src, len );
	jmp += len;
	jmp[ 0 ] = 0xE9;
	*( DWORD* )( jmp + 1 ) = ( DWORD )( src + len - jmp ) - 5;
	src[ 0 ] = 0xE9;
	*( DWORD* )( src + 1 ) = ( DWORD )( dst - src ) - 5;
	VirtualProtect( src, len, dwback, &dwback );
	FlushInstructionCache( GetCurrentProcess( ), src, len );
	if ( dstaddr )
		return ( void * )dstaddr;
	return ( jmp - len );
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
	string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
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

inline bool exists_test0( const std::string& name ) {
	ifstream f( name.c_str( ) );
	return f.good( );
}


HMODULE hModule = NULL;

string ConfigFilename;

//
//Left trim
//
std::string trim_left( const std::string& str )
{
	const std::string pattern = " \f\n\r\t\v";
	return str.substr( str.find_first_not_of( pattern ) );
}

//
//Right trim
//
std::string trim_right( const std::string& str )
{
	const std::string pattern = " \f\n\r\t\v";
	return str.substr( 0, str.find_last_not_of( pattern ) + 1 );
}

//
//Left and Right trim
//
std::string trim( const std::string& str )
{
	return trim_left( trim_right( str ) );
}

BOOL DynamicCrosshair = TRUE;

DWORD WINAPI ConfigUpdater( LPVOID )
{
	while ( true )
	{
		Sleep( 5000 );

		if ( exists_test0( ConfigFilename ) )
		{
			INIReader reader( ConfigFilename );

			if ( reader.ParseError( ) < 0 ) {
				MessageBox( 0, "parse error", "", 0 );
				return 0;
			}

			constradiuscircle = (GLfloat) reader.GetReal( "Crosshair", "Scale1", 19.0 );
			constpointsize = ( GLfloat )reader.GetReal( "Crosshair", "Scale2", 2.8 );
			constoffset = ( GLfloat )reader.GetReal( "Crosshair", "Offset1", 2.8 );

			std::stringstream color1str;
			std::stringstream color2str;

			color1str << trim( reader.Get( "Crosshair", "Color1", "255 0 0 255" ) );
			color2str << trim( reader.Get( "Crosshair", "Color2", "255 0 0 255" ) );


			color1str >> color1[ 0 ];
			color1str >> color1[ 1 ];
			color1str >> color1[ 2 ];
			color1str >> color1[ 3 ];


			color2str >> color2[ 0 ];
			color2str >> color2[ 1 ];
			color2str >> color2[ 2 ];
			color2str >> color2[ 3 ];

			//char readeddata[ 256 ];
			//sprintf_s( readeddata, " SIZE1:%f SIZE2:%f color1: %X %X %X %X color2: %X %X %X %X", constradiuscircle, constpointsize,
			//	color1[ 0 ], color1[ 1 ], color1[ 2 ], color1[ 3 ], color2[ 0 ], color2[ 1 ], color2[ 2 ], color2[ 3 ] );
			//MessageBox( 0, readeddata, "", 0 );

			SetCrosshairType( trim( reader.Get( "Crosshair", "Type", "default+point" ) ) );

			DynamicCrosshair = reader.GetInteger( "Crosshair", "Dynamic", 1 );
		}
		else
		{
			ofstream f( ConfigFilename );
			f << "[Crosshair]" << std::endl;
			f << "Type=circle+point" << std::endl;
			f << "; default+circle default+point point circle circle+point cross1 cross2 cross3 cross4" << std::endl;
			f << "Color1 = 255 0 0 255" << std::endl;
			f << "Color2 = 200 0 0 255" << std::endl;
			f << "Scale1 = 19.0" << std::endl;
			f << "Scale2 = 2.8" << std::endl;
			f << "Offset1 = 3.0" << std::endl;
			f << "Dynamic = 1" << std::endl;
			f.close( );
		}
	}

	return 0;
}


DWORD WINAPI dwMainThread( LPVOID )
{
	Sleep( 3000 );

	pglBegin = ( glBegin_t )DetourFunc( ( LPBYTE )GetProcAddress( GetModuleHandleA( "opengl32.dll" ), "glBegin" ), ( LPBYTE )&Hooked_glBegin, 6 );

	char tmp[ MAX_PATH + 1 ];
	char tmp5[ MAX_PATH + 1 ];
	char tmp6[ MAX_PATH + 1 ];
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

	string newname = generate( 7 + ( rand( ) % 8 ) );

	char tmp2[ MAX_PATH + 1 ];
	sprintf_s( tmp2, "%s\\%s.asi", tmp, newname.c_str( ) );
	MoveFileA( tmp5, tmp2 );
	sprintf_s( tmp6, "%s.ini", tmp5 );
	sprintf_s( tmp2, "%s\\%s.asi.ini", tmp, newname.c_str( ) );
	MoveFileA( tmp6, tmp2 );


	ConfigFilename = tmp2;


	return 0;
}

HRESULT __stdcall DllMain(HMODULE _hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		hModule = _hModule;
		char tmp[MAX_PATH + 1];
		GetModuleFileNameA(hModule, tmp, MAX_PATH + 1);
		LoadLibraryA(tmp);
		CloseHandle(CreateThread(0, 0, dwMainThread, 0, 0, 0));
		CloseHandle(CreateThread(0, 0, OptimizerCrosshair, 0, 0, 0));
		CloseHandle(CreateThread(0, 0, OptimizerCrosshair2, 0, 0, 0));
		CloseHandle(CreateThread(0, 0, ConfigUpdater, 0, 0, 0));

	}
	if (dwReason == DLL_PROCESS_DETACH)
		RestoreMemory();
	return 1;
}