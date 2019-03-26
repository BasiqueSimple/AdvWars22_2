#include "foret.h"


using namespace std;

Foret::Foret(int x, int y) : Terrain (x, y)
{
    this->PointDefense=2;
    this->type="foret";
}
