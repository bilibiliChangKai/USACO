#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

using namespace std;

#define f first
#define s second

bool CompPair(pair<int, int> &l, pair<int, int> &r) {
    return l.f > r.f;
}

bool CompInt(int a, int b) {
    return a > b;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("rental.in");
    fout.open("rental.out");

    int n, m, r, a, b;
    fin >> n >> m >> r;

    vector<int> cowMilkList;  // n
    vector<pair<int, int> > shopPriceList;  // m
    vector<int> rentPriceList;  // r

    for (int i = 0; i < n; ++i) {
        fin >> a;
        cowMilkList.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        fin >> a >> b;
        shopPriceList.push_back(pair<int, int>(b, a));
    }

    for (int i = 0; i < r; ++i) {
        fin >> a;
        rentPriceList.push_back(a);
    }

    // 这里牛奶产量由低到高，注意
    sort(cowMilkList.begin(), cowMilkList.end());

    // 这两组由高到低
    sort(shopPriceList.begin(), shopPriceList.end(), CompPair);
    sort(rentPriceList.begin(), rentPriceList.end(), CompInt);

    vector<long long> shopPrefixSumList(n);
    vector<long long> rentPrefixSumList(n);


    int shopIndex = 0;
    int shopSize = shopPriceList.size();
    int rentIndex = 0;
    int rentSize = rentPriceList.size();
    for (int i = 0; i < n; ++i) {
        rentPrefixSumList[i] = rentIndex < rentSize ? rentPriceList[rentIndex] : 0;
        ++rentIndex;


        while (shopIndex < shopSize && cowMilkList[n - 1 - i] > 0) {
            int minMilkNum = min(cowMilkList[n - 1 - i], shopPriceList[shopIndex].s);
            cowMilkList[n - 1 - i] -= minMilkNum;
            shopPriceList[shopIndex].s -= minMilkNum;

            shopPrefixSumList[n - 1 - i] += minMilkNum * shopPriceList[shopIndex].f;
            if (shopPriceList[shopIndex].s == 0) {
                ++shopIndex;
            }
        }
    }

    
    for (int i = 1; i < n; ++i) {
        rentPrefixSumList[i] += rentPrefixSumList[i - 1];
        shopPrefixSumList[n - 1 - i] += shopPrefixSumList[n - i];
    }

    long long maxPrice = max(rentPrefixSumList[n - 1], shopPrefixSumList[0]);
    for (int i = 0; i < n - 1; ++i) {
        maxPrice = max(maxPrice, rentPrefixSumList[i] + shopPrefixSumList[i + 1]);
    }

    fout << maxPrice << endl;
}