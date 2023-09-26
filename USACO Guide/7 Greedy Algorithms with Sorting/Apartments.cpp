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
int house[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> house[i];
    }

    sort(people, people + n);
    sort(house, house + m);

    int houseIndex = 0;
    int times = 0;
    for (int peopleIndex = 0; peopleIndex < n; peopleIndex++) {
        int p = people[peopleIndex];
        while (houseIndex < m && house[houseIndex] < p - k)
        {
            ++houseIndex;
        }

        if (houseIndex == m) {
            break;
        }
        
        if (house[houseIndex] <= p + k) {
            ++times;
            ++houseIndex;
        }
    }

    cout << times << endl;
}

int main() {
    solve();
}
    