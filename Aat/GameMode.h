#pragma once
#include "Controllers.h"
#include "UI.h"
#include "Components.h"

class GameMode
{
protected:
	PlayerController playerController;
	std::vector<Controller> controllers;
public:
	GameMode();

	virtual void Update() = 0;
	virtual void Render() = 0;
};

class TutorialGameMode
	:public GameMode
{
public:
	TutorialGameMode();
	void Update() override;
	void Render() override;

private:
	GraphicsComponent* graphicsComponent;
};
