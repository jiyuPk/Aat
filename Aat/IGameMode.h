#pragma once
#include "MainMenuGameMode.h"

namespace Aat::GameMode
{
	class IGameMode
	{
	public:
		IGameMode();

		void Initialize(size_t gamemode_id, Window::Window* window, sf::Font& font);

		void Update();
		void Render();
	private:
		GameMode* gameMode;
		Window::Window* window;
		sf::Vector2i mousePositionWindow;
		//Methods
		void UpdateMousePosition(Window::Window* window);
	};
}


