#include "pont.h"


using namespace std;

Pont::Pont(int x, int y) : Terrain (x, y)
{
    this->PointDefense=0;
    this->type="pont";
}
