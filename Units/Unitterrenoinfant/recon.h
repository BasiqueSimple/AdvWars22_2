#ifndef UNITTERRENOINFANTRECON_H
#define UNITTERRENOINFANTRECON_H


#include "terrenoinfant.h"

class Recon : public Terrenoinfant
{
public:
    static const int cost =4000;
    Recon(int, int, Game*, std::string);
    void resetMP();
};

#endif // UNITTERRENOINFANTRECON_H
