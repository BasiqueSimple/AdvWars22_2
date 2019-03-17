#ifndef UNITTERRENOINFANTMDTANK_H
#define UNITTERRENOINFANTMDTANK_H

#include "unitterrenoinfant.h"

class Unitterrenoinfantmdtank : public Unitterrenoinfant
{
public:
    static const int Cout =16000;
    static const int MovePoint =5;
    Unitterrenoinfantmdtank(int, int, Game*, std::string);
};

#endif // UNITTERRENOINFANTMDTANK_H
