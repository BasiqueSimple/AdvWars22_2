#ifndef GAME_H
#define GAME_H
#include "activable.h"
#include "joueur.h"
#include <iostream>
#include <Units/units.h>
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
private:
    std::vector<Unit*> units;
    std::vector<Batiment*> batiments;
    std::vector<Joueur*> joueurs;
    std::tuple<int,int> conv_coord(int x, int y);
    Joueur* joueur_actuel;
    Activable* dernier_active;
    void start_game();
};

#endif // GAME_H
