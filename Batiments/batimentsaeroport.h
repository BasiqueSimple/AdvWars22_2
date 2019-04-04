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
    //bool activate();
    void setImage(std::string);
};

#endif // BATIMENTSAEROPORT_H
