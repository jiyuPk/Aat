#pragma once
namespace Aat
{
	class WindowSetting
	{
	public: 
		WindowSetting();

		sf::VideoMode videoMode;
		bool fullScreen;
		std::string title;
		int style : 5;
		sf::ContextSettings contextSetting;
		size_t frameRateLimit;

		void LoadFromFile(std::filesystem::path path);
	};
}

