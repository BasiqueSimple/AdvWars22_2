#ifndef GAME_H
#define GAME_H
#include "activable.h"
#include <iostream>
#include <Units/units.h>
#include <vector>

using namespace std;


class Game {
public:
    Game();
    void what_in(int x, int y);
private:
    std::vector<Unit*> activables;
    std::tuple<int,int> conv_coord(int x, int y);
    void start_game();
};

#endif // GAME_H
