#include "Ship.h"
#include "World.h"
#include "InputManager.h"
#include "Constants.h"
#include "EventSystem.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"

Ship::Ship(int id) : Actor(id)
{
    auto colliderComponent = new ColliderComponent(id);
    colliderComponent->SetTag(CollisionTag::SHIP);

    AddComponent(colliderComponent);
}

void Ship::Initialize()
{
    auto wSize = WORLD->GetWorldSize();
    int padding = 10;

    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);

    auto size = exVector2(50, 20);
    transform->SetSize(size);
    transform->SetPosition(exVector2(wSize.x / 2.0f, wSize.y - size.y - padding));

    mHalfSize = exVector2(size.x / 2.0f, size.y / 2.0f);

    mColor = mNormalColor = exColor(66, 33, 0);
    mHurtColor = exColor(255, 0, 0);
    mHurtTimer = 0;

    mSpeed = 100;

    mShootFrequency = 1.0f;

    mShootCooldown = 0.0f;
}

void Ship::Update(float dt)
{
    CheckMovement(dt);

    CheckShoot(dt);

    CheckHurtRoutine(dt);
}

void Ship::PlayHurt()
{
    mColor = mHurtColor;
    mHurtTimer = HURT_DURATION;
}

void Ship::CheckMovement(float dt)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    if (INPUT->IsMovingLeft())
    {
        transform->Translate(exVector2(ClampPosition(mSpeed * dt * -1), 0));
    }

    if (INPUT->IsMovingRight())
    {
        transform->Translate(exVector2(ClampPosition(mSpeed * dt), 0));
    }
}

void Ship::CheckShoot(float dt)
{
    mShootCooldown -= dt;
    if (INPUT->IsShooting() && mShootCooldown <= 0.0f)
    {
        mShootCooldown = mShootFrequency;
        
        auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
        auto pos = transform->GetPosition();
        auto size = transform->GetSize();
        ShootEventArgs args = { exVector2(pos.x, pos.y - size.y) };
        EVTSYS->Trigger(EventTypes::Shoot, args);
    }
}

void Ship::CheckHurtRoutine(float dt)
{
    if (mHurtTimer > 0.0f)
    {
        mHurtTimer -= dt;
        if (mHurtTimer <= 0.0f)
        {
            mColor = mNormalColor;
        }
    }
}

float Ship::ClampPosition(float delta)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    auto pos = transform->GetPosition();

    if ((delta < 0.0f && (pos.x - mHalfSize.x + delta) < 0) ||
        (delta > 0.0f && (pos.x + mHalfSize.x + delta) > kViewportWidth))
    {
        return 0.0f;
    }
    return delta;
}