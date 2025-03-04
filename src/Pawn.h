#ifndef __PAWN_CHESS
#define __PAWN_CHESS

#include <string>
#include "Piece.h"

class Pawn : public Piece
{
private:
    bool m_firstMove;
public:
    Pawn(Color _Color);
    ~Pawn();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};



#endif // __PAWN_CHESS