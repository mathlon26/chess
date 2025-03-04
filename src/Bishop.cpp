#include "Bishop.h"

Bishop::Bishop(Color _Color)
    : Piece{_Color}
{
}

Bishop::~Bishop()
{
}

bool Bishop::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    // The move must be diagonal and non-zero.
    if (std::abs(dx) != std::abs(dy) || (dx == 0 && dy == 0))
        return false;
    
    // Determine the step increments.
    int stepX = (dx > 0) ? 1 : -1;
    int stepY = (dy > 0) ? 1 : -1;
    
    // Check each square along the diagonal path, excluding the destination.
    int curX = x0 + stepX;
    int curY = y0 + stepY;
    while (curX != x1)
    {
        if (board[curY][curX] != nullptr)
            return false;
        curX += stepX;
        curY += stepY;
    }
    
    // Check the destination square:
    // Allow the move if the square is empty, or if it contains an opponent's piece.
    if (board[y1][x1] == nullptr)
        return true;
    return board[y1][x1]->getColor() != m_color;
}


std::string Bishop::getToken()
{
    return "B";
}
