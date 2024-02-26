#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).to << " " << (p).nxt << endl;

#define EMPTY 0
#define RED 1
#define BLACK 2

using namespace std;

struct Edge {
    int to;
    int nxt;

    Edge(int t, int n) {
        to = t;
        nxt = n;
    }
};

vector<int> indexList;
vector<Edge> edgeList;

vector<int> visitList;

inline void AddEdge(int a, int b) {
    edgeList.push_back(Edge(b, indexList[a]));
    indexList[a] = edgeList.size() - 1;
}

inline bool Bfs(int n, int m) {
    queue<int> redBfs, blackBfs;

    for (int i = 0; i < n; ++i) {
        if (indexList[i] != -1 && visitList[i] == EMPTY) {
            visitList[i] = RED;
            redBfs.push(i);

            while (!redBfs.empty() || !blackBfs.empty()) {
                while (!redBfs.empty()) {
                    int from = redBfs.front();
                    redBfs.pop();

                    for (int index = indexList[from]; index != -1; index = edgeList[index].nxt) {
                        int to = edgeList[index].to;
                        if (visitList[to] == RED) {
                            return false;
                        }
                        else if (visitList[to] == EMPTY) {
                            visitList[to] = BLACK;
                            blackBfs.push(to);
                        }
                    }
                }

                while (!blackBfs.empty()) {
                    int from = blackBfs.front();
                    blackBfs.pop();

                    for (int index = indexList[from]; index != -1; index = edgeList[index].nxt) {
                        int to = edgeList[index].to;
                        if (visitList[to] == BLACK) {
                            return false;
                        }
                        else if (visitList[to] == EMPTY) {
                            visitList[to] = RED;
                            redBfs.push(to);
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < n; ++i) {
        indexList.push_back(-1);
        visitList.push_back(EMPTY);
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        AddEdge(a - 1, b - 1);
        AddEdge(b - 1, a - 1);
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << indexList[i] << " ";
    // }

    // cout << endl;

    // for (int i = 0; i < edgeList.size(); ++i) {
    //     DebugPrint(edgeList[i]);
    // }


    bool isSuccess = Bfs(n, m);

    if (!isSuccess) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (visitList[i] == EMPTY) {
                visitList[i] = RED;
            }
        }
        
        cout << visitList[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << visitList[i];
        }
        cout << endl;
    }
}
