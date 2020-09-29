#include "pch.h"
#include "Engine.h"
#include "InputManager.h"
#include "ScriptEngine.h"
#include "Window.h"

Aat::Engine::Engine()
{
	engineState = EngineState::Uninitialized;
	ms_per_update = 5;
	inputManager = new InputManager;
	scriptEngine = new ScriptEngine;
	window = new Window;

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

	InitInputManager();
	InitScriptEngine();
}

void Aat::Engine::Run()
{
	window->MakeWindow();


	if (!window->IsOpen())
		std::cerr << "window is not open" << std::endl;

	engineState = EngineState::Run;
	std::cout << gameClock.getElapsedTime().asMilliseconds() << std::endl;

	sf::Clock deltaTimeClock;
	int previous = deltaTimeClock.getElapsedTime().asMilliseconds();
	float lag = 0;
	while (engineState==EngineState::Run)
	{
		int current = deltaTimeClock.getElapsedTime().asMilliseconds();
		int elapsed = current - previous;
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
	std::cout << this << std::endl;
}

//int Engine::CreateWindow(lua_State* L)
//{
//	lua_getglobal(L, "Engine");
//	Engine* engine = static_cast<Engine*>(lua_touserdata(L, -1));
//	bool fullscreen;
//
//	if (fullscreen)
//	{
//		engine
//	}
//	return 0;
//}

void Aat::Engine::Update()
{
	//std::cout << "UPDATE" << std::endl;
	HandleEvent();
}

void Aat::Engine::Render(float lag)
{
	//hud.render
	window->Clear();
	window->Display();
}

void Aat::Engine::HandleEvent()
{
	sf::Event sfEvent;
	while (window->PollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
		{
			window->Close();
		}
	}
}

void Aat::Engine::InitConfig()
{
	//config.load()
}

void Aat::Engine::InitWindow()
{
	window->Initialize("");
}

void Aat::Engine::InitScriptEngine()
{
	scriptEngine->Initialize();

	lua_pushlightuserdata(scriptEngine->GetLuaState(), this);
	lua_setglobal(scriptEngine->GetLuaState(), "ENGINE");
	//scriptEngine.pushlightuserdata(this) any로 인수 받음

	scriptEngine->LoadLuaFile("test.lua");
	lua_getglobal(scriptEngine->GetLuaState(), "test");
	lua_pcall(scriptEngine->GetLuaState(), 0, 0, 0);
}

void Aat::Engine::InitInputManager()
{
	inputManager->Initialize("Config/KeyMap.ini");
}