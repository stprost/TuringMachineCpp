
#include "output.h"

void Output::printTapes(string *arrayOfTapes, int numOfTapes, int *arrayOfPointers) {
    int count;
    cout << "Tapes:" << endl;
    output << "Tapes:" << endl;
    for (int i = 0; i < numOfTapes; i++) {
        count = 0;
        while (count < arrayOfTapes[i].size()) {
            if (count == arrayOfPointers[i]) {
                cout << "v";
                output << "v";
            }
            if (count != arrayOfPointers[i]) {
                cout << "_";
                output << "_";
            }
            count++;
        }
        cout << endl;
        output << endl;
        count = 0;
        while (arrayOfTapes[i][count] != '\0' && count < arrayOfTapes[i].size()) {
            cout << arrayOfTapes[i][count];
            output << arrayOfTapes[i][count];
            count++;
        }
        cout << endl;
        output << endl;
    }
}

void Output::printCommands(vector<vector<Cond>> &q,  int numOfTapes) {
    cout << "Commands:" << endl;
    output << "Commands:" << endl;
    for (int i = 1; i < q.size(); i++) {
        for (int j = 0; j < q[i].size() - 1; j++) {
            cout << i << "[";
            output  << i << "[";
            for (int k = 0; k < numOfTapes; k++) {
                cout << q[i][j].prevSymb[k];
                output << q[i][j].prevSymb[k];
                if (k != numOfTapes - 1) {
                    cout << ",";
                    output << ",";
                } else {
                    cout << "]";
                    output << "]";
                }
            }
            cout << q[i][j].nextCond << "[";
            output << q[i][j].nextCond << "[";
            for (int k = 0; k < numOfTapes; k++) {
                cout << q[i][j].nextSymb[k];
                output << q[i][j].nextSymb[k];
                if (k != numOfTapes - 1) {
                    cout << ",";
                    output << ",";
                } else {
                    cout << "]";
                    output << "]";
                }
            }
            cout << "[";
            output << "[";
            for (int k = 0; k < numOfTapes; k++) {
                cout << q[i][j].move[k];
                output << q[i][j].move[k];
                if (k != numOfTapes - 1) {
                    cout << ",";
                    output << ",";
                } else {
                    cout << "]";
                    output << "]";
                }
            }
            cout << endl;
            output << endl;
        }
    }
    cout << endl;
    output << endl;
}

void Output::printCommand(vector<vector<Cond>> &q, int numOfTapes, int row, int col) {
    cout << "Running command" << endl;
    output << "Running command" << endl;
    cout << row << "[";
    output << row << "[";
    for (int i = 0; i < numOfTapes; i++) {
        cout << q[row][col].prevSymb[i];
        output << q[row][col].prevSymb[i];
        if (i != numOfTapes - 1) {
            cout << ",";
            output << ",";
        } else {
            cout << "]";
            output << "]";
        }
    }
    cout << q[row][col].nextCond << "[";
    output << q[row][col].nextCond << "[";
    for (int i = 0; i < numOfTapes; i++) {
        cout << q[row][col].nextSymb[i];
        output << q[row][col].nextSymb[i];
        if (i != numOfTapes - 1) {
            cout << ",";
            output << ",";
        } else {
            cout << "]";
            output << "]";
        }
    }
    cout << "[";
    output << "[";
    for (int i = 0; i < numOfTapes; i++) {
        cout << q[row][col].move[i];
        output << q[row][col].move[i];
        if (i != numOfTapes - 1) {
            cout << ",";
            output << ",";
        } else {
            cout << "]";
            output << "]";
        }
    }
    cout << endl;
    output << endl;
}

void Output::print(string str){
    output << str;
}

void Output::println(string str){
    output << str << endl;
}

void Output::closeFile() {
    output.close();
}
