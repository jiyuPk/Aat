#pragma once
#include "GameMode.h"
#include "Player.h"

class PlayGameMode : 
	public GameMode
{
public:
	PlayGameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler);
	virtual void Update(const Game& game_ref) override;
	virtual void Render() override;
private:
	Player player;

	InputHandler InputHandler;
};

