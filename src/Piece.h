#ifndef __PIECE_CHESS
#define __PIECE_CHESS

#include <vector>
#include "Player.h"

class Piece
{
private:
    Color m_color;
public:
    Piece(Color _Color);
    ~Piece();

    Color getColor();
};

#endif // __PIECE_CHESS