#ifndef UNITTERRENOINFANT_H
#define UNITTERRENOINFANT_H

#include "./Units/unit.h"
#include "./Batiments/batimentsusine.h"
#include "./Batiments/batimentsville.h"


class Unitterrenoinfant : public Unit
{
public:
    //Méthode
    Unitterrenoinfant(int, int);
    void etrerepare(Terrain, Joueur);
    virtual void resetMP();
};


#endif // UNITTERRENOINFANT_H
