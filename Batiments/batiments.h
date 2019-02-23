#ifndef BATIMENTS_H
#define BATIMENTS_H

#include "./Terrains/terrain.h"

class Batiment : public Terrain
{
    std::string team;
public:
    //Attributs
    int PointCapture;
    int Cout;

    //Méthodes
    Batiment(int,int);
    void setTeam(std::string team);
    std::string getTeam();
    virtual void activate() = 0;
};


#endif // BATIMENTS_H
