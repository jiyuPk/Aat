#pragma once
#include "Actor.h"

class Pawn :
	public Actor
{
public:
protected:
	int x, y;

	// Components
	MovementComponent* movementCompoment;
private:
};

