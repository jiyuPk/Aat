#include "pch.h"
#include "Engine.h"

Aat::Engine::Engine()
{
	engineState = EngineState::Uninitialized;
	ms_per_update = 5;
}

Aat::Engine::~Engine()
{
}

void Aat::Engine::Initialize()
{
	engineState = EngineState::Initialized;
	InitializeScriptEngine();
	InitializeInputManager();
	InitializeWindow();
	InitializeFont();
	InitGameMode();

	std::cout << "Initilatized: " << gameClock.getElapsedTime().asMilliseconds() << std::endl;
}

void Aat::Engine::Run()
{
	if (!window.IsOpen())
		throw std::exception("window is not open");

	engineState = EngineState::Run;

	sf::Clock deltaTimeClock;

	int previous = deltaTimeClock.getElapsedTime().asMilliseconds();
	float lag = 0;
	int current, elapsed = 0;

	while (engineState==EngineState::Run)
	{
		current = deltaTimeClock.getElapsedTime().asMilliseconds();
		elapsed = current - previous;
		previous = current;
		lag += elapsed;
		while (lag >= ms_per_update)
		{
			Update();
			lag -= ms_per_update;
		}
		Render(lag / ms_per_update);
	}
}

void Aat::Engine::PrintThis()
{
	std::cout << "Engine pointer: " << this << std::endl;
}

void Aat::Engine::Update()
{
	gameMode.Update();
	HandleEvent();
}

void Aat::Engine::Render(float lag)
{
	window.Clear();
	gameMode.Render();
	window.Display();
}

void Aat::Engine::HandleEvent()
{
	sf::Event sfEvent;
	while (window.PollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
		{
			window.Close();
			engineState = EngineState::Stop;
		}
	}
}

void Aat::Engine::InitConfig()
{
	//config.load()
}

//void Aat::Engine::initializeResource()
//{
//	scriptEngine.LoadLuaFile("resource.lua");
//	lua_getglobal(scriptEngine.GetLuaState(), "initializefont");
//	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);
//}

void Aat::Engine::InitializeFont()
{
	scriptEngine.LoadLuaFile("font.lua");
	lua_getglobal(scriptEngine.GetLuaState(), "initializefont");
	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);

	fonts[0];
}

void Aat::Engine::InitializeWindow()
{
	scriptEngine.LoadLuaFile("window.lua");
	lua_getglobal(scriptEngine.GetLuaState(), "initializewindow");
	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);

	//C++
	//window.Initialize();
	//window.MakeWindow();
}

void Aat::Engine::InitGameMode()
{
	scriptEngine.LoadLuaFile("gamemode.lua");
	lua_getglobal(scriptEngine.GetLuaState(), "initializegamemode");
	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);
}

void Aat::Engine::InitializeScriptEngine()
{
	scriptEngine.Initialize();

	lua_pushlightuserdata(scriptEngine.GetLuaState(), this);
	lua_setglobal(scriptEngine.GetLuaState(), "ENGINE");

	//scriptEngine.pushlightuserdata(this) any로 인수 받음

	//test
	/*scriptEngine.LoadLuaFile("test.lua");
	lua_getglobal(scriptEngine.GetLuaState(), "test2");
	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);*/
}

void Aat::Engine::InitializeInputManager()
{
	//inputManager.Initialize("Config/KeyMap.ini");
}
