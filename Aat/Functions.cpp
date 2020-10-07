#include "pch.h"
#include "Engine.h"
int Aat::Engine::Test(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));
    std::cout << "CPP_TEST" << std::endl;
    //engine->PrintThis();
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

    return 0;
}

int Aat::Engine::LoadFontFromFile(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));

    std::filesystem::path path = lua_tostring(lua_state, 1);

    engine->fonts.LoadFromFile(path);

    return 0;
}

int Aat::Engine::InitGameMode(lua_State* lua_state)
{
    lua_getglobal(lua_state, "ENGINE");
    Engine* engine = static_cast<Engine*>(lua_touserdata(lua_state, -1));

    size_t gamemodeID = lua_tointeger(lua_state, 1);

    engine->gameMode.Initialize(gamemodeID, &engine->window, engine->fonts[0]);
    return 0;
}
