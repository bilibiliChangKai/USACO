#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

#define Pair pair<int, int>
#define f first
#define s second

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
    int n;
    cin >> n;
    
    int a, b;
    vector<Pair> moiveList;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        moiveList.push_back(Pair(a, b));
    }

    sort(moiveList.begin(), moiveList.end(), Comp);

    int currentEnd = 0; 
    int nums = 0;
    for (int i = 0; i < n; ++i) {
        if (moiveList[i].f >= currentEnd) {
            ++nums;
            currentEnd = moiveList[i].s;
        }
    }

    cout << nums << endl;
}
    