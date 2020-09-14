#include "pch.h"
#include "Game.h"
#include "GameMode.h"

std::unique_ptr<sf::RenderWindow> MakeWindow(const std::string& path)
{
	WindowSetting winSetting(path);
	if (winSetting.Fullscreen == true)
	{
		//std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(winSetting.Resolution, winSetting.title, sf::Style::Fullscreen, winSetting.ContextSettings);
		//window->setFramerateLimit(winSetting.FrameRateLimit);
		sf::VideoMode vm(1920, 1080);
		std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(vm, "aat", sf::Style::Close);
		return window;
	}
	else
	{
		//std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(winSetting.Resolution, winSetting.title, sf::Style::Titlebar | sf::Style::Close, winSetting.ContextSettings);
		//window->setFramerateLimit(winSetting.FrameRateLimit);
		//return window;
	}
}

void Game::InitWindow()
{
	window = MakeWindow("Config/WinSetting.ini");
}

void Game::InitGameMode()
{

	
	//적용예정 코드
	//if (tutorialcleared)
	//{
	//Nofity(Event)
	//gameModes.push(new TutorialGameMode());
	//}
	//gameModes.push(new MainMenuGameMode())
	
	gameModes.push(new MainMenuGameMode(window));
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
	//Nofity(event(Game Start))
	InitWindow();
	LoadFont();

	InitGameMode();
	ms_per_update = 5;
}

Game::~Game()
{
}

void Game::GameLoop()
{
	if (gameModes.empty())
		throw ("GameModeStack is empty");
	int lag = 0;

	//isGameRunning = true;

	//while(isGameRunning)
	//{
		while (window->isOpen())
		{
		//	UpdateDeltaTime();
		//	lag += deltaTime;

			//while (lag > ms_per_update)
		//	{
		//		Update();
		//		lag -= ms_per_update;
		//	}
		//	Render();
			Update();
			Render();
		}
	//}
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

	sf::Texture texture;
	texture.loadFromFile("Graphics/Background/background.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	window->draw(sprite);

	gameModes.top()->Render();
	window->display();
}
