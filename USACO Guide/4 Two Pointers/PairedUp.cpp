#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>

using namespace std;

const int N = 100000;

#define Pair pair<int, int>
#define num first
#define volume second

Pair cows[N];

bool Comp(const Pair& p1, const Pair& p2) {
    return p1.volume < p2.volume;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("pairup.in");
    fout.open("pairup.out");

    int n;
    fin >> n;
    
    int v1, v2;
    for (int i = 0; i < n; i++) {
        fin >> v1 >> v2;

        cows[i].num = v1;
        cows[i].volume = v2;
    }

    sort(cows, cows + n, Comp);

    int maxTime = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int leftTime = cows[left].volume;
        int rightTime = cows[right].volume;

        maxTime = max(maxTime, leftTime + rightTime);

        int minNum = min(cows[left].num, cows[right].num);
        cows[left].num -= minNum;
        cows[right].num -= minNum;
        if (cows[left].num <= 0) {
            ++left;
        }

        if (cows[right].num <= 0) {
            --right;
        }
    }


    fout << maxTime << endl;
}
    