#pragma once

#include "Actor.h"

class IPoolableActor : public Actor
{
public:
    IPoolableActor(int id, bool isActive = false)
        : Actor(id, isActive)
    {}

    virtual void Initialize() = 0;
    virtual void Respawn() = 0;
};