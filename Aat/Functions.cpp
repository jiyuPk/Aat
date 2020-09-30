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

    size_t vmWidth = lua_tointeger(lua_state, 1);
    size_t vmHeight = lua_tointeger(lua_state, 2);
    std::string title = lua_tostring(lua_state, 3);
    bool fullScreen = lua_toboolean(lua_state, 4);
    size_t framerate_lmit = lua_tointeger(lua_state, 5);

    //std::cout << vmWidth << std::endl;
    //std::cout << vmHeight << std::endl;
    //std::cout << title << std::endl;
    //std::cout << fullScreen << std::endl;
    //std::cout << "framerate limit: " << framerate_lmit << std::endl;

    engine->window.Initialize(sf::VideoMode(vmWidth, vmHeight), title,framerate_lmit,fullScreen);
    return 0;
}

int Aat::Engine::MakeWindow(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));

    engine->window.MakeWindow();

    return 0;
}

int Aat::Engine::SetFrameRateLimit(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));

    size_t framerate_lmit = lua_tointeger(lua_state, 1);

    engine->window.SetFramerateLimit(framerate_lmit);
    std::cout << "framerate limit: " << framerate_lmit << std::endl;

    return 0;
}

int Aat::Engine::LoadFont(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));


    return 0;
}
