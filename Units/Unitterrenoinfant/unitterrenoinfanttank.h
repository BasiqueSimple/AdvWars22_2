#ifndef UNITTERRENOINFANTTANK_H
#define UNITTERRENOINFANTTANK_H


#include "unitterrenoinfant.h"

class Unitterrenoinfanttank : public Unitterrenoinfant
{
public:
    static const int Cout =7000;
    Unitterrenoinfanttank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTTANK_H
