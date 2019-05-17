#ifndef UNITTERRENOINFANTNEOTANK_H
#define UNITTERRENOINFANTNEOTANK_H


#include "terrenoinfant.h"

class Neotank : public Terrenoinfant
{
public:
    static const int cost =22000;
    Neotank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTNEOTANK_H
