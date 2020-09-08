#pragma once
#include "Command.h"
class MoveLeftCommand :
    public Command
{
    virtual void Execute(Actor& actor) override;
};

