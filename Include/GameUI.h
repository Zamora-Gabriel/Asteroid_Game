#pragma once

#include "EngineTypes.h"

class exEngineInterface;

#define BUFFER_SIZE 32

class GameUI
{
public:
    static GameUI* GetInstance();

    void Initialize();
    void RenderUI();

    void SetFontID(int fontID) { mFontID = fontID; }

private:
    GameUI() = default;

    void RenderPlayingState();
    void RenderGameOver();

    static GameUI* sInstance;

    int mFontID;
    const char* mWindowName;

    char mScoreStringBuilder[BUFFER_SIZE];
    char mLivesStringBuilder[BUFFER_SIZE];

    exColor mTextColor;
    exVector2 mScorePosition;
    exVector2 mLivesPosition;
};