#pragma once
#include "WindowSetting.h"
#include "EventHandler.h"

class GameMode;

class Game
{
public:
	Game();
	~Game();

	void GameLoop();
	void Update();
	void Render();

	//getter
	sf::Vector2i GetMousePositionWindow() const; // 삭제 예정
	std::stack<std::shared_ptr<GameMode>> gamemodes; // 삭제예정

private:
	std::stack<GameMode> gameModes;
	sf::RenderWindow* window_; // 이름 변경예정 window
	WindowSetting windowSetting;
	sf::Event event;
	std::map<std::string, sf::Font> fonts;

	std::shared_ptr<sf::RenderWindow> window; //삭제예정
	sf::Vector2i mousePositionGlobal;
	sf::Vector2i mousePositionWindow;

	int ms_per_update;
	int deltaTime;
	sf::Clock deltaTimeClock;

	std::shared_ptr<EventHandler> eventHandler; // 삭제예정

	void MakeWindow(); //파일시스템 공부후 개선예정
	void InitGameMode();
	void LoadFont();

	void UpdateMousePosition();
	void UpdateDeltaTime();
	void UpdateQuit();
};

