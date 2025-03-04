#include <iostream>
#include "Player.h"
#include "Game.h"

static bool running{true};
static long long int count{0};


void pause() {
    while (true) {};
}

int main()
{
    Game game{&running};
    game.draw();

    while (running)
    {
        // New turen alternating between the black and white player
        game.newTurn(count++ % 2 == 0);
    }

    pause();
    
    return 0;
}
