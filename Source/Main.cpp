#include "Game.h"
#include "EngineInterface.h"

int main()
{
    exEngineInterface* engine = AccessEngine();

    if (engine == nullptr)
    {
        return 0;
    }

    engine->Run(Game::GetInstance());

    return 0;
}