#include "plain.h"


using namespace std;

Plain::Plain(int x, int y) : Terrain (x, y)
{
    this->defensePoints=1;
    this->type="plain";
}
