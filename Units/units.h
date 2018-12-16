#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <string>
#include "./activable.h"

class Unit : public Activable
{
public:
    int getposx();
protected:
    //Attributs
    int PV;
    std::string MoveType;
    int Cout;
    int MovePoint;
    int posX;
    int posY;
    std::string Team;

public:
    //Méthodes
    Unit(int,int);
    void move();
    void attendre();
    void attaquer();
    void recevoirdegat();
    void etrerepare();
    void fusion();
    bool EtreEnVie();
    void activate();
};

#endif // UNITS_H
