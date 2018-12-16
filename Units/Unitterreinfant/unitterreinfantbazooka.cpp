#include "unitterreinfantbazooka.h"

using namespace std;

Unitterreinfantbazooka::Unitterreinfantbazooka(int x, int y, std::string team): Unitterreinfant (x, y)
{
    this->MoveType ="B";
    this->Cout =3000;
    this->MovePoint =2;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
