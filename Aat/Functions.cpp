#include "pch.h"
#include "Engine.h"

int Aat::Engine::Test(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));
    std::cout << "CPP_TEST" << std::endl;
    engine->PrintThis();
    //engine->window
    return 0;
}

int Aat::Engine::InitWindow(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));

    return 0;
}

int Aat::Engine::MakeWindow(lua_State* lua_state)
{
    return 0;
}

int Aat::Engine::SetMaxFrameRate(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));
    const unsigned framerate_lmit = lua_tointeger(lua_state, 1);
    return 0;
}
