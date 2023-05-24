#pragma once

#include "ComponentBase.h"
#include "Bounds.h"

class TransformComponent : public ComponentBase
{
public:
    TransformComponent(int actorID);

    ComponentType GetType() override { return ComponentType::Transform; }

    void Translate(exVector2 delta);

    Bounds      GetBounds() const { return mBounds; }
    exVector2   GetPosition() const { return mPosition; }
    exVector2   GetSize() const { return mSize; }

    void SetBounds(Bounds bounds) { mBounds = bounds; }
    void SetPosition(exVector2 position);
    void SetSize(exVector2 size);

private:
    void UpdateBounds();

    Bounds mBounds;
    exVector2 mPosition;
    exVector2 mSize;
};