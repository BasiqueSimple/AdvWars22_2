#include "unitterrenoinfantrecon.h"

using namespace std;

Unitterrenoinfantrecon::Unitterrenoinfantrecon(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="W";
    this->Cout =4000;
    this->MovePoint =8;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
