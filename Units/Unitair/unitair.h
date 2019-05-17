#ifndef UNITAIR_H
#define UNITAIR_H

#include "./Units/unit.h"
#include "./Buildings/airport.h"

class Unitair : public Unit
{
public:
    //Méthode
    Unitair(int, int);
    void etrerepare(Terrain, Player);
    virtual void resetMP();
};

#endif // UNITAIR_H
