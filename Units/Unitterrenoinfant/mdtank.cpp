#include "mdtank.h"

using namespace std;

Mdtank::Mdtank(int x, int y, Game * game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='T';
    this->UnitType=6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "md-tank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Mdtank::resetMP()
{
    this->MovePoint = 5;
}
