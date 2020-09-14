#pragma once
namespace Aat
{
	class ResourceManager
	{
	public:
		static ResourceManager& RMInstance();
		sf::Texture& GetTexture(int id);
	private:
		static ResourceManager instance;

		sf::Texture* background;
	};

}

