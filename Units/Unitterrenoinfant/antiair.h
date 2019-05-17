#ifndef UNITTERRENOINFANTAINTIAIR_H
#define UNITTERRENOINFANTAINTIAIR_H

#include "terrenoinfant.h"

class Antiair : public Terrenoinfant
{
public:
    static const int cost =8000;
    Antiair(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTAINTIAIR_H
