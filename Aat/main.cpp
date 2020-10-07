#include "pch.h"
#include "Engine.h"

#/*define _CRTDBG_MAP_ALLOC

#include <cstdlib>

#include <crtdbg.h>

#ifdef _DEBUG

#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#endif*/

int main()
{
	//HWND hWndConsole = GetConsoleWindow();
	//ShowWindow(hWndConsole, SW_HIDE);

	try
	{
		Aat::Engine engine;
		engine.Initialize();
		engine.Run();
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
