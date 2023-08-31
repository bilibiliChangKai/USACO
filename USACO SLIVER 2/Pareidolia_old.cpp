#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>
#include <string>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;

using namespace std;

void AddPrefixSumList(vector<long long> &arrList, int l, int r) {
    ++arrList[0];
    --arrList[l];
    ++arrList[r];
}

int main() {
    string str;
    cin >> str;

    //vector<long long> arrList(str.size() + 1);
    

    int leftIndex;
    int rightIndex;
    int currentIndex = 0;
    long long sum = 0;
    string bessie = "bessie";
    for (int i = 0; i <= str.size(); ++i) {
        if (str[i] == bessie[currentIndex]) {
            ++currentIndex;
            if (currentIndex == 1) {
                leftIndex = i + 1;
            }
            else if (currentIndex == bessie.size()) {
                rightIndex = i + 1;
                cout << "Index: " << leftIndex << " " << rightIndex << endl;

                currentIndex = 0;
                // AddPrefixSumList(arrList, leftIndex, rightIndex);
                sum += leftIndex * (str.size() + 1 - rightIndex);
            }
        }
        else if (currentIndex == 1 && str[i] == bessie[0]) {
            leftIndex = i + 1;
        }
    }

    // cout << "List: " << endl;
    // for (int i = 0; i < arrList.size(); ++i) {
    //     cout << arrList[i] << " ";
    // }
    // cout << endl;

    // int count = 0;
    // for (int i = 1; i < arrList.size(); ++i) {
    //     arrList[i] += arrList[i - 1];
    //     count += arrList[i];
    // }

    // cout << "List: " << endl;
    // for (int i = 0; i < arrList.size(); ++i) {
    //     cout << arrList[i] << " ";
    // }
    // cout << endl;

    cout << sum << endl;
}