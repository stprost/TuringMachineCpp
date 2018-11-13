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

    if (argc == 6 && (strcmp(argv[5], "-p") == 0)) {
        checkArgs.printInputData(conditions.getQ(), conditions.getNumOfTapes(), tapes.getArrayOfTapes(),
                                 tapes.getArrayOfPointers(), out);
    }
    Step step(tapes.getArrayOfTapes(), conditions.getNumOfTapes(), tapes.getArrayOfPointers(), conditions.getQ(),
              checkArgs.getDebug());
    step.step(out);
    exit(0);
}

