#include "unitterrenoinfantantiair.h"

using namespace std;

Unitterrenoinfantantiair::Unitterrenoinfantantiair(int x, int y, Game * game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->UnitType=0;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "anti-air";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfantantiair::resetMP()
{
    this->MovePoint = 6;
}
