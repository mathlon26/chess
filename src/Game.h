#ifndef __BOARD_CHESS
#define __BOARD_CHESS

#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include <vector>

class Game
{
private:
    Player* m_playerWhite;
    Player* m_playerBlack;

    bool *m_running;

    static std::vector<std::vector<Piece*>> m_board;

    void parseInputToMove(const std::string& input, int &x0, int &y0, int &x1, int &y1);
    void updateBoard();
    inline bool isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1);
public:
    void draw();
    Game(bool *running);
    ~Game();

    void newTurn(bool _WhiteTurn);
};


#endif // __BOARD_CHESS