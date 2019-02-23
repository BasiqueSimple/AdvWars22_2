#include "batiments.h"


using namespace std;

Batiment::Batiment(int x, int y) : Terrain (x, y)
{
    this->PointCapture = 20;
}

void Batiment::setTeam(std::string team)
{
    this->team=team;
}

std::string Batiment::getTeam(){
    return this->team;
}
