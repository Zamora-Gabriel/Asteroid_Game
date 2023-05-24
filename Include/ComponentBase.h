#pragma once

#include "Enums.h"

class ActorHandle;

class ComponentBase
{
public:
    ComponentBase(int actorID);

    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void PostUpdate() {}

    virtual ComponentType GetType() = 0;

    int GetActorID() const { return mActorID; }
    ActorHandle* GetOwner() const;

protected:
    int mActorID;
};