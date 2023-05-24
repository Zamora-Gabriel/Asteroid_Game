#pragma once

enum class EventTypes
{
    Shoot,
    Collision
};

enum CollisionTag
{
    NONE,
    SHIP,
    BULLET,
    ASTEROID,
    COUNT
};

enum class GameState
{
    Playing,
    GameOver
};

enum ComponentType
{
    Transform,
    Collider,
    SquaredRendering,
    SquareWithinSquareRendering,
    Count
};