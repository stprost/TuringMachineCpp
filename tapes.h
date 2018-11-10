
#ifndef TURINGMACHINEC_TAPES_H
#define TURINGMACHINEC_TAPES_H

#include "header.h"

class Tapes {
public:
    Tapes(ifstream &inputTwo, int numOfTapes):inputTwo(inputTwo), numOfTapes(numOfTapes){
        arrayOfTapes = new string[numOfTapes];
        arrayOfPointers = new int[numOfTapes];
    }
    void readTapes();
    string* getArrayOfTapes();
    int* getArrayOfPointers();
private:
    ifstream &inputTwo;
    string *arrayOfTapes;
    int *arrayOfPointers;
    int numOfTapes;
};


#endif //TURINGMACHINEC_TAPES_H
