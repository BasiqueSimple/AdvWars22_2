#ifndef UNITTERRENOINFANTAINTIAIR_H
#define UNITTERRENOINFANTAINTIAIR_H

#include "unitterrenoinfant.h"

class Unitterrenoinfantantiair : public Unitterrenoinfant
{
public:
    static const int Cout =8000;
    Unitterrenoinfantantiair(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTAINTIAIR_H
