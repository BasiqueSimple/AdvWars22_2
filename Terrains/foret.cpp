#include "foret.h"


using namespace std;

Foret::Foret(int x, int y) : Terrain (x, y)
{
    this->PointDefense=2;
    //this->ConsommationMovePoint=F1 B1 T2 W3 A1
    this->ConsommationMovePoint=1;
}
