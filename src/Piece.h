#ifndef __PIECE_CHESS
#define __PIECE_CHESS

#include <vector>
#include "Player.h"

class Piece
{
protected:
    Color m_color;
public:
    Piece(Color _Color);
    ~Piece();
    virtual bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) {return true;};
    virtual std::string getToken() {return " ";};
    Color getColor();
};

#endif // __PIECE_CHESS