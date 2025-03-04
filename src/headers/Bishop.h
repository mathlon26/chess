#ifndef __BISHOP__CHESS
#define __BISHOP__CHESS

#include "Piece.h"
#include <vector>

class Bishop : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece> &pieces) override;

public:
    Bishop(Vec2 position, Color color);
};

#endif // __BISHOP__CHESS
