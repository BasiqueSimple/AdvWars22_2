#ifndef TERRAINS_H
#define TERRAINS_H

# include <QPainter>
#include "position.h"

class Terrain
{
protected:
    Position *pos;
    int PointDefense;
    int Image;
    std::string type;


public:
    Terrain(int, int);
    int getPointDefense();
    bool isAt(int, int);
    std::string getTerrainType();
    int getPosX();
    int getPosY();
};


#endif // TERRAINS_H
