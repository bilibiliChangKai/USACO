#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
using namespace std;

const int N = 100000;
const int M = 100000;

struct Point {
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Rect {
    int minX;
    int maxX;
    int minY;
    int maxY;

    Rect(Point p) : minX(p.x), maxX(p.x), minY(p.y), maxY(p.y) {}

    void AddPoint(Point p) {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    }

    int GetPerimeter() {
        return (maxX - minX + maxY - minY) * 2;
    }
};

vector<Point> cowPoints;
vector<Rect> edgePerimeter;
bool isReached[N];
vector<int> edge[N];

void SetGraghRect(int i, int n) {
    Rect r(cowPoints[i]);
    
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
        auto from = que.front();
        que.pop();

        if (isReached[from]) {
            continue;
        }

        isReached[from] = true;
        r.AddPoint(cowPoints[from]);

        for (auto to : edge[from]) {
            if (!isReached[to]) {
                que.push(to);
            }
        }
    }

    edgePerimeter.push_back(r);
}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int n, m;
    fin >> n >> m;

    int x, y;
    for (int i = 0; i < n; ++i) {
        fin >> x >> y;
        cowPoints.push_back(Point(x, y));
    }

    int to, from;
    for (int i = 0; i < m; ++i) {
        fin >> to >> from;
        edge[to - 1].push_back(from - 1);
        edge[from - 1].push_back(to - 1);
    }

    for (int i = 0; i < n; ++i) {
        if (isReached[i]) {
            continue;
        }

        SetGraghRect(i, n);
    }

    int minPerimeter = numeric_limits<int>::max();
    for (auto& r : edgePerimeter) {
        minPerimeter = min(minPerimeter, r.GetPerimeter());
    }

    fout << minPerimeter << endl;
}