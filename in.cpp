#include "header.h"

void inf() {
    printf("Turing simulator\nto run the program type in command line\nTuring.exe input1.txt input2.txt output.txt -a/-o"
           " [-p]\n-a runs the program,\n-o runs debug,\n-p gives you information about your input data."
           "\ninput1.txt should contain such commands:\na[x1,x2,...,xn]  b[y1,y2,...,yn][D1,D2,...,Dn], where a and b are the numbers of temporary and next states of machine\n"
           "[x1,x2,...,xn] and [y1,y2,...,yn] are the symbols on the tape\n[D1,D2,...,Dn] are the direction of move (L - left, R - right, _ - no move, "
           "S - stop).\ninput2.txt should contain the initial tape in such structure:\n__v___\n100001\n___v__\n100321\nif "
           "you run debug\ns - one step,\nb - break,\nf - follow the program in standart mode.\nExample:"
           "\ninput1.txt\n2\n1[0,0] 2[1,1][R,R]\n2[1,1] 3[_,0][_,R]\n2[0,1] 2[0,1][L,_]\n3[_,0] 2[1,1][R,S]\ninput2.txt\n__v___\n100001\n_v____\n"
           "101010\noutput.txt\nTapes:\n__v___\n100001\n_v____\n101010\nRunning command\n1[0,0] 2[1,1][R,R]\nTapes:\n___v__\n101001\n__v___\n111010\n"
           "Running command\n2[0,1] 2[0,1][L,_]\nTapes:\n__v___\n101001\n__v___\n111010\nRunning command\n2[1,1] 3[_,0][_,R]\nTapes:\n__v___\n"
           "10_001\n___v__\n110010\nRunning command\n3[_,0] 2[1,1][R,S]\nTapes:\n___v__\n101001\n___v__\n110110\nEnd of program");
}
In::In(int argc, char *argv[]) {

    ifstream inputOne;
    ifstream inputTwo;
    ofstream output;
    if (argc == 1) {
        inf(); // информация о программе
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

    //считывание количества лент и состояний машины
    int prevQ, nextQ, ret, numOfTapes, rowQ;
    string temp;
    char *token, *last;

    string str;

    getline(inputOne, str);
    numOfTapes = stoi(str);
    if (numOfTapes <= 0) {
        printf("error 200: Wrong number of tapes");
        exit(200);
    }
    int len = numOfTapes * 2;
    vector<vector<Cond>> q(2);
    int maxQ = 1;
    for (int i = 1; i < maxQ + 1; i++) {
        q[i].resize(1);
    }
    char *strPrevSymb = new char[len];
    char *strNextSymb = new char[len];
    char *strMove = new char[len];
    char tempLine[6 + 6 * numOfTapes];
    while (!inputOne.eof()) {
        inputOne.getline(tempLine, 9 + 6 * numOfTapes);
        token = strtok_r(tempLine, " []", &last);
        prevQ = strtol(token, NULL, 0);
        if (prevQ == 0) {
            printf("error 201: Incorrect input conditions data");
            exit(201);
        }
        token = strtok_r(NULL, " []", &last);
        if (strlen(token) != len - 1) {
            printf("error 201: Incorrect input conditions data");
            exit(201);
        }
        strcpy(strPrevSymb, token);
        token = strtok_r(NULL, " []", &last);
        nextQ = strtol(token, NULL, 0);
        token = strtok_r(NULL, " []", &last);
        if (strlen(token) != len - 1) {
            printf("error 201: Incorrect input conditions data");
            exit(201);
        }
        strcpy(strNextSymb, token);
        token = strtok_r(NULL, " []", &last);
        if (strlen(token) != len - 1) {
            printf("error 201: Incorrect input conditions data");
            exit(201);
        }
        strcpy(strMove, token);
        token = strtok_r(NULL, " []\n", &last);
        if (token != NULL) {
            printf("error 201: Incorrect input conditions data");
            exit(201);
        }

        if (nextQ > maxQ) {
            q.resize(nextQ + 1);
            for (int i = maxQ + 1; i <= nextQ; i++) {
                q[i].resize(1);
            }
            maxQ = nextQ;
        }


        int n = prevQ; //строка
        int m = q[prevQ].size() - 1; //столбец
        q[n][m].nextCond = nextQ;
        int i = 0;
        token = strtok_r(strPrevSymb, " ,", &last);
        while (token != NULL) {
            q[n][m].prevSymb += token;
            token = strtok_r(NULL, " ,", &last);
            i++;
        }
        i = 0;
        token = strtok_r(strNextSymb, " ,", &last);
        while (token != NULL) {
            q[n][m].nextSymb += token;
            token = strtok_r(NULL, " ,", &last);
            i++;
        }
        i = 0;
        token = strtok_r(strMove, " ,", &last);
        while (token != NULL) {
            q[n][m].move += token;
            token = strtok_r(NULL, " ,", &last);
            i++;
        }
        q[prevQ].resize(q[prevQ].size() + 1);
    }
    delete[]strPrevSymb;
    delete[]strNextSymb;
    delete[]strMove;
    inputOne.close();

    //считывание начального состояния лент
    string *arrayOfTapes = new string[numOfTapes], tempTape;
    int *arrayOfPointers = new int[numOfTapes];
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


    Output out;
    if (argc == 6 && (strcmp(argv[5], "-p")) == 0) {
        out.printTapes(arrayOfTapes, numOfTapes, arrayOfPointers, output);
        out.printCommands(q, maxQ, numOfTapes, output);

    }
    bool debug = false;
    if (strcmp(argv[4], "-o") == 0) debug = true;
    Step(arrayOfTapes, numOfTapes, arrayOfPointers, q, debug, out, output);
}

