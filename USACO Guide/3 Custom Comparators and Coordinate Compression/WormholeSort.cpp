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

// #TODD: 需要构建连通图
int main() {
    ifstream fin;
    ofstream fout; 

    fin.open("wormsort.in");
    fout.open("wormsort.out");

    int n, m;
    fin >> n >> m;
    
    map<int, int> cowMap;

    int num;
    for (int i = 1; i <= n; ++i) {
        fin >> num;
        if (num != i) {
            cowMap.insert({num, 1});
        }
    }

    vector<pair<int, Pair>> wormList;
    int a, b, w;
    for (int i = 0; i < m; ++i) {
        fin >> a >> b >> w;
        wormList.push_back({w, {a, b}});
    }

    sort(wormList.begin(), wormList.end(), Comp);

    // for (int i = 0; i < m; ++i) {
    //     fout << wormList[i].aNum << " " << wormList[i].bNum << " " << wormList[i].wNum << endl;
    // }

    int minWormWNum = -1;
    for (int i = 0; i < m; ++i) {
        if (cowMap.size() == 0) {
            break;
        }

        pair<int, Pair> &worm = wormList[i];
        minWormWNum = worm.wNum;

        cowMap.erase(worm.aNum);
        cowMap.erase(worm.bNum);
    }

    fout << minWormWNum << endl;

    fin.close();
    fout.close();
}