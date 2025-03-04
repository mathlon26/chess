#ifndef __KNIGHT_CHESS
#define __KNIGHT_CHESS

#include <string>
#include "Piece.h"

class Knight : public Piece
{
private:
    bool m_firstMove;
public:
    Knight(Color _Color);
    ~Knight();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};


#endif // __KNIGHT_CHESS