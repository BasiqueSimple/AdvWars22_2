#ifndef TERRAINS_H
#define TERRAINS_H

# include <QPainter>
#include "position.h"

class Terrain
{
protected:
    Position *pos;
    int PointDefense;
    int ConsommationMovePoint;
    int Image;
    std::string type;


public:
    Terrain(int, int);
    void modifierConsommationMovePoint(int);
    int getPointDefense();
    int getMP();
    bool isAt(int, int);
    std::string getTerrainType();
    int getPosX();
    int getPosY();
};


#endif // TERRAINS_H
