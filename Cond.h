
#ifndef TURINGMACHINEC_COND_H
#define TURINGMACHINEC_COND_H

#include <iostream>

using namespace std;

struct Cond {
    string prevSymb;
    string nextSymb;
    string move;
    int nextCond;
};


#endif //TURINGMACHINEC_COND_H
