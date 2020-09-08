#include "pch.h"
#include "Player.h"

Player::Player()
{
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(200, 200));
	circle.setRadius(20);
}

void Player::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(circle);
}
