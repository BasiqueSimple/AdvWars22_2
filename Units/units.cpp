#include "units.h"
#include <string>


using namespace std;

Unit::Unit(int x, int y)
{
    this->posX = x;
    this->posY = y;
}

void Unit::move()
{

}

void Unit::attendre()
{

}

void Unit::attaquer()
{

}

void Unit::recevoirdegat()
{

}

void Unit::etrerepare()
{

}

void Unit::fusion()
{

}

bool Unit::EtreEnVie()
{

}

int Unit::getposx()
{
    return this->posX;
}

void Unit::activate()
{
    cout << "AIE !" << endl;
}
