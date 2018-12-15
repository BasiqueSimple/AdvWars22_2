#ifndef BATIMENTSUSINE_H
#define BATIMENTSUSINE_H

#include "batiments.h"


class Batimentusine : public Batiment
{
public:
    //Méthode
    Batimentusine();
    void GagnerArgent();
    void construireUnit();
    void reparerUnit();
};


#endif // BATIMENTSUSINE_H
