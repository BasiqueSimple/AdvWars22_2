#ifndef BATIMENTS_H
#define BATIMENTS_H

#include <QPainter>
#include "./Terrains/terrains.h"

class Batiment : public Terrain
{
public:
    //Attributs
    int PointCapture;
    int Cout;


    //Méthodes
    Batiment();
};


#endif // BATIMENTS_H
