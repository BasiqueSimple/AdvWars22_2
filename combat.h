#ifndef ATTAQUE_H
#define ATTAQUE_H
#include "damage.h"
#include "math.h"

class Combat
{
public :
    Combat();
    static void attaquer(Unit* attack, Unit* defense, Terrain* terrain, bool riposte);
};

#endif // ATTAQUE_H
