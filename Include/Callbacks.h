#pragma once

#include "Events.h"
#include "World.h"
#include "Enums.h"
#include "ColliderComponent.h"

void ShootCallback(const IEventArgs& shootEvt)
{
    const ShootEventArgs* evt = static_cast<const ShootEventArgs*>(&shootEvt);
#if VERBOSE
    printf("CALLBACK - Shoot listener\n");
#endif

    auto bullet = WORLD->GetBulletPool()->GetNext();
    bullet->Shoot(evt->mPosition, 250);
}

void CollisionCallback(const IEventArgs& collisionEvt)
{
    const CollisionEventArgs* evt = static_cast<const CollisionEventArgs*>(&collisionEvt);
#if VERBOSE
    printf("CALLBACK - Collision listener %d, %d\n", evt->mCollider->GetTag(), evt->mOther);
#endif

    switch (evt->mCollider->GetTag())
    {
        case CollisionTag::SHIP:
        {
            if (evt->mOther == CollisionTag::ASTEROID)
            {
                WORLD->HurtPlayer(1);
            }
            break;
        }
        case CollisionTag::ASTEROID:
        {
            WORLD->AddPlayerScore(10);
        }
        // fallthrough
        case CollisionTag::BULLET:
        {
            if (WORLD->GetActor(evt->mCollider->GetActorID())->IsValid())
            {
                WORLD->GetActor(evt->mCollider->GetActorID())->GetActor()->SetActive(false);
            }
            break;
        }
    }
}