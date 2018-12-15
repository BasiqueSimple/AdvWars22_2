#include "game.h"
#include <tuple>
#include <iostream>
#include "activable.h"

using namespace std;

Game::Game(){
}

tuple<int,int> Game::conv_coord(int x, int y){
    int width = 1000;
    int size_img = width/21;
    cout << x/size_img << endl;
    return make_tuple(x/size_img, y/size_img);
}

void Game::what_in(int x, int y){
    tie(x, y) = conv_coord(x, y);
/*    for(int a=0;a<this->activables.size();++a){
        if(this->activables[a].posX==x){
            this->Unit(activables[a]).activate();
        }
    }*/
}

void Game::start_game(){
    //this->clickables[0]= new Joueur();
}
