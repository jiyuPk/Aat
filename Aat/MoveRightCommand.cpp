#include "pch.h"
#include "MoveRightCommand.h"

void MoveRightCommand::Execute(Actor& actor)
{
	sf::Vector2f position = actor.circle.getPosition();
	position.x += 5;
	actor.circle.setPosition(position);
	std::cout << "move right" << std::endl;
}
