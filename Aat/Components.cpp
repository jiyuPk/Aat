#include "pch.h"
#include "Components.h"
#include "ResourceManager.h"

Aat::MovementComponent::MovementComponent(unsigned id, const Controller& controller)
	:Component(id), controller(controller)
{
	x, y = 0;
}

void Aat::MovementComponent::Update()
{
}

Aat::Component::Component(unsigned id)
{
	ID = id;
}

Aat::SpriteComponent::SpriteComponent(int id,int texture_id, Coordinate coordinate)
	:Component(id)
{
	SetTexture(texture_id);
	SetPosition(coordinate);
}

void Aat::SpriteComponent::SetTexture(int id)
{
	textureID = id;
	//Aat::ResourceManager::RMInstance().GetTexture(id);
	sf::Texture texture;
	texture.loadFromFile("Graphics/Background/background.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

void Aat::SpriteComponent::SetPosition(Coordinate coordinate)
{
	//if (!spriteInit)
	//	throw ID + " this sprite has not been initialized";

	sprite.setPosition(coordinate.x, coordinate.y);
}

sf::Sprite& Aat::SpriteComponent::GetSprite()
{
	return sprite;
}
