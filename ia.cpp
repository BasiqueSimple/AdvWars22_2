#include "ia.h"
#include <Buildings/building.h>
#include <windows.h>


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
            }
    }
     if (nbrUnits == 0){
                cout << "t'as pas encore de unit" << endl;
                //this->mainwindow->launch_event(game->click_on(15, 3, false), 15*1000/21, 3*1000/21);
                Building * building = game->getBuildingAt(15, 3);
                game->setLastBuilding( building);
                game->setCurrentPlayer((game->getPlayers())[1]);
                this->mainwindow->create_unit(INFANTRY, true);

            }
}
