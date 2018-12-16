#ifndef ATTAQUE_H
#define ATTAQUE_H
#include "damage.h"

class combat
{
public :
    combat();
    void attaquer(Unit, Unit, Terrain, damage, combat);
    void riposter(Unit, Unit, Terrain, damage);
};

#endif // ATTAQUE_H
