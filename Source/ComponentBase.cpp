#include "ComponentBase.h"
#include "Actor.h"
#include "World.h"

ComponentBase::ComponentBase(int actorID) :
    mActorID(actorID)
{}

ActorHandle* ComponentBase::GetOwner() const
{
    return WORLD->GetActor(mActorID);
}