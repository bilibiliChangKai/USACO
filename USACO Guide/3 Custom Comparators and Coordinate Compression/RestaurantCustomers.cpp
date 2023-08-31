#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

bool Comp(pair<int, int> &l, pair<int, int> &r) {
    return l.f != r.f ? l.f < r.f : l.s < r.s;
}

int main() {
    int n, a, b;
    cin >> n;

    vector<pair<int, int> > timeList;
    vector<int> indexList;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        timeList.push_back(pair<int, int>(a, b));
        
        indexList.push_back(a);
        indexList.push_back(b);
    }

    sort(indexList.begin(), indexList.end());
    //sort(timeList.begin(), timeList.end(), Comp);

    // 使用 std::unique 算法和 erase 函数删除重复元素
    auto it = unique(indexList.begin(), indexList.end());
    indexList.erase(it, indexList.end());

    vector<int> prefixSum(indexList.size() + 2);
    for (int i = 0; i < n; ++i) {
        auto fit = lower_bound(indexList.begin(), indexList.end(), timeList[i].f);
        auto sit = lower_bound(indexList.begin(), indexList.end(), timeList[i].s);

        int fIndex = (fit - indexList.begin());
        int sIndex = (sit - indexList.begin());

        prefixSum[fIndex] += 1;
        prefixSum[sIndex] -= 1;
    }

    int maxNum = 0;
    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] += prefixSum[i - 1];

        maxNum = max(maxNum, prefixSum[i]);
    }

    cout << maxNum << endl;
}