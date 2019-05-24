#define dimx 21
#define dimy 17

#include "game.h"
#include <tuple>
#include <array>
#include <iostream>
#include <vector>
#include <Units/Unitair/bcopter.h>
#include <Units/Unitair/fighter.h>
#include <Units/Unitair/bomber.h>
#include <Buildings/airport.h>
#include <Buildings/factory.h>
#include <Buildings/city.h>
#include <Units/Unitterreinfant/bazooka.h>
#include <Units/Unitterreinfant/infantry.h>
#include <Units/Unitterrenoinfant/antiair.h>
#include <Units/Unitterrenoinfant/mdtank.h>
#include <Units/Unitterrenoinfant/megatank.h>
#include <Units/Unitterrenoinfant/neotank.h>
#include <Units/Unitterrenoinfant/recon.h>
#include <Units/Unitterrenoinfant/tank.h>

#define NOTHING 0
#define MOVE 5
#define FACTORY 1
#define AIRPORT 2
#define ATTACK 3
#define MERGE 4
#define MOVEANDCAPTURE 6

#define INFANTRY 0
#define BAZOOKA 1
#define BCOPTER 2
#define BOMBER 3
#define FIGHTER 4
#define ANTIAIR 5
#define MDTANK 6
#define MEGATANK 7
#define NEOTANK 8
#define RECON 9
#define TANK 10

#define LEFT 16777234
#define UP 16777235
#define RIGHT 16777236
#define DOWN 16777237


using namespace std;

Game::Game(int earnings, string firstPlayer, ia* IAOS, ia* IABM)
{
    this->earnings = earnings;
    this->firstPlayer = firstPlayer;
    this->start_game(IAOS, IABM);
}

// SETTERS
void Game::setHighlighted(vector<Terrain *> *casesAcces)
{
    this->highlighted = casesAcces;
}

void Game::setCurrentPlayer(Player *value)
{
    currentPlayer = value;
}

void Game::setEarnings(int value)
{
    earnings = value;
}

void Game::setLastBuilding(Building *value)
{
    lastBuilding = value;
}

void Game::setSelectedUnit(Unit *value)
{
    selectedUnit = value;
}

void Game::setThisPlayer(string value)
{
    if( value == "os") thisPlayer = players[0] ;
    else if( value == "bm" ) thisPlayer = players[1];
}

void Game::setFirstPlayer(const string &value)
{
    firstPlayer = value;
}

// GETTERS
Player* Game::getCurrentPlayer() const {
    return this->currentPlayer;
}

std::string Game::getWinner() const
{
    return winner;
}

Position *Game::getPosBeforeMoved() const
{
    return posBeforeMoved;
}

Unit* Game::getLastMovedUnit() const
{
    return lastMovedUnit;
}

Unit* Game::getSelectedUnit() const {
    return this->selectedUnit;
}

std::vector<Building *> * Game::getBuildings() const {
    return buildings;
}

vector<Unit*> * Game::getUnits() const {
    return this->units;
}

Terrain *Game::getSelectedCase() const
{
    return selectedCase;
}

int Game::getEarnings() const
{
    return earnings;
}

string Game::getFirstPlayer() const
{
    return firstPlayer;
}

Player * Game::getThisPlayer() const
{
    return thisPlayer;
}

Building *Game::getLastBuilding() const
{
    return lastBuilding;
}

vector<Terrain *>* Game::getHighlited() const {
    return this->highlighted;
}
// -------------------------------------------------------------

void Game::start_game(ia* IAOS, ia* IABM){
    // On crée les joueurs
    players = *new std::vector<Player*>;

    players.push_back(new Player(0,"os", IAOS));
    players.push_back(new Player(1,"bm", IABM));

    // On crée les terrains
    initiate_terrains();

    // On crée les bâtiments
    initiate_buildings();

    units = new std::vector<Unit*>;
    setHighlighted(new vector<Terrain*>);
    selectedCase = getTerrainAt(4,14);

    // On désigne le premier joueur et on le rémunère (doit être après initiate_buildings() )
    if( firstPlayer == "os" ) currentPlayer = players[0];
    else if( firstPlayer == "bm" ) currentPlayer = players[1];
    pay_player(currentPlayer);
}

void Game::initiate_terrains()
{
    this->terrains = new std::vector<Terrain*>;

    //On cree les pipes

    int pipes[20][2] = {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{0,1},{0,2},
                       {0,3},{14,16},{15,16},{16,16},{17,16},{18,16},{19,16},{20,16},
                       {20,13},{20,14},{20,15}};

    for (int v = 0 ; v < 20 ; v++)
       {
            this->terrains->push_back(new Pipe(pipes[v][0],pipes[v][1]));
       }

    //On cree les forêts

    int forests[40][2] = {{7,0},{13,1},{15,1},{19,1},{3,2},{11,2},{13,3},{3,4},{18,4},
                       {13,5},{20,5},{0,6},{4,6},{9,6},{14,6},{18,6},{7,7},
                       {11,7},{3,8},{5,8},{15,8},{17,8},{9,9},{13,9},{20,10},{0,11},{7,11},{2,12},{17,12},
                        {7,13},{9,14},{17,14},{1,15},{5,15},{7,15},{13,16},
                        {2,10},{6,10},{11,10},{16,10}};

    for (int v = 0 ; v < 40 ; v++)
       {
            this->terrains->push_back(new Forest(forests[v][0],forests[v][1]));
       }

    //On cree les plaines

    int plains[112][2] = {{8,0},{14,0},{15,0},{16,0},{2,1},{3,1},{4,1},{6,1},{11,1},
                       {12,1},{14,1},{16,1},{17,1},{18,1},{2,2},{8,2},{9,2},
                       {10,2},{12,2},{13,2},{14,2},{15,2},{19,2},{6,3},{7,3},{14,3},{17,3},{20,3},{4,4},
                        {5,4},{6,4},{13,4},{17,4},{3,5},{4,5},{5,5},{14,5},{16,5},{17,5},{18,5},
                        {19,5},{1,6},{3,6},{7,6},{13,6},{17,6},{0,7},{3,7},{4,7},{9,7},{10,7},{12,7},{13,7},{16,7},{17,7},{4,8},{16,8},
                        {3,9},{4,9},{7,9},{8,9},{10,9},{11,9},{16,9},{17,9},{20,9},{3,10},{7,10},{13,10},
                        {17,10},{19,10},{1,11},{2,11},{3,11},{4,11},{6,11},
     {15,11},{16,11},{17,11},{3,12},{7,12},{14,12},{15,12},{16,12},{0,13},{3,13},{6,13},{13,13},{14,13},
    {1,14},{5,14},{6,14},{7,14},{8,14},{10,14},{11,14},{12,14},
    {18,14},{2,15},{3,15},{4,15},{6,15},{8,15},{9,15},{14,15},{16,15},{17,15},{18,15},{4,16},
     {5,16},{6,16},{12,16}};

    for (int v = 0 ; v < 112 ; v++)
       {
            this->terrains->push_back(new Plain(plains[v][0],plains[v][1]));
       }

    //On cree les montagnes

    int mountains[60][2] = {{9,0},{17,0},{5,1},{1,2},{4,2},{20,2},{1,3},{8,3},{9,3},
                       {10,3},{11,3},{12,3},{7,4},{8,4},{9,4},{10,4},{12,4},
                       {0,5},{6,5},{7,5},{9,5},{10,5},{11,5},{12,5},{5,6},{6,6},{10,6},{11,6},{19,6},
                           {5,7},{15,9},{1,10},{9,10},{10,10},{14,10},{15,10},{8,11},
                           {9,11},{10,11},{11,11},{13,11},{14,11},{20,11},{8,12},{10,12},{11,12},{12,12},{13,12},{8,13},
                           {9,13},{10,13},{11,13},{12,13},{19,13},{0,14},{16,14},{19,14},
                           {15,15},{3,16},{11,16}};

    for (int v = 0 ; v < 60 ; v++)
       {
            this->terrains->push_back(new Mountain(mountains[v][0],mountains[v][1]));
       }

    //On cree les routes

    int routes[60][2] = {{10,0},{11,0},{12,0},{7,1},{8,1},{9,1},{5,2},{6,2},{17,2},
                       {18,2},{3,3},{4,3},{16,3},{18,3},{19,3},{15,4},{19,4},
                       {15,5},{8,6},{15,6},{1,7},{8,7},{14,7},{15,7},{1,8},{6,8},{7,8},{8,8},{9,8},
                           {10,8},{11,8},{12,8},{13,8},{14,8},{19,8},{5,9},{6,9},
                           {12,9},{19,9},{5,10},{12,10},{5,11},{1,12},{5,12},{1,13},{2,13},{4,13},{16,13},{17,13},
                           {2,14},{3,14},{14,14},{15,14},{11,15},{12,15},{13,15},{8,16},
                           {9,16},{10,16}};

    for (int v = 0 ; v < 60 ; v++)
       {
            this->terrains->push_back(new Route(routes[v][0],routes[v][1]));
       }

    //On cree les plages

    int beaches[6][2] = {{18,0},{19,0},{20,1},{0,15},{1,16},{2,16}};

    for (int v = 0 ; v < 6 ; v++)
       {
            this->terrains->push_back(new Beach(beaches[v][0],beaches[v][1]));
       }

    //On cree les reefs

    int reefs[2][2] = {{0,16},{20,0}};

    for (int v = 0 ; v < 2 ; v++)
       {
            this->terrains->push_back(new Reef(reefs[v][0],reefs[v][1]));
       }

    //On cree les ponts

    int bridges[4][2] = {{2,6},{2,7},{18,9},{18,10}};

    for (int v = 0 ; v < 4 ; v++)
       {
            this->terrains->push_back(new Bridge(bridges[v][0],bridges[v][1]));
       }

    //On cree les rivières

    int rivers[18][2] = {{0,4},{1,4},{2,4},{2,5},{2,8},{0,9},{1,9},{2,9},{0,10},
                       {20,6},{18,7},{19,7},{20,7},{18,8},{18,11},{18,12},{19,12},
                       {20,12}};

    for (int v = 0 ; v < 18 ; v++)
       {
            this->terrains->push_back(new River(rivers[v][0],rivers[v][1]));
       }
}

void Game::initiate_buildings()
{
    this->buildings = new std::vector<Building*>;

    //On crée les batiments neutres
    int cities[26][2] = {{1,1},{4,10},{8,5},{2,3},{5,3},{8,10},{1,5},{6,7},{9,12},
                         {0,12},{6,12},{10,15},{7,16},{10,1},{11,4},{12,6},{12,11},
                         {13,0},{14,4},{14,9},{15,13},{16,6},{18,13},{19,15},{19,11},{20,4}};

    for (int v = 0 ; v < 26 ; v++)
       {
            Building* building = new City(cities[v][0],cities[v][1], "neutre");
            this->buildings->push_back(building);
            this->terrains->push_back(building);
       }

    int airports[2][2] = {{20,8},{0,8}};

    for (int v = 0 ; v < 2 ; v++)
       {
            Building* building = new Airport(airports[v][0],airports[v][1], "neutre");
            this->buildings->push_back(building);
            this->terrains->push_back(building);
       }

    int factories[2][2] = {{7,2},{13,14}};

    for (int v = 0 ; v < 2 ; v++)
       {
            Building *building = new Factory(factories[v][0],factories[v][1], "neutre");
            this->buildings->push_back(building);
            this->terrains->push_back(building);
       }

    //On cree les batiments OS
    Building* building = new City(4,14, "os");
    this->buildings->push_back(building);
    this->terrains->push_back(building);

    int factories2[2][2] = {{4,12},{5,13}};

    for (int v = 0 ; v < 2 ; v++)
       {
        Building * building = new Factory(factories2[v][0], factories2[v][1], "os");
        this->buildings->push_back(building);
        this->terrains->push_back(building);
       }

    //On cree les batiments BM

    building = new City(16,2, "bm");
    this->buildings->push_back(building);
    this->terrains->push_back(building);

    int factories3[2][2] = {{16,4},{15,3}};

    for (int v = 0 ; v < 2 ; v++)
       {
            building = new Factory(factories3[v][0], factories3[v][1], "bm");
            this->buildings->push_back(building);
            this->terrains->push_back(building);
       }
}

void Game::conv_coord(int& x, int& y){
    int width = 1000;
    int size_img = width/21;
    x = x/size_img;
    y = y/size_img;
}

bool Game::isHighlighted(int x, int y)
{
    for(vector<Terrain*>::iterator it = this->highlighted->begin(); it != this->highlighted->end(); ++it){
        if((*it)->isAt(x,y)){
            return true;
        }
    }
    return false;
}

int Game::move_unit(int x, int y)
{
    if( (isHighlighted(x, y) || currentPlayer != thisPlayer) &&
            (getUnitAt(x, y) == 0 or getUnitAt(x, y) == selectedUnit )){
        highlighted->clear();
        posBeforeMoved = new Position(selectedUnit->getPosX(), selectedUnit->getPosY());
        selectedUnit->move(x, y);
        lastMovedUnit = selectedUnit;
        if( Building * building = getBuildingAt(x, y) ) {
            if(building->getTeam() != currentPlayer->getTeam() && (selectedUnit->getUnitType() == INFANTRY || selectedUnit->getUnitType() == BAZOOKA)){
                building->setPointCapture(20);
                this->lastBuilding = building;
                return MOVEANDCAPTURE;
            }
        }
        return MOVE;
    }
    else{
        highlighted->clear();
        return NOTHING;
    }

}

int Game::click_on(int x, int y){

        conv_coord(x, y);
    cout << "click on" << endl;
    // Si c'est pour opérer un déplacement
    if( !this->highlighted->empty() ){
        return move_unit(x, y);
    }

    // Si c'est une unit
    if( Unit * unit = getUnitAt(x, y) ){
        // Soit de son équipe
        if( unit->getTeam() == currentPlayer->getTeam() ){
            if ( areNextToEachOther(x, y, lastMovedUnit->getPosX(), lastMovedUnit->getPosY()) &&
                 !lastMovedUnit->hasFinished() && lastMovedUnit->getTeam() == currentPlayer->getTeam()){
                selectedUnit = unit;
                return MERGE;
            }
            else {
                unit->activate();
                selectedUnit = unit;
                return NOTHING;
            }
        }
        // Sinon ça ne peut qu'être pour attaquer
        else if( areNextToEachOther(x, y, lastMovedUnit->getPosX(), lastMovedUnit->getPosY()) &&
                 !lastMovedUnit->hasFinished() && lastMovedUnit->getTeam() == currentPlayer->getTeam()){
            selectedUnit = unit;
            return ATTACK;
        }
    }

    // Si c'est un building
    if( Building * building = getBuildingAt(x, y) ) {
        if(building->getTeam() == currentPlayer->getTeam()){
            this->lastBuilding = building;
            if (building->getTerrainType() == "factory"){
                return FACTORY;
            }
            else if (building->getTerrainType() == "airport"){
                return AIRPORT;
            }
        }
    }

    return NOTHING;
}

bool Game::areNextToEachOther(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && (y1 == y2-1 || y1 == y2+1)) || (y1 == y2 && (x1 == x2-1 || x1 == x2+1));
}

void Game::pay_player(Player* j){
    int total_earnings = 0;
    for(vector<Building*>::iterator it = this->buildings->begin(); it != this->buildings->end(); ++it)
    {
        if((*it)->getTeam() == j->getTeam()){
            total_earnings += this->earnings;
        }
    }
    j->gagne_argent(total_earnings);
}

int Game::next_turn(){
    change_player();
    for(vector<Unit*>::iterator it = this->units->begin(); it != this->units->end(); ++it){
        if( (*it)->getTeam() == this->currentPlayer->getTeam() ){
            (*it)->resetMP();
            (*it)->resetHasMoved();
            (*it)->setTourFini(false);
            int x = (*it)->getPosX();
            int y = (*it)->getPosY();
            if( this->getBuildingAt(x,y) ){
                Building * batiment = this->getBuildingAt(x,y);
                if( batiment->getTeam() != this->currentPlayer->getTeam() && ((*it)->getUnitType()==INFANTRY || (*it)->getUnitType()==BAZOOKA) && batiment->getEnCapture() ){
                    batiment->reducePointCapture((*it)->getPV(), this->currentPlayer->getTeam());
                    cout << "plus que " << batiment->getPointCapture() << " points" << endl;
                } else {
                  (*it)->etrerepare(*batiment);
                }
                            }

        }
    }
    this->pay_player(this->currentPlayer);
    cout << "Joueur " << this->currentPlayer->getTeam() << " à toi de jouer !" <<endl;
    cout << "Tu as " << this->currentPlayer->getargent() << " d'argent." <<endl;
    if (this->currentPlayer->getIA()->getType() == "path_find"){
        cout << "hello" << endl;
        this->currentPlayer->getIA()->play_path_find(this);

    }
}

void Game::change_player(){
    if(this->currentPlayer == players[0]){
        this->currentPlayer = players[1];
    }
    else {
        this->currentPlayer = players[0];
    }
}

Terrain * Game::getTerrainAt(int x, int y)
{
    for(vector<Terrain*>::iterator it = this->terrains->begin(); it != this->terrains->end(); ++it){
        if((*it)->isAt(x,y)){
            return *it;
        }
    }
    return 0;
}

Building * Game::getBuildingAt(int x, int y)
{
    for(vector<Building*>::iterator it = this->buildings->begin(); it != this->buildings->end(); ++it){
        if((*it)->isAt(x,y)){
            return *it;
        }
    }
    return 0;
}

Unit * Game::getUnitAt(int x, int y)
{
    for(vector<Unit*>::iterator it = this->units->begin(); it != this->units->end(); ++it){
        if((*it)->isAt(x,y)){
            return *it;
        }
    }
    return 0;
}

bool Game::check_money(int cost, Player * player){
    if(cost<=player->getargent()){
        player->gagne_argent(-cost);
        cout << "Plus que $" << player->getargent() << endl;
        return true;
    }
    else {
        return false;
    }
}

void Game::checkUnits(){
    for(vector<Unit*>::iterator it = this->getUnits()->begin(); it != this->getUnits()->end(); ++it){
        if((*it)->getPV() <= 0){
            //delete (*it); PROBLEME AVEC LES DESTRUCTORS
            this->getUnits()->erase(it);
            break;
        }
    }
}

bool Game::checkGameOver(){
    if (this->players[1]->getIA()->getType() == "path_find"){
        Building* building = getBuildingAt(4, 14);
        if (building->getTeam() == players[1]->getTeam())
        {
            this->winner = "bm";
            return true;
        }
    }

    int osUnitsCount = 0;
    int bmUnitsCount = 0;
    int osBuildingsCount = 0;
    int bmBuildingsCount = 0;

    for(vector<Unit*>::iterator it = this->getUnits()->begin(); it != this->getUnits()->end(); ++it){
        if((*it)->getTeam() == "os"){
            osUnitsCount++;
        }
        else if((*it)->getTeam() == "bm"){
            bmUnitsCount++;
        }
    }
    for(vector<Building*>::iterator it = this->buildings->begin(); it != this->buildings->end(); ++it){
        if((*it)->getTeam() == "os" && ((*it)->getTerrainType() == "airport" || (*it)->getTerrainType() == "factory")){
            osBuildingsCount++;
        }
        else if((*it)->getTeam() == "bm" && ((*it)->getTerrainType() == "airport" || (*it)->getTerrainType() == "factory")){
            bmBuildingsCount++;
        }
    }
    if(osUnitsCount == 0 && osBuildingsCount == 0){
        this->winner = "bm";
        return true;
    }
    else if(bmUnitsCount == 0 && bmBuildingsCount == 0){
        this->winner = "os";
        return true;
    }
    return false;
}

void Game::create_unit(int type){
    Player* player = currentPlayer;
    if( check_money(getUnitCost(type), player) ){
        bool isFirstUnit = units->empty();

        Unit * new_unit = make_unit(type);
        units->push_back(new_unit);

        if ( isFirstUnit ){
            lastMovedUnit = new_unit;
        }
    }
    else {
        cout << "Tu n'as pas assez d'argent." << endl;
    }
}

Unit * Game::make_unit(int type){
    switch (type)
    {
    case INFANTRY:
        return new Infantry(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case BAZOOKA:
        return new Bazooka(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case BCOPTER:
        return new Bcopter(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case BOMBER:
        return new Bomber(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case FIGHTER:
        return new Fighter(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case ANTIAIR:
        return new Antiair(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case MDTANK:
        return new Mdtank(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case MEGATANK:
        return new Megatank(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case NEOTANK:
        return new Neotank(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case RECON:
        return new Recon(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    case TANK:
        return new Tank(lastBuilding->getPosX(), lastBuilding->getPosY(), this, currentPlayer->getTeam());
    default:
        return 0;
    }
}

Building *Game::getSelectedBuilding() const
{
    return selectedBuilding;
}

void Game::setSelectedBuilding(Building *value)
{
    selectedBuilding = value;
}

std::vector<Player *> Game::getPlayers() const
{
    return players;
}

int Game::getUnitCost(int type){
    switch (type)
    {
    case INFANTRY:
        return Infantry::cost;
    case BAZOOKA:
        return Bazooka::cost;
    case BCOPTER:
        return Bcopter::cost;
    case BOMBER:
        return Bomber::cost;
    case FIGHTER:
        return Fighter::cost;
    case ANTIAIR:
        return Antiair::cost;
    case MDTANK:
        return Mdtank::cost;
    case MEGATANK:
        return Megatank::cost;
    case NEOTANK:
        return Neotank::cost;
    case RECON:
        return Recon::cost;
    case TANK:
        return Tank::cost;
    default:
        return 0;
    }
}

void Game::moveSelectedCase(int direction){
    switch ( direction )
    {
        case RIGHT:
            if( Terrain * terrain = getTerrainAt(selectedCase->getPosX()+1, selectedCase->getPosY()) )
                selectedCase = terrain;
            break;
        case LEFT:
            if( Terrain * terrain = getTerrainAt(selectedCase->getPosX()-1, selectedCase->getPosY()) )
                selectedCase = terrain;
            break;
        case UP:
            if( Terrain * terrain = getTerrainAt(selectedCase->getPosX(), selectedCase->getPosY()-1) )
                selectedCase = terrain;
            break;
        case DOWN:
            if( Terrain * terrain = getTerrainAt(selectedCase->getPosX(), selectedCase->getPosY()+1) )
            selectedCase = terrain;
            break;
    }
}


