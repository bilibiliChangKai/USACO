#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

// 这里要从后往前计算
int main() {
    string numStr;
    cin >> numStr;

    vector<int> remainderList(numStr.size() + 1);
    remainderList[numStr.size()] = 0;
    int mul = 1;
    for (int i = numStr.size() - 1; i >= 0; --i) {
        remainderList[i] = ((numStr[i] - '0') * mul + remainderList[i + 1]) % 2019;
        mul = (mul * 10) % 2019;
    }

    map<int, int> indexMap;
    int nums = 0;
    for (int i = 0; i < numStr.size() + 1; ++i) {
        if (indexMap.find(remainderList[i]) != indexMap.end()) {
            nums += indexMap[remainderList[i]];
            ++indexMap[remainderList[i]];
        }
        else {
            indexMap.insert(pair<int, int>(remainderList[i], 1));
        }
    }

    cout << nums << endl;
}