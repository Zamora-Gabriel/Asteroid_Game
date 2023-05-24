#include "TransformComponent.h"
#include "Actor.h"
#include "ActorHandle.h"
#include "ActorImpl.h"
#include "ColliderComponent.h"

TransformComponent::TransformComponent(int actorID)
    : ComponentBase(actorID)
{}

void TransformComponent::Translate(exVector2 delta)
{
    SetPosition(exVector2(mPosition.x + delta.x, mPosition.y + delta.y));
}

void TransformComponent::SetPosition(exVector2 position)
{
    mPosition = position;
    UpdateBounds();
}

void TransformComponent::SetSize(exVector2 size)
{
    mSize = size;
    UpdateBounds();
}

void TransformComponent::UpdateBounds()
{
    exVector2 halfSize = exVector2(mSize.x / 2, mSize.y / 2);

    mBounds.min.x = mPosition.x - halfSize.x;
    mBounds.min.y = mPosition.y - halfSize.y;

    mBounds.max.x = mPosition.x + halfSize.x;
    mBounds.max.y = mPosition.y + halfSize.y;

    if (GetOwner()->IsValid())
    {
        if (auto collider = GetOwner()->GetActor()->GetComponent<ColliderComponent>(ComponentType::Collider))
        {
            collider->SetBounds(mBounds);
        }
    }
}