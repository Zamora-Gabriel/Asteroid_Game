#pragma once

#include "EngineTypes.h"

#define FACTORIZE friend ActorFactory;
#define ACTORFAC ActorFactory::GetInstance()

class ActorFactory
{
public:
    static ActorFactory* GetInstance();

    template<typename T>
    T* CreateActor();

private:
    ActorFactory() = default;

    static ActorFactory* sInstance;

    int ids = 0;
};
