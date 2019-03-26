#include "plaine.h"


using namespace std;

Plaine::Plaine(int x, int y) : Terrain (x, y)
{
    this->PointDefense=1;
    this->type="plaine";
}
