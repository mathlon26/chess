#include "Game.h"
#include <string>
#include <iostream>

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

void Game::updateBoard()
{
}

inline bool Game::isValidMove(Piece *_Selected, Piece *_Target, int &x0, int &y0, int &x1, int &y1)
{
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
                std::cout << "W" << m_board[i][j]->getToken() << ' '; // White piece
            } else {
                std::cout << "B" << m_board[i][j]->getToken() << ' '; // Black piece
            }
        }
        std::cout << "\n";
    }
}

Game::Game()
    : m_playerWhite{new Player{Color::WHITE}},
      m_playerBlack{new Player{Color::BLACK}}
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