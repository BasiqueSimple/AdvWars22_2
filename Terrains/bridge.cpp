#include "bridge.h"


using namespace std;

Bridge::Bridge(int x, int y) : Terrain (x, y)
{
    this->defensePoints=0;
    this->type="bridge";
}
