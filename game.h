#ifndef GAME_H
#define GAME_H
#include "activable.h"
#include <iostream>
#include <array>

using namespace std;


class Game {
public:
    Game();
    void what_in(int x, int y);
private:
    std::array<Activable,30> activables;
    std::tuple<int,int> conv_coord(int x, int y);
    void start_game();
};

#endif // GAME_H
