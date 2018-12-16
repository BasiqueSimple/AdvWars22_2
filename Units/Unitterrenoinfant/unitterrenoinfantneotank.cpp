#include "unitterrenoinfantneotank.h"

using namespace std;

Unitterrenoinfantneotank::Unitterrenoinfantneotank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "neotank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
