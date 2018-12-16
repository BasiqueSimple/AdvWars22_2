#include "activable.h"
#include <iostream>

Activable::Activable(int x, int y) : OnMap(x,y)
{
}

void Activable::activate()
{
}

Activable::~Activable()
{

}

void Activable::setTeam(std::string team)
{
    this->team=team;
}

std::string Activable::getTeam(){
    return this->team;
}

