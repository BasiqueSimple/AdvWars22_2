#include "unitterrenoinfantantiair.h"

using namespace std;

Unitterrenoinfantantiair::Unitterrenoinfantantiair(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "anti-air";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
