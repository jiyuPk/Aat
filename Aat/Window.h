#pragma once

namespace Aat
{
	class Window
	{
	public:
		Window();

		//basic initialize
		void Initialize();
		//initialize with file, not realized 
		void Initialize(std::filesystem::path path);
		//initialize with lua, 다른 인수도 추가 예정
		void Initialize(sf::VideoMode video_mode, std::string title, size_t framerate_limit, bool fullscreen);

		void MakeWindow();
		void SetFramerateLimit(size_t limit);
		void Display();
		void Clear();
		void Close();
		bool PollEvent(sf::Event& event);
		bool IsOpen();

		void Draw(sf::Drawable* objekt);
	private:
		sf::RenderWindow window;
		bool isInitialized;
		//window setting
		sf::VideoMode videoMode;
		bool fullScreen;
		std::string title;
		int style : 5;
		sf::ContextSettings contextSetting;
		size_t frameRateLimit;
	};
}
