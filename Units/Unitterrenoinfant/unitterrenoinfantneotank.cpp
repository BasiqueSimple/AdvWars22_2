#include "unitterrenoinfantneotank.h"

using namespace std;

Unitterrenoinfantneotank::Unitterrenoinfantneotank(int x, int y, Game* game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='T';
    this->MovePoint = 6;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "neotank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfantneotank::resetMP()
{
    this->MovePoint = 6;
}
