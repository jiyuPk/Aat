#pragma once
#include "Pawn.h"
class Player :
    public Pawn
{
private:
public:
    Player();

    void Render(std::shared_ptr<sf::RenderWindow> window);
};

