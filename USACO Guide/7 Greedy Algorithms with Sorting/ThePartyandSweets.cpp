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

const int N = 100000;

long long boySweet[N];
long long girlSweet[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> boySweet[i];
    }

    long long girlSweetSum = 0;
    for (int i = 0; i < m; i++) {
        cin >> girlSweet[i];

        girlSweetSum += girlSweet[i];
    }

    sort(boySweet, boySweet + n);
    sort(girlSweet, girlSweet + m);

    long long sweetNums = 0;
    if (girlSweet[0] < boySweet[n - 1]) {
        cout << -1 << endl;

        return;
    }


    if (girlSweet[0] == boySweet[n - 1]) {
        for (int i = 0; i < n - 1; ++i) {
            sweetNums += boySweet[i] * m;
        }

        sweetNums += girlSweetSum;
    }
    else {
        for (int i = 0; i < n - 2; ++i) {
            sweetNums += boySweet[i] * m;
        }

        sweetNums += boySweet[n - 2] * (m - 1) + girlSweet[0];
        sweetNums += girlSweetSum - girlSweet[0] + boySweet[n - 1];
    }

    cout << sweetNums << endl;
}

int main() {
    solve();
}
