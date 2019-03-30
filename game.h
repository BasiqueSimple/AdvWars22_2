#ifndef GAME_H
#define GAME_H
#include "joueur.h"
#include <iostream>
#include <Units/unit.h>
#include <vector>
#include <Batiments/batiments.h>



using namespace std;


class Game {
public:
    Game();
    int click_on(int, int);
    Unit* getDernierUnit();
    void create_infant();
    void create_bazoo();
    void create_aa();
    void create_recon();
    void create_tank();
    void create_mdtank();
    void create_megatank();
    void create_neotank();
    vector<Unit *> getunits();
    vector<Terrain *> * getHighlited();
    void joueur_suivant();
    Terrain * get_terrain_at(int, int);
    Batiment * get_batiment_at(int, int);
    void setHighlighted(vector<Terrain*>*);
    std::vector<Batiment *> * getBatiments() const;

private:
    std::vector<Terrain*> * highlighted;
    std::vector<Terrain*> terrains;
    std::vector<Unit*> units;
    std::vector<Batiment*> * batiments;
    std::vector<Joueur*> joueurs;
    std::tuple<int,int> conv_coord(int x, int y);
    Joueur* joueur_actuel;
    Batiment* dernier_batiment;
    Unit* dernier_unit;
    void start_game();
    void remunere(Joueur*);
    bool check_money(int, Joueur *);
};

#endif // GAME_H
