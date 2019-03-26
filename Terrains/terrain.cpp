#include "terrain.h"


using namespace std;

Terrain::Terrain(int x, int y)
{
    this->pos = new Position(x,y);;
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

bool Terrain::isAt(int x, int y)
{
    return this->pos->isAt(x, y);
}

int Terrain::getPosX()
{
    return this->pos->getPosX();
}

int Terrain::getPosY()
{
    return this->pos->getPosY();
}

std::string Terrain::getTerrainType() {
    return this->type;
}
