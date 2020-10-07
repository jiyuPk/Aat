#pragma once
#include "Window.h"
#include "GameObjects.h"
#include "GUI.h"
namespace Aat::GameMode
{
	class GameMode
	{
	public:
		virtual void Update(const sf::Vector2i& mouse_position_window) = 0;
		virtual void Render(Window::Window& window) = 0;
	protected:
		GameObjects objects;
		GUI::GUI gui;
	};
}

