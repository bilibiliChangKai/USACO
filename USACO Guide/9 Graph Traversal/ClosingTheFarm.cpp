#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

const int N = 3000;
const int M = 3000;

int isReach[N];
int isClose[N];
bool result[N];
set<int> edge[N];

inline void RemoveCloseEdge(int from) {
    for (auto to : edge[from]) {
        edge[to].erase(from);
    }

    edge[from].clear();
}

inline int GetBeginNode(int n) {
    for (int i = 0; i < n; ++i) {
        if (!isClose[i]) {
            return i;
        }
    }

    return -1;
}

inline bool IsReachGragh(int n, int openCount) {
    for (int i = 0; i < n; ++i) {
        isReach[i] = false;
    }

    int beginNode = GetBeginNode(n);
    int currentCount = 0;

    queue<int> que;
    que.push(beginNode);
    while (!que.empty()) {
        auto from = que.front();
        que.pop();

        if (isReach[from]) {
            continue;
        }

        isReach[from] = true;
        currentCount++;

        for (auto to : edge[from]) {
            if (!isReach[to]) {
                que.push(to);
            }
        }
    }

    return currentCount == openCount;
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    int n, m;
    fin >> n >> m;
    int openCount = n;

    int to, from;
    for (int i = 0; i < m; ++i) {
        fin >> to >> from;
        edge[to - 1].insert(from - 1);
        edge[from - 1].insert(to - 1);
    }

    int closeIndex;
    for (int i = 0; i < n; ++i) {
        auto isReach = IsReachGragh(n, openCount);
        result[i] = isReach;

        fin >> closeIndex;
        isClose[closeIndex - 1] = true;
        openCount--;

        RemoveCloseEdge(closeIndex - 1);
    }

    for (int i = 0; i < n; ++i) {
        auto isReach = result[i];
        fout << (isReach ? "YES" : "NO") << endl;
    }
}