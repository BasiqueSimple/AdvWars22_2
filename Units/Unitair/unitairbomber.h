#ifndef UNITAIRBOMBER_H
#define UNITAIRBOMBER_H

#include "unitair.h"

class Unitairbomber : public Unitair
{
public:
    static int const Cout = 22000;
    Unitairbomber(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRBOMBER_H
