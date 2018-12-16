#include "unitterreinfantbazooka.h"

using namespace std;

Unitterreinfantbazooka::Unitterreinfantbazooka(int x, int y, std::string team): Unitterreinfant (x, y)
{
    this->MoveType ="B";
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "mech";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
