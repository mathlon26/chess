#ifndef __COLOR_CHESS
#define __COLOR_CHESS

enum class Color{WHITE, BLACK};

#endif // __COLOR_CHESS


#ifndef __PLAYER_CHESS
#define __PLAYER_CHESS

#include <vector>
#include <string>
#include "Piece.h"

class Player
{
private:
    Color m_color;
public:
    Player(Color _Color);
    ~Player();

    std::string getInput();
    Color getColor();
};

#endif // __PLAYER_CHESS