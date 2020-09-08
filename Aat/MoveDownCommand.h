#pragma once
#include "Command.h"
class MoveDownCommand :
    public Command
{
    virtual void Execute(Actor& actor) override;

};

