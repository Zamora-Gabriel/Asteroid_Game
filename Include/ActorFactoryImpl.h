#pragma once

#include "ActorFactory.h"
#include "World.h"

template<typename T>
T* ActorFactory::CreateActor()
{
    T* actor = new T(ids++);
    WORLD->AddActor(actor);
    return actor;
}
