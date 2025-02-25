#include "headers/Pawn.h"

Pawn::Pawn(Vec2 position, Color color)
    : Piece{position, color}
{
}

bool Pawn::isValidMove(Vec2 newPos, std::vector<Piece> &pieces)
{
}