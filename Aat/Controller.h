#pragma once
#include "Pawn.h"
#include "HUD.h";

class Controller
{
public:
    void Possess(Pawn& pawn);
private:
	Pawn& pawn;
};

class PlayerController :
    public Controller
{
public:
private:
    HUD playerHUD;
    //Camera PlayerCamera

};
