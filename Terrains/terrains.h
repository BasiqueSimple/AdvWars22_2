#ifndef TERRAINS_H
#define TERRAINS_H

# include <QPainter>
#include "onmap.h"

class Terrain : OnMap
{
protected:
    int PointDefense;
    int ConsommationMovePoint;
    QPixmap Image;


public:
    Terrain(int, int);
    void modifierConsommationMovePoint(int);
    int getPointDefense();
};


#endif // TERRAINS_H
