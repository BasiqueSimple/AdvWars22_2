#include "unitairfighter.h"

using namespace std;

Unitairfighter::Unitairfighter(int x, int y, Game * game, std::string team): Unitair (x, y)
{
    this->Cout =20000;
  //image depend de l'équipe (couleur ?)
    this->setTeam(team);
    this->setGame(game);
}

void Unitairfighter::resetMP()
{
    this->MovePoint = 9;
}
