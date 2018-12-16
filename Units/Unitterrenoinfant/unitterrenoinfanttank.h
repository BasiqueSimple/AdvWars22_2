#ifndef UNITTERRENOINFANTTANK_H
#define UNITTERRENOINFANTTANK_H


#include "unitterrenoinfant.h"

class Unitterrenoinfanttank : public Unitterrenoinfant
{
public:
    static const int Cout =7000;
    static const int MovePoint =6;
    Unitterrenoinfanttank(int, int, std::string);
};

#endif // UNITTERRENOINFANTTANK_H
