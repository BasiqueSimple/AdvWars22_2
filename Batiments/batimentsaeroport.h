#ifndef BATIMENTSAEROPORT_H
#define BATIMENTSAEROPORT_H

#include "batiments.h"


class Batimentaeroport : public Batiment
{
public:
    //Méthode
    Batimentaeroport(int, int, std::string);
    void construireUnit();
    void reparerUnitair();
    void activate();
};

#endif // BATIMENTSAEROPORT_H
