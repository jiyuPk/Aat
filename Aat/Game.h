#pragma once
#include "EventQueue.h"
#include "GameMode.h"
#include "WindowSetting.h"

class Game
{
public:
	Game();
	~Game();

	void GameLoop();
	void Update();
	void Render();


private:
	std::stack<GameMode*> gameModes;

	std::shared_ptr<sf::RenderWindow> window;

	sf::Event event;
	std::map<std::string, sf::Font> fonts;

	sf::Vector2i mousePositionGlobal;
	sf::Vector2i mousePositionWindow;

	int ms_per_update;
	int deltaTime;
	sf::Clock deltaTimeClock;

	bool isGameRunning;

	void InitWindow();
	void InitGameMode();
	void LoadFont(); // 이동 예정

	void UpdateMousePosition();
	void UpdateDeltaTime();
	void UpdateQuit();
};

