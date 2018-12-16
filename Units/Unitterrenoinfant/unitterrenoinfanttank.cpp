#include "unitterrenoinfanttank.h"

using namespace std;

Unitterrenoinfanttank::Unitterrenoinfanttank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->Cout =7000;
    this->MovePoint =6;
    this->setTeam(team);
  //image depend de l'équipe (couleur ?)
}
