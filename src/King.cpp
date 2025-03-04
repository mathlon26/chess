#include "King.h"

King::King(Color _Color)
    : Piece{_Color}
{
}

King::~King()
{
}

bool King::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece *>> &board)
{
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    // King must move at least one square and at most one square in any direction.
    if ((dx == 0 && dy == 0) || dx > 1 || dy > 1)
        return false;

    // If destination square is empty, move is allowed.
    if (board[y1][x1] == nullptr)
        return true;

    // If destination square is occupied, allow capture only if the piece is of opposite color.
    return board[y1][x1]->getColor() != m_color;
}

std::string King::getToken()
{
    return "K";
}