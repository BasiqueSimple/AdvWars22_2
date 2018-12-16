#include "batiments.h"


using namespace std;

Batiment::Batiment(int x, int y) : Activable(x,y), Terrain (x, y)
{
    this->PointCapture = 20;
}
