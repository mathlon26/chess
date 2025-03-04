#ifndef __BOARD_CHESS
#define __BOARD_CHESS

#include "Player.h"
#include "Pawn.h"
#include <vector>

class Game
{
private:
    Player* m_playerWhite;
    Player* m_playerBlack;

    std::vector<std::vector<Piece*>> m_board{
        {new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, },
        {new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, },
        {new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, }
    };

    void parseInputToMove(const std::string& input, int &x0, int &y0, int &x1, int &y1);
    void updateBoard();
    inline bool isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1);
public:
    void draw();
    Game();
    ~Game();

    void newTurn(bool _WhiteTurn);
};


#endif // __BOARD_CHESS