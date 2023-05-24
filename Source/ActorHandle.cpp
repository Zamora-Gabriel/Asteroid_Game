#include "ActorHandle.h"

ActorHandle::ActorHandle(Actor* actor)
    : mActor(actor)
{

}

bool ActorHandle::IsValid() const
{
    return mActor != nullptr;
}

Actor* ActorHandle::GetActor() const
{
    return mActor;
}