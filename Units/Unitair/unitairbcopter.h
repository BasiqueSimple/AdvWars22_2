#ifndef UNITAIRBCOPTER_H
#define UNITAIRBCOPTER_H

#include "unitair.h"

class Unitairbcopter : public Unitair
{
public:
    static const int Cout =9000;
    Unitairbcopter(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRBCOPTER_H
