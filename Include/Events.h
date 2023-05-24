#pragma once

#include "EngineTypes.h"
#include "Enums.h"

class ColliderComponent;

class IEventArgs
{};


class ShootEventArgs : public IEventArgs
{
public:
    ShootEventArgs(exVector2 position) :
        mPosition(position) {}

    exVector2 mPosition;
};

class CollisionEventArgs : public IEventArgs
{
public:
    CollisionEventArgs(ColliderComponent* col, CollisionTag other) :
        mCollider(col), mOther(other)
    {}        

    ColliderComponent* mCollider;
    CollisionTag mOther;
};