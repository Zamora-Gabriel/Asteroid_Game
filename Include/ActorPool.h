#pragma once

#include <vector>

template<typename T>
class ActorPool
{
public:
    ActorPool();
    ~ActorPool();

    void InitializePool(int sizePool);

    T* GetNext();

private:
    int mPoolSize;
    int mLastPoolIdx;
    std::vector<T*> mPool;

    int FindNextAvailable();
    T* ExpandPool();
};
