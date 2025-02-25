#ifndef __BOARD__CHESS
#define __BOARD__CHESS

#include <vector>

class Board
{
private:
    std::vector<int> pieces = {};

public:
    Board(/* args */);
    ~Board();
};

Board::Board(/* args */)
{
    // Initialize the board with pieces
}

Board::~Board()
{
}

#endif // __BOARD__CHESS