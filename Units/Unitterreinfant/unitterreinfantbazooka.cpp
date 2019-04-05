#include "unitterreinfantbazooka.h"

using namespace std;

Unitterreinfantbazooka::Unitterreinfantbazooka(int x, int y, Game * game, std::string team): Unitterreinfant (x, y)
{
    this->MoveType ='B';
    this->UnitType=6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "mech";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterreinfantbazooka::resetMP()
{
    this->MovePoint = 2;
}
