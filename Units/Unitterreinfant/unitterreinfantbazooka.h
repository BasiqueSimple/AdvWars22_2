#ifndef UNITTERREINFANTBAZOOKA_H
#define UNITTERREINFANTBAZOOKA_H

#include "unitterreinfant.h"

class Unitterreinfantbazooka : public Unitterreinfant
{
public:
    static const int Cout =3000;
    static const int MovePoint =2;
    Unitterreinfantbazooka(int, int, std::string);
};

#endif // UNITTERREINFANTBAZOOKA_H
