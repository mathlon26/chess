#include "Game.h"
#include <string>
#include <iostream>

std::vector<std::vector<Piece *>> Game::m_board{
    {
        {new Rook{Color::BLACK}, new Knight{Color::BLACK}, new Bishop{Color::BLACK}, new Queen{Color::BLACK}, new King{Color::BLACK}, new Bishop{Color::BLACK}, new Knight{Color::BLACK}, new Rook{Color::BLACK}, },
        {new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, new Pawn{Color::BLACK}, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, },
        {new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, new Pawn{Color::WHITE}, },
        {new Rook{Color::WHITE}, new Knight{Color::WHITE}, new Bishop{Color::WHITE}, new Queen{Color::WHITE}, new King{Color::WHITE}, new Bishop{Color::WHITE}, new Knight{Color::WHITE}, new Rook{Color::WHITE}, }
    }
};

void Game::parseInputToMove(const std::string &input, int &x0, int &y0, int &x1, int &y1)
{
    if (input.length() >= 7 && input[2] == ' ' && input[3] == 't' && input[4] == 'o' && input[5] == ' ')
    {
        x0 = input[0] - '0';
        y0 = input[1] - '0';
        x1 = input[6] - '0';
        y1 = input[7] - '0';
    }
    else
    {
        std::cerr << "Invalid input format! Expected format: '00 to 01'\n";
        x0 = y0 = x1 = y1 = -1; // Error flag
    }
}


inline bool Game::isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1)
{
    if (x1 > 7 || x1 < 0 || y1 > 7 || y1 < 0)
        return false;
    
    return _Selected->isPossibleMove(x0, y0, x1, y1, m_board);
}


void Game::draw()
{
    std::cout <<  "\033[6;0H";
    std::cout << "  0  1  2  3  4  5  6  7\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 8; ++j) {
            if (m_board[i][j] == nullptr) {
                std::cout << "__ "; // Empty square
            } else if (m_board[i][j]->getColor() == Color::WHITE) {
                std::cout << "w" << m_board[i][j]->getToken() << ' '; // White piece
            } else {
                std::cout << "b" << m_board[i][j]->getToken() << ' '; // Black piece
            }
        }
        std::cout << "\n";
    }
}

Game::Game(bool *running)
    : m_playerWhite{new Player{Color::WHITE}},
      m_playerBlack{new Player{Color::BLACK}},
      m_running{running}
{
}

Game::~Game()
{
    delete m_playerWhite;
    delete m_playerBlack;
    for (auto& row : m_board) {
        for (auto& piece : row) {
            delete piece;
        }
    }
}

void Game::newTurn(bool _WhiteTurn)
{
    Player *playerOnTurn = _WhiteTurn ? m_playerWhite : m_playerBlack;
    Color playerColor = playerOnTurn->getColor();
    
    int x0, y0, x1, y1;
    bool first{true};
    
    Piece *selectedFile = nullptr;
    Piece *targetFile = nullptr;

    bool kingInCheck = isKingInCheck(playerColor);

    while (selectedFile == nullptr ||
           selectedFile->getColor() != playerColor ||
           !isValidMove(selectedFile, targetFile, x0, y0, x1, y1) ||
           (kingInCheck && !doesMoveRemoveCheck(x0, y0, x1, y1, playerColor)))
    {
        if (!first) {
            std::cerr << "Invalid move! ";
            if (kingInCheck) {
                std::cerr << "Your king is in check, you must make a move that removes the check.\n";
            } else {
                std::cerr << "Try again.\n";
            }
        }
        first = false;
        
        x0 = -1;
        while (x0 == -1)
        {
            std::string input = playerOnTurn->getInput();
            parseInputToMove(input, x0, y0, x1, y1);
        }

        selectedFile = m_board[y0][x0];
        targetFile = m_board[y1][x1];
    }

    // If we reach this, it's a valid move.
    if (targetFile != nullptr)
        delete targetFile;
    
    m_board[y1][x1] = selectedFile;
    m_board[y0][x0] = nullptr;

    draw();
    checkForCheckMate();
}

bool Game::doesMoveRemoveCheck(int x0, int y0, int x1, int y1, Color kingColor)
{
    // Simulate the move
    Piece *movingPiece = m_board[y0][x0];
    Piece *targetBackup = m_board[y1][x1];

    m_board[y1][x1] = movingPiece;
    m_board[y0][x0] = nullptr;

    // Check if the king is still in check
    bool stillInCheck = isKingInCheck(kingColor);

    // Revert the move
    m_board[y0][x0] = movingPiece;
    m_board[y1][x1] = targetBackup;

    // The move is valid only if it removes the check
    return !stillInCheck;
}



void Game::checkForCheckMate()
{
    // Check for both colors (or you could just check the opponent's king).
    for (Color kingColor : {Color::WHITE, Color::BLACK}) {
        if (isKingInCheck(kingColor) && !hasLegalMove(kingColor)) {
            std::cout <<  "\033[20;0H";
            std::cout << ((kingColor == Color::WHITE) ? "White" : "Black")
                      << " is in checkmate!\n";
            *m_running = false;  // Stop the game.
            return;
        }
    }
}

// Helper: Determine if the king of the given color is currently in check.
bool Game::isKingInCheck(Color kingColor)
{
    int kingX = -1, kingY = -1;
    // Locate the king by scanning the board.
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (m_board[y][x] != nullptr &&
                m_board[y][x]->getColor() == kingColor &&
                m_board[y][x]->getToken() == "K")  // Assumes King token is "K"
            {
                kingX = x;
                kingY = y;
                break;
            }
        }
        if (kingX != -1)
            break;
    }
    // If the king isn't found (shouldn't happen), assume not in check.
    if (kingX == -1)
        return false;
    
    // Check every enemy piece to see if it can move to the king's square.
    Color enemyColor = (kingColor == Color::WHITE) ? Color::BLACK : Color::WHITE;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (m_board[y][x] != nullptr &&
                m_board[y][x]->getColor() == enemyColor)
            {
                int fromX = x, fromY = y;
                if (m_board[y][x]->isPossibleMove(fromX, fromY, kingX, kingY, m_board))
                    return true;
            }
        }
    }
    return false;
}

// Helper: Determine if any move exists for pieces of the given color that would leave the king safe.
bool Game::hasLegalMove(Color kingColor)
{
    // Loop over every square on the board.
    for (int y0 = 0; y0 < 8; ++y0) {
        for (int x0 = 0; x0 < 8; ++x0) {
            // Consider only pieces of the given color.
            if (m_board[y0][x0] != nullptr && m_board[y0][x0]->getColor() == kingColor) {
                // Try every destination square.
                for (int y1 = 0; y1 < 8; ++y1) {
                    for (int x1 = 0; x1 < 8; ++x1) {
                        // If the piece can legally move to (x1, y1)...
                        int fromX = x0, fromY = y0, toX = x1, toY = y1;
                        if (m_board[y0][x0]->isPossibleMove(fromX, fromY, toX, toY, m_board)) {
                            // Simulate the move.
                            Piece* movingPiece = m_board[y0][x0];
                            Piece* targetBackup = m_board[y1][x1];
                            
                            m_board[y1][x1] = movingPiece;
                            m_board[y0][x0] = nullptr;
                            
                            // If the king is no longer in check after the move, it's a legal move.
                            bool moveRelievesCheck = !isKingInCheck(kingColor);
                            
                            // Revert the simulated move.
                            m_board[y0][x0] = movingPiece;
                            m_board[y1][x1] = targetBackup;
                            
                            if (moveRelievesCheck)
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

