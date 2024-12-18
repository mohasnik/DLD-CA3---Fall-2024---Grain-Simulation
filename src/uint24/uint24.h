#ifndef __UINT24__
#define __UINT24__

#include <cstdint>
#include <string>
#include <iomanip>
#include <iostream>
#include "stdio.h"

class uint24_t
{
    private:
        uint32_t val;

    public:

    uint24_t();

    uint24_t(std::string bitStr, bool isBinary);

    uint24_t(uint32_t initVal);

    uint16_t value() { return this->val; }
    

    uint24_t operator>>(int shiftAmnt);
    
    uint24_t operator<<(int shiftAmnt);
    
    uint24_t& operator>>=(int shiftAmnt);

    uint24_t& operator<<=(int shiftAmnt);

    uint8_t operator[](size_t index) const;

    uint24_t operator|(uint24_t other);

    friend std::ostream& operator<<(std::ostream& os, const uint24_t& obj);

    ~uint24_t();
};

std::ostream& operator<<(std::ostream& os, const uint24_t& obj);

#endif