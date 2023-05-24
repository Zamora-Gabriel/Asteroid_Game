#pragma once


#include "EngineInterface.h"
#include "EngineTypes.h"
#include "Bounds.h"
#include "ActorFactory.h"
#include "ComponentBase.h"
#include <vector>

class Actor
{
    FACTORIZE

public:
    virtual void Update(float dt) = 0;
    virtual void Render();
    
    int         GetID() const { return mID; }

    exColor     GetColor() const { return mColor; }

    bool IsActive() const;
    void SetActive(bool active);

    void AddComponent(ComponentBase* component);
    void RemoveComponent(ComponentType type);

    template <typename T>
    T* GetComponent(ComponentType type) const;

protected:
    int mID;

    exColor mColor;

    bool mIsActive;

    std::vector<ComponentBase*> mComponents;

    Actor(int id, bool isActive = true);
};