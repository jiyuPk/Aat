#include "pch.h"
#include "GUI.h"

void Aat::GUI::GUI::AddElement(IGUIElement* element)
{
	elements.push_back(element);
}

void Aat::GUI::GUI::Update(const sf::Vector2i& mouse_position_window)
{
	for (auto element : elements)
	{
		element->Update(mouse_position_window);
	}
}

void Aat::GUI::GUI::Render(Window::Window& window)
{
	for (auto element : elements)
	{
		element->Render(window);
	}
}
