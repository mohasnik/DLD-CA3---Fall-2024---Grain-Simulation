#ifndef __GRAIN__
#define __GRAIN__

#include "../LFSR/LFSR.h"
#include "../NFSR/NFSR.h"

typedef struct GrainValue {
    uint80_t lfsrVal;
    uint24_t nfsrVal;

    friend std::ostream& operator<<(std::ostream& os, const GrainValue& obj) {
        os << obj.lfsrVal << " , " << obj.nfsrVal;
        return os;
    }
} GrainValue;

class Grain
{
private:
    LFSR* lfsr;
    NFSR* nfsr;    
public:

    Grain();
    Grain(std::string seedHex);
    Grain(uint24_t nfsrSeed, uint80_t lfsrSeed);
    Grain(uint64_t nfsrSeed, uint64_t lfsrSeed);
    

    uint8_t h();

    uint24_t getNFSRVal() { return this->nfsr->getValue(); }
    uint80_t getLFSRVal() { return this->lfsr->getValue(); }

    uint8_t execute();

    GrainValue getValue() { return {lfsr->getValue(), nfsr->getValue()}; }


    ~Grain();
};






#endif