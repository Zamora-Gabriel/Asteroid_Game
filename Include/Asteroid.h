#pragma once

#include "IPoolableActor.h"

class Asteroid : public IPoolableActor
{
    FACTORIZE

public:
    void Initialize() override;
    void Respawn() override;
    void Update(float dt) override;
    void Render() override;

    void Launch(exVector2 position, exVector2 direction, float speed);

private:
    Asteroid(int id);

    void UpdateMovement(float dt);
    void CheckOutOfScreen();

    float mSpeed = 0;
    exVector2 mHalfSize;
    exVector2 mDirection;
};