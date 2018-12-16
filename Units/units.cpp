#include "units.h"
#include <onmap.h>
#include <string>


using namespace std;

Unit::Unit(int x, int y) : Activable (x, y)
{
}

void Unit::move()
{

}

void Unit::attendre()
{

}

void Unit::attaquer()
{

}

void Unit::recevoirdegat()
{

}

void Unit::etrerepare()
{

}

void Unit::fusion()
{

}

bool Unit::EtreEnVie()
{

}

void Unit::activate()
{
    cout << this->getTeam() << endl;
}
