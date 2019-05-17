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
