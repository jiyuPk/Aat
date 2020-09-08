#include "pch.h"
#include "MoveUpCommand.h"

void MoveUpCommand::Execute(Actor& actor)
{
	sf::Vector2f position = actor.circle.getPosition();
	position.y -= 5;
	actor.circle.setPosition(position);
	std::cout << "move up" << std::endl;
}
