#ifndef UNITAIRBCOPTER_H
#define UNITAIRBCOPTER_H

#include "unitair.h"

class Bcopter : public Unitair
{
public:
    static const int cost =9000;
    Bcopter(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRBCOPTER_H
