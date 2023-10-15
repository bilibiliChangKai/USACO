#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 500000;

struct Oppo {
    long long time;
    int point;
    bool isLosed;

    Oppo() : time(0), point(0), isLosed(false) {}
};

Oppo oppos[N];

bool CompTime(const Oppo& a, const Oppo& b) {
    return a.time != b.time ? a.time < b.time : a.point > b.point;
}

bool CompPoint(const Oppo& a, const Oppo& b) {
    return a.point != b.point ? a.point > b.point : a.isLosed;
}


bool CompPointLower(const Oppo& oppo, const int& point) {
    return point < oppo.point;
}

// ifstream cin("helpcross.in");
// ofstream cout("helpcross.out");

void solve() {
    int n;
    long long sumTime;
    int myPoint = 0;

    cin >> n >> sumTime;

    long long time;
    for (int i = 0; i < n; ++i) {
        cin >> time;

        oppos[i].time = time;
        oppos[i].point = i + 1;
        oppos[i].isLosed = false;
    }

    sort(oppos, oppos + n, CompTime);

    int i;
    long long currentTime = 0;
    long long lastUseTime = 0;
    for (i = 0; i < n; ++i) {
        if (currentTime + oppos[i].time > sumTime) {
            break;
        }

        lastUseTime = oppos[i].time;

        currentTime += oppos[i].time;
        oppos[i].isLosed = true;
        oppos[i].point--;
    }

    // cout << "I: " << i << " " << lastUseTime << endl;

    if (i == n) {
        cout << 1 << endl;

        return;
    }

    if (i == 0) {
        cout << n + 1 << endl;

        return;
    }

    sort(oppos, oppos + n, CompPoint);

    // cout << "Oppos Arr: " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << oppos[i].point << " " << oppos[i].time << endl;
    // }
    // cout << endl;

    myPoint = i;
    int dis = lower_bound(oppos, oppos + n, myPoint, CompPointLower) - oppos;
    // cout << "Dis: " << dis << endl;

    if (dis == 0) {
        cout << 1 << endl;

        return;
    }

    if (oppos[dis - 1].point == myPoint + 1 && !oppos[dis - 1].isLosed) {
        if (currentTime - lastUseTime + oppos[dis - 1].time <= sumTime) {
            dis--;
        }   
    }

    cout << dis + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}