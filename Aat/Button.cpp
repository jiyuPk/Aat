#include "pch.h"
#include "Button.h"

Button::Button(int x, int y, int width, int height, ButtonColor button_color, ButtonColor text_color, sf::Font* font, std::wstring string, unsigned font_size)
{
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));

	text_font = font;
	textIdleColor = text_color.IdleColor;
	textHoverColor = text_color.HoverColor;
	textPressedColor = text_color.PressedColor;

	text.setFont(*this->text_font);
	text.setString(string);
	text.setFillColor(textIdleColor);
	text.setCharacterSize(font_size);
	//text.setPosition(shape.getPosition().x + (shape.getPosition().x / 2.f) - shape.getPosition().y / 2.f, shape.getPosition().y);
	text.setPosition(shape.getPosition().x+10, shape.getPosition().y+5);


	idleColor = button_color.IdleColor;
	hoverColor = button_color.HoverColor;
	pressedColor = button_color.PressedColor;

	shape.setFillColor(idleColor);
	buttonState = IDLE;
	oldState = IDLE;
}

void Button::Update(const sf::Vector2i& mouse_position_window) //전 상태와 같을 시 색갈 업데이트 안함 구현 예정
{
	oldState = buttonState;

	if (shape.getGlobalBounds().contains(sf::Vector2f(mouse_position_window.x, mouse_position_window.y)))
	{
		buttonState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = PRESSED;
		//	std::cout << oldState << std::endl;
	//		std::cout << buttonState << "new" << std::endl;
		}
	//	std::cout << oldState << std::endl;
		//std::cout << buttonState << "new" << std::endl;
	}
	else
	{
		buttonState = IDLE;
	//	std::cout << oldState << std::endl;
	//	std::cout << buttonState << "new" << std::endl;
	}


	//if (!oldState == buttonState)
	//{
		switch (buttonState)
		{
		case IDLE:
			shape.setFillColor(idleColor);
			text.setFillColor(textIdleColor);
			break;

		case HOVER:
			shape.setFillColor(hoverColor);
			text.setFillColor(textHoverColor);
			break;

		case PRESSED:
			shape.setFillColor(pressedColor);
			text.setFillColor(textPressedColor);
			break;
		}
	//}
}

void Button::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(shape);
	window->draw(text);
}

bool Button::IsButtonPressed() const
{
	if (buttonState == PRESSED)
	{
		return true;
	}
	return false;
}
