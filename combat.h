#ifndef ATTAQUE_H
#define ATTAQUE_H
#include "damage.h"

class Combat
{
public :
    Combat();
    static void attaquer(Unit* attack, Unit* defense, Terrain* terrain, bool riposte) {
        int damages = Damage::calculerdamage(attack, defense);
        int pvAttack = attack->getPV();
        int pvDefense = defense->getPV();
        int pointdefense = (Damage::calculerpointdefense(defense, terrain));

        int degat = damages*pvAttack*(100-pvDefense*pointdefense)/1000;
        defense->recevoirdegat(degat);
        cout << "AOUCH il ne me reste que " << defense->getPV() << endl;
        if(!riposte && defense->getPV()>0){
            attaquer(defense, attack, terrain, true);
        }
    }
};

#endif // ATTAQUE_H
