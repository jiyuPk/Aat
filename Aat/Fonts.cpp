#include "pch.h"
#include "Fonts.h"

Aat::Fonts::Fonts()
{
}

void Aat::Fonts::LoadFromFile(std::filesystem::path path)
{
	sf::Font font;
	if (!font.loadFromFile(path.string()))
	{
		std::cerr << "fail open font file" << std::endl;
	}
	fonts.push_back(font);
}

const sf::Font& Aat::Fonts::operator[](size_t index) const
{
	if (index >= fonts.size())
	{
		//throw "error";
		//std::cerr << "error" << std::endl;
	}
	return fonts[index];
}
