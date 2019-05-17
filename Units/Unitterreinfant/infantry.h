#ifndef UNITTERREINFANTINFANT_H
#define UNITTERREINFANTINFANT_H

#include "terreinfant.h"
#include <QPixmap>

class Infantry : public Terreinfant
{
public:
    Infantry(int, int, Game*, std::string);
    static int const cost = 1000;
    void resetMP();
};


#endif // UNITTERREINFANTINFANT_H
