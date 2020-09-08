#pragma once
class Component
{
public:
	unsigned int GameObjectID;
private:
};

class MovementComponent
	:Component
{
public:
	void Update();
};

class GraphicsComponent
	:Component
{

};

class InputComponent
	:Component
{

};

