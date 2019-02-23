#include "batimentsaeroport.h"

using namespace std;

Batimentaeroport::Batimentaeroport(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->ConsommationMovePoint=1;
    this->setTeam(team);
}

void Batimentaeroport::construireUnit()
{

}

void Batimentaeroport::reparerUnitair()
{

}

void Batimentaeroport::activate()
{

}
