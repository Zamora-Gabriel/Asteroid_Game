#include "AsteroidManager.h"
#include "ActorFactoryImpl.h"
#include "ActorPoolImpl.h"
#include "Constants.h"
#include "World.h"
#include "MathUtils.h"
#include "TransformComponent.h"

void AsteroidManager::Initialize(int poolSize, float initiaFreqSec, AsteroidTargetPositionGenerator generator)
{
    mAsteroidPool = new ActorPool<Asteroid>();
    mAsteroidPool->InitializePool(poolSize);

    mSpawnCooldownSec = 0.0f;
    mSpawnFrequency = initiaFreqSec;

    mAsteroidBaseSpeed = 80.0f;
    mTargetPositionGenerator = generator;
}

void AsteroidManager::Update(float dt)
{
    mSpawnCooldownSec -= dt;

    if (mSpawnCooldownSec <= 0.0f)
    {
        SpawnAsteroid();
        mSpawnCooldownSec = GetCooldown();
    }
}

void AsteroidManager::SpawnAsteroid()
{
    auto asteroid = mAsteroidPool->GetNext();

    exVector2 originPosition = GetSpawnPosition(asteroid);
    exVector2 direction = GetDirection(originPosition);

    float speedOffset = rand() % 50 - 25;

    asteroid->Launch(originPosition, direction, mAsteroidBaseSpeed + speedOffset);
}

exVector2 AsteroidManager::GetSpawnPosition(const Asteroid* asteroid) const
{
    auto asteroidTransform = asteroid->GetComponent<TransformComponent>(ComponentType::Transform);

    const int halfWindowSize = kViewportWidth / 2.0f;
    const int quarterWindowSize = halfWindowSize / 2.0f;

    float x = float(rand() % (halfWindowSize + kViewportWidth)) - quarterWindowSize;
    float y = -asteroidTransform->GetSize().y;

    return exVector2(x, y);
}

exVector2 AsteroidManager::GetDirection(const exVector2& originPosition) const
{
    exVector2 targetPosition = mTargetPositionGenerator();
    exVector2 direction = exVector2(targetPosition.x - originPosition.x,
                                    targetPosition.y - originPosition.y);

    MathUtils::normalizeVector(direction);

    return direction;
}

float AsteroidManager::GetCooldown() const
{
    return mSpawnFrequency - (int(WORLD->GetTotalPlayedTime() / 10.0f)) * 0.1f;
}
