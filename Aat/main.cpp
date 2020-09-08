#include "pch.h"
#include "Game.h"

#define _CRTDBG_MAP_ALLOC

#include <cstdlib>

#include <crtdbg.h>

#ifdef _DEBUG

#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#endif

int main()
{
	//_CrtSetBreakAlloc(2668);
	Game game_instance;
	game_instance.GameLoop();
	_CrtDumpMemoryLeaks();
}
