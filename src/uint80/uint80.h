#ifndef __UINT80__
#define __UINT80__

#include <cstdint>
#include <string>
#include <iomanip>
#include <iostream>
#include "stdio.h"

class uint80_t
{
    private:
        uint16_t upper;
        uint64_t lower;

    public:

    uint80_t();

    uint80_t(std::string bitStr, bool isBinary = true);

    uint80_t(uint64_t lower, uint16_t upper);

    uint80_t(const uint80_t& other);

    uint16_t upperValue() { return this->upper; }
    uint64_t lowerValue() { return this->lower; }

    uint80_t operator>>(int shiftAmnt);
    
    uint80_t operator<<(int shiftAmnt);
    
    uint80_t& operator>>=(int shiftAmnt);

    uint80_t& operator<<=(int shiftAmnt);

    uint8_t operator[](size_t index) const;

    uint80_t operator|(uint80_t other);

    friend std::ostream& operator<<(std::ostream& os, const uint80_t& obj);

    ~uint80_t();
};

std::ostream& operator<<(std::ostream& os, const uint80_t& obj);

#endif