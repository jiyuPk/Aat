#pragma once
#include "Command.h"
class InputHandler
{
public:
	InputHandler();

	Command* HandleInput();
private:
	Command* KeyA;
	Command* KeyD;
	Command* KeyS;
	Command* KeyW;
};

