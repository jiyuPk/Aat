#include "pch.h"
#include "MainMenuGameMode.h"
#include "Button.h"

Aat::GameMode::MainMemuGameMode::MainMemuGameMode(sf::Font& font)
{
	backgroundTexture.loadFromFile("Graphics/Background/Background.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);

	GUI::GUIColor buttoncolor;
	GUI::GUIColor textcolor;
	buttoncolor.IdleColor = sf::Color::Red;
	GUI::Text text(L"testbutton", font, 30);

	GUI::Button* button = new GUI::Button(200, 300, 200, 50, buttoncolor, textcolor, text);
	button->text.SetPosition(400, 400);
	gui.AddElement(button);
}

void Aat::GameMode::MainMemuGameMode::Update(const sf::Vector2i& mouse_position_window)
{
	gui.Update(mouse_position_window);
}

void Aat::GameMode::MainMemuGameMode::Render(Window::Window& window)
{
	window.Draw(backgroundSprite);
	gui.Render(window);
}
