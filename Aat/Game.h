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
	sf::Vector2i GetMousePositionWindow() const; // ���� ����
	std::stack<std::shared_ptr<GameMode>> gamemodes; // ��������

private:
	std::stack<GameMode> gameModes;
	sf::RenderWindow* window_; // �̸� ���濹�� window
	WindowSetting windowSetting;
	sf::Event event;
	std::map<std::string, sf::Font> fonts;

	std::shared_ptr<sf::RenderWindow> window; //��������
	sf::Vector2i mousePositionGlobal;
	sf::Vector2i mousePositionWindow;

	int ms_per_update;
	int deltaTime;
	sf::Clock deltaTimeClock;

	std::shared_ptr<EventHandler> eventHandler; // ��������

	void MakeWindow(); //���Ͻý��� ������ ��������
	void InitGameMode();
	void LoadFont();

	void UpdateMousePosition();
	void UpdateDeltaTime();
	void UpdateQuit();
};

