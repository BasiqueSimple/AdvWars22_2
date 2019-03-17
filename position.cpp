#include "position.h"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Position::getPosX()
{
    return this->x;
}

void Position::setPosX(int x)
{
    this->x = x;
}

int Position::getPosY()
{
    return this->y;
}

void Position::setPosY(int y)
{
    this->y = y;
}

bool Position::isAt(int x, int y)
{
    if((this->x == x) && (this->y == y)){
        return true;
    }
    else {
        return false;
    }
}
