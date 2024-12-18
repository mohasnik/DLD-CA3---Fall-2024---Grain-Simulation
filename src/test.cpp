#include <iostream>
#include <string>
#include <typeinfo>
#include "uint80/uint80.h"
#include "LFSR/LFSR.h"
#include "stdio.h"

using namespace std;




int main() {

    uint80_t x("00110110010111010101010101000011011010000001011101101010000010111000100100010101");


    LFSR lfsr(111698117298);
    printf("%x\n");

    for(int i = 0; i < 100; i++) {
        cout << "reg : " << (lfsr.getValue()) << endl;

        cout << "F result : " << (int)(lfsr.F()) << endl;

        cout << "Ser out : " << (int)(lfsr.execute()) << endl;
    }
    


    // printf("%lx\n", x.lowerValue());
    // printf("%x\n", x.upperValue());

    
    // printf("%lu\n", x.lowerValue());
    // printf("%u\n", x.upperValue());

    // uint16_t val = 1;
    // cout << (val << 15) << endl;

    // x = x | uint80_t(0, val<<15);

    // printf("%lu\n", x.lowerValue());
    // printf("%u\n", x.upperValue());
    
    // printf("%u\n", x[79]);

    // // cout << x.upperValue() << endl;



    return 0;
}