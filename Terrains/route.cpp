#include "route.h"


using namespace std;

Route::Route(int x, int y) : Terrain(x, y)
{
    this->PointDefense=0;
    this->ConsommationMovePoint=1;
}
