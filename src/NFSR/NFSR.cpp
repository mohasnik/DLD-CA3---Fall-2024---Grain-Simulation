#include "NFSR.h"


NFSR::NFSR() {
    this->reg = new uint24_t();
}


NFSR::NFSR(uint32_t seed) {
    this->reg = new uint24_t(seed);
}

NFSR::NFSR(uint24_t seed) {
    this->reg = new uint24_t();
    *this->reg = seed;
}

NFSR::~NFSR() {
    delete this->reg;
}

uint8_t NFSR::g() {
    return (
            (*this->reg)[0] ^ (*this->reg)[5] ^ (*this->reg)[6] ^ (*this->reg)[9] ^ (*this->reg)[17] ^ (*this->reg)[22] 
            ^ ((*this->reg)[4] & (*this->reg)[13]) 
            ^ ((*this->reg)[8] & (*this->reg)[16]) 
            ^ ((*this->reg)[5] & (*this->reg)[11] & (*this->reg)[14]) 
            ^ ((*this->reg)[2] & (*this->reg)[5] & (*this->reg)[8] & (*this->reg)[10])
            )  & 0x1;
}

uint8_t NFSR::execute() {
    uint16_t newEntry = this->g();
    uint8_t result = (*this->reg)[0];

    *this->reg = *this->reg >> 1;
    
    *this->reg = *this->reg | uint24_t(newEntry<<23);
    
    return result;
}

uint8_t NFSR::manualExecute(uint8_t serIn) {
    uint8_t result = (*this->reg)[0];

    *this->reg = *this->reg >> 1;
    
    *this->reg = *this->reg | uint24_t(serIn<<23);
    
    return result;
}