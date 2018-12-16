#ifndef ONMAP_H
#define ONMAP_H
#include <iostream>

using namespace std;

class OnMap{
public:
    OnMap(int, int);

    int getposy();
    int getposx();
    bool is_at(int,int);
private:
    int posX;
    int posY;
};

#endif // ONMAP_H
