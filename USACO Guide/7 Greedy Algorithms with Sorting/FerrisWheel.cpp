#include <iostream>
#include <queue>
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

const int N = 200000;

int people[N];

void solve() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    sort(people, people + n);

    int counts = 0;
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        if (i == j) {
            counts++;
            break;
        }

        if (people[i] + people[j] > x) {
            counts++;
            j--;
        }
        else {
            counts++;
            i++;
            j--;
        }
    }

    cout << counts << endl;
}

int main() {
    solve();
}
