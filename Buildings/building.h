#ifndef BATIMENTS_H
#define BATIMENTS_H

#include "./Terrains/terrain.h"

class Building : public Terrain
{
    std::string team;
    int PointCapture;
public:
    //Attributs
    int Cout;

    //Méthodes
    Building(int,int);
    void setTeam(std::string team);
    std::string getTeam();
    virtual bool activate();
    virtual void setImage(std::string);
    int getPointCapture() const;
    void setPointCapture(int value);
    void reducePointCapture(int value, std::string);
    int getImage();
};


#endif // BATIMENTS_H
