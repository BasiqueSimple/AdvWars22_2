#include "joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur(int id, std::string team, bool IA)
{
    this->id=id;
    this->team=team;
    this->est_IA=IA;
    this->argent=0;
}

std::string Joueur::getTeam(){
    return this->team;
}

void Joueur::gagne_argent(int rev)
{
    this->argent+=rev;
}

int Joueur::getargent()
{
    return this->argent;
}
