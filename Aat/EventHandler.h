#pragma once
class GameMode;

class EventHandler
{
public:
	void GameQuitEvent(std::shared_ptr<sf::RenderWindow> window);
	void PushState(std::stack<std::shared_ptr<GameMode>> gamemodes, std::shared_ptr<GameMode> gamemode);
};

