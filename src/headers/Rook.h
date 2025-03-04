#ifndef __ROOK__CHESS
#define __ROOK__CHESS

#include "Piece.h"
#include <vector>

class Rook : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece> &pieces) override;

public:
    Rook(Vec2 position, Color color);
};

#endif // __ROOK__CHESS
