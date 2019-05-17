#include "terrenoinfant.h"
#include <typeinfo>
using namespace std;

Terrenoinfant::Terrenoinfant(int x, int y): Unit(x, y)
{

}

void Terrenoinfant::etrerepare(Terrain terrain, Player joueur)
{
    if ((typeid (terrain) == typeid (Factory)) || (typeid(terrain) == typeid(City)))
    {
        if (this->PV <= 10)
        {
            this->PV +=2;
            void (joueur.payer(this->Cout/10));
        }
    }
}

void Terrenoinfant::resetMP()
{

}

