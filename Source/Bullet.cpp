#include "Bullet.h"
#include "World.h"
#include "Constants.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"

Bullet::Bullet(int id)
    : IPoolableActor(id)
    , mSpeed(0)
{
    auto colliderComponent = new ColliderComponent(id);
    colliderComponent->SetTag(CollisionTag::BULLET);

    AddComponent(colliderComponent);
}

void Bullet::Initialize()
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);

    auto size = exVector2(10, 20);
    transform->SetSize(size);
    mHalfSize = exVector2(size.x / 2.0f, size.y / 2.0f);

    mColor = exColor(51, 51, 255);
}

void Bullet::Respawn()
{
#if VERBOSE
    printf("BULLET - Bullet %d has been respawned\n", mID);
#endif
    mIsActive = true;
}

void Bullet::Update(float dt)
{
    UpdateMovement(dt);
    CheckOutOfScreen();
}

void Bullet::Shoot(exVector2 position, float speed)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);

    transform->SetPosition(position);
    mSpeed = speed;
}

void Bullet::UpdateMovement(float dt)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    transform->Translate(exVector2(0, -mSpeed * dt));
}

void Bullet::CheckOutOfScreen()
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    if (transform->GetPosition().y + mHalfSize.y < 0)
    {
#if VERBOSE
        printf("BULLET - Bullet %d has been removed because it out of screen\n", mID);
#endif

        mIsActive = false;
    }
}