#include "unitterrenoinfantmdtank.h"

using namespace std;

Unitterrenoinfantmdtank::Unitterrenoinfantmdtank(int x, int y, Game * game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->MovePoint = 5;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "md-tank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfantmdtank::resetMP()
{
    this->MovePoint = 5;
}
