#include "unitairfighter.h"

using namespace std;

Unitairfighter::Unitairfighter(int x, int y, Game * game, std::string team): Unitair (x, y)
{
    this->UnitType=3;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "fighter";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitairfighter::resetMP()
{
    this->MovePoint = 9;
}
