//
// Created by pk on 13.10.2018.
//

#ifndef TURINGMACHINEC_STEP_H
#define TURINGMACHINEC_STEP_H

#include "header.h"

class Step {
public:
    Step(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers, vector<vector<Cond>> q,
         bool debug) : arrayOfTapes(arrayOfTapes), arrayOfPointers(arrayOfPointers), q(q), numOfTapes(numOfTapes),
                       debug(debug) {}

    void step(Output out);

private:
    vector<vector<Cond>> q;
    string *arrayOfTapes;
    int *arrayOfPointers;
    int numOfTapes;
    bool debug;
};


#endif //TURINGMACHINEC_STEP_H
