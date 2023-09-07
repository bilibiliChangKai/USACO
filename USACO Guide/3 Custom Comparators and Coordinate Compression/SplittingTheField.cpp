#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>

using namespace std;


struct Cow {
    long long x;
    long long y;

    Cow() : x(0), y(0) {}
};

struct Area {
    long long minX;
    long long maxX;
    long long minY;
    long long maxY;

    Area() : minX(-1), maxX(-1), minY(-1), maxY(-1) {}
    void Clear() {
        minX = -1;
        maxX = -1;
        minY = -1;
        maxY = -1;
    }
    long long GetArea() { 
        return (maxX - minX) * (maxY - minY);
    }
    void SetCow(long long x, long long y) {
        if (minX == -1) {
            minX = x;
        }

        if (maxX == -1) {
            maxX = x;
        }

        if (minY == -1) {
            minY = y;
        }

        if (maxY == -1) {
            maxY = y;
        }

        maxX = max(maxX, x);
        maxY = max(maxY, y);
        minX = min(minX, x);
        minY = min(minY, y);
    }

    bool CheckValid(const Area &other) {
        if (maxX < other.minX || other.maxX < minX || maxY < other.minY || other.minX < minY) {
            return true; // 两个长方形不相交
        }
        return false; // 两个长方形相交
    }
};


bool CompX(const Cow &left, const Cow &right) {
    return left.x != right.x ? left.x < right.x : left.y < right.y;
}

bool CompY(const Cow &left, const Cow &right) {
    return left.y != right.y ? left.y < right.y : left.x < right.x;
}

const int N = 50000;

Cow cows[N];
Area areas[N];
Area rAreas[N];

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("split.in");
    fout.open("split.out");


    long long n;
    fin >> n;
    getchar();
    
    long long x, y;

    for (size_t i = 0; i < n; i++)
    {
        fin >> x >> y;

        cows[i].x = x;
        cows[i].y = y;
    }
    
    // X Sort
    sort(cows, cows + n, CompX);

    Area lArea;
    Area rArea;
    
    for (size_t i = 0; i < n; i++)
    {
        size_t ri = n - 1 - i;

        lArea.SetCow(cows[i].x, cows[i].y);
        rArea.SetCow(cows[ri].x, cows[ri].y);

        areas[i] = lArea;
        rAreas[ri] = rArea;
    }

    long long oriArea = rAreas[0].GetArea();
    long long minArea = oriArea;


    // for (int i = 0; i < n; i++) {
    //     cout << "Cow: " << i << " " << cows[i].x << " " << cows[i].y << endl;
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << "Area: " << i << " " << areas[i].GetArea() << " " << rAreas[i].GetArea() << endl;
    // }

    int index = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        Area &lArea = areas[i];
        Area &rArea = rAreas[i + 1];

        if (lArea.CheckValid(rArea)) {
            long long area = lArea.GetArea() + rArea.GetArea();
            if (area < minArea) {
                index = i;
            }

            minArea = min(minArea, area);
        }
    }

    // cout << "AreaIndexX: " << index << endl;

    // Y Sort
    sort(cows, cows + n, CompY);

    lArea.Clear();
    rArea.Clear();

    for (size_t i = 0; i < n; i++)
    {
        size_t ri = n - 1 - i;

        lArea.SetCow(cows[i].x, cows[i].y);
        rArea.SetCow(cows[ri].x, cows[ri].y);

        areas[i] = lArea;
        rAreas[ri] = rArea;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        Area &lArea = areas[i];
        Area &rArea = rAreas[i + 1];

        if (lArea.CheckValid(rArea)) {
            long long area = lArea.GetArea() + rArea.GetArea();
            if (area < minArea) {
                index = i;
            }

            minArea = min(minArea, area);
        }
    }

    // cout << "AreaIndexY: " << index << endl;

    // for (int i = 0; i < nCount; i++) {
    //     cout << "N: " << northCows[i].index << " " << northCows[i].x << " " << northCows[i].y << endl;
    // }

    fout << oriArea - minArea << endl;
}