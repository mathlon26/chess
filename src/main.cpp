#include <iostream>
#include "Player.h"
#include "Board.h"

void pause() {
    while (true){};
}

static bool running{true};
static long long int count{0};

int main()
{
    Player* playerWhite{new Player{Color::WHITE}};
    Player* playerBlack{ new Player{Color::BLACK}};
    
    Board board{playerWhite, playerBlack};
    board.draw();

    while (running)
    {
        board.newTurn(count++ % 2 == 0);
    }
    pause();
    return 0;
}
