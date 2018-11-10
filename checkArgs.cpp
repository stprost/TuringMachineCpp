#include "checkArgs.h"

void CheckArgs::printInfo() {
    string line;
    ifstream info("../textFiles/Info");
    if (info.is_open()) {
        while (!info.eof()) {
            getline(info, line);
            cout << line << endl;
        }
        info.close();
    } else cout << "Unable to open file with info";
}

void CheckArgs::checkArguments(int argc, char *argv[]) {
    if (argc == 1) {
        printInfo(); // информация о программе
        exit(0);
    }

    if ((argc == 5) && (strcmp(argv[4], "-a") == 0 || strcmp(argv[4], "-o") == 0) ||
        ((argc == 6) && (strcmp(argv[4], "-a") == 0 || strcmp(argv[4], "-o") == 0) && (strcmp(argv[5], "-p") == 0))) {

        inputOne.open(argv[1]);
        if (!inputOne.is_open()) {
            printf("error 100: Can not find first input file\n");
            exit(100);
        }

        inputTwo.open(argv[2]);
        if (!inputTwo.is_open()) {
            printf("error 101: Can not find second input file\n");
            exit(101);
        }

        output.open(argv[3]);
        if (!output.is_open()) {
            printf("Can not find output file\n");
        }
    }

    if (argc != 5) {
        if (argc != 6 || (argc == 6 && (strcmp(argv[5], "-p") != 0))) {
            printf("error 102: Wrong number of arguments\n");
            exit(102);
        }
    }

    debug = false;
    if (strcmp(argv[4], "-o") == 0) debug = true;
}

bool CheckArgs::getDebug() { return debug; }
