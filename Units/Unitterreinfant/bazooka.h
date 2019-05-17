#ifndef UNITTERREINFANTBAZOOKA_H
#define UNITTERREINFANTBAZOOKA_H

#include "terreinfant.h"

class Bazooka : public Terreinfant
{
public:
    static const int cost =3000;
    Bazooka(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERREINFANTBAZOOKA_H
