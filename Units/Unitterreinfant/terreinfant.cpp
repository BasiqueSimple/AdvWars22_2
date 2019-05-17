#include "terreinfant.h"
#include <typeinfo>

using namespace std;

Terreinfant::Terreinfant(int x, int y): Unit(x, y)
{

}

void Terreinfant::etrerepare(Terrain terrain, Player joueur)
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

void Terreinfant::resetMP()
{

}

