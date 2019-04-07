#define dimx 21
#define dimy 17

#include "game.h"
#include <tuple>
#include <array>
#include <iostream>
#include <vector>
#include <Units/Unitair/unitairbcopter.h>
#include <Units/Unitair/unitairfighter.h>
#include <Units/Unitair/unitairbomber.h>
#include <Batiments/batimentsaeroport.h>
#include <Batiments/batimentsusine.h>
#include <Batiments/batimentsville.h>
#include <Units/Unitterreinfant/unitterreinfantbazooka.h>
#include <Units/Unitterreinfant/unitterreinfantinfant.h>
#include <Units/Unitterrenoinfant/unitterrenoinfantantiair.h>
#include <Units/Unitterrenoinfant/unitterrenoinfantmdtank.h>
#include <Units/Unitterrenoinfant/unitterrenoinfantmegatank.h>
#include <Units/Unitterrenoinfant/unitterrenoinfantneotank.h>
#include <Units/Unitterrenoinfant/unitterrenoinfantrecon.h>
#include <Units/Unitterrenoinfant/unitterrenoinfanttank.h>

using namespace std;

Game::Game()
{
    this->start_game();
    this->setHighlighted(new vector<Terrain*>);
}

Joueur* Game::getJoueur_actuel(){
    return this->joueur_actuel;
}

tuple<int,int> Game::conv_coord(int x, int y){
    int width = 1000;
    int size_img = width/21;
    return make_tuple(x/size_img, y/size_img);
}

std::string Game::getWinner() const
{
    return winner;
}

Unit *Game::getDernier_bouge() const
{
    return dernier_bouge;
}

int Game::click_on(int x, int y){
    tie(x, y) = conv_coord(x, y);
    cout << x << "," << y << endl;

    if(!this->highlighted->empty()){ //Si c'est pour opérer un déplacement
        for(vector<Terrain*>::iterator it = this->highlighted->begin(); it != this->highlighted->end(); ++it){
            if((*it)->isAt(x,y)){
                this->dernier_unit->move(x,y);
                this->dernier_bouge = this->dernier_unit;
                /*for(vector<Unit*>::iterator unit = this->units.begin(); unit != this->units.end(); ++unit){
                    if(((*unit)->isAt(x-1,y) || (*unit)->isAt(x+1,y) || (*unit)->isAt(x,y-1) || (*unit)->isAt(x,y+1)) && (*unit)->getTeam() != this->joueur_actuel->getTeam()){
                        return 3;
                    }
                }*/
                break;
            }
        }
        this->highlighted->clear();
        return 0;
    }

    for(vector<Unit*>::iterator it = this->units->begin(); it != this->units->end(); ++it){
        if((*it)->isAt(x,y)){
            if((*it)->getTeam() == this->joueur_actuel->getTeam()){ //Si c'est de sa propre équipe
                if ((*it)->getHasMoved()){
                    cout << "Tu t'es déjà déplacé" << endl;
                } else {
                    (*it)->activate();
                    this->dernier_unit=*it;
                }
            return 0;
            }
            else {
                cout << "Ce n'est pas ton equipe." << endl;
                int lastX = this->dernier_unit->getPosX();
                int lastY = this->dernier_unit->getPosY();
                if((x==lastX && (y==lastY-1 || y==lastY+1)) || (y==lastY && (x==lastX-1 || x==lastX+1))){
                        this->dernier_unit=*it;
                        return 3;
                }
            }
        }
    }

    for(vector<Batiment*>::iterator it = this->batiments->begin(); it != this->batiments->end(); ++it)
    {
        if((*it)->isAt(x,y))
        {
            if((*it)->getTeam() == this->joueur_actuel->getTeam()){
                if( (*it)->activate()){
                    this->dernier_batiment=*it;
                    if ((*it)->getTerrainType() == "usine"){
                        return 1;
                    }
                    else if ((*it)->getTerrainType() == "aeroport"){
                        return 2;
                    }
                }
            }
            else {
                cout << "Ce n'est pas ton equipe." << endl;
            }
        }
    }
    return 0;
}

Unit* Game::getDernierUnit(){
    return this->dernier_unit;
}

void Game::remunere(Joueur* j){
    int revenus = 0;
    for(vector<Batiment*>::iterator it = this->batiments->begin(); it != this->batiments->end(); ++it)
    {
        if((*it)->getTeam() == j->getTeam()){
            revenus+=1000;
        }
    }
    j->gagne_argent(revenus);
}

void Game::joueur_suivant(){
    if(this->joueur_actuel == joueurs[0]){
        this->joueur_actuel = joueurs[1];
    }
    else {
        this->joueur_actuel = joueurs[0];
    }
    for(vector<Unit*>::iterator it = this->units->begin(); it != this->units->end(); ++it){
        if( (*it)->getTeam() == this->joueur_actuel->getTeam() ){
            (*it)->resetMP();
            (*it)->resetHasMoved();
            (*it)->setTourNonFini(true);
            int x = (*it)->getPosX();
            int y = (*it)->getPosY();
            if( this->get_batiment_at(x,y) )
            {
                Batiment * batiment = this->get_batiment_at(x,y);
                if( batiment->getTeam() != this->joueur_actuel->getTeam() )
                {
                    batiment->reducePointCapture((*it)->getPV(), this->joueur_actuel->getTeam());
                    cout << "plus que " << batiment->getPointCapture() << " points" << endl;
                }
            }
        }
    }
    this->remunere(this->joueur_actuel);
    cout << "Joueur " << this->joueur_actuel->getTeam() << " à toi de jouer !" <<endl;
    cout << "Tu as " << this->joueur_actuel->getargent() << " d'argent." <<endl;
    for(vector<Unit*>::iterator iter = this->units->begin(); iter != this->units->end(); ++iter){
        if( (*iter)->getTeam() == this->joueur_actuel->getTeam() ){
            int x = (*iter)->getPosX();
            int y = (*iter)->getPosY();
            if( this->get_batiment_at(x,y))
            {
                Batiment * batiment = this->get_batiment_at(x,y);
                if( batiment->getTeam() == this->joueur_actuel->getTeam() )
                {
                    (*iter)->etrerepare(*batiment);
                }
            }
        }
    }
}

Terrain * Game::get_terrain_at(int x, int y)
{
    for(vector<Terrain*>::iterator it = this->terrains.begin(); it != this->terrains.end(); ++it){
        if((*it)->isAt(x,y)){
            return *it;
        }
    }
    return 0;
}

Batiment *Game::get_batiment_at(int x, int y)
{
    for(vector<Batiment*>::iterator it = this->batiments->begin(); it != this->batiments->end(); ++it){
        if((*it)->isAt(x,y)){
            return *it;
        }
    }
    return 0;
}

void Game::setHighlighted(vector<Terrain *> *casesAcces)
{
    this->highlighted = casesAcces;
}

std::vector<Batiment *> * Game::getBatiments() const
{
    return batiments;
}

void Game::start_game(){
    this->joueurs = *new std::vector<Joueur*>;
    this->joueurs.push_back(new Joueur(0,"os",false));
    this->joueur_actuel = joueurs[0];

    this->terrains = *new std::vector<Terrain*>;
    this->joueurs.push_back(new Joueur(1,"bm",true));

    this->batiments = new std::vector<Batiment*>;
    this->units = new std::vector<Unit*>;

    //On cree les batiments neutres
    int villes[26][2] = {{1,1},{4,10},{8,5},{2,3},{5,3},{8,10},{1,5},{6,7},{9,12},
                         {0,12},{6,12},{10,15},{7,16},{10,1},{11,4},{12,6},{12,11},
                         {13,0},{14,4},{14,9},{15,13},{16,6},{18,13},{19,15},{19,11},{20,4}};

    for (int v = 0 ; v < 26 ; v++)
       {
            Batiment* bat = new Batimentville(villes[v][0],villes[v][1], "neutre");
            this->batiments->push_back(bat);
            this->terrains.push_back(bat);
       }

    int aeroports[2][2] = {{20,8},{0,8}};

    for (int v = 0 ; v < 2 ; v++)
       {
            Batiment* bat = new Batimentaeroport(aeroports[v][0],aeroports[v][1], "neutre");
            this->batiments->push_back(bat);
            this->terrains.push_back(bat);
       }

    int usines[2][2] = {{7,2},{13,14}};

    for (int v = 0 ; v < 2 ; v++)
       {
            Batiment *bat = new Batimentusine(usines[v][0],usines[v][1], "neutre");
            this->batiments->push_back(bat);
            this->terrains.push_back(bat);
       }

    //On cree les batiments OS
    Batiment* bat = new Batimentville(4,14, "os");
    this->batiments->push_back(bat);
    this->terrains.push_back(bat);

    int usines2[2][2] = {{4,12},{5,13}};

    for (int v = 0 ; v < 2 ; v++)
       {
        Batiment * bat = new Batimentusine(usines2[v][0],usines2[v][1], "os");
        this->batiments->push_back(bat);
        this->terrains.push_back(bat);
       }

    //On cree les batiments BM

    bat = new Batimentville(16,2, "bm");
    this->batiments->push_back(bat);
    this->terrains.push_back(bat);

    int usines3[2][2] = {{16,4},{15,3}};

    for (int v = 0 ; v < 2 ; v++)
       {
            bat = new Batimentusine(usines3[v][0],usines3[v][1], "bm");
            this->batiments->push_back(bat);
            this->terrains.push_back(bat);
       }

    //On cree les pipes

    int pipe[20][2] = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{0,1},{0,2},
                       {0,3},{14,16},{15,16},{16,16},{17,16},{18,16},{19,16},{20,16},
                       {20,13},{20,14},{20,15}};

    for (int v = 0 ; v < 20 ; v++)
       {
            this->terrains.push_back(new Pipe(pipe[v][0],pipe[v][1]));
       }

    //On cree les forêts

    int foret[40][2] = {{7,0},{13,1},{15,1},{19,1},{3,2},{11,2},{13,3},{3,4},{18,4},
                       {13,5},{20,5},{0,6},{4,6},{9,6},{14,6},{18,6},{7,7},
                       {11,7},{3,8},{5,8},{15,8},{17,8},{9,9},{13,9},{20,10},{0,11},{7,11},{2,12},{17,12},
                        {7,13},{9,14},{17,14},{1,15},{5,15},{7,15},{13,16},
                        {2,10},{6,10},{11,10},{16,10}};

    for (int v = 0 ; v < 40 ; v++)
       {
            this->terrains.push_back(new Foret(foret[v][0],foret[v][1]));
       }

    //On cree les plaines

    int plaine[112][2] = {{8,0},{14,0},{15,0},{16,0},{2,1},{3,1},{4,1},{6,1},{11,1},
                       {12,1},{14,1},{16,1},{17,1},{18,1},{2,2},{8,2},{9,2},
                       {10,2},{12,2},{13,2},{14,2},{15,2},{19,2},{6,3},{7,3},{14,3},{17,3},{20,3},{4,4},
                        {5,4},{6,4},{13,4},{17,4},{3,5},{4,5},{5,5},{14,5},{16,5},{17,5},{18,5},
                        {19,5},{1,6},{3,6},{7,6},{13,6},{17,6},{0,7},{3,7},{4,7},{9,7},{10,7},{12,7},{13,7},{16,7},{17,7},{4,8},{16,8},
                        {3,9},{4,9},{7,9},{8,9},{10,9},{11,9},{16,9},{17,9},{20,9},{3,10},{7,10},{13,10},
                        {17,10},{19,10},{1,11},{2,11},{3,11},{4,11},{6,11},
     {15,11},{16,11},{17,11},{3,12},{7,12},{14,12},{15,12},{16,12},{0,13},{3,13},{6,13},{13,13},{14,13},
    {1,14},{5,14},{6,14},{7,14},{8,14},{10,14},{11,14},{12,14},
    {18,14},{2,15},{3,15},{4,15},{6,15},{8,15},{9,15},{14,15},{16,15},{17,15},{18,15},{4,16},
     {5,16},{6,16},{12,16}};

    for (int v = 0 ; v < 112 ; v++)
       {
            this->terrains.push_back(new Plaine(plaine[v][0],plaine[v][1]));
       }

    //On cree les montagnes

    int montagne[60][2] = {{9,0},{17,0},{5,1},{1,2},{4,2},{20,2},{1,3},{8,3},{9,3},
                       {10,3},{11,3},{12,3},{7,4},{8,4},{9,4},{10,4},{12,4},
                       {0,5},{6,5},{7,5},{9,5},{10,5},{11,5},{12,5},{5,6},{6,6},{10,6},{11,6},{19,6},
                           {5,7},{15,9},{1,10},{9,10},{10,10},{14,10},{15,10},{8,11},
                           {9,11},{10,11},{11,11},{13,11},{14,11},{20,11},{8,12},{10,12},{11,12},{12,12},{13,12},{8,13},
                           {9,13},{10,13},{11,13},{12,13},{19,13},{0,14},{16,14},{19,14},
                           {15,15},{3,16},{11,16}};

    for (int v = 0 ; v < 60 ; v++)
       {
            this->terrains.push_back(new Montagne(montagne[v][0],montagne[v][1]));
       }

    //On cree les routes

    int route[60][2] = {{10,0},{11,0},{12,0},{7,1},{8,1},{9,1},{5,2},{6,2},{17,2},
                       {18,2},{3,3},{4,3},{16,3},{18,3},{19,3},{15,4},{19,4},
                       {15,5},{8,6},{15,6},{1,7},{8,7},{14,7},{15,7},{1,8},{6,8},{7,8},{8,8},{9,8},
                           {10,8},{11,8},{12,8},{13,8},{14,8},{19,8},{5,9},{6,9},
                           {12,9},{19,9},{5,10},{12,10},{5,11},{1,12},{5,12},{1,13},{2,13},{4,13},{16,13},{17,13},
                           {2,14},{3,14},{14,14},{15,14},{11,15},{12,15},{13,15},{8,16},
                           {9,16},{10,16}};

    for (int v = 0 ; v < 60 ; v++)
       {
            this->terrains.push_back(new Route(route[v][0],route[v][1]));
       }

    //On cree les plages

    int plage[6][2] = {{18,0},{19,0},{20,1},{0,15},{1,16},{2,16}};

    for (int v = 0 ; v < 6 ; v++)
       {
            this->terrains.push_back(new Plage(plage[v][0],plage[v][1]));
       }

    //On cree les reefs

    int reef[2][2] = {{0,16},{20,0}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->terrains.push_back(new Reef(reef[v][0],reef[v][1]));
       }

    //On cree les ponts

    int pont[4][2] = {{2,6},{2,7},{18,9},{18,10}};

    for (int v = 0 ; v < 4 ; v++)
       {
            this->terrains.push_back(new Pont(pont[v][0],pont[v][1]));
       }

    //On cree les rivières

    int riviere[18][2] = {{0,4},{1,4},{2,4},{2,5},{2,8},{0,9},{1,9},{2,9},{0,10},
                       {20,6},{18,7},{19,7},{20,7},{18,8},{18,11},{18,12},{19,12},
                       {20,12}};

    for (int v = 0 ; v < 18 ; v++)
       {
            this->terrains.push_back(new Riviere(riviere[v][0],riviere[v][1]));
       }

    this->remunere(this->joueur_actuel);
    cout << this->joueur_actuel->getargent() << endl;
}

vector<Unit*> * Game::getunits(){
    return this->units;
}

vector<Terrain *>* Game::getHighlited()
{
    return this->highlighted;
}

bool Game::check_money(int Cout, Joueur* j){
    if(Cout<=j->getargent()){
        j->gagne_argent(-Cout);
        cout << "Plus que " << j->getargent() << endl;
        return true;
    }
    else {
        return false;
    }
}

void Game::checkUnits(){
    for(vector<Unit*>::iterator it = this->getunits()->begin(); it != this->getunits()->end(); ++it){
        if((*it)->getPV() <= 0){
            //delete (*it); PROBLEME AVEC LES DESTRUCTORS
            this->getunits()->erase(it);
            break;
        }
    }
}

bool Game::checkGameOver(){
    int osUnitsCount = 0;
    int bmUnitsCount = 0;
    int osBuildingsCount = 0;
    int bmBuildingsCount = 0;
    for(vector<Unit*>::iterator it = this->getunits()->begin(); it != this->getunits()->end(); ++it){
        if((*it)->getTeam() == "os"){
            osUnitsCount++;
        }
        else if((*it)->getTeam() == "bm"){
            bmUnitsCount++;
        }
    }
    for(vector<Batiment*>::iterator it = this->batiments->begin(); it != this->batiments->end(); ++it){
        if((*it)->getTeam() == "os" && ((*it)->getTerrainType() == "aeroport" || (*it)->getTerrainType() == "usine")){
            osBuildingsCount++;
        }
        else if((*it)->getTeam() == "bm" && ((*it)->getTerrainType() == "aeroport" || (*it)->getTerrainType() == "usine")){
            bmBuildingsCount++;
        }
    }
    if(osUnitsCount == 0 && osBuildingsCount == 0){
        this->winner = "bm";
        return true;
    }
    else if(bmUnitsCount == 0 && bmBuildingsCount == 0){
        this->winner = "os";
        return true;
    }
    return false;
}

void Game::create_infant(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterreinfantinfant::Cout,j)){
        units->push_back(new Unitterreinfantinfant(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),
                                                       this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }

}

void Game::create_bazoo(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterreinfantbazooka::Cout,j)){
        units->push_back(new Unitterreinfantbazooka(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_bcopter(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitairbcopter::Cout,j)){
        units->push_back(new Unitairbcopter(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),
                                                       this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }

}

void Game::create_bomber(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitairbomber::Cout,j)){
        units->push_back(new Unitairbomber(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),
                                                       this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }

}

void Game::create_fighter(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitairfighter::Cout,j)){
        units->push_back(new Unitairfighter(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),
                                                       this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_recon(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantrecon::Cout,j)){
        units->push_back(new Unitterrenoinfantrecon(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_aa(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantantiair::Cout,j)){
        units->push_back(new Unitterrenoinfantantiair(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_tank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfanttank::Cout,j)){
        units->push_back(new Unitterrenoinfanttank(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_mdtank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantmdtank::Cout,j)){
        units->push_back(new Unitterrenoinfantmdtank(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_megatank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantmegatank::Cout,j)){
        units->push_back(new Unitterrenoinfantmegatank(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_neotank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantneotank::Cout,j)){
        units->push_back(new Unitterrenoinfantneotank(this->dernier_batiment->getPosX(),
                                                       this->dernier_batiment->getPosY(),this,
                                                       this->joueur_actuel->getTeam()));
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}
