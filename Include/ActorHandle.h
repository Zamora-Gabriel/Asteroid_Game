#pragma once

class Actor;

class ActorHandle
{
public:
    ActorHandle(Actor* actor);

    bool IsValid() const;

    Actor* GetActor() const;

private:
    Actor* mActor;
};
