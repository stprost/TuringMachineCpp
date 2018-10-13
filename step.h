//
// Created by pk on 13.10.2018.
//

#ifndef TURINGMACHINEC_STEP_H
#define TURINGMACHINEC_STEP_H

#include <iostream>

using namespace std;

class Step {
public:
    Step(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers, vector<vector<Cond>> &q,
         bool debug, Output out, ofstream &output);
};


#endif //TURINGMACHINEC_STEP_H
