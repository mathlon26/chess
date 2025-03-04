#include "Bishop.h"

Bishop::Bishop(Color _Color)
    :
    Piece{_Color}
{
}

Bishop::~Bishop()
{
}

bool Bishop::isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece *>> &board)
{
    return true;
}

std::string Bishop::getToken()
{
    return "B";
}
