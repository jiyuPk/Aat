#include "pch.h"
#include "Button.h"

Aat::GUI::Button::Button(float x, float y, int width, int height, GUIColor button_color, GUIColor text_color, Text text)
	:text(text)
{
	std::cout << "button" << std::endl;
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));

	idleColor = button_color.IdleColor;
	hoverColor = button_color.HoverColor;
	pressedColor = button_color.PressedColor;

	textIdleColor = text_color.IdleColor;
	textHoverColor = text_color.HoverColor;
	textPressedColor = text_color.PressedColor;
	text.SetFillColor(textIdleColor);

	text.SetPosition(100.f,100.f);
	text.printposition(4);

	shape.setFillColor(idleColor);
	buttonState = IDLE;
	text.printposition(5);
}

void Aat::GUI::Button::Update(const sf::Vector2i& mouse_position_window)
{
	if (shape.getGlobalBounds().contains(sf::Vector2f(mouse_position_window.x, mouse_position_window.y)))
	{
		buttonState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = PRESSED;
		}
	}
	else
	{
		buttonState = IDLE;
	}
	switch (buttonState)
	{
	case IDLE:
		shape.setFillColor(idleColor);
		//text.SetFillColor(textIdleColor);
		break;

	case HOVER:
		shape.setFillColor(hoverColor);
		//text.SetFillColor(textHoverColor);
		break;

	case PRESSED:
		shape.setFillColor(pressedColor);
		//text.SetFillColor(textPressedColor);
		break;
	}
}

void Aat::GUI::Button::Render(Window::Window& window)
{
	window.Draw(shape);
	text.Render(window);
}

bool Aat::GUI::Button::IsButtonPressed() const
{
	if (buttonState == PRESSED)
	{
		return true;
	}
	return false;
}
