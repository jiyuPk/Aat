#pragma once
#include "Window.h"
namespace Aat::GUI
{
	struct GUIColor
	{
		sf::Color IdleColor = sf::Color::Black;
		sf::Color HoverColor = sf::Color::Green;
		sf::Color PressedColor = sf::Color::Red;
	};

	class Text
	{
	public:
		Text(std::wstring string, sf::Font& font, size_t size, sf::Color color = sf::Color::Black);
		void SetFillColor(sf::Color color);
		void SetPosition(float x, float y);

		void Render(Window::Window& window);

		void printposition(int i);
	private:
		sf::Text text;
		float x;
		float y;
	};

}

