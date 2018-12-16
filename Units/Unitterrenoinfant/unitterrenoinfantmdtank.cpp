#include "unitterrenoinfantmdtank.h"

using namespace std;

Unitterrenoinfantmdtank::Unitterrenoinfantmdtank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "md-tank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
