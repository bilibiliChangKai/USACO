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
    return a.f < b.f;
}

int main() {
    int n, x;
    cin >> n >> x;

    int t;
    vector<Pair> arrList;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> t;
        arrList.push_back(Pair(t, i + 1));
    }

    sort(arrList.begin(), arrList.end());
    
    int lIndex = 0;
    int rIndex = n - 1;
    bool isPossiable = false;

    // for (int i = 0; i < n; ++i) {
    //     cout << arrList[i].f << " " << arrList[i].s << endl;
    // }

    while (lIndex < rIndex) {
        int sum = arrList[lIndex].f + arrList[rIndex].f;

        if (sum == x) {
            isPossiable = true;

            // if (arrList[lIndex].s < arrList[rIndex].s) {
            //     cout << arrList[lIndex].s << " " << arrList[rIndex].s << endl;
            // }
            // else {
            //     cout << arrList[rIndex].s << " " << arrList[lIndex].s << endl;
            // }
            
            cout << arrList[lIndex].s << " " << arrList[rIndex].s << endl;

            break;
        }
        else if (sum < x) {
            ++lIndex;
        }
        else {
            --rIndex;
        }
    }

    if (!isPossiable) {
        cout << "IMPOSSIBLE" << endl;
    }
}
    