#ifndef IA_H
#define IA_H
#include "game.h"
#include <Buildings/building.h>


class MainWindow;
class Game;
class Building;
class Unit;

class ia {
public :
    ia(std::string type, MainWindow* mainwindow);

    std::string getType() const;
    void play_path_find(Game* game);
    Terrain* distanceMin(std::vector<Terrain*>* cases, int goalX, int goalY);
    void play_greedy(Game* game);
    int closestBuildingToCapture(std::vector<Building*> ToCapture, Unit* unit);

private :
    std::string type;
    MainWindow* mainwindow;
    std::vector<Building*> ToCapture;
};

#endif // IA_H
