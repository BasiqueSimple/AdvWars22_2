#include "megatank.h"

using namespace std;

Megatank::Megatank(int x, int y, Game * game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='T';
    this->UnitType=7;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "megatank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Megatank::resetMP()
{
    this->MovePoint = 4;
}
