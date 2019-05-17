#include "neotank.h"

using namespace std;

Neotank::Neotank(int x, int y, Game* game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='T';
    this->setTeam(team);
    this->UnitType=8;
    std::string path = ":/ImageUnit/" + team + "neotank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Neotank::resetMP()
{
    this->MovePoint = 6;
}
