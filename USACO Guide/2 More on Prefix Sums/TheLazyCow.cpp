#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

#define TO_LEAN(leanX, leanY, x, y, n) \
    leanX = x + y - 1; \
    leanY = n - x + y;

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("lazy.in");
    fout.open("lazy.out");

    int n, k;
    fin >> n >> k;

    int leanSize = n * 2 - 1;
    int leanK = 2 * k + 1;
    vector<vector<int> > v(leanSize + 1);

    // reset
    for (int i = 0; i < leanSize + 1; ++i) {
        v[i].resize(leanSize + 1);

        for (int j = 0; j < leanSize + 1; ++j) {
            v[i][j] = 0;
        }
    }

    int leanX, leanY;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            TO_LEAN(leanX, leanY, i, j, n);
            fin >> v[leanX][leanY];
        }
    }

    for (int i = 1; i <= leanSize; i++) {
        for (int j = 1; j <= leanSize; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }

    int maxNum = INT_MIN;
    if (k >= leanSize) {
        maxNum = v[leanSize][leanSize];
    }
    else {
        for (int i = leanK; i <= leanSize; i++) {
            for (int j = leanK; j <= leanSize; j++) {
                maxNum = max(maxNum, v[i][j] - v[i - leanK][j] - v[i][j - leanK] + v[i - leanK][j - leanK]);
            }
        }
    }

    // cout << "Matrix:" << minX << " " << minY << " " << maxX << " " << maxY << endl;
    // for (int i = minX; i <= maxX; i++) {
    //     for (int j = minY; j <= maxY; j++) {
    //         cout << v[i][j] << ' ';
    //     }

    //     cout << endl;
    // }

    fout << maxNum << endl;

    return 0;
}