#include "pch.h"
#include "InputHandler.h"

#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveDownCommand.h"
#include "MoveUpCommand.h"

InputHandler::InputHandler()
{
	KeyA = new MoveLeftCommand();
	KeyD = new MoveRightCommand();
	KeyS = new MoveDownCommand();
	KeyW = new MoveUpCommand();
}

Command* InputHandler::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "key A" << std::endl;
		return KeyA;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "key D" << std::endl;
		return KeyD;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "key S" << std::endl;
		return KeyS;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		std::cout << "key W" << std::endl;
		return KeyW;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		std::cout << "attack key" << std::endl;
		return 0;
	}
}
