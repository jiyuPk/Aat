#pragma once
#include "Game.h"
#include "InputHandler.h"
#include "UI.h"

class GameMode
{
protected:
	std::shared_ptr<sf::RenderWindow> renderWindow;
	sf::RectangleShape background;

	std::shared_ptr<EventHandler> eventHandler;
public:
	GameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler);

	GameMode();

	virtual void Update(const Game& game_ref) = 0;
	virtual void Render() = 0;
};

class TutorialGameMode
	:public GameMode
{

};
