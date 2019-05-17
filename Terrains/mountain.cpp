#include "mountain.h"


using namespace std;

Mountain::Mountain(int x, int y) : Terrain (x, y)
{
    this->defensePoints=4;
    this->type="mountain";
}
