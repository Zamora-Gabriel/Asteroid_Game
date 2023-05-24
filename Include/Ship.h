#pragma once

#include "Actor.h"

#define HURT_DURATION 0.5f

class Ship : public Actor
{
    FACTORIZE

public:
    void Initialize();
    
    void Update(float dt) override;

    void PlayHurt();

private:
    Ship(int id);

    void CheckMovement(float delta);
    void CheckShoot(float delta);
    void CheckHurtRoutine(float delta);

    float ClampPosition(float delta);

    float mShootFrequency;
    float mShootCooldown;
    float mSpeed;
    exVector2 mHalfSize;

    exColor mNormalColor;
    exColor mHurtColor;
    float mHurtTimer;


};