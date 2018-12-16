#include "unitterrenoinfantneotank.h"

using namespace std;

Unitterrenoinfantneotank::Unitterrenoinfantneotank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->Cout =22000;
    this->MovePoint =6;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
