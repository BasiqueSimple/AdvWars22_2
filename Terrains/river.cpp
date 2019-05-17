#include "river.h"


using namespace std;

River::River(int x, int y) : Terrain(x, y)
{
    this->PointDefense=0;
    this->type="riviere";
}
