#ifndef UNITTERRENOINFANTMEGATANK_H
#define UNITTERRENOINFANTMEGATANK_H


#include "terrenoinfant.h"

class Megatank : public Terrenoinfant
{
public:
    static const int cost =28000;
    Megatank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTMEGATANK_H
