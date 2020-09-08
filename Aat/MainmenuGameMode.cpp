#include "pch.h"
#include "MainmenuGameMode.h"
#include "PlayGameMode.h"

MainmenuGameMode::MainmenuGameMode(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<EventHandler> eventHandler, sf::Font* font)
	:GameMode(window,eventHandler)
{
	background.setSize(sf::Vector2f(renderWindow->getSize().x, renderWindow->getSize().y));
	background.setFillColor(sf::Color::Blue);
	MakeButtons(font);

}

void MainmenuGameMode::Update(const Game& game_ref)
{
	UpdateButtons(game_ref);
}

void MainmenuGameMode::Render()
{
	renderWindow->draw(background);
	RenderButtons();
}

void MainmenuGameMode::MakeButtons(sf::Font* font)
{
	ButtonColor text, button;
	text.IdleColor = sf::Color::White;
	text.PressedColor = sf::Color::White;
	text.HoverColor = sf::Color::White;

	buttons["NEW_GAME_BUTTON"] = std::make_unique<Button>(200, 300, 200, 50, button, text, font, L"새 게임", 30);
	buttons["LOAD_GAME_BUTTON"] = std::make_unique<Button>(200,360, 200, 50, button, text, font, L"게임 불러오기", 30);
	buttons["ACHIEVEMENT_BUTTON"] = std::make_unique<Button>(200, 420, 200, 50, button, text, font, L"업적", 30);
	buttons["OPTIONS_BUTTON"] = std::make_unique<Button>(200, 480, 200, 50, button, text, font, L"옵션", 30);
	buttons["QUIT_BUTTON"] = std::make_unique<Button>(200, 540, 200, 50, button, text, font, L"나가기", 30);
}

void MainmenuGameMode::UpdateButtons(const Game& game_ref)
{
	for (auto& button : buttons)
	{
		button.second->Update(game_ref.GetMousePositionWindow());
	}
	if (buttons["NEW_GAME_BUTTON"]->IsButtonPressed())
	{
		eventHandler->PushState(game_ref.gamemodes, std::make_shared<PlayGameMode>(renderWindow, eventHandler));
	}
	if (buttons["QUIT_BUTTON"]->IsButtonPressed())
	{
		eventHandler->GameQuitEvent(renderWindow);
	}
}

void MainmenuGameMode::RenderButtons()
{
	for (auto& button : buttons)
	{
		button.second->Render(renderWindow);
	}
}
