#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <limits.h>

using namespace std;

struct Num {
    int oriIndex;
    int curIndex;
    int maxValue;
    int value;

    Num() : value(0), oriIndex(0), curIndex(0), maxValue(0) {}
};

bool Comp(const Num& left, const Num& right) {
    return left.value < right.value;
}

const int N = 100000;

Num oriArr[N];
bool sorted[N];

int GetBubbleTimes(int a, int b) {
    if (a == b) {
        return 0;
    }

    for (int i = a; i < b; ++i) {
        // divide two part
        Num& num = oriArr[i];
        if (num.value = num.maxValue && num.oriIndex == num.curIndex) {
            int timesA = GetBubbleTimes(a, i);
            int timesB = GetBubbleTimes(i + 1, b);

            return max(timesA, timesB);
        }
    }

    // from left to right
    int l2rtimes = 0;
    int r2lTimes = 0;
    for (int i = b - 1; i >= a; --i)
    {
        Num& num = oriArr[i];
        if (num.oriIndex <= num.curIndex) {
            l2rtimes++;
        }
        else {
            r2lTimes = max(r2lTimes, num.oriIndex - num.curIndex);
        }
    }
    
    return max(l2rtimes, r2lTimes);
}

void solve() {
    ifstream fin;
    ofstream fout;

    fin.open("sort.in");
    fout.open("sort.out");

    int n;
    fin >> n;

    int value = 0;
    int maxValue = 0;
    for (size_t i = 0; i < n; i++)
    {
        fin >> value;
        maxValue = max(maxValue, value);

        oriArr[i].oriIndex = i;
        oriArr[i].value = value;
        oriArr[i].maxValue = maxValue;

        sorted[i] = false;

        // cout << "Arr: ";
        // for (int j = 0; j < currentLen; j++) {
        //     cout << sortArr[j] << " ";
        // }
        // cout << endl;

        // cout << "V: " << value << " Len: " << currentLen << endl;
    }

    stable_sort(oriArr, oriArr + n, Comp);

    int minStep = 0;
    for (int i = 0; i < n; i++)
    {
        oriArr[i].curIndex = i;
    }
    
    int times = GetBubbleTimes(0, n);

    fout << times + 1 << endl;
}

int main() {
    solve();
}