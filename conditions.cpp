#include "conditions.h"

void Conditions::readCond() {
    //считывание количества лент и состояний машины
    int prevQ, nextQ;
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
}

vector<vector<Cond>> Conditions::getQ(){
    return q;
}

int Conditions::getNumOfTapes(){
    return numOfTapes;
}
