#include "fighter.h"

using namespace std;

Fighter::Fighter(int x, int y, Game * game, std::string team): Unitair (x, y)
{
    this->UnitType=3;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "fighter";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Fighter::resetMP()
{
    this->MovePoint = 9;
}
