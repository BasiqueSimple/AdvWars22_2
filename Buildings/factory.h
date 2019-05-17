#ifndef BATIMENTSUSINE_H
#define BATIMENTSUSINE_H

#include "building.h"


class Factory : public Building
{
public:
    //Méthode
    Factory(int, int, std::string);
    void GagnerArgent();
    void construireUnit();
    void reparerUnit();
    bool activate();
    void setImage();
};


#endif // BATIMENTSUSINE_H
