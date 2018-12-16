#ifndef BATIMENTS_H
#define BATIMENTS_H

#include "./Terrains/terrains.h"

class Batiment : public Terrain
{
public:
    //Attributs
    int PointCapture;
    int Cout;
    std::string Team;


    //Méthodes
    Batiment();
};


#endif // BATIMENTS_H
