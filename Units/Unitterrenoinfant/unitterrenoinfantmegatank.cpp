#include "unitterrenoinfantmegatank.h"

using namespace std;

Unitterrenoinfantmegatank::Unitterrenoinfantmegatank(int x, int y, Game * game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->UnitType=7;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "megatank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfantmegatank::resetMP()
{
    this->MovePoint = 4;
}
