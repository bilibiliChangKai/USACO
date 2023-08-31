#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int arrNum, haybaleNum;
    cin >> arrNum >> haybaleNum;

    vector<int> arrList(arrNum + 2);
    arrList[0] = 0;

    int beginIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < haybaleNum; ++i) {
        cin >> beginIndex >> endIndex;
        ++arrList[beginIndex];
        --arrList[endIndex + 1];
    }

    for (int i = 1; i < arrNum + 1; ++i) {
        arrList[i] = arrList[i] + arrList[i - 1];
    }

    sort(arrList.begin() + 1, arrList.end() - 1);

    cout << arrList[arrNum / 2 + 1] << endl;

    return 0;
}