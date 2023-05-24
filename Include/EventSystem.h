#pragma once

#include "Events.h"
#include <map>
#include <vector>
#include "Enums.h"

class IEventArgs;

typedef void(*EvtCallback)(const IEventArgs&);

#define EVTSYS EventSystem::GetInstance()

class EventSystem
{
public:
    static EventSystem* GetInstance();
    ~EventSystem();

    void StartListening(EventTypes type, const EvtCallback& callback);
    void StopListening(EventTypes type, const EvtCallback& callback);
    void Trigger(EventTypes type, const IEventArgs& args);

private:
    static EventSystem* sInstance;

    EventSystem() = default;

    std::map<EventTypes, std::vector<EvtCallback>> mListeners;
};