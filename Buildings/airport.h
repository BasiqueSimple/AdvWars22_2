#ifndef BATIMENTSAEROPORT_H
#define BATIMENTSAEROPORT_H

#include "building.h"


class Airport : public Building
{
public:
    //Méthode
    Airport(int, int, std::string);
    void construireUnit();
    void reparerUnitair();
    bool activate();
    void setImage();
};

#endif // BATIMENTSAEROPORT_H
