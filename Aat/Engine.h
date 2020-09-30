#pragma once
#include "InputManager.h"
#include "ResourceManager.h"
#include "ScriptEngine.h"
#include "Window.h"
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
		Aat::Window window;
		int ms_per_update;
		EngineState engineState;
		//Managers
		InputManager inputManager;
		ScriptEngine scriptEngine;

		sf::Clock gameClock;
		//Methods
		void Update();
		void Render(float lag);

		void HandleEvent();
		//Initializers
		void InitConfig();
		void InitLogger();
		void initializeResource();
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
		static int LoadFont(lua_State* lua_state);
	};
}
