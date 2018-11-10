
#include "tapes.h"

void Tapes::readTapes() {
    string tempTape;
    int count;
    bool flag;
    for (int i = 0; i < numOfTapes; i++) {
        getline(inputTwo, tempTape);
        if (tempTape == "empty" || tempTape == "Empty") {
            arrayOfPointers[i] = 0;
            arrayOfTapes[i] = "_";
            continue;
        }
        count = 0;
        flag = false;
        while (tempTape[count] != '\0') {
            if (tempTape[count] == 'v' || tempTape[count] == 'V') {
                flag = true;
                arrayOfPointers[i] = count;
                break;
            } else if (tempTape[count] != '_') {
                printf("error 202: Incorrect input tapes data");
                exit(202);
            }
            count++;
        }
        if (!flag) {
            printf("error 202: Incorrect input tapes data");
            exit(202);
        }
        getline(inputTwo, tempTape);
        arrayOfTapes[i] += tempTape;
    }
}

string* Tapes::getArrayOfTapes(){
    return arrayOfTapes;
}

int* Tapes::getArrayOfPointers(){
    return arrayOfPointers;
}