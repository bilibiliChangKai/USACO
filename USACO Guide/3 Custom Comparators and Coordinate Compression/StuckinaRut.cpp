#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define Pair pair<int, int>
#define wNum first
#define aNum second.first
#define bNum second.second

bool Comp(pair<int, Pair> &left, pair<int, Pair> &right) {
    return left.wNum > right.wNum;
}

const int N = 1000;

Pair northCows[N];
Pair eastCows[N];

// east => x + 1
// north => y + 1
int main() {
    int n;
    cin >> n;
    getchar();
    
    int eCount = 0;
    int nCount = 0;

    int x, y;
    char direct;

    for (size_t i = 0; i < n; i++)
    {
        direct = getchar();
        cin >> x >> y;
        getchar();

        if (direct == 'E') {
            eastCows[eCount++] = Pair(x, y);
        }
        else {
            northCows[nCount++] = Pair(x, y);
        }
    }
    
    sort()
    while ()
}