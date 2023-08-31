#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arrNum, ansNum;
    cin >> arrNum >> ansNum;

    vector<long long> arrList(arrNum + 1);

    arrList[0] = 0;
    for (int i = 1; i <= arrNum; ++i) {
        cin >> arrList[i];
        arrList[i] += arrList[i - 1];
    }

    int begin, end;
    for (int i = 0; i < ansNum; ++i) {
        cin >> begin >> end;

        long long sum = arrList[end] - arrList[begin];

        cout << sum << endl;
    }
}