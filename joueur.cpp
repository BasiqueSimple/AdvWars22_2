#include "joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur(int id, std::string team, bool IA)
{
    this->id=id;
    this->team=team;
    this->est_IA=IA;
}

std::string Joueur::getTeam(){
    return this->team;
}
