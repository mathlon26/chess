#ifndef __KING__CHESS
#define __KING__CHESS

#include "Piece.h"
#include <vector>

class King : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece> &pieces) override;

public:
    King(Vec2 position, Color color);
};

#endif // __KING__CHESS
