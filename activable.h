#ifndef CELL_H
#define CELL_H
#include <iostream>


class Activable {
public:
    virtual void activate();
    virtual ~Activable();
};

#endif // CELL_H
