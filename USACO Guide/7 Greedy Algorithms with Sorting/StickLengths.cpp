#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 200000;

int arr[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int value = arr[n / 2];
    long long diff = 0;
    for (int i = 0; i < n; i++) {
        diff += abs(arr[i] - value);
    }

    cout << diff << endl;
}

int main() {
    solve();
}
    