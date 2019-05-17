#ifndef UNITTERRENOINFANT_H
#define UNITTERRENOINFANT_H

#include "./Units/unit.h"
#include "./Buildings/factory.h"
#include "./Buildings/city.h"


class Terrenoinfant : public Unit
{
public:
    //Méthode
    Terrenoinfant(int, int);
    void etrerepare(Terrain, Player);
    virtual void resetMP();
};


#endif // UNITTERRENOINFANT_H
