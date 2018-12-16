#include "unitterrenoinfantmdtank.h"

using namespace std;

Unitterrenoinfantmdtank::Unitterrenoinfantmdtank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->Cout =16000;
    this->MovePoint =5;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
