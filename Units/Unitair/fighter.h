#ifndef UNITAIRFIGHTER_H
#define UNITAIRFIGHTER_H

#include "unitair.h"

class Fighter : public Unitair
{
public:
    static int const cost = 20000;
    Fighter(int, int, Game*, std::string);
    void resetMP();
};


#endif // UNITAIRFIGHTER_H
