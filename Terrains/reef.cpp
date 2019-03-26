#include "reef.h"


using namespace std;

Reef::Reef(int x, int y) : Terrain (x, y)
{
    this->PointDefense=1;
    this->type="reef";
}
