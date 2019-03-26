#include "plaine.h"


using namespace std;

Plaine::Plaine(int x, int y) : Terrain (x, y)
{
    this->PointDefense=1;
    //this->ConsommationMovePoint=F1 B1 T1 W2 A1
    this->ConsommationMovePoint=1;
    this->type="plaine";
}
