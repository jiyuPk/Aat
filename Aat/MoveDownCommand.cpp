#include "pch.h"
#include "MoveDownCommand.h"

void MoveDownCommand::Execute(Actor& actor)
{
	sf::Vector2f position = actor.circle.getPosition();
	position.y += 5;
	actor.circle.setPosition(position);
	std::cout << "move dowm" << std::endl;
}
