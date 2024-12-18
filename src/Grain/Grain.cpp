#include "Grain.h"


Grain::Grain() {
    lfsr = new LFSR();
    nfsr = new NFSR();
}

Grain::Grain(std::string seedHex) {
    if(seedHex.size() < 26) {
        seedHex = std::string(26 - seedHex.size(), '0') + seedHex;
    }

    std::string lfsrSeed = seedHex.substr(6, 26);
    std::string nfsrSeed = seedHex.substr(0, 6);

    printf("NFSR seed : %s\n", nfsrSeed.c_str());
    printf("LFSR seed : %s\n", lfsrSeed.c_str());

    this->lfsr = new LFSR(uint80_t(lfsrSeed, false));
    this->nfsr = new NFSR(uint24_t(nfsrSeed, false));


}

Grain::Grain(uint24_t nfsrSeed, uint80_t lfsrSeed) {
    lfsr = new LFSR(lfsrSeed);
    nfsr = new NFSR(nfsrSeed);
}

Grain::Grain(uint64_t nfsrSeed, uint64_t lfsrSeed) {
    lfsr = new LFSR(lfsrSeed);
    nfsr = new NFSR(nfsrSeed);
}

Grain::~Grain() {
    delete lfsr;
    delete nfsr;
}

uint8_t Grain::h() {
    uint24_t XN = this->nfsr->getValue();
    uint80_t XL = this->lfsr->getValue();

    return  (XL[0] ^ XL[3] ^ (XL[1] & XL[2]) ^ XN[0] ^ (XN[1] & XL[5]) ^ (XN[3] & XL[7]) ^ (XL[8] & XL[13] & XN[5]) ^ XN[2]) & 0x1;
}

uint8_t Grain::execute() {
    uint8_t outH = this->h();
    uint8_t outG = this->nfsr->g();
    uint8_t outF = this->lfsr->F();

    uint8_t lfsrSerOut = this->lfsr->manualExecute(outF);
    uint8_t nfsrSerOut = this->nfsr->manualExecute((outG ^ lfsrSerOut) & 0x1);

    return (outH ^ nfsrSerOut) & 0x1;

}