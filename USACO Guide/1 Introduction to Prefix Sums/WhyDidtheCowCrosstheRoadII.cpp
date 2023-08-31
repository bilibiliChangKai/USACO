#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;

    inFile.open("maxcross.in");
    outFile.open("maxcross.out");

    int arrNum, sequenceNum, brokenNum;
    inFile >> arrNum >> sequenceNum >> brokenNum;

    vector<int> arrList(arrNum + 1);
    int index;
    for (int i = 0; i < brokenNum; ++i)
    {
        inFile >> index;
        arrList[index] = 1;
    }
    
    arrList[0] = 0;
    for (int i = 1; i < arrNum + 1; ++i)
    {
        arrList[i] = arrList[i - 1] + arrList[i];
    }
    
    int minNum = INT32_MAX;
    for (int i = sequenceNum; i < arrNum + 1; ++i)
    {
        minNum = min(minNum, arrList[i] - arrList[i - sequenceNum]);
    }

    outFile << minNum << endl;
}