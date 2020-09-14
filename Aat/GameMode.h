#pragma once
#include "Controllers.h"
#include "UI.h"
#include "ComponentList.h"

class GameMode
{
protected:
	PlayerController playerController;
	std::vector<Controller> controllers;
	std::shared_ptr<sf::RenderWindow> window;
	//ComponentList componentList;
public:
	GameMode(std::shared_ptr<sf::RenderWindow> window);

	virtual void Update() = 0;
	virtual void Render() = 0;
};

class MainMenuGameMode
	:public GameMode
{
public:
	MainMenuGameMode(std::shared_ptr<sf::RenderWindow> window);
	void Update() override;
	void Render() override;
private:
	Aat::SpriteComponent background;
};

//class TutorialGameMode
//	:public GameMode
//{
//public:
//	TutorialGameMode();
//	void Update() override;
//	void Render() override;
//
//private:
//};
