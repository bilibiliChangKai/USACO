#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;


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

struct Point {
    int x;
    int y;
    int p;
};

inline bool InDistance(int a, int b, int c) {
    return c * c >= a * a + b * b; 
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("moocast.in");
    fout.open("moocast.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i)
    {
        indexList.push_back(-1);
        visitList.push_back(-1);
    }
     
    int a, b, p;
    vector<Point> pointList;
    for (size_t i = 0; i < n; i++)
    {
        fin >> a >> b >> p;
        pointList.push_back({a, b, p});
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = pointList[i].x - pointList[j].x;
            int b = pointList[i].y - pointList[j].y;
            int c1 = pointList[i].p;
            int c2 = pointList[j].p;
            if (InDistance(a, b, c1)) {
                AddEdge(i, j);
            }
            
            if (InDistance(a, b, c2)) {
                AddEdge(j, i);
            }
        }
    }

    int maxSize = 1;
    queue<int> bfsList;
    for (int i = 0; i < n; ++i) {
        if (indexList[i] != -1) {
            int groupSize = 0;

            for (int i = 0; i < n; ++i) {
                visitList[i] = 0;
            }

            visitList[i] = 1;
            ++groupSize;
            bfsList.push(i);

            while (!bfsList.empty()) {
                int from = bfsList.front();
                bfsList.pop();

                for (int index = indexList[from]; index != -1; index = edgeList[index].nxt) {
                    int to = edgeList[index].to;
                    
                    if (visitList[to] != 1) {
                        // 加入节点
                        visitList[to] = 1;
                        ++groupSize;
                        bfsList.push(to);

                        
                    }
                }
            }

            maxSize = max(maxSize, groupSize);
        }
    }

    fout << maxSize << endl;
}
