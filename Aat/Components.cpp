#include "pch.h"
#include "Components.h"

MovementComponent::MovementComponent(unsigned id, const Controller& controller)
	:Component(id), controller(controller)
{
	x, y = 0;
}

void MovementComponent::Update()
{
}

Component::Component(unsigned id)
	:GameObjectID(id)
{
}
