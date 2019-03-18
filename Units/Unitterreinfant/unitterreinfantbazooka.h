#ifndef UNITTERREINFANTBAZOOKA_H
#define UNITTERREINFANTBAZOOKA_H

#include "unitterreinfant.h"

class Unitterreinfantbazooka : public Unitterreinfant
{
public:
    static const int Cout =3000;
    Unitterreinfantbazooka(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERREINFANTBAZOOKA_H
