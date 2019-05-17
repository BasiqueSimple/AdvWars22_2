#ifndef UNITAIRBOMBER_H
#define UNITAIRBOMBER_H

#include "unitair.h"

class Bomber : public Unitair
{
public:
    static int const cost = 22000;
    Bomber(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRBOMBER_H
