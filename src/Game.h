#ifndef __BOARD_CHESS
#define __BOARD_CHESS

#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include <vector>

class Game
{
private:
    Player* m_playerWhite;
    Player* m_playerBlack;

    bool *m_running;

    std::vector<std::vector<Piece*>> m_board{
        {new Rook{Color::BLACK}, new Pawn{Color::BLACK}, new Bishop{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Bishop{Color::BLACK}, new Pawn{Color::BLACK}, new Rook{Color::BLACK}, },
        {new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, },
        {new Rook{Color::WHITE}, new Pawn{Color::WHITE}, new Bishop{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Bishop{Color::WHITE}, new Pawn{Color::WHITE}, new Rook{Color::WHITE}, }
    };

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