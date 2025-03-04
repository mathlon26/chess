#include "Rook.h"

Rook::Rook(Color _Color)
    :
    Piece{_Color}
{
}

Rook::~Rook()
{
}

bool Rook::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    // Rook must move in a straight line (either horizontally or vertically)
    if (x0 != x1 && y0 != y1)
        return false;

    // Ensure the move is not staying in place
    if (dx == 0 && dy == 0)
        return false;

    // Determine the increments for the movement.
    int stepX = (dx == 0) ? 0 : ((dx > 0) ? 1 : -1);
    int stepY = (dy == 0) ? 0 : ((dy > 0) ? 1 : -1);

    // Check each square along the path, excluding the destination.
    int curX = x0 + stepX;
    int curY = y0 + stepY;
    while (curX != x1 || curY != y1)
    {
        if (board[curY][curX] != nullptr)
            return false;
        curX += stepX;
        curY += stepY;
    }

    // Check the destination square:
    // If it's empty, the move is allowed.
    if (board[y1][x1] == nullptr)
        return true;
    // If occupied, ensure the piece belongs to the opposite color.
    return board[y1][x1]->getColor() != m_color;
}


std::string Rook::getToken()
{
    return "R";
}
