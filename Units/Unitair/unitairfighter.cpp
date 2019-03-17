#include "unitairfighter.h"

using namespace std;

Unitairfighter::Unitairfighter(int x, int y, Game * game, std::string team): Unitair (x, y)
{
    this->Cout =20000;
    this->MovePoint =9;
  //image depend de l'équipe (couleur ?)
    this->setTeam(team);
    this->setGame(game);
}
