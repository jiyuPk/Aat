#pragma once
#include "Command.h"
class MoveUpCommand :
    public Command
{
    virtual void Execute(Actor& actor) override;
};

