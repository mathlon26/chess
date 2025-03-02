#ifndef __BOARD_CHESS
#define __BOARD_CHESS

#include "Player.h"
#include <vector>

class Board
{
private:
    Player* m_playerWhite;
    Player* m_playerBlack;

    std::vector<std::vector<Piece*>> m_board{
        {new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, },
        {new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, new Piece{Color::BLACK}, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, },
        {new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, new Piece{Color::WHITE}, }
    };

    void parseInputToMove(const std::string& input, int &x0, int &y0, int &x1, int &y1);
    void updateBoard();
    bool isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1);
public:
    void draw();
    Board(Player* _PlayerWhite, Player* _PlayerBlack);
    ~Board();

    void newTurn(bool _WhiteTurn);
};


#endif // __BOARD_CHESS