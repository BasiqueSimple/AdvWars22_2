#ifndef BATIMENTSAEROPORT_H
#define BATIMENTSAEROPORT_H

#include "batiments.h"


class Batimentaeroport : public Batiment
{
public:
    //Méthode
    Batimentaeroport();
    void construireUnit();
    void reparerUnitair();
};

#endif // BATIMENTSAEROPORT_H
