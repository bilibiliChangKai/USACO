#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;

using namespace std;

vector<unsigned int> cowList;

int main() {
    int c, n;
    cin >> c >> n;
    getchar();
    
    unsigned int cow;
    char ch;
    for (int i = 0; i < n; ++i)
    {
        cow = 0;
        for (int j = 0; j < c; ++j) {
            ch = getchar();
            cow <<= 1;
            cow += (ch == 'G') ? 1 : 0;
        }

        getchar();
        cowList.push_back(cow);
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << cowList[i] << endl;
    // } 


    vector<int> maxDiffSize(n);
    for (int i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j)
        {
            unsigned int diff = cowList[i] ^ cowList[j];
            int count = __builtin_popcount(diff);
            
            maxDiffSize[i] = max(maxDiffSize[i], count);
            maxDiffSize[j] = max(maxDiffSize[j], count);
        } 
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << maxDiffSize[i] << endl;
    } 
}