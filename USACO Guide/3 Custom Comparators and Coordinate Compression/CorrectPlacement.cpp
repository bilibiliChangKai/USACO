#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Fri {
    int x;
    int y;
    int index;

    Fri() : x(0), y(0) {}
};


bool CompX(const Fri &left, const Fri &right) {
    return left.x != right.x ? left.x < right.x : left.y > right.y;
}

const int N = 200000;

Fri fris[N];
int ans[N];

void solve() {
    int n;
    cin >> n;

    int x, y;

    for (size_t i = 0; i < n; i++)
    {
        cin >> x >> y;

        fris[i].x = min(x, y);
        fris[i].y = max(x, y);
        fris[i].index = i;

        ans[i] = -1;
    }

    // Sort
    sort(fris, fris + n, CompX);

    // for (int i = 0; i < n; i++) {
    //     cout << "Fri: " << fris[i].index << " " << fris[i].x << " " << fris[i].y << endl;
    // }

    Fri& minYFri = fris[0];

    for (int i = 1; i < n; ++i) {
        Fri& fri = fris[i];
        if (fri.y > minYFri.y) {
            ans[fri.index] = minYFri.index + 1;
        }
        else if (fri.y < minYFri.y) {
            minYFri = fri;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << "Area: " << i << " " << areas[i].GetArea() << " " << rAreas[i].GetArea() << endl;
    // }
    // cout << "AreaIndexY: " << index << endl;

    // for (int i = 0; i < nCount; i++) {
    //     cout << "N: " << northCows[i].index << " " << northCows[i].x << " " << northCows[i].y << endl;
    // }

    cout << ans[0];

    for (int i = 1; i < n; i++) {
        cout << " " << ans[i];
    }

    cout << endl;
}

int main() {
   int t;
   cin >> t;

   for (int i = 0; i < t; i++) {
        solve();
   }
}