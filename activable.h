#ifndef CELL_H
#define CELL_H
#include "onmap.h"

#include <iostream>


class Activable : public OnMap
{
public:
    virtual void activate();
    virtual ~Activable();
    Activable(int x, int y);
    void setTeam(std::string team);
    std::string getTeam();
private:
    std::string team;
};

#endif // CELL_H
