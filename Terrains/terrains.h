#ifndef TERRAINS_H
#define TERRAINS_H

# include <QPainter>
#include "onmap.h"

class Terrain : public OnMap
{
protected:
    int PointDefense;
    int ConsommationMovePoint;
    QPixmap Image;


public:
    Terrain(int, int);
    void modifierConsommationMovePoint(int);
    int getPointDefense();
    int getMP();
};


#endif // TERRAINS_H
