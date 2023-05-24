#include "GameUI.h"
#include "World.h"
#include "Constants.h"
#include <string>
#include "Game.h"

GameUI* GameUI::sInstance = nullptr;

GameUI* GameUI::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new GameUI();
    }
    return sInstance;
}

void GameUI::Initialize()
{
    mTextColor = exColor(0, 0, 0);
    mScorePosition = exVector2(50, 50);
    mLivesPosition = exVector2(kViewportWidth - 150, 50);
}

void GameUI::RenderUI()
{
    if (WORLD->GetGameState() == GameState::Playing)
    {
        RenderPlayingState();
    }
    else
    {
        RenderGameOver();
    }
}

void GameUI::RenderPlayingState()
{
    auto engine = Game::GetInstance()->GetEngine();

    sprintf_s(mScoreStringBuilder, BUFFER_SIZE, "Score: %d", WORLD->GetPlayerScore());
    engine->DrawText(mFontID, mScorePosition, mScoreStringBuilder, mTextColor, 1);

    sprintf_s(mLivesStringBuilder, BUFFER_SIZE, "Lives: %d", WORLD->GetPLayerLives());
    engine->DrawText(mFontID, mLivesPosition, mLivesStringBuilder, mTextColor, 1);
}

void GameUI::RenderGameOver()
{
    auto engine = Game::GetInstance()->GetEngine();

    exVector2 centerScreen = exVector2(kViewportWidth / 2.0f, kViewportHeight / 2.0f);

    exVector2 gameOverPosition = exVector2(centerScreen.x - 100, centerScreen.y - 20);
    exVector2 finalScorePosition = exVector2(centerScreen.x - 100, centerScreen.y + 20);

    engine->DrawText(mFontID, gameOverPosition, "GAME OVER", mTextColor, 1);

    sprintf_s(mScoreStringBuilder, BUFFER_SIZE, "Score: %d", WORLD->GetPlayerScore());
    engine->DrawText(mFontID, finalScorePosition, mScoreStringBuilder, mTextColor, 1);
}