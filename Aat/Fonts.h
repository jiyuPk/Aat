#pragma once
namespace Aat
{
	class Fonts
	{
	public:
		Fonts();

		void LoadFromFile(std::filesystem::path path);

		sf::Font& operator[] (size_t index);
	private:
		std::vector<sf::Font> fonts;
	};
}


