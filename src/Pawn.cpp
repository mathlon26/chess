#include <string>
#include "Pawn.h"
#include <math.h>


Pawn::Pawn(Color _Color)
    :   
    Piece{_Color},
    m_firstMove{true}
{
}

Pawn::~Pawn()
{
}

bool Pawn::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board)
{
    // For white (at bottom), forward means moving up (decreasing y)
    int direction = (m_color == Color::WHITE) ? -1 : 1;
    int maxYDT = m_firstMove ? 2 : 1;

    // Normal move (no capture)
    if (x0 == x1)
    {
        if (y1 - y0 != direction && y1 - y0 != direction * maxYDT)
            return false;

        // Check all squares in the path are empty.
        for (int i = 1; i <= abs(y1 - y0); i++)
        {
            if (board[y0 + i * direction][x0] != nullptr)
                return false;
        }
        
        m_firstMove = false;
        return true;
    }

    // Capture move (diagonal)
    if (abs(x1 - x0) == 1 && y1 - y0 == direction)
    {
        if (board[y1][x1] != nullptr)
        {
            m_firstMove = false;
            return true;
        }
    }

    return false;
}


std::string Pawn::getToken()
{
    return "p";
}
