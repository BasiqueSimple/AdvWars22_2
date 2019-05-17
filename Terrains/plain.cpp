#include "plain.h"


using namespace std;

Plain::Plain(int x, int y) : Terrain (x, y)
{
    this->PointDefense=1;
    this->type="plaine";
}
