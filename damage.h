#ifndef DAMAGE_H
#define DAMAGE_H

#include "./Terrains/plaine.h"
#include "./Terrains/montagne.h"
#include "./Terrains/foret.h"
#include "./Terrains/pipe.h"
#include "./Terrains/plage.h"
#include "./Terrains/pont.h"
#include "./Terrains/reef.h"
#include "./Terrains/riviere.h"
#include "./Terrains/route.h"
#include "./Batiments/batimentsville.h"
#include "./Batiments/batimentsusine.h"
#include "./Batiments/batimentsaeroport.h"

#include "./Units/Unitair/unitairbcopter.h"
#include "./Units/Unitair/unitairbomber.h"
#include "./Units/Unitair/unitairfighter.h"
#include "./Units/Unitterreinfant/unitterreinfantbazooka.h"
#include "./Units/Unitterreinfant/unitterreinfantinfant.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfantantiair.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfantmdtank.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfantmegatank.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfantneotank.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfantrecon.h"
#include "./Units/Unitterrenoinfant/unitterrenoinfanttank.h"
#include "./Units/unit.h"
#include "./Terrains/terrain.h"

class damage
{
public :
    damage();
    int calculerdamage(Unit, Unit);
    int calculerpointdefense(Unit, Terrain);

};

#endif //DAMAGE_H
