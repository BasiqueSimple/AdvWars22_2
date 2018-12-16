#include "combat.h"

combat::combat()
{

}

void combat::riposter(Unit attaquant, Unit attaque, Terrain terrain, damage damage)
{
    int damages = (damage.calculerdamage(attaque, attaquant));
    int pvattaque = attaque.getPV();
    int pvattaquant = attaquant.getPV();
    int pointdefense = (damage.calculerpointdefense(attaque, terrain));

    int degat = damages*pvattaque*(100-pvattaquant*pointdefense)/1000;
    void (attaquant.recevoirdegat(degat));
}

void combat::attaquer(Unit attaquant, Unit attaque, Terrain terrain, damage damage, combat combats)
{
    int damages =(damage.calculerdamage(attaquant, attaque));
    int pvattaquant = attaquant.getPV();
    int pvattaque = attaque.getPV();
    int pointdefense = (damage.calculerpointdefense(attaquant, terrain));

    int degat = damages*pvattaquant*(100-pvattaque*pointdefense)/1000;
    void (attaque.recevoirdegat(degat));
    void (combats.riposter(attaquant, attaque, terrain, damage));
}


