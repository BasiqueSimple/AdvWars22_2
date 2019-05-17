#include "forest.h"


using namespace std;

Forest::Forest(int x, int y) : Terrain (x, y)
{
    this->PointDefense=2;
    this->type="foret";
}
