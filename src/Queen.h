#ifndef __QUEEN_CHESS
#define __QUEEN_CHESS

#include <string>
#include "Piece.h"

class Queen : public Piece
{
private:
    bool m_firstMove;
public:
    Queen(Color _Color);
    ~Queen();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};



#endif // __QUEEN_CHESS