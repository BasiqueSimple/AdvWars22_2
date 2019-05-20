#ifndef DAMAGE_H
#define DAMAGE_H

#include "./Terrains/plain.h"
#include "./Terrains/mountain.h"
#include "./Terrains/forest.h"
#include "./Terrains/pipe.h"
#include "./Terrains/beach.h"
#include "./Terrains/bridge.h"
#include "./Terrains/reef.h"
#include "./Terrains/river.h"
#include "./Terrains/route.h"
#include "./Buildings/city.h"
#include "./Buildings/factory.h"
#include "./Buildings/airport.h"

#include "./Units/Unitair/bcopter.h"
#include "./Units/Unitair/bomber.h"
#include "./Units/Unitair/fighter.h"
#include "./Units/Unitterreinfant/bazooka.h"
#include "./Units/Unitterreinfant/infantry.h"
#include "./Units/Unitterrenoinfant/antiair.h"
#include "./Units/Unitterrenoinfant/mdtank.h"
#include "./Units/Unitterrenoinfant/megatank.h"
#include "./Units/Unitterrenoinfant/neotank.h"
#include "./Units/Unitterrenoinfant/recon.h"
#include "./Units/Unitterrenoinfant/tank.h"
#include "./Units/unit.h"
#include "./Terrains/terrain.h"

class Damage
{
public :
    Damage();
    static int calculerdamage(Unit* attack, Unit* defense);
    static int calculerpointdefense(Unit* defense, Terrain* terrain);
};

#endif //DAMAGE_H
