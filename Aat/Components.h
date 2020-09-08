#pragma once
#include "Controllers.h"
class Component
{
public:
	unsigned ID;
protected:
	Component(unsigned id);
private:

};

class StateCompoment
	:public Component
{
public:
private:
	unsigned GameObjectID;
	std::string name;
};

class MovementComponent
	:public Component
{
public:
	MovementComponent(unsigned id,const Controller& controller);

	void Update();
private:
	int x, y;
	const Controller& controller;
};

class GraphicsComponent
	:public Component
{

};

class InputComponent
	:public Component
{

};

class ControllerComponent
	:public Component
{

};

class ImageComponent
	:public Component
{
public:
private:
	sf::RectangleShape shape;
};