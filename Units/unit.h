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

class Game;

class Unit
{
protected:
    //Attributs
    int PV;
    char MoveType;
    int Cout;
    int MovePoint;
    std::string team;
    void setImg(QPixmap img);
    Position *pos;
    Game * game;
    vector<Terrain*>* casesAcces;
public:
    //Méthodes
    Unit(int,int);
    ~Unit();
    void move(int, int);
    void mouvementspossibles(Terrain);
    bool peut_dessus(Unit, int, int, vector<Terrain*>);
    void mvts_possibles(Unit, int, int, vector<Terrain*>);
    int ptconso(Terrain*, char);
    void attendre();
    void recevoirdegat(int);
    virtual void etrerepare(Terrain, Joueur);
    virtual void resetMP();
    void fusion(Unit);
    bool EtreEnVie();
    bool isAt(int,int);
    void activate();
    char getMoveType();
    int getPV();
    QPixmap getimg();
    int getMP();
    int getPosX();
    int getPosY();
    void setTeam(std::string team);
    void setGame(Game*);
    std::string getTeam();
private:
    QPixmap img;
    vector<Terrain*> * where(int posx, int posy, int PM, Game * game, vector<Terrain*> * cases_acces);
    void setCasesAcces(vector<Terrain *> *cases_acces);
};


#endif // UNITS_H
