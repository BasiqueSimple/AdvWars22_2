#ifndef TERRAINS_H
#define TERRAINS_H

# include <QPainter>

class Terrain
{
protected:
    int PointDefense;
    int ConsommationMovePoint;
    QPixmap Image;
    int posX;
    int posY;

public:
    Terrain();
};


#endif // TERRAINS_H
