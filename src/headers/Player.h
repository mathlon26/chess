#ifndef __PLAYER__CHESS
#define __PLAYER__CHESS

#include "Color.h"
#include <iostream>
#include <string>

class Player
{
private:
    std::string m_position;

public:
    Player();
    const std::string getMoveInput();
};

#endif // __PLAYER__CHESS