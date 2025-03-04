#include "Queen.h"

Queen::Queen(Color _Color)
    :
    Piece{_Color}
{
}

Queen::~Queen()
{
}

bool Queen::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    // The move must not be zero.
    if(dx == 0 && dy == 0)
        return false;

    // Check if the move is along a straight line (rook-like) or diagonal (bishop-like).
    if( dx != 0 && dy != 0 && std::abs(dx) != std::abs(dy) )
        return false;

    // Determine step increments for x and y.
    int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
    int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

    // Check each square along the path, excluding the destination.
    int curX = x0 + stepX;
    int curY = y0 + stepY;
    while(curX != x1 || curY != y1)
    {
        if(board[curY][curX] != nullptr)
            return false;
        curX += stepX;
        curY += stepY;
    }

    // Validate the destination square:
    // Allowed if the square is empty or holds an opponent's piece.
    if(board[y1][x1] == nullptr)
        return true;
    else
        return board[y1][x1]->getColor() != m_color;
}


std::string Queen::getToken()
{
    return "Q";
}
