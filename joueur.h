#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Joueur{
public:
    Joueur(int, std::string, bool);
    std::string getTeam();
private:
    std::string team;
    int id;
    bool est_IA;
};

#endif // PLAYER_H
