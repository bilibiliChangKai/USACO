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

void solve() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> cows[i];
    }

    sort(cows, cows + n, greater<int>());

    int i = 0;
    for (i = 0; i < n; ++i) {
        if (cows[i] < i) {
            break;
        }
    }

    fout << i << endl;
}

int main() {
    solve();
}
