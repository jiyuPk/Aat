#include "pch.h"
#include "Game.h"
#include "GameMode.h"

void Game::MakeWindow()
{
	windowSetting.LoadWinSwtting("Config/WinSetting.ini");

	window = new sf::RenderWindow(windowSetting.Resolution, windowSetting.title, sf::Style::Titlebar | sf::Style::Close,windowSetting.ContextSettings);
	window->setFramerateLimit(windowSetting.FrameRateLimit);
}

void Game::InitGameMode()
{

	
	//적용예정 코드
	//if (tutorialcleared)
	//{
	gameModes.push(new TutorialGameMode());
	//}
	//gameModes.push(new MainMenuGameMode())
	

}

void Game::LoadFont()
{
	fonts["MainMenuFont"].loadFromFile("Fonts/paybooc Bold.ttf");
}

void Game::UpdateMousePosition()
{
	mousePositionGlobal = sf::Mouse::getPosition();
	mousePositionWindow = sf::Mouse::getPosition(*window);
}

void Game::UpdateDeltaTime()
{
	deltaTime = deltaTimeClock.restart().asMilliseconds();
}

void Game::UpdateQuit()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

Game::Game()
{
	MakeWindow();
	LoadFont();

	InitGameMode();
	ms_per_update = 5;
}

Game::~Game()
{
	delete window;
}

void Game::GameLoop()
{
	if (gameModes.empty())
		throw ("GameModeStack is empty");
	int lag = 0;

	while(window->isOpen())
	{
		UpdateDeltaTime();
		lag += deltaTime;

		while (lag > ms_per_update)
		{
			Update();
			lag -= ms_per_update;
		}
		Render();
	}
}

void Game::Update()
{
	UpdateQuit();
	UpdateMousePosition();

	gameModes.top()->Update();
}

void Game::Render()
{
	window->clear();

	gameModes.top()->Render();
	window->display();
}
