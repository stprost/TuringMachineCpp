
#ifndef TURINGMACHINEC_CHECKDATA_H
#define TURINGMACHINEC_CHECKDATA_H

#include "header.h"

class CheckArgs {
public:
    CheckArgs(ifstream &inputOne, ifstream &inputTwo, ofstream &output) : inputOne(inputOne), inputTwo(inputTwo),
                                                                          output(output) {}

    void checkArguments(int, char **);

    bool getDebug();

private:
    ifstream &inputOne;
    ifstream &inputTwo;
    ofstream &output;
    bool debug;

    void printInfo();
};


#endif //TURINGMACHINEC_CHECKDATA_H
