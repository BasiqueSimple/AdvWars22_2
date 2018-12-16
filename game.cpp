#include "game.h"
#include <tuple>
#include <array>
#include <iostream>
#include <vector>
#include <Units/Unitair/unitairbcopter.h>
#include <Batiments/batimentsaeroport.h>
#include <Batiments/batimentsusine.h>
#include <Batiments/batimentsville.h>

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

void Game::click_on(int x, int y){
    tie(x, y) = conv_coord(x, y);
    cout << x << "," << y << endl;
    for(int i = 0; i < this->activables.size(); ++i)
    {
        if(this->activables[i]->is_at(x,y)){
            if(this->activables[i]->getTeam() == this->joueur_actuel->getTeam()){
                this->activables[i]->activate();
            }
            else {
                cout << "Ce n'est pas ton equipe." << endl;
            }
        }
    }
}

void Game::start_game(){
    this->joueurs = *new std::vector<Joueur*>;
    this->joueurs.push_back(new Joueur(0,"os",false));
    this->joueur_actuel = joueurs[0];

    this->activables = *new std::vector<Activable*>;

    //On cree les batiments neutres
    int villes[26][2] = {{1,1},{4,10},{8,5},{2,3},{5,3},{8,10},{1,5},{6,7},{9,12},
                         {0,12},{6,12},{10,15},{7,16},{10,1},{11,4},{12,6},{12,11},
                         {13,0},{14,4},{14,9},{15,13},{16,6},{18,13},{19,15},{19,11},{20,4}};

    for (int v = 0 ; v < 26 ; v++)
       {
            this->activables.push_back(new Batimentville(villes[v][0],villes[v][1], "neutre"));
       }

    int aeroports[2][2] = {{20,8},{0,8}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->activables.push_back(new Batimentaeroport(aeroports[v][0],aeroports[v][1], "neutre"));
       }

    int usines[2][2] = {{7,2},{13,14}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->activables.push_back(new Batimentusine(usines[v][0],usines[v][1], "neutre"));
       }

    //On cree les batiments OS

    this->activables.push_back(new Batimentville(4,14, "os"));

    int usines2[2][2] = {{4,12},{5,13}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->activables.push_back(new Batimentusine(usines2[v][0],usines2[v][1], "os"));
       }

    //On cree les batiments BM

    this->activables.push_back(new Batimentville(16,2, "bm"));

    int usines3[2][2] = {{16,4},{15,3}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->activables.push_back(new Batimentusine(usines3[v][0],usines3[v][1], "bm"));
       }
}
