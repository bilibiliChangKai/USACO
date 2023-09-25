#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 50000;

int diamonds[N];
int lmaxCount[N];
int rmaxCount[N];

void solve() {
    ifstream fin;
    ofstream fout;

    fin.open("diamond.in");
    fout.open("diamond.out");


    int n, k;
    fin >> n >> k;

    for (int i = 0; i < n; ++i) {
        fin >> diamonds[i];
    }

    sort(diamonds, diamonds + n);

    int leftIndex = 0;
    int rightIndex;
    lmaxCount[0] = 1;
    for (rightIndex = 1; rightIndex < n; ++rightIndex) {
        while (diamonds[rightIndex] - diamonds[leftIndex] > k) {
            leftIndex++;
        }

        int currentCount = rightIndex - leftIndex + 1;

        lmaxCount[rightIndex] = max(lmaxCount[rightIndex - 1], currentCount);
    }

    rmaxCount[n - 1] = 1;
    rightIndex = n - 1;
    for (leftIndex = n - 2; leftIndex >= 0; --leftIndex) {
        while (diamonds[rightIndex] - diamonds[leftIndex] > k) {
            --rightIndex;
        }

        int currentCount = rightIndex - leftIndex + 1;

        rmaxCount[leftIndex] = max(rmaxCount[leftIndex + 1], currentCount);
    }

    int maxCount = max(lmaxCount[n - 1], rmaxCount[0]);
    for (int i = 0; i < n - 2; ++i) {
        maxCount = max(maxCount, lmaxCount[i] + rmaxCount[i + 1]);
    }

    fout << maxCount << endl;
}

int main() {
    solve();
}
    