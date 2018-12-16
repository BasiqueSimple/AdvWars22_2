#include "unitterreinfantinfant.h"
#include <iostream>

using namespace std;

Unitterreinfantinfant::Unitterreinfantinfant(int x, int y, std::string team): Unitterreinfant (x, y)
{
    this->MoveType ="F";
    this->Cout =1000;
    this->MovePoint =3;
    this->setTeam(team);
    std::string path = ":/ImageUnit/" + team + "infantry";
    this->setImg(*new QPixmap(QString::fromStdString(path)));
}
