#include "uint24.h"

uint24_t::~uint24_t() {}

uint24_t::uint24_t() {
    this->val = 0;
}

uint24_t::uint24_t(std::string bitStr) {
    this->val = 0;

    for(int i = 0; i < 24; i++) {
        uint32_t val = bitStr[i] - '0';
        
        if(val != 0 && val != 1) {
            throw "Invalid char in bit stirng!";
        }
        else {
            this->val |= (val << (23 -i));          
        }
    }
    
}


uint24_t::uint24_t(uint32_t initVal) {
    this->val = initVal & ((1<<25) - 1);
}

uint24_t uint24_t::operator>>(int shiftAmnt) {
    return uint24_t(this->val>>shiftAmnt);
}

uint24_t uint24_t::operator<<(int shiftAmnt) {
    return uint24_t(this->val<<shiftAmnt);
}

uint24_t& uint24_t::operator>>=(int shiftAmnt) {
    this->val >>= shiftAmnt;
    return *this;
}

uint24_t& uint24_t::operator<<=(int shiftAmnt) {
    this->val = ((this->val << shiftAmnt) & ((1 << 25)-1));

    return *this;
}

uint8_t uint24_t::operator[](size_t index) const {
    if(index < 24)
        return (this->val >> (index)) & 0x1;
    else
        throw "Index Out of Range";
}


uint24_t uint24_t::operator|(uint24_t other) {
    return (this->val | other.val);
}

std::ostream& operator<<(std::ostream& os, const uint24_t& obj) {
    os << "0x" << std::hex << std::setw(4) << std::setfill('0') << obj.val;
    return os;
}