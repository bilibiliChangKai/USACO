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

const int N = 1500;

int cows[N];

vector<int> indexVector[256];
string komomiStr;

void solve() {
    int m;
    char color;
    cin >> m >> color;

    vector<int> &indexs = indexVector[color];
    if (indexs.size() + m >= komomiStr.size()) {
        cout << komomiStr.size() << endl;

        return;
    }

    int leftIndex = 0;
    int maxLength = m;

    for (int rightIndex = 0; rightIndex < indexs.size(); rightIndex++)
    {
        while (indexs[rightIndex] - indexs[leftIndex] - (rightIndex - leftIndex) > m) {
            leftIndex++;
        }

        maxLength = max(maxLength, m + (rightIndex - leftIndex + 1));
    }

    cout << maxLength << endl;
}

int main() {
    int n;
    cin >> n;
    cin >> komomiStr;

    for (int i = 0; i < komomiStr.size(); i++)
    {
        indexVector[komomiStr[i]].push_back(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
}
    