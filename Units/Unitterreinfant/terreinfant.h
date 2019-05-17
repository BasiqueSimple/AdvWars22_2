#ifndef UNITTERREINFANT_H
#define UNITTERREINFANT_H

#include "./Units/unit.h"
#include "./Buildings/factory.h"
#include "./Buildings/city.h"


class Terreinfant : public Unit
{
public:
    //Méthode
    Terreinfant(int, int);
    void capturer();
    void etrerepare(Terrain, Player);
    void resetMP();
};

#endif // UNITTERREINFANT_H
