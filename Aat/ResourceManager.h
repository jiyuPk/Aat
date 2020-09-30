#pragma once
#include "Fonts.h"
namespace Aat
{
	class ResourceManager
	{
	public:
		ResourceManager();

		void LoadFont();
	private:
		std::vector<sf::Font> font;
	};
}


