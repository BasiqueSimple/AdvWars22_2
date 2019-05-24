#include "player.h"
#include <iostream>
using namespace std;

Player::Player(int id, std::string team, ia* IA)
{
    this->id=id;
    this->team=team;
    this->IA = IA;
    this->argent=0;
}

std::string Player::getTeam(){
    return this->team;
}

void Player::payer(int a)
{
    this->argent=--a;
}
void Player::gagne_argent(int rev)
{
    this->argent+=rev;
}

int Player::getargent()
{
    return this->argent;
}

ia *Player::getIA() const
{
    return IA;
}
