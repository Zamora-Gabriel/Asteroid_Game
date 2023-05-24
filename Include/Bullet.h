#pragma once

#include "IPoolableActor.h"

class Bullet : public IPoolableActor
{
    FACTORIZE

public:
    void Initialize() override;
    void Respawn() override;
    void Update(float dt) override;

    void Shoot(exVector2 position, float speed);

private:
    Bullet(int id);

    void UpdateMovement(float dt);
    void CheckOutOfScreen();

    float mSpeed;
    exVector2 mHalfSize;
};