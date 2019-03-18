#include "unitterrenoinfanttank.h"

using namespace std;

Unitterrenoinfanttank::Unitterrenoinfanttank(int x, int y, Game* game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->MovePoint = 6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "tank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfanttank::resetMP()
{
    this->MovePoint = 6;
}
