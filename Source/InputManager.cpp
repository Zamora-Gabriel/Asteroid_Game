#include "InputManager.h"

#include "SDL.h"

InputManager* InputManager::sInstance = nullptr;

InputManager* InputManager::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new InputManager();
    }
    return sInstance;
}

void InputManager::Update()
{
    mState = CMD_NONE;

    if (IsButtonDown(SDL_SCANCODE_SPACE))
    {
        mState = mState | CMD_SHOOT;
    }

    if (IsButtonDown(SDL_SCANCODE_A))
    {
        mState = mState | CMD_LEFT;
    }

    if (IsButtonDown(SDL_SCANCODE_D))
    {
        mState = mState | CMD_RIGHT;
    }
}

bool InputManager::IsButtonDown(int nScancode) const
{
    int nKeys = 0;
    const Uint8* pKeys = SDL_GetKeyboardState(&nKeys);

    if (pKeys == nullptr)
    {
        return false;
    }

    if (nScancode >= nKeys)
    {
        return false;
    }

    return pKeys[nScancode];
}

bool InputManager::IsShooting() const
{
    return mState & CMD_SHOOT;
}

bool InputManager::IsMovingLeft() const
{
    return mState & CMD_LEFT;
}

bool InputManager::IsMovingRight() const
{
    return mState & CMD_RIGHT;
}

InputManager::InputManager()
    : mState(CMD_NONE)
{

}