#include "game.h"
#include <tuple>
#include <array>
#include <iostream>
#include <vector>
#include <Units/Unitair/unitairbcopter.h>
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
}

tuple<int,int> Game::conv_coord(int x, int y){
    int width = 1000;
    int size_img = width/21;
    return make_tuple(x/size_img, y/size_img);
}

bool Game::click_on(int x, int y){
    tie(x, y) = conv_coord(x, y);
    cout << x << "," << y << endl;

    for(int i = 0; i < this->units.size(); ++i)
    {
        if(this->units[i]->is_at(x,y)){
            if(this->units[i]->getTeam() == this->joueur_actuel->getTeam()){
                this->units[i]->activate();
                this->dernier_active=this->units[i];
                return false;
            }
            else {
                cout << "Ce n'est pas ton equipe." << endl;
            }
        }
    }

    for(int i = 0; i < this->batiments.size(); ++i)
    {
        if(this->batiments[i]->is_at(x,y)){
            if(this->batiments[i]->getTeam() == this->joueur_actuel->getTeam()){
                this->batiments[i]->activate();
                this->dernier_active=this->batiments[i];
                return true;
            }
            else {
                cout << "Ce n'est pas ton equipe." << endl;
            }
        }
    }
    return false;
}

void Game::remunere(Joueur* j){
    int revenus = 0;
    for(int i = 0; i < this->batiments.size(); ++i)
    {
        if(this->batiments[i]->getTeam() == j->getTeam()){
            revenus+=1000;
        }
    }
    j->gagne_argent(revenus);
}

void Game::start_game(){
    this->joueurs = *new std::vector<Joueur*>;
    this->joueurs.push_back(new Joueur(0,"os",false));
    this->joueur_actuel = joueurs[0];

    this->joueurs.push_back(new Joueur(1,"bm",true));

    this->batiments = *new std::vector<Batiment*>;
    this->units = *new std::vector<Unit*>;

    //On cree les batiments neutres
    int villes[26][2] = {{1,1},{4,10},{8,5},{2,3},{5,3},{8,10},{1,5},{6,7},{9,12},
                         {0,12},{6,12},{10,15},{7,16},{10,1},{11,4},{12,6},{12,11},
                         {13,0},{14,4},{14,9},{15,13},{16,6},{18,13},{19,15},{19,11},{20,4}};

    for (int v = 0 ; v < 26 ; v++)
       {
            this->batiments.push_back(new Batimentville(villes[v][0],villes[v][1], "neutre"));
       }

    int aeroports[2][2] = {{20,8},{0,8}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->batiments.push_back(new Batimentaeroport(aeroports[v][0],aeroports[v][1], "neutre"));
       }

    int usines[2][2] = {{7,2},{13,14}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->batiments.push_back(new Batimentusine(usines[v][0],usines[v][1], "neutre"));
       }

    //On cree les batiments OS

    this->batiments.push_back(new Batimentville(4,14, "os"));

    int usines2[2][2] = {{4,12},{5,13}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->batiments.push_back(new Batimentusine(usines2[v][0],usines2[v][1], "os"));
       }

    //On cree les batiments BM

    this->batiments.push_back(new Batimentville(16,2, "bm"));

    int usines3[2][2] = {{16,4},{15,3}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->batiments.push_back(new Batimentusine(usines3[v][0],usines3[v][1], "bm"));
       }

    this->remunere(this->joueur_actuel);
    cout << this->joueur_actuel->getargent() << endl;
}

vector<Unit*> Game::getunits(){
    return this->units;
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

void Game::create_infant(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterreinfantinfant::Cout,j)){
        units.push_back(new Unitterreinfantinfant(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }

}

void Game::create_bazoo(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterreinfantbazooka::Cout,j)){
        units.push_back(new Unitterreinfantbazooka(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_recon(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantrecon::Cout,j)){
        units.push_back(new Unitterrenoinfantrecon(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_aa(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantantiair::Cout,j)){
        units.push_back(new Unitterrenoinfantantiair(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_tank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfanttank::Cout,j)){
        units.push_back(new Unitterrenoinfanttank(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_mdtank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantmdtank::Cout,j)){
        units.push_back(new Unitterrenoinfantmdtank(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_megatank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantmegatank::Cout,j)){
        units.push_back(new Unitterrenoinfantmegatank(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}

void Game::create_neotank(){
    Joueur* j = this->joueur_actuel;
    if(this->check_money(Unitterrenoinfantneotank::Cout,j)){
        units.push_back(new Unitterrenoinfantneotank(this->dernier_active->getposx(),
                                                       this->dernier_active->getposy(),
                                                       this->joueur_actuel->getTeam()));
        cout << "infant" << endl;
    }
    else {
        cout << "t'as pas de thunes" << endl;
    }
}
