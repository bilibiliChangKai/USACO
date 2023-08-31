#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;

    inFile.open("div7.in");
    outFile.open("div7.out");

    int arrNum;
    inFile >> arrNum;

    vector<int> arrList(arrNum + 1);
    arrList[0] = 0;

    int minIndex[7];
    int maxIndex[7];
    for (int i = 0; i < 7; ++i) {
        minIndex[i] = arrNum + 2;
        maxIndex[i] = 0;
    }

    int id = 0;
    for (int i = 1; i <= arrNum; ++i) {
        inFile >> id;

        int nextID = (id + arrList[i - 1]) % 7;
        minIndex[nextID] = min(minIndex[nextID], i);
        maxIndex[nextID] = max(maxIndex[nextID], i);

        arrList[i] = nextID;
    }

    int outputLength = 0;
    for (int i = 0; i < 7; ++i) {
        //printf("%d %d\n", minIndex[i], maxIndex[i]);

        outputLength = max(outputLength, maxIndex[i] - minIndex[i]);
    }

    outFile << outputLength << endl;
}