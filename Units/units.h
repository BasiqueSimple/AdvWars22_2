#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <onmap.h>
#include <string>
#include "./activable.h"
#include "./Terrains/terrains.h"




class Unit : public Activable
{
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
    void recevoirdegat(int);
    void etrerepare();
    void fusion();
    bool EtreEnVie();
    void activate();
    std:: string getMoveType();
    int getPV();
    int getposx();
};

int calculerdamage(Unit, Unit);
int calculerpointdefense(Unit, Terrain);




#endif // UNITS_H
