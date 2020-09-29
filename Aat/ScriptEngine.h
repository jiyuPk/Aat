#pragma once
namespace Aat
{

	class ScriptEngine
	{
	public:
		ScriptEngine();
		~ScriptEngine();

		void Initialize();

		void LoadLuaFile(const std::string& file_name);
		//void Update();
		inline lua_State* GetLuaState() { return luaState; }
	private:
		bool isInitialized;
		lua_State* luaState;

		//Methode
		void RegisterFunctions();
	};
}
