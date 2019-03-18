#ifndef UNITTERRENOINFANTNEOTANK_H
#define UNITTERRENOINFANTNEOTANK_H


#include "unitterrenoinfant.h"

class Unitterrenoinfantneotank : public Unitterrenoinfant
{
public:
    static const int Cout =22000;
    Unitterrenoinfantneotank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTNEOTANK_H
