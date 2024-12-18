#ifndef __GRAIN__
#define __GRAIN__

#include "../LFSR/LFSR.h"
#include "../NFSR/NFSR.h"

class Grain
{
private:
    LFSR* lfsr;
    NFSR* nfsr;    
public:

    Grain();
    Grain(uint24_t nfsrSeed, uint80_t lfsrSeed);

    uint8_t h();


    uint8_t execute();

    ~Grain();
};




#endif