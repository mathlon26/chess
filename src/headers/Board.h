#ifndef __BOARD__CHESS
#define __BOARD__CHESS

#include <vector>
#include <iostream>

class Board
{
private:
    std::vector<int> pieces = {};

public:
    Board(/* args */);
    ~Board();
    void Draw();
};

#endif // __BOARD__CHESS