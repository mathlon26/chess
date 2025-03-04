#include "Piece.h"

Piece::Piece(Color _Color)
    :
    m_color{_Color}
{
}

Piece::~Piece()
{
}

Color Piece::getColor()
{
    return m_color;
}
