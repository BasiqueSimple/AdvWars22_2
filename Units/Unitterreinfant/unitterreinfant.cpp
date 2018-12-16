#include "unitterreinfant.h"
#include <typeinfo.h>

using namespace std;

Unitterreinfant::Unitterreinfant(int x, int y): Unit(x, y)
{

}

void Unitterreinfant::etrerepare(Terrain terrain, Joueur joueur)
{
    if ((typeid (terrain) == typeid (Batimentusine)) || (typeid(terrain) == typeid(Batimentville)))
    {
        if (this->PV <= 10)
        {
            this->PV +=2;
            void (joueur.payer(this->Cout/10));
        }
    }
}
