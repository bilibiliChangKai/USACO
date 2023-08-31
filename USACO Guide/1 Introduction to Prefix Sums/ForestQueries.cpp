#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void PrefixSumMatrix(vector<vector<int> > &v, int n) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int> > v(n + 1);

    // reset
    for (int i = 0; i < n + 1; ++i) {
        v[i].resize(n + 1);

        for (int j = 0; j < n + 1; ++j) {
            v[i][j] = 0;
        }
    }

    string temp;
    for (int i = 1; i < n + 1; ++i) {
        cin >> temp;
        for (int j = 1; j < n + 1; ++j) {
            v[i][j] = temp[j - 1] == '*' ? 1 : 0;
        }
    }

    PrefixSumMatrix(v, n);

    // cout << "Matrix:" << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << v[i][j] << ' ';
    //     }

    //     cout << endl;
    // }
    

    int beginX, beginY, endX, endY;
    for (int i = 0; i < q; ++i) {
        cin >> beginX >> beginY >> endX >> endY;
        cout << (v[endX][endY] - v[endX][beginY - 1] - v[beginX - 1][endY] + v[beginX - 1][beginY - 1]) << endl;
    }

    return 0;
}