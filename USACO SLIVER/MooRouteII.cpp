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
    int from;
    int to;
    int fTime;
    int tTime;

    Edge(int f, int t, int fT, int tT) {
        from = f;
        to = t;
        fTime = fT;
        tTime = tT;
    }

    bool operator<(const Edge &other) {
        return fTime < other.fTime;
    }
};

vector<int> waitTimeList;
vector<int> visitTimeList;
vector<int> relexEdgeIndex;

map <int, vector<Edge>*> edgeMap;

inline void AddEdge(int a, int b, int fT, int tT) {
    if (edgeMap.find(a) == edgeMap.end()) {
        edgeMap.insert(pair<int, vector<Edge>*>(a, new vector<Edge>()));
    }

    edgeMap[a]->push_back(Edge(a, b, fT, tT));
}

inline bool HaveEdges(int i) {
    return edgeMap.find(i) != edgeMap.end();
}

inline bool Comp(const Edge &e, const int a) {
    return e.fTime < a;
}

int main() {
    int n, m;
    cin >> n >> m;

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
        visitTimeList.push_back(INT_MAX);
    }

    // sort edge
    for (int i = 0; i < n; ++i) {
        if (HaveEdges(i)) {
            auto &edges = edgeMap[i];

            if (i != 0) {
                for (size_t j = 0; j < edges->size(); j++)
                {
                    edges->at(j).fTime -= waitTimeList[i];
                }
            }

            sort(edges->begin(), edges->end());

            relexEdgeIndex.push_back(edges->size());
        }
        else {
            relexEdgeIndex.push_back(0);
        }
    }
    
    queue<Edge*> relexEdgeList;
    

    // init
    for (int i = 0; i < relexEdgeIndex[0]; ++i) {
        auto &edges = edgeMap[0];

        relexEdgeList.push(&edges->at(i));
    }
    // update
    relexEdgeIndex[0] = 0;
    visitTimeList[0] = 0;

    while (!relexEdgeList.empty()) {
        auto &edge = *relexEdgeList.front();

        relexEdgeList.pop();

        int from = edge.from;
        int to = edge.to;

        if (edge.tTime < visitTimeList[to]) {
            // need update
            visitTimeList[to] = edge.tTime;
            
            if (HaveEdges(to)) {
                auto &edges = edgeMap[to];

                // cout << "size: " << edges->size() << endl;
                //cout << edges->at(0).fTime << " " << edges->at(1).fTime << endl;
                int pos = distance(edges->begin(), lower_bound(edges->begin(), edges->end(), edge.tTime, Comp));

                // cout << "Print: " << from << ' ' << to << " " << edge.tTime << " " << pos << endl;

                for (size_t i = pos; i < relexEdgeIndex[to]; i++)
                {
                    relexEdgeList.push(&edges->at(i));
                }

                relexEdgeIndex[to] = pos;
            }
        }
    }

    for (int i = 0; i < n; ++i) {

        cout << (visitTimeList[i] == INT_MAX ? -1 : visitTimeList[i]) << endl;
    }
}
