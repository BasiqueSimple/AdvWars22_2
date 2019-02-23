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
    bool click_on(int, int);
    void create_infant();
    void create_bazoo();
    void create_aa();
    void create_recon();
    void create_tank();
    void create_mdtank();
    void create_megatank();
    void create_neotank();
    vector<Unit *> getunits();
    void joueur_suivant();
private:
    std::vector<Terrain*> terrains;
    std::vector<Unit*> units;
    std::vector<Batiment*> batiments;
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
