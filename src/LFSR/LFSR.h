#ifndef __LFSR__
#define __LFSR__
#include "../uint80/uint80.h"

class LFSR
{
private:
    uint80_t* reg;
    

public:
    LFSR();
    LFSR(uint64_t seed);
    LFSR(uint80_t seed);

    ~LFSR();

    uint80_t getValue() { return *this->reg; }
    
    uint8_t F();

    uint8_t execute();

    uint8_t manualExecute(uint8_t serIn);
};



#endif