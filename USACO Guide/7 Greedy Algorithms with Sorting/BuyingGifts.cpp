#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 500000;

struct Gift {
    int boy;
    int girl;
    int index;

    Gift() : boy(0), girl(0), index(0) {}
};

Gift boySort[N];
Gift girlSort[N];


bool CompBoy(const Gift &a, const Gift &b) {
    return a.boy != b.boy ? a.boy > b.boy : a.girl < b.girl;
}

bool CompGirl(const Gift &a, const Gift &b) {
    return a.girl != b.girl ? a.girl > b.girl : a.boy < b.boy;
}

bool Comp(const Gift& boy, const Gift& girl) {
    return boy.boy > girl.girl;
}

void solve() {
    int n;
    cin >> n;

    int boy, girl;
    for (int i = 0; i < n; ++i) {
        cin >> boy >> girl;

        boySort[i].boy = boy;
        boySort[i].girl = girl;
        boySort[i].index = i;

        girlSort[i].boy = boy;
        girlSort[i].girl = girl;
        girlSort[i].index = i;
    }

    sort(boySort, boySort + n, CompBoy);
    sort(girlSort, girlSort + n, CompGirl);

    // cout << "Boy: \n";
    // for (int i = 0; i < n; ++i) {
    //     cout << boySort[i].index << " " << boySort[i].boy << " " << boySort[i].girl << endl;
    // }

    // cout << "Girl: \n";
    // for (int i = 0; i < n; ++i) {
    //     cout << girlSort[i].index << " " << girlSort[i].boy << " " << girlSort[i].girl << endl;
    // }

    int maxBoy = 0;
    int minDiff = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        Gift& girl = girlSort[i];
        // cout << "G: " << girlSort[i].index << " " << girlSort[i].boy << " " << girlSort[i].girl << endl;

        int dis = lower_bound(boySort, boySort + n, girl, Comp) - boySort;
        // cout << "Dis: "<< dis << endl;
        if (dis < n) {
            Gift& boy = boySort[dis];
            if (boy.index == girl.index) {
                if (dis < n - 1) {
                    Gift& boy2 = boySort[dis + 1];

                    int diff = abs(max(maxBoy, boy2.boy) - girl.girl);
                    minDiff = min(minDiff, diff);
                }
            }
            else {

                int diff = abs(max(maxBoy, boy.boy) - girl.girl);
                minDiff = min(minDiff, diff);
            }
        }

        --dis;
        if (dis >= 0) {
            Gift& boy = boySort[dis];

            if (boy.index == girl.index) {
                if (dis > 0) {
                    Gift& boy2 = boySort[dis - 1];

                    int diff = abs(max(maxBoy, boy2.boy) - girl.girl);
                    minDiff = min(minDiff, diff);
                }
            }
            else {
                int diff = abs(max(maxBoy, boy.boy) - girl.girl);
                minDiff = min(minDiff, diff);
            }
        }

        // cout << "MaxBoy: " << maxBoy << endl;
        if (girl.girl <= maxBoy) {
            break;
        }

        maxBoy = max(maxBoy, girl.boy);
    }

    cout << minDiff << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}