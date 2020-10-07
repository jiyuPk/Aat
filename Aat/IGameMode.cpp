#include "pch.h"
#include "IGameMode.h"

Aat::GameMode::IGameMode::IGameMode()
{
	gameMode = nullptr;
	window = nullptr;
}

void Aat::GameMode::IGameMode::Initialize(size_t gamemode_id, Window::Window* window, sf::Font& font)
{
	this->window = window;
	if (gamemode_id == 1)
	{
		gameMode = new MainMemuGameMode(font);
	}
}

void Aat::GameMode::IGameMode::Update()
{
	gameMode->Update(mousePositionWindow);
}

void Aat::GameMode::IGameMode::Render()
{
	gameMode->Render(*window);
}

void Aat::GameMode::IGameMode::UpdateMousePosition(Window::Window* window)
{
	mousePositionWindow = sf::Mouse::getPosition(window->GetWindow());
}
