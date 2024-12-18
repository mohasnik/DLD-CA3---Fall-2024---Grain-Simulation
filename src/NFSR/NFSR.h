#ifndef __NFSR__
#define __NFSR__
#include <cstdint>
#include "../uint24/uint24.h"


class NFSR
{
private:
    uint24_t* reg;
    

public:
    NFSR();
    NFSR(uint32_t seed);
    NFSR(uint24_t seed);

    ~NFSR();

    uint24_t getValue() { return *this->reg; }
    
    uint8_t g();

    uint8_t execute();

    uint8_t manualExecute(uint8_t serIn);
};


#endif