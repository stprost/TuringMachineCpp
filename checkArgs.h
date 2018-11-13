
#ifndef TURINGMACHINEC_CHECKDATA_H
#define TURINGMACHINEC_CHECKDATA_H

#include "header.h"

class CheckArgs {
public:
    CheckArgs(ifstream &inputOne, ifstream &inputTwo, ofstream &output) : inputOne(inputOne), inputTwo(inputTwo),
                                                                          output(output) {}

    void checkArguments(int, char **);

    bool getDebug();

    void printInputData(vector<vector<Cond>> q, int numOfTapes, string *arrayOfTapes, int *arrayOfPointers, Output out);

private:
    ifstream &inputOne;
    ifstream &inputTwo;
    ofstream &output;
    bool debug;

    void printInfo();
};


#endif //TURINGMACHINEC_CHECKDATA_H
