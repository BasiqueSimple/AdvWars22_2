#ifndef UNITTERRENOINFANTRECON_H
#define UNITTERRENOINFANTRECON_H


#include "unitterrenoinfant.h"

class Unitterrenoinfantrecon : public Unitterrenoinfant
{
public:
    static const int MovePoint =8;
    static const int Cout =4000;
    Unitterrenoinfantrecon(int, int, Game*, std::string);
};

#endif // UNITTERRENOINFANTRECON_H
