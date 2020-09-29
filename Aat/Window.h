#pragma once

namespace Aat
{
	class WindowSetting;

	class Window
	{
	public:
		Window();
		void Initialize(std::filesystem::path path);

		void MakeWindow();
		void Display();
		void Clear();
		void Close();
		bool PollEvent(sf::Event& event);
		bool IsOpen();

		void Draw(sf::Drawable* objekt);
	private:
		WindowSetting* setting;
		sf::RenderWindow window;
	};
}
