#include "beach.h"


using namespace std;

Beach::Beach(int x, int y) : Terrain (x, y)
{
    this->PointDefense=0;
    this->type="plage";
}
