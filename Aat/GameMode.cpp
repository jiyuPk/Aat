#include "pch.h"
#include "GameMode.h"

GameMode::GameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler)
{
	this->renderWindow = window;
	this->eventHandler = eventHandler;
}
