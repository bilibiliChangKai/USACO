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

const int N = 100000;

int cows[N];

int CalMin(int n) {
    int leftIndex = 0;
    int rightIndex = 0;

    if (cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) {
        return 2;
    }

    if (cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2) {
        return 2;
    }

    // caculate Min
    for (rightIndex = 0; rightIndex < n; ++rightIndex) {
        if (cows[rightIndex] - cows[leftIndex] > n - 1) {
            break;
        }
    }

    rightIndex--;

    int minMoveTimes = n - (rightIndex - leftIndex + 1);

    for (; rightIndex < n; ++rightIndex) {
        while (cows[rightIndex] - cows[leftIndex] > n - 1) {
            ++leftIndex;
        }

        int times = n - (rightIndex - leftIndex + 1);
        
        minMoveTimes = min(minMoveTimes, times);
    }

    return minMoveTimes;
}

void solve() {
    ifstream fin;
    ofstream fout;

    fin.open("herding.in");
    fout.open("herding.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        fin >> cows[i];
    }

    sort(cows, cows + n);

    int minTimes = CalMin(n);

    // calculate Max
    int maxTimes = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxTimes += cows[i + 1] - cows[i] - 1;
    }
    maxTimes -= min(cows[1] - cows[0] - 1, cows[n - 1] - cows[n - 2] - 1);

    fout << minTimes << endl << maxTimes << endl;
}

int main() {
    solve();
}
    