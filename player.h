#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <ia.h>

class ia;

using namespace std;

class Player{
public:
    Player(int, std::string, ia*);
    std::string getTeam();
    void payer(int);
    void gagne_argent(int);
    int getargent();
    ia *getIA() const;

private:
    std::string team;
    int id;
    int argent;
    ia* IA;
};

#endif // PLAYER_H
