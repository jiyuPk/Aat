#pragma once
#include "WindowSetting.h"
#include "GameMode.h"

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

	sf::RenderWindow* window; 
	WindowSetting windowSetting;
	sf::Event event;
	std::map<std::string, sf::Font> fonts;

	sf::Vector2i mousePositionGlobal;
	sf::Vector2i mousePositionWindow;

	int ms_per_update;
	int deltaTime;
	sf::Clock deltaTimeClock;


	void MakeWindow(); //파일시스템 공부후 개선예정
	void InitGameMode();
	void LoadFont(); // 이동 예정

	void UpdateMousePosition();
	void UpdateDeltaTime();
	void UpdateQuit();
};

