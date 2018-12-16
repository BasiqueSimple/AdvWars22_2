#include "unitairbomber.h"

using namespace std;

Unitairbomber::Unitairbomber(int x, int y, std::string team): Unitair(x, y)
{
    this->Cout =22000;
    this->MovePoint =7;
    //image depend de l'équipe (couleur ?)
    this->setTeam(team);
}
