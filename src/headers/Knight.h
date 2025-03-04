#ifndef __KNIGHT__CHESS
#define __KNIGHT__CHESS

#include "Piece.h"
#include <vector>

class Knight : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece> &pieces) override;

public:
    Knight(Vec2 position, Color color);
};

#endif // __KNIGHT__CHESS
