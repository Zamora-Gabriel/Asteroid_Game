#pragma once

#include "EngineTypes.h"
#include <math.h>

namespace MathUtils
{
    inline void normalizeVector(exVector2& vector)
    {
        double magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
        vector.x /= magnitude;
        vector.y /= magnitude;
    }
}