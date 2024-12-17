#ifndef __LFSR__
#define __LFSR__
#include "../uint80/uint80.h"

class LFSR
{
private:
    uint80_t* reg;
    
    uint8_t F();

public:
    LFSR();
    LFSR(uint64_t seed);

    uint8_t execute();
    ~LFSR();
};



#endif