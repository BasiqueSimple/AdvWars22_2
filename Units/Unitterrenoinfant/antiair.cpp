#include "antiair.h"

using namespace std;

Antiair::Antiair(int x, int y, Game * game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='T';
    this->UnitType=0;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "anti-air";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Antiair::resetMP()
{
    this->MovePoint = 6;
}
