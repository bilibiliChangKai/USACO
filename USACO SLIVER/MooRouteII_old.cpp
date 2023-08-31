#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>

#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;


using namespace std;

struct Edge {
    int to;
    int fTime;
    int tTime;
    int nxt;

    Edge(int t, int n, int fT, int tT) {
        to = t;
        fTime = fT;
        tTime = tT;
        nxt = n;
    }
};

vector<int> indexList;
vector<Edge> edgeList;

vector<int> waitTimeList;
vector<int> visitTimeList;

inline void AddEdge(int a, int b, int fT, int tT) {
    edgeList.push_back(Edge(b, indexList[a], fT, tT));
    indexList[a] = edgeList.size() - 1;
}

int main() {
    // ifstream fin;
    // ofstream fout;

    // fin.open("moocast.in");
    // fout.open("moocast.out");

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        indexList.push_back(-1);
        visitTimeList.push_back(-1);
    }
     
    int a, b, r, s;
    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> r >> b >> s;
        AddEdge(a - 1, b - 1, r, s);
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> a;
        waitTimeList.push_back(a);
    }
    
    queue<int> bfsList;
    
    bfsList.push(0);
    visitTimeList[0] = 0 - waitTimeList[0];

    while (!bfsList.empty()) {
        int from = bfsList.front();
        bfsList.pop();

        int fTime = visitTimeList[from] + waitTimeList[from];

        // cout << "Enter: " << fTime << endl;
        for (int index = indexList[from]; index != -1; index = edgeList[index].nxt) {
            // cout << index << endl;
            
            Edge &e = edgeList[index];
            if (e.fTime < fTime) {
                continue;
            }

            int to = e.to;
            if (to == 0) {
                continue;
            }

            

            int tTime = e.tTime;

            // cout << to << " " << visitTimeList[to] << " " << tTime << endl;
            if (visitTimeList[to] == -1 || tTime < visitTimeList[to]) {
                visitTimeList[to] = tTime;
                bfsList.push(to);
            }
        }
    }

    cout << 0 << endl;
    for (int i = 1; i < n; ++i) {
        cout << visitTimeList[i] << endl;
    }
}
