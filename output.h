
#ifndef TURINGMACHINEC_OUTPUT_H
#define TURINGMACHINEC_OUTPUT_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Cond.h"

using namespace std;

class Output {
public:
    void  printTapes(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers, ofstream &output);
    void printCommands(vector<vector<Cond>> &q, int maxQ, int numOfTapes, ofstream &output);
    void printCommand(vector<vector<Cond>> &q, int numOfTapes, int row, int col, ofstream &output);
};


#endif //TURINGMACHINEC_OUTPUT_H
