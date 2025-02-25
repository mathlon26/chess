#ifndef __PIECE__CHESS
#define __PIECE__CHESS

#include "Vec2.h"
#include "Color.h"
#include <vector>

class Piece
{
private:
    Vec2 m_position;
    /* data */
protected:
    Color m_color;

    virtual bool isValidMove(Vec2 newPos, std::vector<Piece>& pieces) {};
public:
    Piece(Vec2 position, Color color);
};

#endif // __PIECE__CHESS
