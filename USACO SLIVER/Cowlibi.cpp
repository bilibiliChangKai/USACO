#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

#define f first
#define s second
#define Pair pair<int, int>

struct Point {
public:
    long long a;
    long long b;
    long long t;
};

vector<Point> gList;
vector<Point> nList;

inline bool Comp(const Point &p1, const Point &p2) {
    return p1.t < p2.t;
}

inline bool InRange(const Point &p1, const Point &p2) {
    return pow(p1.a - p2.a, 2) + pow(p1.b - p2.b, 2) <= pow(p1.t - p2.t, 2);
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("Cow.in");
    fout.open("Cow.out");

    int g, n;

    fin >> g >> n;

    long long a, b, t;
    for (int i = 0; i < g; ++i) {
        fin >> a >> b >> t;
        gList.push_back({a, b, t});
    }

    sort(gList.begin(), gList.end(), Comp);

    // for (auto &&p : gList)
    // {
    //     fout << p.a << " " << p.b << " " << p.t << endl;
    // }
    
    for (int i = 0; i < n; ++i) {
        fin >> a >> b >> t;
        nList.push_back({a, b, t});
    }


    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        auto &p1 = nList[i];
        auto it = upper_bound(gList.begin(), gList.end(), p1, Comp);
        int index = it - gList.begin();

        fout << p1.t << " " << index << endl;

        if (index == 0) {
            if (InRange(p1, gList[index])) {
                ++count;
            }
        }
        else if (index == g) {
            if (InRange(p1, gList[index - 1])) {
                ++count;
            }
        }
        else {
            if (InRange(p1, gList[index]) && InRange(p1, gList[index - 1])) {
                ++count;
            }
        }
    }

    cout << count << " " << n - count << endl;
}