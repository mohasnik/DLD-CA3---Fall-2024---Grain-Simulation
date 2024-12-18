#include "LFSR.h"


LFSR::LFSR() {
    this->reg = new uint80_t();
}


LFSR::LFSR(uint64_t seed) {
    this->reg = new uint80_t(seed, 0);
}

LFSR::LFSR(uint80_t seed) {
    this->reg = new uint80_t();
    *this->reg = seed;
}

LFSR::~LFSR() {
    delete this->reg;
}

uint8_t LFSR::F() {
    return ((*this->reg)[62] ^ (*this->reg)[51] ^ (*this->reg)[38] ^ (*this->reg)[23] ^ (*this->reg)[13] ^ (*this->reg)[0]) & 0x1;
}

uint8_t LFSR::execute() {
    uint16_t newEntry = this->F();
    uint8_t result = (*this->reg)[0];

    *this->reg  = *this->reg >> 1;
    
    *this->reg  = *this->reg | uint80_t(0, newEntry<<15);
    
    return result;
}