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

pair<long long, long long> glassPos[N];

#define Pos first
#define Value second

bool Comp(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.Value > b.Value;
}

void solve() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");

    long long l, n, rf, rb;
    fin >> l >> n >> rf >> rb;

    long long x, c;
    for (int i = 0; i < n; i++) {
        fin >> x >> c;

        glassPos[i].Pos = x;
        glassPos[i].Value = c;
    }

    sort(glassPos, glassPos + n, Comp);

    long long nowPos = 0;
    long long maxGlassCount = 0;
    for (int i = 0; i < n; ++i) {
        if (glassPos[i].Pos <= nowPos) {
            continue;
        }

        long long times = (glassPos[i].Pos - nowPos) * (rf - rb);
        nowPos = glassPos[i].Pos;
        maxGlassCount += glassPos[i].Value * times;
    }

    fout << maxGlassCount << endl;
}

int main() {
    solve();
}
