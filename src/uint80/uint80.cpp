#include "uint80.h"

uint80_t::~uint80_t() {}

uint80_t::uint80_t() {
    this->lower = 0;
    this->upper = 0;
}

uint80_t::uint80_t(std::string bitStr) {
    this->upper = 0;
    this->lower = 0;

    for(int i = 0; i < 80; i++) {
        uint64_t val = bitStr[i] - '0';
        
        if(val != 0 && val != 1) {
            throw "Invalid char in bit stirng!";
        }
        else {
            if(i  < 16) {
                uint16_t v = val;
                this->upper |= (v << (15 -i));
            }
            else
                this->lower |= (val << (63- (i-16)));
        }
    }
    
}

uint80_t::uint80_t(uint64_t lower, uint16_t upper) {
    this->lower = lower;
    this->upper = upper;
}

// uint80_t uint80_t::operator>>(int shiftAmnt) {
//     uint64_t lower = this->lower;
//     uint16_t upper = this->upper;
//     lower >>= shiftAmnt;
//     uint64_t upperSlice = (upper & (1 << (shiftAmnt+1) - 1));
//     upper >>= shiftAmnt;

//     upperSlice <<= (64-shiftAmnt);
//     lower |= upperSlice;

//     return uint80_t(lower, upper);
// }

uint80_t uint80_t::operator>>(int shiftAmnt) {
    if (shiftAmnt >= 80) {
        // If the shift amount is >= 80, the entire number becomes zero.
        return uint80_t(0, 0);
    }

    uint64_t newLower = 0;
    uint16_t newUpper = 0;

    if (shiftAmnt >= 64) {
        // If shiftAmnt >= 64, the lower part will be entirely replaced by shifted upper bits.
        int upperShift = shiftAmnt - 64;
        newLower = (this->upper >> upperShift);
        newUpper = 0;  // All bits in upper are shifted out.
    } else {
        // Regular shift within 80 bits.
        uint64_t shiftedLower = this->lower >> shiftAmnt;
        uint64_t upperSlice = (this->upper & ((1ULL << shiftAmnt) - 1)) << (64 - shiftAmnt);
        newLower = shiftedLower | upperSlice;
        newUpper = this->upper >> shiftAmnt;
    }

    return uint80_t(newLower, newUpper);
}


uint80_t& uint80_t::operator>>=(int shiftAmnt) {
    if (shiftAmnt >= 80) {
        // If shift amount >= 80, all bits are shifted out, result is zero.
        this->upper = 0;
        this->lower = 0;
    } else if (shiftAmnt >= 64) {
        // If shift amount >= 64, lower takes bits from upper, and upper becomes 0.
        int upperShift = shiftAmnt - 64;
        this->lower = (this->upper >> upperShift);
        this->upper = 0;
    } else {
        // Regular shift: shift lower and propagate overflow bits from upper.
        uint64_t lowerShifted = this->lower >> shiftAmnt;
        uint64_t upperSlice = (this->upper & ((1ULL << shiftAmnt) - 1)) << (64 - shiftAmnt);

        this->lower = lowerShifted | upperSlice;
        this->upper >>= shiftAmnt;
    }

    return *this;  // Return reference to the modified object
}


uint80_t uint80_t::operator<<(int shiftAmnt) {
    if (shiftAmnt >= 80) {
        // If the shift amount is >= 80, all bits are shifted out, result is 0.
        return uint80_t(0, 0);
    }

    uint64_t newLower = 0;
    uint16_t newUpper = 0;

    if (shiftAmnt >= 64) {
        // If shiftAmnt >= 64, lower becomes 0, and upper takes bits from lower.
        int lowerShift = shiftAmnt - 64;
        newUpper = (this->lower << lowerShift);
        newLower = 0;
    } else {
        // Regular shift: shift lower and propagate overflow bits into upper.
        uint64_t lowerShifted = this->lower << shiftAmnt;
        uint16_t upperOverflow = (this->lower >> (64 - shiftAmnt)) & 0xFFFF;

        newLower = lowerShifted;
        newUpper = (this->upper << shiftAmnt) | upperOverflow;
    }

    return uint80_t(newLower, newUpper);
}


uint80_t& uint80_t::operator<<=(int shiftAmnt) {
    if (shiftAmnt >= 80) {
        // If shift amount >= 80, all bits are shifted out, result is zero.
        this->upper = 0;
        this->lower = 0;
    } else if (shiftAmnt >= 64) {
        // If shift amount >= 64, lower becomes 0, and upper takes bits from lower.
        int lowerShift = shiftAmnt - 64;
        this->upper = (this->lower << lowerShift);
        this->lower = 0;
    } else {
        // Regular shift: shift lower and propagate overflow bits into upper.
        uint16_t upperOverflow = (this->lower >> (64 - shiftAmnt)) & 0xFFFF;

        this->lower <<= shiftAmnt;
        this->upper = (this->upper << shiftAmnt) | upperOverflow;
    }

    return *this;  // Return reference to the modified object
}


uint8_t uint80_t::operator[](size_t index) const {
    if(index < 64) {
        return (this->lower >> index) & 0x1;
    }
    else if(index < 80) {
        return (this->upper >> (index-64)) & 0x1;    
    }
    else {
        throw "Index Out of Range!";
    }
}

uint80_t uint80_t::operator|(uint80_t other) {
    return uint80_t(this->lower | other.lower, this->upper | other.upper);
    
}

std::ostream& operator<<(std::ostream& os, const uint80_t& obj) {
    os << "0x" << std::hex << std::setw(4) << std::setfill('0') << obj.upper;
    os << std::hex << std::setw(16) << std::setfill('0') << obj.lower;

    return os;
}