#pragma once
#include "Components.h"
class Actor
{
private:
protected:
	std::vector<Component*> components;
public:
	Actor();
sf::Sprite sprite;
sf::CircleShape circle;
};

