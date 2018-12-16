#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Joueur{
public:
    Joueur(int, std::string, bool);
    std::string getTeam();
    void payer(int);
    void gagne_argent(int);
    int getargent();
private:
    std::string team;
    int id;
    int argent;
    bool est_IA;
};

#endif // PLAYER_H
