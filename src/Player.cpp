#include "headers/Player.h"

Player::Player()
{
}

const std::string Player::getMoveInput()
{
    std::string moveInput;
    std::cout << "Enter your move: ";
    std::cin >> moveInput;
    return moveInput;
}