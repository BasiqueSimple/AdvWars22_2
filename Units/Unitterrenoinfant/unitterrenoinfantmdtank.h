#ifndef UNITTERRENOINFANTMDTANK_H
#define UNITTERRENOINFANTMDTANK_H

#include "unitterrenoinfant.h"

class Unitterrenoinfantmdtank : public Unitterrenoinfant
{
public:
    static const int Cout =16000;
    Unitterrenoinfantmdtank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTMDTANK_H
