#include "terrains.h"


using namespace std;

Terrain::Terrain()
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
