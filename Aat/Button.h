#pragma once
#include "Events.h"

struct ButtonColor
{
	sf::Color IdleColor = sf::Color::Black;
	sf::Color HoverColor = sf::Color::Green;
	sf::Color PressedColor = sf::Color::Red;
};

enum ButtonState //enum class »ç¿ë
{
	IDLE,
	HOVER,
	PRESSED
};

class Button
{
public:
	Button(int x, int y, int width, int height, ButtonColor button_color, ButtonColor text_color,sf::Font* font, std::wstring text, unsigned font_size);

	std::unique_ptr<Aat::Event> Update(const sf::Vector2i& mouse_position_window);
	void Render(std::shared_ptr<sf::RenderWindow> window);

	bool IsButtonPressed() const;
private:
	sf::RectangleShape shape;

	sf::Text text;
	sf::Font* text_font;
	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textPressedColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;

	ButtonState oldState;
	ButtonState buttonState;
};

