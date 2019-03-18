#include "unitair.h"
#include <typeinfo>

using namespace std;

Unitair::Unitair(int x,int y): Unit(x, y)
{
    this->MoveType ='A';
}

void Unitair::etrerepare(Terrain terrain, Joueur joueur)
{
    if (typeid (terrain) == typeid (Batimentaeroport))
    {
        if (this->PV <= 10)
        {
            this->PV +=2;
            void (joueur.payer(this->Cout/10));
        }
    }
}

void Unitair::resetMP()
{

}
