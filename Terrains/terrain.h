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
    QPixmap Image;


public:
    Terrain(int, int);
    void modifierConsommationMovePoint(int);
    int getPointDefense();
    int getMP();
    bool isAt(int, int);
    int getPosX();
    int getPosY();
};


#endif // TERRAINS_H
