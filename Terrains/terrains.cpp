#include "terrains.h"


using namespace std;

Terrain::Terrain(int x, int y) : OnMap(x,y)
{

}

void Terrain::modifierConsommationMovePoint(int a)
{
    this->ConsommationMovePoint = a;
}

int Terrain::getPointDefense()
{
    return this->PointDefense;
}

int Terrain::getMP()
{
    return this->ConsommationMovePoint;
}
