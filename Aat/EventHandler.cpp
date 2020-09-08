#include "pch.h"
#include "EventHandler.h"
#include "GameMode.h"

void EventHandler::GameQuitEvent(std::shared_ptr<sf::RenderWindow> window)
{
	window->close();
}

void EventHandler::PushState(std::stack<std::shared_ptr<GameMode>> gamemodes, std::shared_ptr<GameMode> gamemode)
{
	gamemodes.push(gamemode);
}
