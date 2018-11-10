
#ifndef TURINGMACHINEC_CONDITIONS_H
#define TURINGMACHINEC_CONDITIONS_H

#include "header.h"

class Conditions {
public:
    Conditions(ifstream &inputOne) : inputOne(inputOne) {
        q.resize(2);
    }

    void readCond();

    vector<vector<Cond>> getQ();

    int getNumOfTapes();


private:
    ifstream &inputOne;
    int numOfTapes;
    vector<vector<Cond>> q;
};


#endif //TURINGMACHINEC_CONDITIONS_H
