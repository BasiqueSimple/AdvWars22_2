#include "plage.h"


using namespace std;

Plage::Plage(int x, int y) : Terrain (x, y)
{
    this->PointDefense=0;
    this->ConsommationMovePoint=1;
}
