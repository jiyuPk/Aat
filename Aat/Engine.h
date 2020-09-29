#pragma once
//나중에 전방선언 빼고 포인터말고 객체로
namespace Aat
{
	class Window;
	class InputManager;
	class ScriptEngine;

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

		////Lua Functions
		//int CreateWindow(lua_State* L);

		void Initialize();
		void Run();

		//개발용
		void PrintThis();
	private:
		Aat::Window* window;
		int ms_per_update;
		EngineState engineState;
		//Managers
		InputManager* inputManager;
		ScriptEngine* scriptEngine;

		sf::Clock gameClock;
		//Methods
		void Update();
		void Render(float lag);

		void HandleEvent();
		//Initializers
		void InitConfig();
		void InitLogger();
		void InitResource();
		void InitWindow();
		void InitScriptEngine();
		void InitInputManager();

	public:
		//test
		static int Test(lua_State* lua_state);
		//Window
		static int InitWindow(lua_State* lua_state);
		static int MakeWindow(lua_State* lua_state);
		static int SetMaxFrameRate(lua_State* lua_state);
	};
}
