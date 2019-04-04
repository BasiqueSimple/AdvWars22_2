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

class Damage
{
public :
    Damage();
    static int calculerdamage(Unit* attack, Unit* defense){
        /* Matrice dans l'ordre suivant:
         * 0: AA
         * 1: Helico
         * 2: Bomber
         * 3: Fighter
         * 4: Infanterie
         * 5: MD Tank
         * 6: Bazooka
         * 7: Mega Tank
         * 8: Neo Tank
         * 9: Reconnaissance
         * 10: Tank */
        int matrice[11][11] = {{45, 120, 75, 65, 105, 10, 105, 1, 5, 60, 25},
                               {25, 65, 0, 0, 75, 25, 75, 10, 20, 55, 55},
                               {95, 0, 0, 0, 110, 95, 110, 35, 90, 105, 105},
                               {0, 100, 100, 55, 0, 0, 0, 0, 0, 0, 0},
                               {5, 7, 0, 0, 55, 1, 45, 1, 1, 12, 5},
                               {105, 12, 0, 0, 105, 55, 95, 25, 45, 105, 85},
                               {65, 9, 0, 0, 65, 15, 55, 5, 15, 85, 55},
                               {195, 22, 0, 0, 135, 125, 125, 65, 115, 195, 180},
                               {115, 22, 0, 0, 125, 75, 115, 35, 55, 125, 105},
                               {4, 12, 0, 0, 70, 1, 65, 1, 1, 35, 6},
                               {65, 10, 0, 0, 75, 15, 70, 10, 15, 85, 55}};
        return matrice[attack->getDamageType()][defense->getDamageType()];
    }
    static int calculerpointdefense(Unit* defense, Terrain* terrain){
        if(defense->getMoveType()=='A'){
            return 0;
        }
        else{
            return terrain->getPointDefense();
        }
    }

};

#endif //DAMAGE_H
