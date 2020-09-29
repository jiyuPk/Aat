#include "pch.h"
#include "WindowSetting.h"

Aat::WindowSetting::WindowSetting()
{
	videoMode.height = 720;
	videoMode.width = 1280;
	fullScreen = false;
	title = "Aat";
	contextSetting.antialiasingLevel = 0;
	frameRateLimit = 240;
}

void Aat::WindowSetting::LoadFromFile(std::filesystem::path path)
{
}
