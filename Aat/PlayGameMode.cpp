#include "pch.h"
#include "PlayGameMode.h"

PlayGameMode::PlayGameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler)
	:GameMode(window,eventHandler)
{
}

void PlayGameMode::Update(const Game& game_ref)
{
	Command* command = InputHandler.HandleInput();
	if (command)
	{
		command->Execute(player);
	}
}

void PlayGameMode::Render()
{
	player.Render(renderWindow);
}
