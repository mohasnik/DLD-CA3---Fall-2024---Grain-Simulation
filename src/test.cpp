#include <iostream>
#include <string>
#include <typeinfo>
#include "uint80/uint80.h"
#include "LFSR/LFSR.h"
#include "NFSR/NFSR.h"
#include "stdio.h"

using namespace std;




int main() {

    uint80_t x("00110110010111010101010101000011011010000001011101101010000010111000100100010101");


    // LFSR lfsr(111698117298);
    // LFSR lfsr(10);
    

    NFSR nfsr(10);
    printf("\n");

    for(int i = 0; i < 100; i++) {
        cout << "reg : " << (nfsr.getValue()) << endl;

        cout << "F result : " << (int)(nfsr.g()) << endl;

        cout << "Ser out : " << (int)(nfsr.execute()) << endl;
    }
    



    return 0;
}