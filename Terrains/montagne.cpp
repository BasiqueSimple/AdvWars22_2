#include "montagne.h"


using namespace std;

Montagne::Montagne(int x, int y) : Terrain (x, y)
{
    this->PointDefense=4;
    //this->ConsommationMovePoint=F2 B1 T- W- A1
    this->ConsommationMovePoint=2;
    this->type="montagne";
}
