#ifndef __QUEEN__CHESS
#define __QUEEN__CHESS

#include "Piece.h"
#include <vector>

class Queen : public Piece
{
private:
    /* data */

    bool isValidMove(Vec2 newPos, std::vector<Piece> &pieces) override;

public:
    Queen(Vec2 position, Color color);
};

#endif // __QUEEN__CHESS
