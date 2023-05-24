#pragma once

#include "ActorPool.h"
#include "ActorFactory.h"

#define NOFIND -1

template <typename T>
ActorPool<T>::ActorPool()
    : mPoolSize(0)
    , mLastPoolIdx(0)
{}

template <typename T>
ActorPool<T>::~ActorPool()
{
    for (auto* t : mPool)
    {
        delete t;
    }
    mPool.clear();
}

template <typename T>
void ActorPool<T>::InitializePool(int sizePool)
{
    mPoolSize = sizePool;
    mPool.reserve(mPoolSize);
    for (int i = 0; i < mPoolSize; ++i)
    {
        mPool.emplace_back(ACTORFAC->CreateActor<T>());
        mPool[i]->Initialize();
    }
}

template <typename T>
T* ActorPool<T>::GetNext()
{
    int next = FindNextAvailable();

    if (next != NOFIND)
    {
        mPool[next]->Respawn();
        return mPool[next];
    }

    // 
    return ExpandPool();
}

template <typename T>
int ActorPool<T>::FindNextAvailable()
{
    int i = (mLastPoolIdx + 1) % mPoolSize;
    while (i != mLastPoolIdx)
    {
        if (i == mLastPoolIdx)
        {
            break;
        }

        if (!mPool[i]->IsActive())
        {
            mLastPoolIdx = i;
            return mLastPoolIdx;
        }
        i = (i + 1) % mPoolSize;
    }

    return NOFIND;
}

template <typename T>
T* ActorPool<T>::ExpandPool()
{
    mPool.push_back(ACTORFAC->CreateActor<T>());
    mPool[mPoolSize]->Initialize();
    mPool[mPoolSize]->Respawn();
    mPoolSize++;
    return mPool[mPoolSize - 1];
}