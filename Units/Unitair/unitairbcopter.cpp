#include "unitairbcopter.h"

using namespace std;

Unitairbcopter::Unitairbcopter(int x, int y, Game * game, std::string team): Unitair (x,y)
{
    this->MoveType='A';
    this->UnitType=1;
    this->setTeam(team);
    this->setGame(game);
}

void Unitairbcopter::resetMP()
{
    this->MovePoint = 6;
}
