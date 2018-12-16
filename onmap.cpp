#include "onmap.h"

OnMap::OnMap(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

int OnMap::getposx()
{
    return this->posX;
}

bool OnMap::is_at(int x, int y)
{
    if((this->posX == x) && (this->posY == y)){
        return true;
    }
    else {
        return false;
    }
}

int OnMap::getposy()
{
    return this->posY;
}
