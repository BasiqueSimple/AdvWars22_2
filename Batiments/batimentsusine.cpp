#include "batimentsusine.h"

using namespace std;

Batimentusine::Batimentusine(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->ConsommationMovePoint=1;
    this->setTeam(team);
}

void Batimentusine::construireUnit()
{

}

void Batimentusine::reparerUnit()
{

}

void Batimentusine::GagnerArgent()
{

}

void Batiment::activate()
{
    cout << this->getTeam() << endl;
}
