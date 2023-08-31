#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

using namespace std;

#define f first
#define s second

bool Comp(pair<int, int> &l, pair<int, int> &r) {
    return l.f != r.f ? l.f < r.f : l.s < r.s;
}

bool Equal(pair<int, int> &l, pair<int, int> &r) {
    return l.f == r.f;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("lifeguards.in");
    fout.open("lifeguards.out");

    int n, a, b;
    fin >> n;

    vector<pair<int, int> > timeList;
    vector<int> indexList;
    for (int i = 0; i < n; ++i) {
        fin >> a >> b;
        timeList.push_back(pair<int, int>(a, b));
        
        indexList.push_back(a);
        indexList.push_back(b);
    }

    sort(indexList.begin(), indexList.end());
    //sort(timeList.begin(), timeList.end(), Comp);

    // 使用 std::unique 算法和 erase 函数删除重复元素
    auto it = unique(indexList.begin(), indexList.end());
    indexList.erase(it, indexList.end());

    vector<int> prefixSum(indexList.size());
    for (int i = 0; i < n; ++i) {
        auto fit = lower_bound(indexList.begin(), indexList.end(), timeList[i].f);
        auto sit = lower_bound(indexList.begin(), indexList.end(), timeList[i].s);

        int fIndex = (fit - indexList.begin());
        int sIndex = (sit - indexList.begin());

        prefixSum[fIndex] += 1;
        prefixSum[sIndex] -= 1;

        timeList[i].f = fIndex;
        timeList[i].s = sIndex;
    }

    int currentCowNum = 0;
    // 第一次转换
    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] += prefixSum[i - 1];
        if (prefixSum[i - 1] > 0) {
            currentCowNum += indexList[i] - indexList[i - 1];
        }
    }

    // 第二次转换
    for (int i = prefixSum.size() - 1; i >= 1; --i) {
        prefixSum[i] = prefixSum[i - 1] == 1 ? indexList[i] - indexList[i - 1] : 0;
    }
    prefixSum[0] = 0;

    // 再次求和
    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] += prefixSum[i - 1];
    }



    int minCowNum = INT_MAX;
    for (int i = 0; i < n; ++i) {
        minCowNum = min(minCowNum, prefixSum[timeList[i].s] - prefixSum[timeList[i].f]);
    }

    fout << currentCowNum - minCowNum << endl;
}