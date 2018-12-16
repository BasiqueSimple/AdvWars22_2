#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <onmap.h>
#include <string>
#include "./activable.h"

class Unit : public Activable
{
public:
    void activate();
    //Méthodes
    Unit(int,int);
    void move();
    void attendre();
    void attaquer();
    void recevoirdegat();
    void etrerepare();
    void fusion();
    bool EtreEnVie();
protected:
    //Attributs
    int PV;
    std::string MoveType;
    int Cout;
    int MovePoint;

};

#endif // UNITS_H
