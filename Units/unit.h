#ifndef UNITS_H
#define UNITS_H
#include <iostream>
#include <string>
#include "./Terrains/terrain.h"
#include "./player.h"
#include "position.h"
#include "./Terrains/plain.h"
#include "./Terrains/mountain.h"
#include "./Terrains/forest.h"
#include "./Terrains/pipe.h"
#include "./Terrains/beach.h"
#include "./Terrains/bridge.h"
#include "./Terrains/reef.h"
#include "./Terrains/river.h"
#include "./Terrains/route.h"
#include "./Buildings/city.h"
#include "./Buildings/factory.h"
#include "./Buildings/airport.h"

class Game;

class Unit
{
protected:
    //Attributs
    int PV;
    char MoveType;
    int UnitType;
    int Cout;
    int MovePoint;
    std::string team;
    void setImg(QPixmap img);
    Position *pos;
    Game * game;
    vector<Terrain*>* casesAcces;
    bool HasMoved;
    bool finished;
public:
    //Méthodes
    Unit(int,int);
    ~Unit();
    virtual int getCout();
    bool hasFinished() const;
    void setTourFini(bool vf);
    bool getHasMoved();
    void resetHasMoved();
    void move(int, int);
    void mouvementspossibles(Terrain);
    bool peut_dessus(Unit, int, int, vector<Terrain*>);
    void mvts_possibles(Unit, int, int, vector<Terrain*>);
    int ptconso(Terrain*);
    void attendre();
    void recevoirdegat(int);
    void etrerepare(Building);
    virtual void resetMP();
    void fusion(Unit*);
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
    void attaquer(Unit*, Terrain*);
    std::string getTeam();
    int getDamageType() const;
    int getUnitType() const;

private:
    QPixmap img;
    vector<Terrain*> * where(int posx, int posy, int PM, Game * game, vector<Terrain*> * cases_acces);
    void setCasesAcces(vector<Terrain *> *cases_acces);
};


#endif // UNITS_H
