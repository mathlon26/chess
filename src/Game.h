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

class Game {
    public:
        // Public member functions
        void newTurn(bool _WhiteTurn);
        void draw();
        void checkForCheckMate();
        void parseInputToMove(const std::string &input, int &x0, int &y0, int &x1, int &y1);
        bool isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1);
    
        // Constructor & destructor
        Game(bool *running);
        ~Game();
    
        // Board and players (you may want to adjust their access specifiers as needed)
        static std::vector<std::vector<Piece*>> m_board;
    
    private:
        Player *m_playerWhite;
        Player *m_playerBlack;
        bool *m_running;
    
        // Declarations for checkmate helper functions
        bool isKingInCheck(Color kingColor);
        bool hasLegalMove(Color kingColor);
        bool doesMoveRemoveCheck(int x0, int y0, int x1, int y1, Color kingColor);
};


#endif // __BOARD_CHESS