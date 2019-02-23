#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <string>
#include "./Terrains/terrain.h"
#include "./joueur.h"
#include "position.h"
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

class Unit
{
protected:
    //Attributs
    int PV;
    std::string MoveType;
    int Cout;
    int MovePoint;
    std::string team;
    void setImg(QPixmap img);
    Position *pos;
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
    bool isAt(int,int);
    void activate(vector<Terrain*>);
    std:: string getMoveType();
    int getPV();
    QPixmap getimg();
    int getMP();
    int getPosX();
    int getPosY();
    void setTeam(std::string team);
    std::string getTeam();
private:
    QPixmap img;
    vector<tuple<int,int>> where(int posx, int posy, int PM, vector<Terrain*>);
};


#endif // UNITS_H
