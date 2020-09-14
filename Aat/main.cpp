#include "pch.h"
#include "Game.h"

#define _CRTDBG_MAP_ALLOC

#include <cstdlib>

#include <crtdbg.h>

#ifdef _DEBUG

#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#endif

int main()
{
	//_CrtSetBreakAlloc(2668);

	Game game_instance;
	game_instance.GameLoop();

	//_CrtDumpMemoryLeaks();
	/*sf::VideoMode vm(1920, 1080);
	sf::RenderWindow window(vm, "tesst", sf::Style::Close);
	sf::Texture texture;
	texture.loadFromFile("Graphics/Background/background.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		window.display();
	}*/
}
