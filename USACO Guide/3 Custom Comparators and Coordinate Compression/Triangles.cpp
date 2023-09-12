#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

using namespace std;

struct Cow {
    long long x;
    long long y;
    long long xLength;
    long long yLength;

    Cow() : x(0), y(0), xLength(0), yLength(0) {}
};


bool CompX(const Cow &left, const Cow &right) {
    return left.x != right.x ? left.x < right.x : left.y < right.y;
}

bool CompY(const Cow &left, const Cow &right) {
    return left.y != right.y ? left.y < right.y : left.x < right.x;
}

const int N = 100000;

Cow cows[N];

int findSameX(const Cow& cow, int i, int n) {
    for (++i; i < n; i++) {
        if (cows[i].x != cow.x) {
            break;
        }
    }

    return i;
}

int findSameY(const Cow& cow, int i, int n) {
    for (++i; i < n; i++) {
        if (cows[i].y != cow.y) {
            break;
        }
    }

    return i;
}

void CalLengthX(int a, int b) {
    long long sumLen = 0;
    for (int j = a + 1; j < b; j++) {
        sumLen += abs(cows[a].y - cows[j].y);
    }

    cows[a].xLength += sumLen;
    for (int j = a + 1; j < b; j++) {
        long long y = abs(cows[j].y - cows[j - 1].y);
        sumLen += (j - a - 1) * y - (b - j - 1) * y;

        cows[j].xLength += sumLen;
    }

    // for (int i = a; i < b; i++) {
    //     for (int j = a; j < b; j++) {
    //         cows[i].xLength += abs(cows[i].y - cows[j].y);
    //     }
    // }
}

void CalLengthY(int a, int b) {
    long long sumLen = 0;
    for (int j = a + 1; j < b; j++) {
        sumLen += abs(cows[a].x - cows[j].x);
    }

    cows[a].yLength += sumLen;
    for (int j = a + 1; j < b; j++) {
        long long x = abs(cows[j].x - cows[j - 1].x);
        sumLen += (j - a - 1) * x - (b - j - 1) * x;

        cows[j].yLength += sumLen;
    }

    // for (int i = a; i < b; i++) {
    //     for (int j = a; j < b; j++) {
    //         cows[i].yLength += abs(cows[i].x - cows[j].x);
    //     }
    // }
}


void solve() {
    ifstream fin;
    ofstream fout;

    fin.open("triangles.in");
    fout.open("triangles.out");

    int n;
    fin >> n;

    long long x, y;

    for (size_t i = 0; i < n; i++)
    {
        fin >> x >> y;

        cows[i].x = x;
        cows[i].y = y;
    }

    // Sort
    sort(cows, cows + n, CompX);

    // add length
    for (int i = 0; i < n; i++)
    {
        Cow& cow = cows[i];
        int j = findSameX(cow, i, n);
        CalLengthX(i, j);

        i = j - 1;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << "Cow: " << cows[i].x << " " << cows[i].y << " " << cows[i].xLength << " " << cows[i].yLength << endl;
    // }

    sort(cows, cows + n, CompY);

    for (int i = 0; i < n; i++)
    {
        Cow& cow = cows[i];
        int j = findSameY(cow, i, n);
        CalLengthY(i, j);

        i = j - 1;
    }
    
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     fout << "Cow: " << cows[i].x << " " << cows[i].y << " " << cows[i].xLength << " " << cows[i].yLength << endl;
    // }

    long long sumValue = 0;
    long long modValue = 1000000007;
    for (int i = 0; i < n; i++)
    {
        long long xV = cows[i].xLength % modValue;
        long long yV = cows[i].yLength % modValue;

        sumValue += (xV * yV) % modValue;
        sumValue = sumValue % modValue;
    }
    
    fout << sumValue << endl;
}

int main() {
    solve();
}