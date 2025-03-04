#include "Knight.h"

Knight::Knight(Color _Color)
    :
    Piece{_Color}
{
}

Knight::~Knight()
{
}

bool Knight::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece *>> &board)
{
    return false;
}

std::string Knight::getToken()
{
    return "H";
}
