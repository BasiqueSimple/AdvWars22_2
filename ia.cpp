#include "ia.h"
#include <Buildings/building.h>
#include <math.h>
#include "mainwindow.h"


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
#define SKEY 83
#define SPACE 32
#define ENTER 16777220


ia::ia(std::string type, MainWindow* mainwindow){
    this->type = type;
    this->mainwindow = mainwindow;

}

std::string ia::getType() const
{
    return type;
}


void ia::play_path_find(Game* game){
    cout << "bouuuuu" << endl;
    int nbrUnits = 0;
    for(vector<Unit*>::iterator it = game->getUnits()->begin(); it != game->getUnits()->end(); ++it){
            if( (*it)->getTeam() == game->getCurrentPlayer()->getTeam() ){
                nbrUnits +=1;
                (*it)->activate();
                Terrain* CaseToMoveTo = this->distanceMin((*it)->getCasesAcces(), 4, 14);
                int goalX = CaseToMoveTo->getPosX();
                int goalY = CaseToMoveTo->getPosY();
                (*it)->move(goalX, goalY);
                if ((*it)->getPosX() == 4 && (*it)->getPosY() == 14){
                    Building * building = game->getBuildingAt(4, 14);
                    building->setEnCapture(true);
                }
                game->next_turn();
            }
    }
     if (nbrUnits == 0){
                cout << "t'as pas encore de unit" << endl;
                Building * building = game->getBuildingAt(15, 3);
                game->setLastBuilding( building);
                game->setCurrentPlayer((game->getPlayers())[1]);
                this->mainwindow->create_unit(INFANTRY, true);
                game->next_turn();

            }
}

Terrain* ia::distanceMin(vector<Terrain*>* cases, int goalX, int goalY){
    int i = 0;
    double distMin = 23567;
    int numCase;
    for (vector<Terrain*>::iterator it = (*cases).begin(); it != (*cases).end(); ++it){
        int sourceX = (*it)->getPosX();
        int sourceY = (*it)->getPosY();
        double distance = sqrt(pow(goalX-sourceX, 2)+pow(goalY-sourceY, 2));
        cout << "dist = " << distance << endl;
        if (i == 0){
           distMin = distance;
           numCase = i;
        }
        else if(distance < distMin){
            distMin = distance;
            numCase = i;
        }
        i += 1;
    }
    return (*cases)[numCase];
}

void ia::play_greedy(Game* game){
    for (vector<Unit*>::iterator ite = game->getUnits()->begin(); ite != game->getUnits()->end(); ++ite){
        if ((*ite)->getTeam() == game->getCurrentPlayer()->getTeam()){
            cout << "1. je suis dans ton équipe"<< endl;
            bool hasMoved = false;
            (*ite)->activate();
            for (vector<Building*>::iterator it = game->getBuildings()->begin(); it != game->getBuildings()->end(); ++it){
               if ((*it)->getTeam() != game->getCurrentPlayer()->getTeam() && game->getUnitAt((*it)->getPosX(), (*it)->getPosY()) == 0 ) {
                   cout << "2. le batiment n'est pas a toi et il n'y a personne dessus "  << endl;
                   (this->ToCapture).push_back((*it));
                }
            }

            int numBuilding = this->closestBuildingToCapture(this->ToCapture, (*ite));
            Building* closestBuilding = (this->ToCapture)[numBuilding];
            int goalX = closestBuilding->getPosX();
            int goalY = closestBuilding->getPosY();

            for (vector<Terrain*>::iterator iter = (*ite)->getCasesAcces()->begin(); iter != (*ite)->getCasesAcces()->end(); ++iter){
                if(goalX == (*iter)->getPosX() && goalY == (*iter)->getPosY()){
                    cout << "3. tu peux direct bouger vers un bat à capt" << endl;
                    (*ite)->move((*iter)->getPosX(), (*iter)->getPosY());
                    closestBuilding->setEnCapture(true);
                    hasMoved = true;
                    break;
                }
            }

            if (! hasMoved){
                cout << "4. Tu n'as pas encore bougé" << endl;
                Terrain* CaseToMoveTo = this->distanceMin((*ite)->getCasesAcces(), closestBuilding->getPosX(), closestBuilding->getPosY());
                int goalX = CaseToMoveTo->getPosX();
                int goalY = CaseToMoveTo->getPosY();
                (*ite)->move(goalX, goalY);
            }
            this->ToCapture.clear();
        }
    }
                /*if ((*iter)->getTerrainType() == "factory" || (*iter)->getTerrainType() == "city" || (*iter)->getTerrainType() == "airport"){
                    int x = (*iter)->getPosX();
                    int y = (*iter)->getPosY();
                    Building* building = game->getBuildingAt(x, y);
                    if(building->getTeam() != game->getCurrentPlayer()->getTeam()){
                        (*ite)->move(x, y);
                        building->setEnCapture(true);
                    }
                }*/
    cout << "j'ai fini de bouger tout le monde" << endl;

    for (vector<Building*>::iterator it = game->getBuildings()->begin(); it != game->getBuildings()->end(); ++it){
        if ((*it)->getTeam() == game->getCurrentPlayer()->getTeam() && (*it)->getTerrainType() == "factory" && game->getCurrentPlayer()->getargent() >= 1000 ){
            cout << "6. tu peux produire" << endl;
            game->setLastBuilding((*it));
            game->setCurrentPlayer((game->getPlayers())[1]);
            this->mainwindow->create_unit(INFANTRY, true);
        }
    }
    game->next_turn() ;
}

int ia::closestBuildingToCapture(vector<Building*> ToCapture, Unit* unit){
    int sourceX = unit->getPosX();
    int sourceY = unit->getPosY();
    int i = 0;
    int numBuilding;
    double distMin = 23567;
    for (vector<Building*>::iterator it = ToCapture.begin(); it != ToCapture.end(); ++it){
        int goalX = (*it)->getPosX();
        int goalY = (*it)->getPosY();
        double distance = sqrt(pow(goalX-sourceX, 2)+pow(goalY-sourceY, 2));
        cout << "dist = " << distance << endl;
        if (i == 0){
           distMin = distance;
           numBuilding = i;
        }
        else if(distance < distMin){
            distMin = distance;
            numBuilding = i;
        }
        i += 1;
    }

    return numBuilding;
}
