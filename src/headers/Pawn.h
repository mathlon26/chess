#ifndef __PAWN__CHESS
#define __PAWN__CHESS

#include "Piece.h"
#include <vector>

class Pawn : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece>& pieces) override;
public:
    Pawn(Vec2 position, Color color);
};

#endif // __PAWN__CHESS
