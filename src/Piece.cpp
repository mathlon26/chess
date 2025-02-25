#include "Piece.h"

Piece::Piece(Vec2 position, Color color)
    : m_position{position},
      m_color{color}
{
}

void Piece::moveTo(Vec2 newPos, std::vector<Piece> &pieces)
{
}