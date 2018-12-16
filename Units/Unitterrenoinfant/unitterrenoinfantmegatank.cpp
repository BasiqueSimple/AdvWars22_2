#include "unitterrenoinfantmegatank.h"

using namespace std;

Unitterrenoinfantmegatank::Unitterrenoinfantmegatank(int x, int y, std::string team): Unitterrenoinfant (x, y)
{
    this->MoveType ="T";
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "megatank";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
