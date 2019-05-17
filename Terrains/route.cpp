#include "route.h"


using namespace std;

Route::Route(int x, int y) : Terrain(x, y)
{
    this->defensePoints=0;
    this->type="route";
}
