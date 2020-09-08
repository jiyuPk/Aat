#include "pch.h"
#include "MoveLeftCommand.h"

void MoveLeftCommand::Execute(Actor& actor)
{
	sf::Vector2f position = actor.circle.getPosition();
	position.x -= 5;
	actor.circle.setPosition(position);
	std::cout << "move left" << std::endl;
}
