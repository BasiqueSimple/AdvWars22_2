#include "unitterrenoinfantrecon.h"

using namespace std;

Unitterrenoinfantrecon::Unitterrenoinfantrecon(int x, int y, Game* game, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ='W';
    this->setTeam(team);
    this->UnitType= 9;
    std::string path = ":/ImageUnit/" + team + "recon";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Unitterrenoinfantrecon::resetMP()
{
    this->MovePoint = 8;
}
