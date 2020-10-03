#pragma once
#include "InputManager.h"
#include "ResourceManager.h"
#include "ScriptEngine.h"
#include "Fonts.h"
#include "IGameMode.h"

namespace Aat
{

	enum class EngineState
	{
		Uninitialized,
		Initialized,
		Run,
		Stop
	};

	class Engine
	{
	public:
		Engine();
		~Engine();

		//void InitGameMode(const char* game_mode_file);

		void Initialize();
		void Run();

		//°³¹ß¿ë
		void PrintThis();
	private:
		Window window;
		IGameMode* gameMode;
		Fonts fonts;
		EngineState engineState;
		int ms_per_update;
		//Managers
		InputManager inputManager;
		ScriptEngine scriptEngine;
		ResourceManager resourceManager;

		sf::Clock gameClock;
		//Methods
		void Update();
		void Render(float lag);

		void HandleEvent();
		//Initializers
		void InitConfig();
		void InitGameMode();
		void InitLogger();
		void InitializeResource();
		void InitializeFont();
		void InitializeWindow();
		void InitializeScriptEngine();
		void InitializeInputManager();

	public:
		//test
		static int Test(lua_State* lua_state);
		//Window
		static int InitWindow(lua_State* lua_state);
		static int MakeWindow(lua_State* lua_state);
		static int SetFrameRateLimit(lua_State* lua_state);
		//Font
		static int LoadFontFromFile(lua_State* lua_state);
		//Gamemode
	};
}
