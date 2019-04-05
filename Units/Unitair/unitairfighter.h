#ifndef UNITAIRFIGHTER_H
#define UNITAIRFIGHTER_H

#include "unitair.h"

class Unitairfighter : public Unitair
{
public:
    static int const Cout = 20000;
    Unitairfighter(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRFIGHTER_H
