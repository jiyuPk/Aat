#pragma once
#include "IGUIElement.h"

namespace Aat::GUI
{
	class GUI
	{
	public:
		void AddElement(IGUIElement* element);
		void Update(const sf::Vector2i& mouse_position_window);
		void Render(Window::Window& window);
	private:
		std::vector<IGUIElement*> elements;
	};
}

