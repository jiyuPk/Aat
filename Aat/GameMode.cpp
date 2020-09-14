#include "pch.h"
#include "GameMode.h"

//TutorialGameMode::TutorialGameMode()
//{
//	graphicsComponent = new GraphicsComponent[10];
//
//}
//
//void TutorialGameMode::Update()
//{
//
//}
//
//void TutorialGameMode::Render()
//{
//}

MainMenuGameMode::MainMenuGameMode(std::shared_ptr<sf::RenderWindow> window)
	:GameMode(window), background(1,1, Aat::Coordinate())
{

}

void MainMenuGameMode::Update()
{
}

void MainMenuGameMode::Render()
{
	window->draw(background.GetSprite());
}

GameMode::GameMode(std::shared_ptr<sf::RenderWindow> window)
{
	this->window = window;
}
