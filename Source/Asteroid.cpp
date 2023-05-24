#include "Asteroid.h"
#include "World.h"
#include "Constants.h"
#include "ColliderComponent.h"
#include "TransformComponent.h"
#include "Game.h"

Asteroid::Asteroid(int id)
    : IPoolableActor(id)
{
    auto colliderComponent = new ColliderComponent(id);
    colliderComponent->SetTag(CollisionTag::ASTEROID);

    AddComponent(colliderComponent);
}

void Asteroid::Initialize()
{
    auto wSize = WORLD->GetWorldSize();

    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);

    auto size = exVector2(40, 40);
    transform->SetSize(size);

    mHalfSize = exVector2(size.x / 2.0f, size.y / 2.0f);

    mColor = exColor(77, 38, 0);
}

void Asteroid::Respawn()
{
    mIsActive = true;
#if VERBOSE
    printf("Asteroid - Asteoird %d has been respawned\n", mID);
#endif
}

void Asteroid::Update(float dt)
{
    UpdateMovement(dt);
    CheckOutOfScreen();
}

void Asteroid::Render()
{
    auto engine = Game::GetInstance()->GetEngine();

    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    auto bounds = transform->GetBounds();

    engine->DrawLineBox(bounds.min, bounds.max, mColor, 0);

    auto coreBounds = bounds;
    coreBounds.min.x += mHalfSize.x / 2.0f;
    coreBounds.min.y += mHalfSize.y / 2.0f;
    
    coreBounds.max.x -= mHalfSize.x / 2.0f;
    coreBounds.max.y -= mHalfSize.y / 2.0f;

    engine->DrawBox(coreBounds.min, coreBounds.max, mColor, 0);
}

void Asteroid::Launch(exVector2 position, exVector2 direction, float speed)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    transform->SetPosition(position);
    mDirection = direction;
    mSpeed = speed;
#if VERBOSE
    printf("Asteroid - Asteroid %d has been launched from %f.2, %f.2 at %f.3, %f.3\n", 
        mID, position.x, position.y, mDirection.x, mDirection.y);
#endif

}

void Asteroid::UpdateMovement(float dt)
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    transform->Translate(exVector2(mDirection.x * mSpeed * dt, mDirection.y * mSpeed * dt));
}

void Asteroid::CheckOutOfScreen()
{
    auto transform = GetComponent<TransformComponent>(ComponentType::Transform);
    if (transform->GetPosition().y - mHalfSize.y > kViewportHeight)
    {
#if VERBOSE
        printf("Asteroid - Asteroid %d has been removed because is out of screen\n", mID);
#endif
        mIsActive = false;
    }
}
