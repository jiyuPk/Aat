#pragma once
#include "IGUIElement.h"

namespace Aat::GUI
{

	enum ButtonState
	{
		IDLE,
		HOVER,
		PRESSED
	};

	class Button :
		public IGUIElement
	{
	public:
		Button(float x, float y, int width, int height, GUIColor button_color, GUIColor text_color, Text text);

		virtual void Update(const sf::Vector2i& mouse_position_window);
		virtual void Render(Window::Window& window);

		bool IsButtonPressed() const;
		Text text;
	private:
		sf::RectangleShape shape;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color pressedColor;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textPressedColor;

		ButtonState buttonState;
	};
}


