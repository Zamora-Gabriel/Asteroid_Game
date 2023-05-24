#include "Game.h"

#include "Constants.h"
#include "EngineInterface.h"
#include "SDL.h"
#include "World.h"
#include "InputManager.h"
#include "GameUI.h"

#include <iostream>

Game* Game::sInstance = nullptr;

Game* Game::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new Game();
    }
    return sInstance;
}

Game::Game() 
    : mEngine(nullptr)
    , mFontID(-1)
    , mWindowName("Game")
{}

Game::~Game()
{

}

void Game::Initialize(exEngineInterface* engine)
{
    mEngine = engine;
    WORLD->Initialize();

    GameUI::GetInstance()->Initialize();
    GameUI::GetInstance()->SetFontID(engine->LoadFont("resources/Urusans.ttf", 32));
}

const char* Game::GetWindowName() const
{
    return mWindowName;
}

void Game::GetClearColor(exColor& color) const
{
    color.r = 200;
    color.g = 200;
    color.b = 255;
}

void Game::OnEvent(SDL_Event* event)
{}

void Game::OnEventsConsumed()
{
    INPUT->Update();
}

void Game::Run(float deltaTime)
{
    WORLD->Update(deltaTime);
    WORLD->PostUpdate();

    GameUI::GetInstance()->RenderUI();
}

exEngineInterface* Game::GetEngine() const
{
    return mEngine;
}