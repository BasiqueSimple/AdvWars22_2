#ifndef GAME_H
#define GAME_H
#include "activable.h"
#include "joueur.h"
#include <iostream>
#include <Units/units.h>
#include <vector>

using namespace std;


class Game {
public:
    Game();
    void click_on(int x, int y);
private:
    std::vector<Activable*> activables;
    std::vector<Joueur*> joueurs;
    std::tuple<int,int> conv_coord(int x, int y);
    Joueur* joueur_actuel;
    void start_game();
};

#endif // GAME_H
