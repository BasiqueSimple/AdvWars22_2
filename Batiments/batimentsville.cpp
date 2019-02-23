#include "batimentsville.h"

using namespace std;

Batimentville::Batimentville(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->ConsommationMovePoint=1;
    this->setTeam(team);
}

void Batimentville::reparerUnit()
{

}

void Batimentville::activate()
{

}

void Batimentville::GagnerArgent()
{

}
