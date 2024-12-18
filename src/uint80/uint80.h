#ifndef __UINT80__
#define __UINT80__

#include <cstdint>
#include <string>
#include <iomanip>
#include "stdio.h"

class uint80_t
{
    private:
        uint16_t upper;
        uint64_t lower;

    public:

    uint80_t();

    uint80_t(std::string bitStr);

    uint80_t(uint64_t lower, uint16_t upper);

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

std::ostream& operator<<(std::ostream& os, const uint80_t& obj) {
    os << "0x" << std::hex << std::setw(4) << std::setfill('0') << obj.upper;
    os << std::hex << std::setw(16) << std::setfill('0') << obj.lower;

    return os;
}

#endif