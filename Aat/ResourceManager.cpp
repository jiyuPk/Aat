#include "pch.h"
#include "ResourceManager.h"

Aat::ResourceManager Aat::ResourceManager::instance;
Aat::ResourceManager& Aat::ResourceManager::RMInstance()
{
    return instance;
}

sf::Texture& Aat::ResourceManager::GetTexture(int id)
{
    if(id=1)
        background->loadFromFile("Graphics/Background/Background.png");
    return *background;
}
