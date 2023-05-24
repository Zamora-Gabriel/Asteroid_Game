#pragma once

#include "EngineTypes.h"

struct Bounds
{
    exVector2 min;
    exVector2 max;

    bool collides(const Bounds& other) const
    {
        return (min.x <= other.max.x &&
            max.x >= other.min.x &&
            min.y <= other.max.y &&
            max.y >= other.min.y);
    }
};