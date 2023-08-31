#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(a, b) cout << a << " " << b << endl;

using namespace std;

bool CompStarted(const int a, const int b) {
    return a > b;
}

bool CompNoStart(const Pair &a, const Pair &b) {
    return a.f < b.f;
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
    
    int a, d;
    long long currentReward = 0;
    vector<long long> taskList;
    for (int i = 0; i < n; ++i) {
        cin >> a >> d;
        currentReward += d - a;
        taskList.push_back(a);
    }

    sort(taskList.begin(), taskList.end());

    long long factor = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        currentReward -= taskList[i] * factor;
        --factor;
    }

    cout << currentReward << endl;
}
    