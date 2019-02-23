#ifndef BATIMENTS_H
#define BATIMENTS_H

#include "./Terrains/terrain.h"

#include <activable.h>

class Batiment : public Activable, public Terrain
{
public:
    //Attributs
    int PointCapture;
    int Cout;


    //Méthodes
    Batiment(int,int);
};


#endif // BATIMENTS_H
