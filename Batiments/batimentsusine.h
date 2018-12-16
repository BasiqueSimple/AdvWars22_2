#ifndef BATIMENTSUSINE_H
#define BATIMENTSUSINE_H

#include "batiments.h"


class Batimentusine : public Batiment
{
public:
    //Méthode
    Batimentusine(int, int, std::string);
    void GagnerArgent();
    void construireUnit();
    void reparerUnit();
};


#endif // BATIMENTSUSINE_H
