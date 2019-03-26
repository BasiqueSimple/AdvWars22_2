#include "riviere.h"


using namespace std;

Riviere::Riviere(int x, int y) : Terrain(x, y)
{
    this->PointDefense=0;
    this->type="riviere";
}
