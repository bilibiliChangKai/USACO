#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("paintbarn.in");
    fout.open("paintbarn.out");

    int n, q, k;
    n = 1002;
    fin >> q >> k;
    vector<vector<int> > v(n + 1);

    // reset
    for (int i = 0; i < n + 1; ++i) {
        v[i].resize(n + 1);

        for (int j = 0; j < n + 1; ++j) {
            v[i][j] = 0;
        }
    }

    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;

    int beginX, beginY, endX, endY;
    for (int i = 0; i < q; ++i) {
        fin >> beginX >> beginY >> endX >> endY;
        ++beginX;
        ++beginY;
        //++endX;
        //++endY;

        minX = min(minX, beginX);
        minY = min(minY, beginY);
        maxX = max(maxX, endX);
        maxY = max(maxY, endY);

        v[beginX][beginY] += 1;
        v[endX + 1][endY + 1] += 1;

        v[endX + 1][beginY] -= 1;
        v[beginX][endY + 1] -= 1;
    }



    int sum = 0;
    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            if (v[i][j] == k) {
                sum += 1;
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

    fout << sum << endl;

    return 0;


}