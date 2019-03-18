#include "batiments.h"


using namespace std;

int Batiment::getPointCapture() const
{
    return PointCapture;
}

void Batiment::setPointCapture(int value)
{
    PointCapture = value;
}

void Batiment::reducePointCapture(int value, std::string team)
{
    this->PointCapture -= value;
    if ( this->PointCapture <= 0){
        this->setTeam(team);
    }
}

Batiment::Batiment(int x, int y) : Terrain (x, y)
{
    this->PointCapture = 20;
}

void Batiment::setTeam(std::string team)
{
    this->team=team;
    this->setImage(team);
}

std::string Batiment::getTeam(){
    return this->team;
}

void Batiment::setImage(string)
{

}

int Batiment::getImage(){
    return this->Image;
}
