#include "pch.h"
#include "Window.h"
#include "WindowSetting.h"

Aat::Window::Window()
	:setting(new WindowSetting)
{
}

void Aat::Window::Initialize(std::filesystem::path path)
{
	setting->LoadFromFile(path);
}

void Aat::Window::MakeWindow()
{
	window.create(setting->videoMode, setting->title, sf::Style::Default, setting->contextSetting);
	window.setFramerateLimit(setting->frameRateLimit);
}

void Aat::Window::Display()
{
	window.display();
}

void Aat::Window::Clear()
{
	window.clear();
}

void Aat::Window::Close()
{
	window.close();
}

bool Aat::Window::PollEvent(sf::Event& event)
{
	return window.pollEvent(event);
}

bool Aat::Window::IsOpen()
{
	return window.isOpen();
}

void Aat::Window::Draw(sf::Drawable* objekt)
{
	window.draw(*objekt);
}