#ifndef IA_H
#define IA_H
#include "game.h"
#include <Buildings/building.h>

class MainWindow;
class Game;
class Building;

class ia {
public :
    ia(std::string type, MainWindow* mainwindow);

    std::string getType() const;
    void play_path_find(Game* game);
    Terrain* distanceMin(std::vector<Terrain*>* cases, int goalX, int goalY);

private :
    std::string type;
    MainWindow* mainwindow;
};

#endif // IA_H
