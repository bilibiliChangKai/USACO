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
    priority_queue<int, vector<int>, bool (*)(const int, const int)> startedTaskHeap(CompStarted);
    priority_queue<Pair, vector<Pair>, bool (*)(const Pair &, const Pair &)> noStartTaskHeap(CompNoStart);

    int endTime = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> d;
        endTime = max(endTime, d);
        
        noStartTaskHeap.push(Pair(d - a, d));
    }

    // while(!noStartTaskHeap.empty()) {
    //     cout << noStartTaskHeap.top().f << " " << noStartTaskHeap.top().s << endl;
    //     noStartTaskHeap.pop();
    // }

    // while(!startedTaskHeap.empty()) {
    //     cout << startedTaskHeap.top() << endl;
    //     startedTaskHeap.pop();
    // }

    int count = 0;
    while (1) {
        int startTask = startedTaskHeap.empty() ? INT_MAX : startedTaskHeap.top();
        int noStartTask = noStartTaskHeap.empty() ? INT_MAX : endTime - noStartTaskHeap.top().f;

        //cout << startTask << " " << noStartTask << endl;

        int taskTime = min(startTask, noStartTask);
        if (endTime < taskTime) {
            break;
        }

        ++count;
        endTime -= taskTime;
        if (startTask < noStartTask) {
            startedTaskHeap.pop();
        }
        else {
            noStartTaskHeap.pop();
        }

        while (!noStartTaskHeap.empty() && noStartTaskHeap.top().s > endTime) {
            auto p = noStartTaskHeap.top();
            startedTaskHeap.push(p.s - p.f);
            noStartTaskHeap.pop();
        }
    }

    cout << count << endl;
}
    