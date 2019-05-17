#include "airport.h"

using namespace std;

Airport::Airport(int x, int y, std::string team): Building (x,y)
{
    this->defensePoints=3;
    this->setTeam(team);
    this->type="airport";
}

void Airport::construireUnit()
{

}

void Airport::reparerUnitair()
{

}

bool Airport::activate()
{
    return true;
}

void Airport::setImage()
{
    if( this->getTeam() == "os" ){
        this->Image = 40;
    }
    else if( this->getTeam() == "bm" ){
        this->Image = 45;
    }
    else{
        this->Image = 36;
    }
}
