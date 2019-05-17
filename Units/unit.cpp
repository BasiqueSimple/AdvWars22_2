#include "unit.h"
#include <string>
#include "Unitterreinfant/infantry.h"
#include "game.h"
#include "math.h"
#include <typeinfo>
#include <cstdlib>
#include <combat.h>
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
    int ConsommationMovePoint = 0;
    char MoveType = this->getMoveType();
    if (TerrainType=="plain"){
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
    else if (TerrainType=="mountain")
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
    else if (TerrainType=="forest")
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
    else if (TerrainType=="river")
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
    else if (TerrainType=="bridge")
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
    else if (TerrainType=="beach")
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
    else if (TerrainType=="city")
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
    else if (TerrainType=="factory")
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
    else if (TerrainType=="airport")
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

void Unit::wait()
{
    cout << "j'attends" << endl;
    this->finished=true;
}

void Unit::attack(Unit* unit, Terrain* terrain){
    Combat::attaquer(this, unit, terrain, false);
    this->finished=true;
}

int Unit::getPV()
{
    return this->PV;
}

void Unit::recevoirdegat(int a)
{
    this->PV -= a;
}

int Unit::getCout(){
    return this->Cout;
}

void Unit::etrerepare(Building batiment)
{
    int prix = 0;
    if ((batiment.getTerrainType()=="usine" || batiment.getTerrainType()=="ville") && (batiment.getTeam()== this->game->getCurrentPlayer()->getTeam())){
        if (this->UnitType == 0){
            prix = Antiair::cost;
        }
        else if (this->UnitType == 4 ){
            prix = Infantry::cost;
        }
        else if (this->UnitType == 5 ){
            prix = Mdtank::cost;
        }
        else if (this->UnitType == 6 ){
            prix = Bazooka::cost;
        }
        else if (this->UnitType == 7 ){
            prix = Megatank::cost;
        }
        else if (this->UnitType == 8 ){
            prix = Neotank::cost;
        }
        else if (this->UnitType == 9 ){
            prix = Recon::cost;
        }
        else if (this->UnitType == 10 ){
            prix = Tank::cost;
        }
        if (prix != 0 && this->PV < 10 && this->game->check_money((int)round(prix*0.9), this->game->getCurrentPlayer())){
            cout << "Tu es une unité " << this->UnitType << " terrestre sur " << batiment.getTerrainType() << "et tu coutes " << prix << endl;
            if (this->PV == 9){
                this->PV +=1;
                cout << "Tu es passé de 9 à" << this->PV << "PV" << endl;
            }
            else {
                this->PV +=2;
                cout << "Tu es passé de moins de 9 à" << this->PV << "PV" << endl;
            }
        }
    }
    else if (batiment.getTerrainType()=="aeroport" && batiment.getTeam()== this->game->getCurrentPlayer()->getTeam()) {
        if (this->UnitType == 1){
            prix = Bcopter::cost;
         }
        else if(this->UnitType == 2){
            prix = Bomber::cost;
        }
        else if (this->UnitType == 3){
            prix = Fighter::cost;
        }
        if (prix != 0 && this->PV < 10 && this->game->check_money((int)round(prix*0.9), this->game->getCurrentPlayer())){
            cout << "dans le if fct.1" << endl;
            cout << "Tu es une unité " << this->UnitType << " aerienne sur " << batiment.getTerrainType() << "et tu coutes " << prix << endl;
            if (this->PV == 9){
                this->PV +=1;
                cout << "Tu es passé de 9 à" << this->PV << "PV" << endl;
            }
            else {
                this->PV +=2;
                cout << "Tu es passé de moins de 9 à" << this->PV << "PV" << endl;
            }
        }
    }
}

void Unit::resetMP()
{

}

void Unit::setCasesAcces(vector<Terrain*> * cases_acces){
    this->casesAcces = cases_acces;
}

void Unit::merge(Unit* celuiquejerejoins)
{
    if (this->getUnitType() == celuiquejerejoins->getUnitType())
    {
        if (celuiquejerejoins->getPV() ==10)
        {
            cout << "Tu ne peux pas fusionner avec moi j'ai encore tous mes points de vie" <<endl;
        }
        else if (celuiquejerejoins->getHasMoved())
        {
            cout << "Tu ne peux pas fusionner avec moi j'ai déjà bougé" <<endl;
        }
        else {
            int a = this->getPV() + celuiquejerejoins->getPV();
            if (a > 10)
            {
              a = 10;
            }
            celuiquejerejoins->PV = 10;
            this->PV = 0;
            this->setTourFini(true);
            celuiquejerejoins->setTourFini(true);
        }
    }
    else {
        cout << "Deux unités du même type ne peuvent pas fusionner..." << endl;
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
    setCasesAcces(where(getPosX(), getPosY(), MovePoint, game, casesAcces));
    game->setHighlighted(casesAcces);
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
            Terrain* ptTerrain = game->getTerrainAt(nextx, nexty);
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
            Terrain* ptTerrain = game->getTerrainAt(nextx, nexty);
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
            Terrain* ptTerrain = game->getTerrainAt(nextx, nexty);
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
            Terrain* ptTerrain = game->getTerrainAt(nextx, nexty);
            int MovePointNecessaires = this->ptconso(ptTerrain);
            if (MP >= MovePointNecessaires && MovePointNecessaires !=0 && nextx < dimx && nextx >= 0 && nexty < dimy && nexty >= 0){
                cases_acces->push_back(ptTerrain);
                this->where(nextx, nexty, MP-MovePointNecessaires, game, cases_acces);
                }
        }
    return cases_acces;
}

int Unit::getDamageType() const
{
    return UnitType;
}

int Unit::getUnitType() const
{
    return UnitType;
}

void Unit::setImg(QPixmap img){
    this->img=img;
}

QPixmap Unit::getimg(){
    return this->img;
}

Unit::~Unit(){

}

void Unit::move(int x, int y)
{
    this->pos->setPosX(x);
    this->pos->setPosY(y);
    this->casesAcces->clear();
    this->MovePoint = 0;
    this->HasMoved = true;
}

bool Unit::hasFinished() const{
    return this->finished;
}

void Unit::setTourFini(bool b){
    this->finished= b;
}
