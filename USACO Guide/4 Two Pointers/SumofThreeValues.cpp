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

// bool CompBinary(const Pair &a, const int b) {
//     return a.f < b;
// }

bool CompBinary(const int a, const Pair &b) {
    return a < b.f;
}

int a, b, c;

bool FindSubSum(vector<Pair> &arrList, int n, int x) {
    int lIndex = 0;
    int rIndex = n - 1;

    while (lIndex < rIndex) {
        int sum = arrList[lIndex].f + arrList[rIndex].f;

        if (sum == x) {
            a = lIndex;
            b = rIndex;

            return true;
        }
        else if (sum < x) {
            ++lIndex;
        }
        else {
            --rIndex;
        }
    }

    return false;
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

    sort(arrList.begin(), arrList.end(), Comp);
    
    bool isPossiable = false;

    // for (int i = 0; i < n; ++i) {
    //     cout << arrList[i].f << " " << arrList[i].s << endl;
    // }

    for (int i = n - 1; i >= 0; --i) {
        int left = x - arrList[i].f;
        c = i;

        auto it = upper_bound(arrList.begin(), arrList.end(), left, CompBinary);
        int subN = it - arrList.begin();

        if (FindSubSum(arrList, min(subN, i), left)) {
            isPossiable = true;

            vector<int> ans(3);
            ans[0] = arrList[a].s;
            ans[1] = arrList[b].s;
            ans[2] = arrList[c].s;

            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

            break;
        }
    }

    if (!isPossiable) {
        cout << "IMPOSSIBLE" << endl;
    }
}
    