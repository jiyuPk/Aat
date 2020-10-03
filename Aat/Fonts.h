#pragma once
namespace Aat
{
	class Fonts
	{
	public:
		Fonts();

		void LoadFromFile(std::filesystem::path path);

		const sf::Font& operator[] (size_t index) const;
	private:
		std::vector<sf::Font> fonts;
	};
}


