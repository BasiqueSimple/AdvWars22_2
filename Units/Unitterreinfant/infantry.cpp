#include "infantry.h"
#include <iostream>

using namespace std;

Infantry::Infantry(int x, int y, Game * game, std::string team): Terreinfant (x, y)
{
    this->MoveType = 'F';
    this->setTeam(team);
    this->UnitType= 4;
    std::string path = ":/ImageUnit/" + team + "infantry";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}
void Infantry::resetMP()
{
    this->MovePoint = 3;
}
