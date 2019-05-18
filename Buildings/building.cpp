#include "building.h"


using namespace std;

bool Building::activate(){
    return true;
}

int Building::getPointCapture() const
{
    return PointCapture;
}

void Building::setPointCapture(int value)
{
    PointCapture = value;
}

void Building::reducePointCapture(int value, std::string team)
{
    this->PointCapture -= value;
    if ( this->PointCapture <= 0){
        this->setTeam(team);
    }
}

void Building::setEnCapture(bool value)
{
    enCapture = value;
}

bool Building::getEnCapture() const
{
    return enCapture;
}

Building::Building(int x, int y) : Terrain (x, y)
{
    this->PointCapture = 20;
}

void Building::setTeam(std::string team)
{
    this->team = team;
    this->setImage();
}

std::string Building::getTeam(){
    return this->team;
}

void Building::setImage()
{

}

int Building::getImage(){
    return this->Image;
}
