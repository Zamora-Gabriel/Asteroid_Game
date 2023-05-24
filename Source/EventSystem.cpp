#include "EventSystem.h"

EventSystem* EventSystem::sInstance = nullptr;

EventSystem* EventSystem::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new EventSystem();
    }
    return sInstance;
}

EventSystem::~EventSystem()
{
    for (auto& listeners : mListeners)
    {
        listeners.second.clear();
    }
    mListeners.clear();
}

void EventSystem::StartListening(EventTypes type, const EvtCallback& callback)
{
    mListeners[type].push_back(callback);
}

void EventSystem::StopListening(EventTypes type, const EvtCallback& callback)
{
    auto listeners = mListeners[type];

    if (listeners.empty())
    {
        return;
    }

    for (auto it = listeners.end() - 1; it != listeners.begin(); --it)
    {
        if (*it == callback)
        {
            mListeners[type].erase(it);
            return;
        }
    }
}

void EventSystem::Trigger(EventTypes type, const IEventArgs& args)
{
    const auto listeners = mListeners[type];

    if (listeners.empty())
    {
        return;
    }

    for (auto it = listeners.begin(); it != listeners.end(); ++it)
    {
        (*it)(args);
    }
}