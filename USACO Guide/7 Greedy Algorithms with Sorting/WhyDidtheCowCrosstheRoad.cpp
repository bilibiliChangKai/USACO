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

const int N = 20000;

vector<long long> chickens;
pair<long long, long long> cows[N];

#define BeginT first
#define EndT second

bool Comp(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.EndT != b.EndT ? a.EndT < b.EndT : a.BeginT < b.BeginT;
}

void solve() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");

    int c, n;
    fin >> c >> n;
    
    long long chicken;
    for (int i = 0; i < c; ++i) {
        fin >> chicken;
        chickens.push_back(chicken);
    }

    long long b, e;
    for (int i = 0; i < n; ++i) {
        fin >> b >> e;
        cows[i].BeginT = b;
        cows[i].EndT = e;
    }

    sort(chickens.begin(), chickens.end());
    sort(cows, cows + n, Comp);

    // cout << "Chicken: ";
    // for (int i = 0; i < c; ++i) {
    //     cout << chickens[i] << ' ';
    // }
    // cout << endl;
    
    // cout << "Cows: \n";
    // for (int i = 0; i < n; ++i) {
    //     cout << i << ": " << cows[i].BeginT << ' ' << cows[i].EndT << endl;
    // }

    int counts = 0;
    for (int i = 0; i < n; ++i) {
        pair<long long, long long> &cow = cows[i];

        auto it = lower_bound(chickens.begin(), chickens.end(), cow.BeginT);
        if (it != chickens.end() && *it <= cow.EndT) {
            counts++;
            chickens.erase(it);
        }

        if (chickens.empty()) {
            break;
        }
    }
    
    
    fout << counts << endl;
}

int main() {
    solve();
}
