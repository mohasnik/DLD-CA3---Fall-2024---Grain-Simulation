#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream> 
#include "uint80/uint80.h"
#include "Grain/Grain.h"
#include "stdio.h"

#define FILE_ADDRESS "./output/"
#define DEFAULT_ITEARATIONS 10

using namespace std;

template<typename T, typename V>
void executeUnit(T* unit, int iterations, string type) {
    string fileName = FILE_ADDRESS + type + ".log";
    ofstream file;
    
    file.open(fileName);


    for(int i = 0; i < iterations; i++) {
        V value = unit->getValue();
        int result = unit->execute();
        file << result << " , " << value << endl;
    }

    file.close();
}


void argumentParser(int argc, char* argv[]) {
    int i = 0;

    if(argc == 1) {
        cout <<  "No Arguments passed. Aborted." << endl;
        abort();
    }


    
    string type = argv[1];

    if(type == "-l") {
        int iterations = DEFAULT_ITEARATIONS;
        if(argc < 3)
            throw "Seed is not provided";
        
        std::string seed(argv[2]);
        printf("%s\n", seed.c_str());
        uint80_t value(seed, false);
        LFSR lfsr(value);
        
        if(argc > 3)
            iterations = std::stoi(argv[3]);
        
        executeUnit<LFSR, uint80_t>(&lfsr, iterations, "LFSR");
        
    }
    else if(type == "-n") {
        int iterations = DEFAULT_ITEARATIONS;
        
        if(argc < 3)
            throw "Seed is not provided";

        std::string seed(argv[2]);
        
        uint32_t seedInt = static_cast<uint32_t>(std::stoul(seed, nullptr, 16));
        NFSR nfsr(seedInt);
        
        if(argc > 3)
            iterations = std::stoi(argv[3]);
        
        
        executeUnit<NFSR, uint24_t>(&nfsr, iterations, "NFSR");
    }
    else if(type == "-g") {
        int iterations = DEFAULT_ITEARATIONS;

        if(argc < 3)
            throw "Seed is not provided.";
        
        std::string seed(argv[2]);

        Grain grain(seed);

        if(argc > 3)
            iterations = std::stoi(argv[3]);
        

        executeUnit<Grain, GrainValue>(&grain, iterations, "Grain");

    }
    else {
        cout << "Invalid Argument Passed! First  arguemnt must be \"-l\" for LFSR, \"-n\" for NFSR, or \"-g\" for Grain." << endl;
        abort();
    }

}


int main(int argc, char* argv[]) {

    argumentParser(argc, argv);


    // uint24_t nfsr("10eba8", false);
    // printf("%x\n", nfsr.value());


    // uint80_t x("00110110010111010101010101000011011010000001011101101010000010111000100100010101");

    // Grain grain(1127, 22169718);

    // for(int i = 0; i < 150; i++) {
    //     // cout << "nfsrReg : " << grain.getNFSRVal() << endl;
    //     // cout << "lfsrReg : " << grain.getLFSRVal() << endl;
    //     cout << "result : " << (int)(grain.execute()) << endl;
    // }



    return 0;
}