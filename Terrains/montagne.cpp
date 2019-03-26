#include "montagne.h"


using namespace std;

Montagne::Montagne(int x, int y) : Terrain (x, y)
{
    this->PointDefense=4;
    this->type="montagne";
}
