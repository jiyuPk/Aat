#include "pch.h"
#include "Engine.h"

Aat::Engine::Engine()
{
	engineState = EngineState::Uninitialized;
	ms_per_update = 5;

	PrintThis();
}

Aat::Engine::~Engine()
{
}

//void Engine::InitGameMode(const char* game_mode_file)
//{
//	if (gameMode != nullptr)
//	{
//		delete gameMode;
//	}
//	gameMode = new Aat::GameMode(game_mode_file);
//
//	lua_pushlightuserdata(gameMode->GetLuaState(), this);
//	lua_setglobal(gameMode->GetLuaState(), "Engine");
//	//registerCppFunction(gameMode->(GetLuaState))
//}

void Aat::Engine::Initialize()
{
	engineState = EngineState::Initialized;

	InitializeScriptEngine();
	InitializeInputManager();
	InitializeWindow();

	std::cout << "Initilatized: " << gameClock.getElapsedTime().asMilliseconds() << std::endl;
}

void Aat::Engine::Run()
{
	if (!window.IsOpen())
		std::cerr << "window is not open" << std::endl;
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
	//std::cout << "UPDATE" << std::endl;
	HandleEvent();
}

void Aat::Engine::Render(float lag)
{
	//hud.render
	window.Clear();
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
		}
	}
}

void Aat::Engine::InitConfig()
{
	//config.load()
}

void Aat::Engine::InitializeWindow()
{
	//window.Initialize();
	scriptEngine.LoadLuaFile("window.lua");
	lua_getglobal(scriptEngine.GetLuaState(), "initializewindow");
	lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);

	//window.MakeWindow();
}

void Aat::Engine::InitializeScriptEngine()
{
	scriptEngine.Initialize();

	lua_pushlightuserdata(scriptEngine.GetLuaState(), this);
	lua_setglobal(scriptEngine.GetLuaState(), "ENGINE");
	//scriptEngine.pushlightuserdata(this) any로 인수 받음

	//test
	//scriptEngine.LoadLuaFile("test.lua");
	//lua_getglobal(scriptEngine.GetLuaState(), "test");
	//lua_pcall(scriptEngine.GetLuaState(), 0, 0, 0);
}

void Aat::Engine::InitializeInputManager()
{
	inputManager.Initialize("Config/KeyMap.ini");
}