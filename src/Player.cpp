#include "Player.h"
#include <iostream>
#include <string>

Player::Player(Color _Color)
    :
    m_color{_Color}
{
}

Player::~Player()
{
}

std::string Player::getInput()
{
    std::cout <<  "\033[0;0H";

    std::string input{};
    if (m_color == Color::WHITE)
    {
        std::cout << "White may move.\n";
    }
    else {
        std::cout << "Black may move.\n";
    }
    
    std::cout << "Enter move (e.g., '00 to 01'):                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    std::getline(std::cin, input);

    return input;
}

Color Player::getColor()
{
    return m_color;
}
