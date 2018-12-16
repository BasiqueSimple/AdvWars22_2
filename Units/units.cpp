#include "units.h"
#include <onmap.h>
#include <string>



Unit::Unit(int x, int y) : Activable (x, y)
{
}

void Unit::move()
{

}

void Unit::attendre()
{

}

int Unit::getPV()
{
    return this->PV;
}

void Unit::recevoirdegat(int a)
{
    this->PV = --a;
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

string Unit::getMoveType()
{
    return this->MoveType;
}

void Unit::activate()
{
    cout << "J'aurais ete chaud bouger" << endl;
    // INTEGRER FONCTION MOVE
}

void Unit::setImg(QPixmap img){
    this->img=img;
}

QPixmap Unit::getimg(){
    return this->img;
}
