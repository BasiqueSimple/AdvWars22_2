#ifndef UNITTERRENOINFANTMEGATANK_H
#define UNITTERRENOINFANTMEGATANK_H


#include "unitterrenoinfant.h"

class Unitterrenoinfantmegatank : public Unitterrenoinfant
{
public:
    static const int Cout =28000;
    static const int MovePoint =4;
    Unitterrenoinfantmegatank(int, int, Game*, std::string);
};

#endif // UNITTERRENOINFANTMEGATANK_H
