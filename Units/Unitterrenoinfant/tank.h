#ifndef UNITTERRENOINFANTTANK_H
#define UNITTERRENOINFANTTANK_H


#include "terrenoinfant.h"

class Tank : public Terrenoinfant
{
public:
    static const int cost =7000;
    Tank(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTTANK_H
