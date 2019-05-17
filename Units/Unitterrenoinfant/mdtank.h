#ifndef UNITTERRENOINFANTMDTANK_H
#define UNITTERRENOINFANTMDTANK_H

#include "terrenoinfant.h"

class Mdtank : public Terrenoinfant
{
public:
    static const int cost =16000;
    Mdtank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTMDTANK_H
