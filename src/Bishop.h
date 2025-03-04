#ifndef __BISHOP_CHESS
#define __BISHOP_CHESS

#include <string>
#include "Piece.h"

class Bishop : public Piece
{
private:
    bool m_firstMove;
public:
    Bishop(Color _Color);
    ~Bishop();
    bool isPossibleMove(int &x0, int &y0, int &x1, int &y1, std::vector<std::vector<Piece*>> &board) override;
    std::string getToken() override;
};



#endif // __BISHOP_CHESS