#include "unit.h"
#include <string>
#include "Unitterreinfant/unitterreinfantinfant.h"
#include "game.h"
#include <typeinfo>
#include <cstdlib>
#define dimx 21
#define dimy 17


Unit::Unit(int x, int y)
{
    this->pos = new Position(x,y);
    this->casesAcces = new vector<Terrain*>;
    this->PV = 10;
    this->MovePoint = 0;
    this->HasMoved = false;
}

void Unit::resetHasMoved(){
    this->HasMoved=false;
}

int Unit::ptconso(Terrain* terrain) {
    std::string TerrainType = terrain->getTerrainType();
    int ConsommationMovePoint;
    char MoveType = this->getMoveType();
    if (TerrainType=="plaine"){
        //ConsommationMovePoint=F1 B1 T1 W2 A1
        if (MoveType == 'F')
        {
           ConsommationMovePoint = 1;
        }
        else if (MoveType == 'B')
        {
           ConsommationMovePoint = 1;
        }
        else if (MoveType == 'T')
        {
           ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
           ConsommationMovePoint = 2 ;
        }
        else if (MoveType == 'A')
        {
           ConsommationMovePoint = 1 ;
        }
        else
        {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (TerrainType=="montagne")
    {
        //ConsommationMovePoint=F2 B1 T- W- A1
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 2 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 0;
            //0 quand on ne peut pas aller dessus
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="foret")
     {//ConsommationMovePoint=F1 B1 T2 W3 A1
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 2 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 3 ;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (TerrainType=="riviere")
    {
        //ConsommationMovePoint=F2 B1 T- W- A1
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 2 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="route")
     {
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
             ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="pont")
     {
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="plage")
     {
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="reef")
     {
        //ConsommationMovePoint=F- B- T- W- A1
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="ville")
     {
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
           ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
           ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
           ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="usine")
     {
        if (MoveType == 'F')
        {
           ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="aeroport")
     {
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 1 ;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (TerrainType=="pipe")
     {    //ConsommationMovePoint=Tjr interdit -
        if (MoveType == 'F')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'B')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'T')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'W')
        {
            ConsommationMovePoint = 0;
        }
        else if (MoveType == 'A')
        {
            ConsommationMovePoint = 0;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else
     {
        cout << "Ce terrain est inconnu" << endl;
     }
    return ConsommationMovePoint;
}

void Unit::attendre()
{
    cout << "j'attends" << endl;
    this->tourNonFini=false;
    //passer un tour
}

void Unit::attaquer(){
    cout << "j'attaque" << endl ;
    this->tourNonFini=false;
}

int Unit::getPV()
{
    return this->PV;
}

void Unit::recevoirdegat(int a)
{
    this->PV = --a;
}

void Unit::etrerepare(Terrain, Joueur)
{

}

void Unit::resetMP()
{

}

void Unit::setCasesAcces(vector<Terrain*> * cases_acces){
    this->casesAcces = cases_acces;
}

void Unit::fusion(Unit celuiquejerejoins)
{
    if (typeid (this) == typeid (celuiquejerejoins))
    {
        if ((celuiquejerejoins.PV)==10)
        {
            cout << "Tu ne peux pas fusionner avec moi j'ai encore tous mes points de vie" <<endl;
        }
        else
        {
            // int a = this->PV + celuiquejerejoins.PV;
            //if (a > 10)
            //{
            //  a = 10;
            //}
            //creer un unit du même type dont PV = a
            //detruire this
            //detruire celuiquejerejoins
        }
    }
}

bool Unit::EtreEnVie()
{
    return this->PV > 0;
}

bool Unit::isAt(int x, int y)
{
    return this->pos->isAt(x,y);
}

char Unit::getMoveType()
{
    return this->MoveType;
}

void Unit::activate()
{
    this->setCasesAcces(this->where(this->getPosX(), this->getPosY(), this->MovePoint, this->game, this->casesAcces));
    this->game->setHighlighted(this->casesAcces);
}

bool Unit::getHasMoved(){
    return this->HasMoved;
}

int Unit::getMP(){
    return this->MovePoint;
}

int Unit::getPosX()
{
    return this->pos->getPosX();
}

int Unit::getPosY()
{
    return this->pos->getPosY();
}

void Unit::setTeam(std::string team)
{
    this->team=team;
}

void Unit::setGame(Game * game)
{
    this->game = game;
}

std::string Unit::getTeam(){
    return this->team;
}

vector<Terrain*> * Unit::where(int posx, int posy, int MP, Game * game, vector<Terrain*> * cases_acces) {
        //Vers le nord
        int nextx = posx;
        int nexty = posy-1;
        if(nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
            Terrain* ptTerrain = game->get_terrain_at(nextx, nexty);
            int MovePointNecessaires = this->ptconso(ptTerrain);
            if (MP >= MovePointNecessaires && MovePointNecessaires !=0){
                cases_acces->push_back(ptTerrain);
                this->where(nextx, nexty, MP-MovePointNecessaires, game, cases_acces);
            }
        }

        //Vers le sud
        nextx = posx;
        nexty = posy+1;
        if(nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
            Terrain* ptTerrain = game->get_terrain_at(nextx, nexty);
            int MovePointNecessaires = this->ptconso(ptTerrain);
            if (MP >= MovePointNecessaires && MovePointNecessaires !=0 && nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
                cases_acces->push_back(ptTerrain);
                this->where(nextx, nexty, MP-MovePointNecessaires, game, cases_acces);
                }
        }

        //Vers l'ouest
        nextx = posx-1;
        nexty = posy;
        if(nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
            Terrain* ptTerrain = game->get_terrain_at(nextx, nexty);
                int MovePointNecessaires = this->ptconso(ptTerrain);
                if (MP >= MovePointNecessaires && MovePointNecessaires !=0 && nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
                    cases_acces->push_back(ptTerrain);
                    this->where(nextx, nexty, MP-MovePointNecessaires, game, cases_acces);
                }
        }

        //Vers l'est
        nextx = posx+1;
        nexty = posy;
        if(nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
            Terrain* ptTerrain = game->get_terrain_at(nextx, nexty);
            int MovePointNecessaires = this->ptconso(ptTerrain);
            if (MP >= MovePointNecessaires && MovePointNecessaires !=0 && nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
                cases_acces->push_back(ptTerrain);
                this->where(nextx, nexty, MP-MovePointNecessaires, game, cases_acces);
                }
        }
    return cases_acces;
}


void Unit::setImg(QPixmap img){
    this->img=img;
}

QPixmap Unit::getimg(){
    return this->img;
}

Unit::~Unit()
{

}

void Unit::move(int x, int y)
{
    this->pos->setPosX(x);
    this->pos->setPosY(y);
    this->casesAcces->clear();
    this->MovePoint = 0;
    this->HasMoved = true;
}

bool Unit::getTourNonFini(){
    return this->tourNonFini;
}

void Unit::setTourNonFini(bool vf){
    this->tourNonFini= vf;
}

/*
bool Unit::peut_dessus(Unit unit, int posx,int posy, vector<Terrain*> terrains){
    Terrain* terrain = this->game->get_terrain_at(posx,posy);
    char MoveType = unit.getMoveType();
    int ptconsomation = ptconso(terrain, MoveType);
    int MP = unit.getMP();
    if (ptconsomation>MP){
        cout << "tu n'as pas assez de MP pour aller sur la case (" << posx << " , " << posy << ")" << endl;
        return 1;
    }
    else {
        cout << "tu peux aller sur la case ( " << posx << " , " << posy << " )" << endl;
        //colorier case
        mvts_possibles(unit, posx, posy, terrains);
        return 0;
    }
}


void Unit::mvts_possibles(Unit unit, int posx, int posy, vector<Terrain*> terrains){
    vector<tuple<int,int>> cases_possibles;
    if (posx-1>0){ //on n'est pas à l'extrême gauche de la map
        cases_possibles.push_back(make_tuple(posx-1,posy));
        if (posx+1<LONG_MAX){ // on n'est pas à l'extrême droite de la map
            cases_possibles.push_back(make_tuple(posx+1, posy));
        }
    }
    if (posy-1>0){ //on n'est pas à tout en haut de la map
        cases_possibles.push_back(make_tuple(posx,posy-1));
        if (posy+1<LONG_MAX){ // on n'est pas tout en bas de la map
            cases_possibles.push_back(make_tuple(posx, posy+1));
        }
    }
    for (tuple<int,int> i : cases_possibles){
        peut_dessus(unit, i, terrains);
    }
}
*/
