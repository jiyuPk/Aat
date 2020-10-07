#include "pch.h"
#include "Window.h"

Aat::Window::Window::Window()
{
	isInitialized = false;

	videoMode.height = 0;
	videoMode.width = 0;
	fullScreen = false;
	title = "";
	contextSetting.antialiasingLevel = 0;
	frameRateLimit = 0;
}

void Aat::Window::Window::Initialize(std::filesystem::path path)
{
	//not realized maybe will delete
}

void Aat::Window::Window::Initialize()
{
	videoMode.height = 720;
	videoMode.width = 1280;
	fullScreen = false;
	title = "Aat";
	contextSetting.antialiasingLevel = 0;
	frameRateLimit = 240;

	std::cout << "Basic initialize" << std::endl;
	isInitialized = true;
}

void Aat::Window::Window::Initialize(sf::VideoMode video_mode, std::string title, size_t framerate_limit, bool fullscreen)
{
	videoMode = video_mode;
	this->title = title;
	fullScreen = fullscreen;
	contextSetting.antialiasingLevel = 0;
	frameRateLimit = framerate_limit;

	isInitialized = true;
}

void Aat::Window::Window::MakeWindow()
{
	if (fullScreen)
	{
		std::cout << "window fullscreen" << std::endl;
	}
	else
	{
		window.create(videoMode, title, sf::Style::Close | sf::Style::Titlebar, contextSetting);
		window.setFramerateLimit(frameRateLimit);
	}
}

void Aat::Window::Window::SetFramerateLimit(size_t limit)
{
	frameRateLimit = limit;
	window.setFramerateLimit(limit);
}

void Aat::Window::Window::Display()
{
	window.display();
}

void Aat::Window::Window::Clear()
{
	window.clear();
}

void Aat::Window::Window::Close()
{
	window.close();
}

bool Aat::Window::Window::PollEvent(sf::Event& event)
{
	return window.pollEvent(event);
}

bool Aat::Window::Window::IsOpen()
{
	return window.isOpen();
}

void Aat::Window::Window::Draw(const sf::Drawable& objekt)
{
	window.draw(objekt);
}


//module
//import Window;
//Aat::Window::Window()
//{
//	style = 5;
//}
//void Aat::Window::Func()
//{
//	std::cout << "func" << std::endl;
//	std::cout << style << std::endl;
//}
