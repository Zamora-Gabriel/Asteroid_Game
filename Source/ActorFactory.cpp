#include "ActorFactory.h"

ActorFactory* ActorFactory::sInstance = nullptr;

ActorFactory* ActorFactory::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new ActorFactory();
    }
    return sInstance;
}