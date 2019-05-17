#include "factory.h"

using namespace std;

Factory::Factory(int x, int y, std::string team): Building (x,y)
{
    this->PointDefense=3;
    this->setTeam(team);
    this->type="usine";
}

void Factory::construireUnit()
{

}

void Factory::reparerUnit()
{

}

void Factory::GagnerArgent()
{

}

bool Factory::activate()
{
    return true;
}

void Factory::setImage(string)
{
    if( this->getTeam() == "os" ){
        this->Image = 39;
    }
    else if( this->getTeam() == "bm" ){
        this->Image = 44;
    }
    else{
        this->Image = 35;
    }
}
