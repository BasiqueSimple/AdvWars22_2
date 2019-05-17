#ifndef BATIMENTSVILLE_H
#define BATIMENTSVILLE_H

#include "building.h"


class City : public Building
{
public:
    //Méthode
    City(int, int, std::string);
    void GagnerArgent();
    void reparerUnit();
    bool activate();
    void setImage(std::string);
};


#endif // BATIMENTSVILLE_H
