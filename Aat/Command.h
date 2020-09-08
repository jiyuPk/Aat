#pragma once
#include"Actor.h"

class Command
{
public:
	Command();
	virtual ~Command() {};
	virtual void Execute(Actor& actor)=0;
};

