#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <iostream>
#include <Units/unit.h>
#include <vector>
#include <Buildings/building.h>



using namespace std;


class Game {
public:
    Game(int, string);
    int click_on(int, int);
    Unit* getSelectedUnit() const;
    vector<Unit *> * getUnits() const;
    vector<Terrain *> * getHighlited() const;
    void change_player();
    Terrain * getTerrainAt(int, int);
    Building * getBuildingAt(int, int);
    void setHighlighted(vector<Terrain*>*);
    std::vector<Building *> * getBuildings() const;
    Player* getCurrentPlayer() const;
    bool check_money(int, Player *);
    Unit *getLastMovedUnit() const;
    void checkUnits();
    bool checkGameOver();
    std::string getWinner() const;
    bool isHighlighted(int x, int y);
    Unit *getUnitAt(int x, int y);
    int getUnitCost(int type);
    void create_unit(int type);
    void moveSelectedCase(int direction);
    Terrain *getSelectedCase() const;
    Position *getPosBeforeMoved() const;
    int move_unit(int x, int y);
    void setSelectedUnit(Unit *value);
    void setLastBuilding(Building *value);
    Building *getLastBuilding() const;
    void setEarnings(int value);
    void conv_coord(int& x, int& y);
    void setCurrentPlayer(Player *value);

    int next_turn();
    Player * getThisPlayer() const;
    void setThisPlayer(string value);

    int getEarnings() const;
    bool areNextToEachOther(int x1, int y1, int x2, int y2);
    string getFirstPlayer() const;
    void setFirstPlayer(const string &value);

    Building *getSelectedBuilding() const;
    void setSelectedBuilding(Building *value);

private:
    std::vector<Terrain*> * highlighted;
    Terrain * selectedCase;
    std::vector<Terrain*> * terrains;
    std::vector<Unit*> * units;
    std::vector<Building*> * buildings;
    std::vector<Player*> players;
    Player* currentPlayer;
    std::string winner;
    Building* lastBuilding;
    Unit* selectedUnit;
    Unit* lastMovedUnit;
    int earnings;
    void start_game();
    void pay_player(Player*);
    void initiate_buildings();
    void initiate_terrains();
    Unit *make_unit(int type);
    Position* posBeforeMoved;
    string firstPlayer;
    Player * thisPlayer;
    Building* selectedBuilding;
};

#endif // GAME_H
