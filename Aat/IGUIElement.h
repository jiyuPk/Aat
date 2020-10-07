#pragma once
#include "Window.h"
#include "Text.h"
namespace Aat::GUI
{
	class IGUIElement
	{
	public:
		virtual void Update(const sf::Vector2i& mouse_position_window) = 0;
		virtual void Render(Window::Window& window) = 0;
	private:
	};
}

