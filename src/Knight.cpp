#include "Knight.h"

Knight::Knight(Color _Color)
    : Piece{_Color}
{
}

Knight::~Knight()
{
}

bool Knight::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board)
{
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    // The knight moves in an L-shape: either (1, 2) or (2, 1)
    if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1)))
        return false;

    // If the destination square is empty, it's a valid move.
    if (board[y1][x1] == nullptr)
        return true;

    // Otherwise, the destination must contain an opponent's piece.
    return board[y1][x1]->getColor() != m_color;
}


std::string Knight::getToken()
{
    return "H";
}