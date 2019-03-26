#include "pipe.h"


using namespace std;

Pipe::Pipe(int x, int y) : Terrain (x, y)
{
    this->PointDefense=0;
    this->type="pipe";
}
