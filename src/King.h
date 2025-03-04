#ifndef __KING_CHESS
#define __KING_CHESS

#include <string>
#include "Piece.h"

class King : public Piece
{
private:
    bool m_firstMove;
public:
    King(Color _Color);
    ~King();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};



#endif // __KING_CHESS