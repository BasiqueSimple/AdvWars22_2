#ifndef UNITTERREINFANT_H
#define UNITTERREINFANT_H

#include "./Units/unit.h"
#include "./Batiments/batimentsusine.h"
#include "./Batiments/batimentsville.h"


class Unitterreinfant : public Unit
{
public:
    //Méthode
    Unitterreinfant(int, int);
    void capturer();
    void etrerepare(Terrain, Joueur);
};

#endif // UNITTERREINFANT_H
