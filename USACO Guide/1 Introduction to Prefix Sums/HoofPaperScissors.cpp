#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Cow {
    int HNum;
    int SNum;
    int PNum;

    inline int GetMax() {
        return max(HNum, max(SNum, PNum));
    }
};

inline Cow Minus(Cow &a, Cow &b) {
    Cow c;
    c.HNum = a.HNum - b.HNum;
    c.SNum = a.SNum - b.SNum;
    c.PNum = a.PNum - b.PNum;
    return c;
}

int main() {
    ifstream inFile;
    ofstream outFile;

    inFile.open("hps.in");
    outFile.open("hps.out");

    int arrNum;
    inFile >> arrNum;

    vector<Cow> arrList(arrNum + 1);

    char type = 0;
    for (int i = 1; i <= arrNum; ++i) {
        inFile >> type;

        if (type == 'H') {
            arrList[i].HNum = arrList[i - 1].HNum + 1;
            arrList[i].SNum = arrList[i - 1].SNum;
            arrList[i].PNum = arrList[i - 1].PNum;
        }
        else if (type == 'S') {
            arrList[i].HNum = arrList[i - 1].HNum;
            arrList[i].SNum = arrList[i - 1].SNum + 1;
            arrList[i].PNum = arrList[i - 1].PNum;
        }
        else if (type == 'P') {
            arrList[i].HNum = arrList[i - 1].HNum;
            arrList[i].SNum = arrList[i - 1].SNum;
            arrList[i].PNum = arrList[i - 1].PNum + 1;
        }
    }

    int maxWinNum = 0;
    for (int i = 0; i < arrNum + 1; ++i) {
        Cow &before = arrList[i];
        Cow after = Minus(arrList[arrNum], arrList[i]); 

        int currentMax = before.GetMax() + after.GetMax();
        maxWinNum = max(maxWinNum, currentMax);
    }

    outFile << maxWinNum << endl;
}