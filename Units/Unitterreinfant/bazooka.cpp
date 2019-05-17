#include "bazooka.h"

using namespace std;

Bazooka::Bazooka(int x, int y, Game * game, std::string team): Terreinfant (x, y)
{
    this->MoveType ='B';
    this->UnitType=6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "mech";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Bazooka::resetMP()
{
    this->MovePoint = 2;
}
