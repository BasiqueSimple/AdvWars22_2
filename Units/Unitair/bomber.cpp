#include "bomber.h"

using namespace std;

Bomber::Bomber(int x, int y, Game * game, std::string team): Unitair(x, y)
{
    this->UnitType = 2;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "bomber";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Bomber::resetMP()
{
    this->MovePoint = 7;
}
