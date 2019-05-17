#include "recon.h"

using namespace std;

Recon::Recon(int x, int y, Game* game, std::string team): Terrenoinfant (x, y)
{
    this->MoveType ='W';
    this->setTeam(team);
    this->UnitType= 9;
    std::string path = ":/ImageUnit/" + team + "recon";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
    this->setGame(game);
}

void Recon::resetMP()
{
    this->MovePoint = 8;
}
