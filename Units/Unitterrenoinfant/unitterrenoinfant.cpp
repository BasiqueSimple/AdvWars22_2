#include "unitterrenoinfant.h"
#include <typeinfo.h>

using namespace std;

Unitterrenoinfant::Unitterrenoinfant(int x, int y): Unit(x, y)
{

}

void Unitterrenoinfant::etrerepare(Terrain terrain, Joueur joueur)
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
