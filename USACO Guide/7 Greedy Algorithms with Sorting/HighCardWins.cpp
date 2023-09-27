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

bool hasCard[N + 1];
int selfCard[N];
int otherCard[N];

void solve() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> otherCard[i];

        hasCard[otherCard[i]] = true;
    }

    int selfCount = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!hasCard[i]) {
            selfCard[selfCount++] = i;
        }
    }

    sort(selfCard, selfCard + n);
    sort(otherCard, otherCard + n);

    // cout << "SelfCard: ";
    // for (int i = 0; i < n; ++i) {
    //     cout << selfCard[i] << " ";
    // }
    // cout << endl;

    // cout << "OtherCard: ";
    // for (int i = 0; i < n; ++i) {
    //     cout << otherCard[i] << " ";
    // }
    // cout << endl;

    int winTimes = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        while (i < n && selfCard[i] < otherCard[j]) {
            ++i;
        }

        if (i == n) {
            break;
        }

        ++winTimes;
        ++i;
    }


    fout << winTimes << endl;
}

int main() {
    solve();
}
