#include "game.h"
#include <tuple>
#include <array>
#include <iostream>
#include <vector>
#include <Units/Unitair/unitairbcopter.h>

using namespace std;

Game::Game()
{
    std::vector<Unit*> activables;
    this->activables = activables;
    this->start_game();
}

tuple<int,int> Game::conv_coord(int x, int y){
    int width = 1000;
    int size_img = width/21;
    cout << x/size_img << endl;
    return make_tuple(x/size_img, y/size_img);
}

void Game::what_in(int x, int y){
    tie(x, y) = conv_coord(x, y);
    if(this->activables[0]->getposx()==x){
            this->activables[0]->activate();
    }
}

void Game::start_game(){
    this->activables.push_back(new Unitairbcopter(3,3));
}
