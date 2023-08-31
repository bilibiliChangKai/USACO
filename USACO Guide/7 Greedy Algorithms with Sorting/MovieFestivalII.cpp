#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <set>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(a, b) cout << a << " " << b << endl;
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
    int n, k;
    cin >> n >> k;
    
    int a, b;
    vector<Pair> moiveList;
    multiset<int, greater<int>> startTimeSet;
    for (int i = 0; i < k; ++i) {
        startTimeSet.insert(0);
    }

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        moiveList.push_back(Pair(a, b));
    }

    sort(moiveList.begin(), moiveList.end(), Comp);

    int nums = 0;
    for (int i = 0; i < n; ++i) {
        auto it = startTimeSet.lower_bound(moiveList[i].f);
        if (it != startTimeSet.end()) {
            ++nums;
            startTimeSet.erase(it);
            startTimeSet.insert(moiveList[i].s);
        }
    }

    cout << nums << endl;
}
