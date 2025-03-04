#ifndef __ROOK_CHESS
#define __ROOK_CHESS

#include <string>
#include "Piece.h"

class Rook : public Piece
{
private:
    bool m_firstMove;
public:
    Rook(Color _Color);
    ~Rook();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};



#endif // __ROOK_CHESS