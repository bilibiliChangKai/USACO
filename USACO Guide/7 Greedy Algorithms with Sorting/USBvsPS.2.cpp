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

#define Value first
#define Type second

const int N = 300000;

string type;

pair<int, bool> comp[N];

bool Comp(const pair<int, bool> &a, const pair<int, bool> &b) {
    return a.Value < b.Value;
}

void solve() {
    int a, b, ab;
    cin >> a >> b >> ab;

    int m;
    cin >> m;

    int aCount = 0;
    int bCount = 0;
    int value = 0;
    for (int i = 0; i < m; i++) {
        cin >> value >> type;
        comp[i].Value = value;
        comp[i].Type = type == "USB";
    }

    sort(comp, comp + m, Comp);

    int count = 0;
    long long cost = 0;
    for (int i = 0; i < m; ++i) {
        pair<int, bool> &com = comp[i];

        if (com.Type) {
            if (a > 0) {
                --a;
                ++count;
                cost += com.Value;
            }
            else if (ab > 0) {
                --ab;
                ++count;
                cost += com.Value;
            }
        }
        else {
            if (b > 0) {
                --b;
                ++count;
                cost += com.Value;
            }
            else if (ab > 0) {
                --ab;
                ++count;
                cost += com.Value;
            }
        }
    }

    cout << count << " " << cost << endl;
}

int main() {
    solve();
}
