#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;

using namespace std;

vector<long long> prefixSumList;
vector<long long> arrList;
vector<long long> sortArrList;

int main() {
    int n, m;
    cin >> n;

    arrList.push_back(0);
    sortArrList.push_back(0);
    prefixSumList.push_back(0);

    long long a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        arrList.push_back(a);
        sortArrList.push_back(a);
    }

    sort(sortArrList.begin(), sortArrList.end());

    long long oriSum = 0;
    for (int i = 1; i <= n; ++i)
    {
        oriSum += i * sortArrList[i];
        prefixSumList.push_back(sortArrList[i] + prefixSumList[i - 1]);
    }

    // debug
    // cout << "OriSum: " << oriSum << " List:" << endl;
    // for (int i = 0; i <= n; ++i)
    // {
    //     cout << prefixSumList[i] << endl;
    // }

    cin >> m;
    int ai, aj;
    for (int i = 0; i < m; ++i) {
        cin >> ai >> aj;

        long long oldValue = arrList[ai];
        long long newValue = aj;
        int oldIndex = distance(sortArrList.begin(), lower_bound(sortArrList.begin() + 1, sortArrList.end(), oldValue));
        int newIndex = distance(sortArrList.begin(), lower_bound(sortArrList.begin() + 1, sortArrList.end(), newValue));
        
        long long ans = oriSum;

        if (newIndex > oldIndex) {
            --newIndex;
            ans -= oldIndex * oldValue;
            ans += newIndex * newValue;
            ans += prefixSumList[oldIndex] - prefixSumList[newIndex];
        }
        else {
            ans -= oldIndex * oldValue;
            ans += newIndex * newValue;
            ans += prefixSumList[oldIndex - 1] - prefixSumList[newIndex - 1];
        }

        // cout << oldIndex << " " << oldValue << " " << newIndex << " " << newValue << endl;

        cout << ans << endl;
    }
}
