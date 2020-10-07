#pragma once
#include "GameMode.h"
namespace Aat::GameMode
{
	class MainMemuGameMode
		:public GameMode
	{
	public:
		MainMemuGameMode(sf::Font& font);

		virtual void Update(const sf::Vector2i& mouse_position_window);
		virtual void Render(Window::Window& window);
	private:
		sf::Sprite backgroundSprite;
		sf::Texture backgroundTexture;
	};
}

