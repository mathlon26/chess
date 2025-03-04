#include <iostream>
#include "Player.h"
#include "Game.h"

void pause() {
    while (true){};
}

static bool running{true};
static long long int count{0};

int main()
{
    Game game{};
    game.draw();

    while (running)
    {
        game.newTurn(count++ % 2 == 0);
    }
    pause();
    return 0;
}
