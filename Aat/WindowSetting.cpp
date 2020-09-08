#include "pch.h"
#include "WindowSetting.h"

WindowSetting::WindowSetting()
{
	Resolution = sf::VideoMode(1280, 720);
	title = "Default Name";
	Fullscreen = false;
	FrameRateLimit = 300;
	ContextSettings.antialiasingLevel = 0;
}

void WindowSetting::SaveWinSetting(const std::string path)
{
}

void WindowSetting::LoadWinSwtting(const std::string path)
{
	char ResolutionName;
	std::ifstream ifs(path);

	if (!ifs.is_open())
	{
		throw("FAIL TO OPEN FILE");
	}
	std::getline(ifs, title);
	ifs >> ResolutionName;
	ifs >> Fullscreen;
	ifs >> FrameRateLimit;
	ifs >> ContextSettings.antialiasingLevel;
	ifs.close();

	switch (ResolutionName)
	{
	case 'H':
		Resolution = sf::VideoMode(1280, 720);
		break;
	case 'F':
		Resolution = sf::VideoMode(1920, 1080);
		break;
	}

}
