#include "unitairbcopter.h"

using namespace std;

Unitairbcopter::Unitairbcopter(int x, int y, Game * game, std::string team): Unitair (x,y)
{
    this->MoveType='A';
    this->Cout =9000;
    this->MovePoint =6;
    this->setTeam(team);
    this->setGame(game);
}
