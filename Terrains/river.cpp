#include "river.h"


using namespace std;

River::River(int x, int y) : Terrain(x, y)
{
    this->defensePoints=0;
    this->type="river";
}
