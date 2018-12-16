#include "unitterrenoinfantantiair.h"

using namespace std;

Unitterrenoinfantantiair::Unitterrenoinfantantiair(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->Cout =8000;
    this->MovePoint =6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "anti-air";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
