#include "combat.h"

Combat::Combat()
{
}

 void Combat::attaquer(Unit* attack, Unit* defense, Terrain* terrain, bool riposte) {
        int damages = Damage::calculerdamage(attack, defense);
        int pvAttack = attack->getPV();
        int pvDefense = defense->getPV();
        int pointdefense = (Damage::calculerpointdefense(defense, terrain));
        int degat = round(damages*pvAttack*(100-pvDefense*pointdefense)/10000);
        defense->recevoirdegat(degat);
        cout << "AOUCH j'ai pris " << degat << endl;
        if(!riposte && defense->getPV()>0){
            attaquer(defense, attack, terrain, true);
        }
}



