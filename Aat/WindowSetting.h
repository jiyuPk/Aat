#pragma once


class WindowSetting
{
public:
	WindowSetting();

	sf::VideoMode Resolution;
	std::string title;
	bool Fullscreen;
	unsigned FrameRateLimit;
	sf::ContextSettings ContextSettings;

	void SaveWinSetting(const std::string path);
	void LoadWinSwtting(const std::string path);
};


