#include "batimentsaeroport.h"

using namespace std;

Batimentaeroport::Batimentaeroport(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->setTeam(team);
    this->type="aeroport";
}

void Batimentaeroport::construireUnit()
{

}

void Batimentaeroport::reparerUnitair()
{

}

bool Batimentaeroport::activate()
{
    return true;
}

void Batimentaeroport::setImage(string team)
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
