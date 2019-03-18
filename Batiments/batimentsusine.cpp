#include "batimentsusine.h"

using namespace std;

Batimentusine::Batimentusine(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->ConsommationMovePoint=1;
    this->setTeam(team);
}

void Batimentusine::construireUnit()
{

}

void Batimentusine::reparerUnit()
{

}

void Batimentusine::GagnerArgent()
{

}

bool Batimentusine::activate()
{
    return true;
}

void Batimentusine::setImage(string)
{
    if( this->getTeam() == "os" ){
        this->Image = 39;
    }
    else if( this->getTeam() == "bm" ){
        this->Image = 44;
    }
    else{
        this->Image = 35;
    }
}
