#pragma once


class WindowSetting
{
public:
	WindowSetting(const std::string& path);

	sf::VideoMode Resolution;
	std::string title;
	bool Fullscreen;
	int FrameRateLimit;
	sf::ContextSettings ContextSettings;

	void SaveWinSetting(const std::string& path);
	void LoadWinSwtting(const std::string& path);
};


