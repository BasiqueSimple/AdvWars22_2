#include "game.h"
#include "mainwindow.h"
#include <QApplication>

#include "damage.h"


Damage::Damage()
{

}

int Damage::calculerdamage(Unit* attack, Unit* defense){
    /* Matrice dans l'ordre suivant:
     * INFANTRY 0
     * BAZOOKA 1
     * BCOPTER 2
     * BOMBER 3
     * FIGHTER 4
     * ANTIAIR 5
     * MDTANK 6
     * MEGATANK 7
     * NEOTANK 8
     * RECON 9
     * TANK 10
     */

    int matrice[11][11] = {{55, 45, 7, 0, 0, 5, 1, 1, 1, 12, 5},
                           {65, 55, 65, 0, 0, 65, 15, 5, 15, 85, 55},
                           {75, 75, 65, 0, 0, 25, 25, 10, 20, 55, 55},
                           {110, 110, 0, 0, 0, 95, 95, 35, 90, 105, 105},
                           {0, 0, 100, 100, 55, 0, 0, 0, 0, 0, 0},
                           {105, 105, 120, 75, 65, 45, 10, 1, 5, 60, 25},
                           {105, 95, 12, 0, 0, 105, 55, 25, 45, 105, 85},
                           {135, 125, 22, 0, 0, 195, 125, 65, 115, 195, 180},
                           {125, 115, 22, 0, 0, 115, 75, 35, 55, 125, 105},
                           {70, 65, 12, 0, 0, 4, 1, 1, 1, 35, 6},
                           {75, 70, 10, 0, 0, 65, 15, 10, 15, 85, 55}};
    return matrice[attack->getDamageType()][defense->getDamageType()];
}

int Damage::calculerpointdefense(Unit* defense, Terrain* terrain){
    if(defense->getMoveType()=='A'){
        return 0;
    }
    else{
        return terrain->getPointDefense();
    }
}
