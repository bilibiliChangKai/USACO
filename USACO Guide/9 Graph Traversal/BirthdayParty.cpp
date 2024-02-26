#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int N = 100;
const int M = 5000;

set<int> edge[N];
pair<int, int> oriEdge[M];
bool isReached[N];

bool IsAllReach(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        isReached[i] = false;
    }

    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        auto from = que.front();
        que.pop();

        if (isReached[from]) {
            continue;
        }

        isReached[from] = true;
        count++;

        for (auto to : edge[from]) {
            if (!isReached[to]) {
                que.push(to);
            }
        }
    }

    return count == n;
}

bool IsInvitedAllFriend(int n, int m) {
    for (int i = 0; i < m; ++i) {
        int from = oriEdge[i].first;
        int to = oriEdge[i].second;
        
        edge[from].erase(to);
        edge[to].erase(from);

        if (!IsAllReach(n)) {
            return false;
        }

        edge[from].insert(to);
        edge[to].insert(from);
    }

    return true;
}

int main() {
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; ++i) {
            edge[i].clear();
        }

        int to, from;
        for (int i = 0; i < m; ++i) {
            cin >> to >> from;
            oriEdge[i].first = to;
            oriEdge[i].second = from;

            edge[to].insert(from);
            edge[from].insert(to);
        }

        auto isInvitedAllFriend = IsInvitedAllFriend(n, m);
        cout << (isInvitedAllFriend ? "No" : "Yes") << endl;
    }
}