#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <onmap.h>
#include <string>
#include "./activable.h"
#include "./Terrains/terrain.h"
#include "./joueur.h"

#include "./Terrains/plaine.h"
#include "./Terrains/montagne.h"
#include "./Terrains/foret.h"
#include "./Terrains/pipe.h"
#include "./Terrains/plage.h"
#include "./Terrains/pont.h"
#include "./Terrains/reef.h"
#include "./Terrains/riviere.h"
#include "./Terrains/route.h"
#include "./Batiments/batimentsville.h"
#include "./Batiments/batimentsusine.h"
#include "./Batiments/batimentsaeroport.h"






class Unit : public Activable
{
protected:
    //Attributs
    int PV;
    std::string MoveType;
    int Cout;
    int MovePoint;
    std::string Team;
    void setImg(QPixmap img);
public:
    //Méthodes
    Unit(int,int);
    ~Unit();
    void move(Terrain);
    void mouvementspossibles(Terrain);
    void attendre();
    void recevoirdegat(int);
    virtual void etrerepare(Terrain, Joueur);
    void fusion(Unit);
    bool EtreEnVie();
    void activate(vector<Terrain*>);
    std:: string getMoveType();
    int getPV();
    QPixmap getimg();
    int getMP();
private:
    QPixmap img;
    vector<tuple<int,int>> where(int posx, int posy, int PM, vector<Terrain*>);
};


#endif // UNITS_H
