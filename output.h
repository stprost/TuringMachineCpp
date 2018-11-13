
#ifndef TURINGMACHINEC_OUTPUT_H
#define TURINGMACHINEC_OUTPUT_H

#include "header.h"

class Output {
public:
    Output(ofstream &output):output(output){}
    void  printTapes(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers);
    void printCommands(vector<vector<Cond>> &q, int numOfTapes);
    void printCommand(vector<vector<Cond>> &q, int numOfTapes, int row, int col);
    void print(string str);
    void println(string str);
    void closeFile();

private:
    ofstream &output;
};


#endif //TURINGMACHINEC_OUTPUT_H
