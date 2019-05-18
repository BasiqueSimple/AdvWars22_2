#include "bcopter.h"

using namespace std;

Bcopter::Bcopter(int x, int y, Game * game, std::string team): Unitair (x,y)
{
    this->MoveType='A';
    this->UnitType=2;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "b-copter";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Bcopter::resetMP()
{
    this->MovePoint = 6;
}
