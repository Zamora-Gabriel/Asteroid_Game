#pragma once

#include "EngineTypes.h"
#include "ActorPool.h"
#include "Asteroid.h"
#include <functional>

typedef std::function<exVector2(void)> AsteroidTargetPositionGenerator;

class AsteroidManager
{
public:
    AsteroidManager() = default;

    void Initialize(int poolSize, float initialFreqSec, AsteroidTargetPositionGenerator generator);
    void Update(float dt);

private:
    void SpawnAsteroid();
    exVector2 GetSpawnPosition(const Asteroid* asteroid) const;
    exVector2 GetDirection(const exVector2& originPosition) const;
    float GetCooldown() const;

    ActorPool<Asteroid>* mAsteroidPool = nullptr;

    AsteroidTargetPositionGenerator mTargetPositionGenerator;

    float mAsteroidBaseSpeed = 80;
    float mSpawnCooldownSec = 0.0f;
    float mSpawnFrequency = 1.0f;

};