#ifndef UNITAIR_H
#define UNITAIR_H

#include "./Units/units.h"
#include "./Batiments/batimentsaeroport.h"

class Unitair : public Unit
{
public:
    //Méthode
    Unitair(int, int);
    void etrerepare(Terrain, Joueur);
};

#endif // UNITAIR_H
