#include "pch.h"
#include "Text.h"

Aat::GUI::Text::Text(std::wstring string, sf::Font& font, size_t size, sf::Color color)
{
	text.setFont(font);
	text.setString(string);
	text.setFillColor(color);
	text.setCharacterSize(size);
	text.setPosition(300, 300);
	printposition(1);
}

void Aat::GUI::Text::SetFillColor(sf::Color color)
{
	text.setPosition(200, 200);
	text.setFillColor(color);
	printposition(2);
}

void Aat::GUI::Text::SetPosition(float x, float y)
{
	text.setPosition(x, y);
	this->x = x;
	this->y = y;
	printposition(3);
}

void Aat::GUI::Text::Render(Window::Window& window)
{
	//printposition(4);
	window.Draw(text);
}

void Aat::GUI::Text::printposition(int i)
{
	std::cout << text.getPosition().x << " " << text.getPosition().y << " " << i << std::endl;
}
