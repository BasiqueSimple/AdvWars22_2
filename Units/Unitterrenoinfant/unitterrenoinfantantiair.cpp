#include "unitterrenoinfantantiair.h"

using namespace std;

Unitterrenoinfantantiair::Unitterrenoinfantantiair(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->Cout =8000;
    this->MovePoint =6;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
