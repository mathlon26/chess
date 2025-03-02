#include "Board.h"
#include <string>
#include <iostream>

void Board::parseInputToMove(const std::string &input, int &x0, int &y0, int &x1, int &y1)
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

void Board::updateBoard()
{
}

bool Board::isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1)
{
    /*
    
    if (_Selected->isPossibleMove(x0, y0, x1, y1)  &&
        canPieceReachTarget(_Selected, x0, y0, x1, y1)
    )
    {
        return true;
    }
    return false;
    */
    return true;
}

void Board::draw()
{
    std::cout <<  "\033[6;0H";
    for (int i = 0; i < 8; ++i) {
        std::cout << i << " "; // Row numbering (8 to 1)
        for (int j = 0; j < 8; ++j) {
            if (m_board[i][j] == nullptr) {
                std::cout << ". "; // Empty square
            } else if (m_board[i][j]->getColor() == Color::WHITE) {
                std::cout << "W "; // White piece
            } else {
                std::cout << "B "; // Black piece
            }
        }
        std::cout << "\n";
    }
    std::cout << "  0 1 2 3 4 5 6 7\n"; // Column lettering
}

Board::Board(Player *_PlayerWhite, Player *_PlayerBlack)
    : m_playerWhite{_PlayerWhite},
      m_playerBlack{_PlayerBlack}
{
}

Board::~Board()
{
    for (auto& row : m_board) {
        for (auto& piece : row) {
            delete piece;
        }
    }
}

void Board::newTurn(bool _WhiteTurn)
{

    Player *playerOnTurn{_WhiteTurn ? m_playerWhite : m_playerBlack};

    int x0, y0, x1, y1;
    bool first{true};

    Piece *selectedFile = nullptr;
    Piece *targetFile = nullptr;

    while ( selectedFile == nullptr || 
            selectedFile->getColor() != playerOnTurn->getColor() ||
            ! isValidMove(selectedFile, targetFile, x0, y0, x1, y1)
    )
    {
        if (!first) {
            std::cerr << "Invalid input!\n";
            first = false;
        }
        x0 = -1;
        while (x0 == -1)
        {
            std::string input{playerOnTurn->getInput()};
            parseInputToMove(input, x0, y0, x1, y1);
        }

        selectedFile = m_board[y0][x0];
        targetFile = m_board[y1][x1];
    }

    // if we reach this its a valid move
    if (targetFile != nullptr)
        delete targetFile;
    m_board[y1][x1] = selectedFile;
    m_board[y0][x0] = nullptr;

    draw();
}