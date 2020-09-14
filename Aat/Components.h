#pragma once
#include "Controllers.h"
namespace Aat
{
	class Component
	{
	public:
	protected:
		Component(unsigned id);
		unsigned ID;
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
		MovementComponent(unsigned id, const Controller& controller);

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

	struct Coordinate
	{
		int x = 0;
		int y = 0;
	};

	class SpriteComponent
		:public Component
	{
	public:
		SpriteComponent(int id, int texture_id, Coordinate coordinate);

		void SetTexture(int id);
		void SetPosition(Coordinate coordinate);
		sf::Sprite& GetSprite();
	private:
		sf::Sprite sprite;
		bool spriteInit;
		int textureID;
	};
}
