#include "unitairbomber.h"

using namespace std;

Unitairbomber::Unitairbomber(int x, int y, Game * game, std::string team): Unitair(x, y)
{
    this->Cout =22000;
    this->damageType = 2;
    this->setTeam(team);
    this->setGame(game);
}

void Unitairbomber::resetMP()
{
    this->MovePoint = 7;
}
