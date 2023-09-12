#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;


bool Comp(const string &s1, const string &s2) {
    return s1 + s2 < s2 + s1;
}

const int N = 100000;

long long dDoubleList[N * 2];
long long dList[N];

bool solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n * 2; i++)
    {
        cin >> dDoubleList[i];
    }
    
    sort(dDoubleList, dDoubleList + (2 * n));

    for (int i = 0; i < n; i++) {
        if (dDoubleList[i * 2] != dDoubleList[i * 2 + 1]) {
            return false;
        }
        
        dList[i] = dDoubleList[i * 2];
    }

    // cout << "n: " << n << endl;

    if (dList[n - 1] % (2 * n) != 0) {
        return false;
    }
    
    long long oriValue = dList[n - 1] / (2 * n);

    // for (int i = 0; i < n; i++) {
    //     cout << "Array: " << i << " " << dList[i] << endl;
    // }

    if (n > 1) {
        for (int i = n - 2; i >= 0; --i) {
            long long diff = dList[i + 1] - dList[i];

            // cout << "i: " << i << " " << diff << endl;

            if (diff == 0 || diff % (2 * (i + 1)) != 0) {
                return false;
            }

            oriValue -= diff / (2 * (i + 1));
            if (oriValue <= 0) {
                return false;    
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        bool ret = solve();

        cout << (ret ? "YES" : "NO") << endl;
    }
}