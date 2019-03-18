#ifndef UNITAIR_H
#define UNITAIR_H

#include "./Units/unit.h"
#include "./Batiments/batimentsaeroport.h"

class Unitair : public Unit
{
public:
    //Méthode
    Unitair(int, int);
    void etrerepare(Terrain, Joueur);
    virtual void resetMP();
};

#endif // UNITAIR_H
