#ifndef BATIMENTS_H
#define BATIMENTS_H

#include "./Terrains/terrains.h"

#include <activable.h>

class Batiment : public Terrain, public Activable
{
public:
    //Attributs
    int PointCapture;
    int Cout;
    std::string team;


    //Méthodes
    Batiment(int,int);
};


#endif // BATIMENTS_H
