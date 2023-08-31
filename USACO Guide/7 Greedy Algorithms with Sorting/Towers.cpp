#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

#define Pair pair<int, int>
#define f first
#define s second

using namespace std;

bool Comp(const Pair &a, const Pair &b) {
    return a.s < b.s;
}

// bool CompBinary(const Pair &a, const int b) {
//     return a.f < b;
// }

bool CompBinary(const int a, const Pair &b) {
    return a < b.f;
}

void AddTower(multiset<int> &towerSet, int k) {
    auto it = towerSet.upper_bound(k);
    if (it != towerSet.end()) {
        towerSet.erase(it);
    }

    towerSet.insert(k);
}

int main() {
    int n;
    cin >> n;
    
    int k;
    multiset<int> towerSet;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        AddTower(towerSet, k);
    }

    cout << towerSet.size() << endl;
}
    