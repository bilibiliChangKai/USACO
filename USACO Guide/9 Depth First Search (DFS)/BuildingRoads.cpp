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
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;


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

int main() {
    int n, m;
    cin >> n >> m;
    
    int a, b;

    map<int, vector<int>*> edgeMap;
    vector<bool> visitList(n + 1);
    vector<int> connectedSet;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        if (edgeMap.find(a) == edgeMap.end()) {
            edgeMap.insert(pair<int, vector<int>*>(a, new vector<int>()));
        }
        
        edgeMap[a]->push_back(b);

        if (edgeMap.find(b) == edgeMap.end()) {
            edgeMap.insert(pair<int, vector<int>*>(b, new vector<int>()));
        }
        
        edgeMap[b]->push_back(a);
    }

    queue<int> nodeList;
    for (auto &&kv : edgeMap)
    {
        if (visitList[kv.first] == false) {
            connectedSet.push_back(kv.first);
            visitList[kv.first] = true;

            nodeList.push(kv.first);
            while (!nodeList.empty())
            {
                auto node = nodeList.front();
                nodeList.pop();

                for (auto &&i : (*edgeMap[node]))
                {
                    if (visitList[i] == false) {
                        visitList[i] = true;
                        if (edgeMap.find(i) != edgeMap.end()) {
                            nodeList.push(i);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (visitList[i] == false) {
            connectedSet.push_back(i);
        }
    }

    cout << connectedSet.size() - 1 << endl;
    if (connectedSet.size() > 1) {
        for (int i = 1; i < connectedSet.size(); ++i) {
            cout << connectedSet[i - 1] << " " << connectedSet[i] << endl;
        }
    }
}
