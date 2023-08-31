#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Cow {
    int t1;
    int t2;
    int t3;
};

int main() {
    ifstream inFile;
    ofstream outFile;

    inFile.open("bcount.in");
    outFile.open("bcount.out");

    int arrNum, questionNum;
    inFile >> arrNum >> questionNum;

    vector<Cow> arrList(arrNum + 1);

    int type = 0;
    for (int i = 1; i <= arrNum; ++i) {
        inFile >> type;

        if (type == 1) {
            arrList[i].t1 = arrList[i - 1].t1 + 1;
            arrList[i].t2 = arrList[i - 1].t2;
            arrList[i].t3 = arrList[i - 1].t3;
        }
        else if (type == 2) {
            arrList[i].t1 = arrList[i - 1].t1;
            arrList[i].t2 = arrList[i - 1].t2 + 1;
            arrList[i].t3 = arrList[i - 1].t3;
        }
        else if (type == 3) {
            arrList[i].t1 = arrList[i - 1].t1;
            arrList[i].t2 = arrList[i - 1].t2;
            arrList[i].t3 = arrList[i - 1].t3 + 1;
        }
    }

    int begin, end;
    for (int i = 0; i < questionNum; ++i) {
        inFile >> begin >> end;

        char str[128];
        sprintf(str, "%d %d %d\n", arrList[end].t1 - arrList[begin - 1].t1, 
            arrList[end].t2 - arrList[begin - 1].t2, arrList[end].t3 - arrList[begin - 1].t3);

        outFile << str;
    }
}