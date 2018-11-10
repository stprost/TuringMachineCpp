#include "checkArgs.h"
#include "conditions.h"
#include "tapes.h"
#include "output.h"
#include "step.h"
#include <cstring>

int main(int argc, char *argv[]) {
    ifstream inputOne;
    ifstream inputTwo;
    ofstream output;

    Output out(output);

    CheckArgs checkArgs(inputOne, inputTwo, output);
    checkArgs.checkArguments(argc, argv);

    Conditions conditions(inputOne);
    conditions.readCond();

    Tapes tapes(inputTwo, 2);
    tapes.readTapes();

    Step step(tapes.getArrayOfTapes(), conditions.getNumOfTapes(), tapes.getArrayOfPointers(), conditions.getQ(),
              checkArgs.getDebug());
    step.step(out);
    exit(0);
}

