#include "unitairfighter.h"

using namespace std;

Unitairfighter::Unitairfighter(int x, int y, Game * game, std::string team): Unitair (x, y)
{
    this->Cout =20000;
    this->damageType=3;
    this->setTeam(team);
    this->setGame(game);
}

void Unitairfighter::resetMP()
{
    this->MovePoint = 9;
}
