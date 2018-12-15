#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <string>
#include <QPainter>

class Unit
{
public:
    //Attributs
    int PV;
    std::string MoveType;
    int Cout;
    int MovePoint;
    QPixmap Image;
    int posX;
    int posY;

    //Méthodes
    Unit();
    void move();
    void attendre();
    void attaquer();
    void recevoirdegat();
    void etrerepare();
    void fusion();
    bool EtreEnVie();
};

#endif // UNITS_H
