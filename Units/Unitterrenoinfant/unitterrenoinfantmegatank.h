#ifndef UNITTERRENOINFANTMEGATANK_H
#define UNITTERRENOINFANTMEGATANK_H


#include "unitterrenoinfant.h"

class Unitterrenoinfantmegatank : public Unitterrenoinfant
{
public:
    static const int Cout =28000;
    Unitterrenoinfantmegatank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTMEGATANK_H
