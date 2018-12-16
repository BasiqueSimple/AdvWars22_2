#ifndef BATIMENTSVILLE_H
#define BATIMENTSVILLE_H

#include "batiments.h"


class Batimentville : public Batiment
{
public:
    //Méthode
    Batimentville(int, int, std::string);
    void GagnerArgent();
    void reparerUnit();
};


#endif // BATIMENTSVILLE_H
