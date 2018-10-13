
#include "header.h"


Step::Step(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers, vector<vector<Cond>> &q,
           bool debug, Output out, ofstream &output) {
    int quit = 0, count;
    int tempCond = 1;
    char tempTapeSymb[numOfTapes];
    bool flag, stop = false;
    out.printTapes(arrayOfTapes, numOfTapes, arrayOfPointers, output);
    while (quit != 1000) {
        flag = false;
        //поиск подходящего состояния
        for (int i = 0; i < q[tempCond].size() - 1; i++) {
            count = 0;
            for (int j = 0; j < numOfTapes; j++) {
                if (arrayOfTapes[j][arrayOfPointers[j]] != q[tempCond][i].prevSymb[j]) {
                    continue;
                }
                count++;
            }
            if (count == numOfTapes) {
                flag = true;
                for (int j = 0; j < numOfTapes; j++) {
                    arrayOfTapes[j][arrayOfPointers[j]] = q[tempCond][i].nextSymb[j];
                    switch (q[tempCond][i].move[j]) {
                        case 'L':
                            arrayOfPointers[j]--;
                            break;
                        case 'R':
                            arrayOfPointers[j]++;
                            break;
                    }
                    if (arrayOfPointers[j] == arrayOfTapes[j].size()) {
                        arrayOfTapes[j].resize(arrayOfTapes[j].size() + 1);
                        arrayOfTapes[j][arrayOfTapes[j].size() - 1] = '_';
                    }
                    if (arrayOfPointers[j] < 0) {
                        printf("error 401: Head index out of bounds\n");
                        exit(401);
                    }
                    if (q[tempCond][i].move[j] == 'S') {
                        stop = true;
                    }
                }
                out.printCommand(q, numOfTapes, tempCond, i, output);
                out.printTapes(arrayOfTapes, numOfTapes, arrayOfPointers, output);
                tempCond = q[tempCond][i].nextCond;
                break;
            }
        }
        if (!flag) {
            cout <<"error 404: Condition not found";
            exit(404);
        }
        if (stop) {
            cout << "End of program" << endl;
            output << "End of program" << endl;
            break;
        }
        if (debug) { //если выбран режим отладки
            char comand[2];
            while (1) {
                cin >> comand;
                fflush(stdin); //очистка буфера
                if (!strcmp(comand, "b")) {
                    cout << "Program break" << endl;
                    output.close();
                    exit(403);
                }
                if (!strcmp(comand, "s")) {
                    break;
                }
                if (!strcmp(comand, "f")) {
                    debug = false;
                    break;
                } else printf("No such instruction. Enter other\n");
            }
        }
        quit++;
        if (quit == 1000) {
            printf("error 402: Runtime error\n");
            exit(402);
        }
    }
}

