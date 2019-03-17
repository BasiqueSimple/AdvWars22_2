#ifndef POSITION_H
#define POSITION_H


class Position
{
    int x;
    int y;
public:
    Position(int, int);
    int getPosX();
    int getPosY();
    bool isAt(int, int);
    void setPosY(int y);
    void setPosX(int x);
};

#endif // POSITION_H
