#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

#define Range pair<long long, long long>
#define f first
#define s second

using namespace std;

bool Comp(const Range &a, const Range &b) {
    return a.f == b.f ? a.s > b.s : a.f < b.f;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("mountains.in");
    fout.open("mountains.out");

    int n;
    fin >> n;

    vector<Range> rangeList;
    long long x, y;
    for (int i = 0; i < n; ++i) {
        fin >> x >> y;

        rangeList.push_back(Range(x - y, x + y));
    }

    sort(rangeList.begin(), rangeList.end(), Comp);

    // for (int i = 0; i < n; ++i) {
    //     cout << rangeList[i].f << " " << rangeList[i].s << endl;
    // }    

    int leftIndex = 0;
    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (rangeList[i].s <= rangeList[leftIndex].s) {
            ++count;
        }
        else {
            leftIndex = i;
        }
    }

    fout << n - count << endl;
}