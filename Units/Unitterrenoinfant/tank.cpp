#include "tank.h"

using namespace std;

Tank::Tank(int x, int y, Game* game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='T';
    this->setTeam(team);
    this->UnitType=10;
    std::string path = ":/ImageUnit/" + team + "tank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Tank::resetMP()
{
    this->MovePoint = 6;
}
