#include "headers/Vec2.h"
#include "Vec2.h"

Vec2::Vec2(const int x, const int y)
    :
    m_X(x),
    m_Y(y)
{
}

Vec2::~Vec2()
{
}

int Vec2::X() const {
    return m_X;
}
int Vec2::Y() const {
    return m_Y;
}

void Vec2::set(const int x, const int y) {
    m_X = x;
    m_Y = y;
}

Vec2 Vec2::getChessVec2(const char file, const int rank)
{
    int x = file - 'a';
    int y = 8 - rank;
    return Vec2(x, y);
}
