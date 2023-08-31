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
    long long n, k;
    cin >> n >> k;
    
    long long t;
    vector<long long> arrList;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        arrList.push_back(t);
    }

    sort(arrList.begin(), arrList.end());

    int medianIndex = n / 2;
    int i = medianIndex + 1;
    long long num = arrList[medianIndex];
    for (; i < n; ++i) {
        long long padding = (i - medianIndex) * (arrList[i] - arrList[i - 1]);
        if (k < padding) {
            break;
        }

        num = arrList[i];
        k -= padding;
    }

    num += k / (i - medianIndex);

    cout << num << endl;
}
