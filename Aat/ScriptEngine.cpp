#include "pch.h"
#include "ScriptEngine.h"
#include "Engine.h"

Aat::ScriptEngine::ScriptEngine()
{
	isInitialized = false;
	luaState = nullptr;
}

Aat::ScriptEngine::~ScriptEngine()
{
	lua_close(luaState);
}

void Aat::ScriptEngine::Initialize()
{
	luaState = luaL_newstate();
	luaL_openlibs(luaState);
	
	RegisterFunctions();

	isInitialized = true;
}

void Aat::ScriptEngine::LoadLuaFile(const std::string& file_name)
{
	int error = luaL_dofile(luaState, file_name.c_str());
	if (error)
	{
		std::cerr << "Lua file error" << std::endl;
	}
}

void Aat::ScriptEngine::RegisterFunctions()
{
	//test
	lua_pushcfunction(luaState, Engine::Test);
	lua_setglobal(luaState, "Test");

	lua_pushcfunction(luaState, Engine::InitWindow);
	lua_setglobal(luaState, "InitWindow");

	lua_pushcfunction(luaState, Engine::MakeWindow);
	lua_setglobal(luaState, "MakeWindow");

	lua_pushcfunction(luaState, Engine::SetMaxFrameRate);
	lua_setglobal(luaState, "SetMaxFrameRate");
}
