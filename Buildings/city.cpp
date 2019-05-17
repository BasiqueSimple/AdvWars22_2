#include "city.h"

using namespace std;

City::City(int x, int y, std::string team): Building (x,y)
{
    this->defensePoints=3;
    this->setTeam(team);
    this->type="city";
}

void City::reparerUnit()
{

}

bool City::activate()
{
    return false;
}

void City::setImage()
{
    if( this->getTeam() == "os" ){
        this->Image = 38;
    }
    else if( this->getTeam() == "bm" ){
        this->Image = 43;
    }
    else{
        this->Image = 34;
    }
}

void City::GagnerArgent()
{

}
