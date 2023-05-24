#pragma once

#define INPUT InputManager::GetInstance()

class InputManager
{
public:
    static InputManager* GetInstance();

    void Update();

    bool IsButtonDown(int nScancode) const;

    bool IsShooting() const;
    bool IsMovingLeft() const;
    bool IsMovingRight() const;

private:
    static InputManager* sInstance;

    InputManager();

    const short CMD_NONE = 0;
    const short CMD_SHOOT = 1 << 0;
    const short CMD_LEFT = 1 << 1;
    const short CMD_RIGHT = 1 << 2;
    short mState;
};