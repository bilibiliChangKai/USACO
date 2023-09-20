#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>

using namespace std;

const int N = 100;

long long oriVals[N];
vector<long long> vals;

long long rsum[N + 1];
long long conv[N + 1];

long long dpmin[N][N];


long long GetMoveNums(int i, int j) {
    return (conv[i] - conv[j]) - i * (rsum[i] - rsum[j]);
}

long long DPMin(int k, int n) {
    if (n <= k) {
        return 0;
    }

    if (k == 0) {
        return GetMoveNums(0, n);
    }

    long long temp = numeric_limits<long long>::max();
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            long long left = GetMoveNums(0, i);
            long long right = GetMoveNums(i + 1, n);

            temp = min(temp, left + right);
        }

        return temp;
    } 

    // set right door
    for (int i = k - 1; i < n; ++i) {
        if (dpmin[k - 1][i] == -1) {
            dpmin[k - 1][i] = DPMin(k - 1, i);
        }

        long long left = dpmin[k - 1][i];
        long long right = GetMoveNums(i + 1, n);

        temp = min(temp, left + right);
    }

    return temp;
}


long long solve(int n, int k) {
    if (n <= k) {
        return 0;
    }

    memset(dpmin, -1, N * N);

    // cal sum and conv
    rsum[n] = 0;
    conv[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        rsum[i] = vals[i] + rsum[i + 1];

        conv[i] = (i + 1) * vals[i] + conv[i + 1];
    }

    // cout << "Value: ";
    // for (int i =0; i < n; ++i) {
    //     cout << vals[i] << " ";
    // }
    // cout << endl;

    // cout << "RSum: ";
    // for (int i =0; i < n; ++i) {
    //     cout << rsum[i] << " ";
    // }
    // cout << endl;

    // cout << "Conv: ";
    // for (int i =0; i < n; ++i) {
    //     cout << conv[i] << " ";
    // }
    // cout << endl;

    return DPMin(k, n);
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cbarn2.in");
    fout.open("cbarn2.out");

    int n, k;
    fin >> n >> k;
    
    long long v = 0;
    for (int i = 0; i < n; i++) {
        fin >> v;

        oriVals[i] = v;
        vals.push_back(v);
    }

    
    vals.erase(vals.begin());
    long long minSum = solve(n - 1, k - 1);
    for (int i = 1; i < n; ++i) {
        vals.push_back(oriVals[i - 1]);
        vals.erase(vals.begin());

        long long temp = solve(n - 1, k - 1);
        minSum = min(minSum, temp);
    }

    fout << minSum << endl;
}
    