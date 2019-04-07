#include "batimentsville.h"

using namespace std;

Batimentville::Batimentville(int x, int y, std::string team): Batiment (x,y)
{
    this->PointDefense=3;
    this->setTeam(team);
    this->type="ville";
}

void Batimentville::reparerUnit()
{

}

bool Batimentville::activate()
{
    return false;
}

void Batimentville::setImage(string)
{
    if( this->getTeam() == "os" ){
        this->Image = 38;
    }
    else if( this->getTeam() == "bm" ){
        this->Image = 43;
    }
    else{
        this->Image = 34;
    }
}

void Batimentville::GagnerArgent()
{

}
