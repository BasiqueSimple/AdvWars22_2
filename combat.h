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
        cout << degat << " AOUCH" << endl;
        defense->recevoirdegat(degat);
        if(!riposte){
            attaquer(defense, attack, terrain, true);
        }
    }
};

#endif // ATTAQUE_H
