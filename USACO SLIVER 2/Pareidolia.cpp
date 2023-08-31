#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <queue>
#include <set>
#include <string>

#define Pair pair<int, int>
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;

using namespace std;

// void AddPrefixSumList(vector<long long> &arrList, int l, int r) {
//     ++arrList[0];
//     --arrList[l];
//     ++arrList[r];
// }


long long sum = 0;
string str;
string bessie = "bessie";
map<char, vector<int>> charIndexMap;
vector<int> bIndex;
vector<int> sIndex;
vector<int> eIndex;
vector<int> iIndex;

void CalculateAllBessie() {
    for (int a = 0; a < bIndex.size(); ++a) {
        int i0 = bIndex[a];
        
        int bl = distance(eIndex.begin(), upper_bound(eIndex.begin(), eIndex.end(), i0));
        for (int b = bl; b < eIndex.size(); ++b) {
            int i1 = eIndex[b];

            int cl = distance(sIndex.begin(), lower_bound(sIndex.begin(), sIndex.end(), i1));
            for (size_t c = cl; c < sIndex.size(); c++)
            {
                int i2 = sIndex[c];

                int dl = distance(sIndex.begin(), lower_bound(sIndex.begin(), sIndex.end(), i2));
                for (size_t d = dl; d < sIndex.size(); d++)
                {
                    int i3 = sIndex[d];

                    int el = distance(iIndex.begin(), lower_bound(iIndex.begin(), iIndex.end(), i3));
                    for (size_t e = el; e < iIndex.size(); e++)
                    {
                        int i4 = iIndex[e];

                        int fl = distance(eIndex.begin(), lower_bound(eIndex.begin(), eIndex.end(), i4));
                        for (int f = fl; f < eIndex.size(); ++f) {
                            int i5 = eIndex[f];

                            cout << i0 << ' ' << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;

                            sum += (i0 + 1) * (str.size() - i5);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> str;

    //vector<long long> arrList(str.size() + 1);

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'b') {
            bIndex.push_back(i);
        }
        else if (str[i] == 's') {
            sIndex.push_back(i);
        }
        else if (str[i] == 'e') {
            eIndex.push_back(i);
        }
        else if (str[i] == 'i') {
            iIndex.push_back(i);
        }
    }


    CalculateAllBessie();

    // int leftIndex;
    // int rightIndex;
    // int currentIndex = 0;
    
    // for (int i = 0; i <= str.size(); ++i) {
    //     if (str[i] == bessie[currentIndex]) {
    //         ++currentIndex;
    //         if (currentIndex == 1) {
    //             leftIndex = i;
    //         }
    //         else if (currentIndex == bessie.size()) {
    //             rightIndex = i;
    //             cout << "Index: " << leftIndex << " " << rightIndex << endl;

    //             currentIndex = 0;
                
    //             // AddPrefixSumList(arrList, leftIndex, rightIndex);
    //             // sum += (leftIndex - 1) * (str.size() - rightIndex);
    //         }
    //     }
    // }

    // cout << "List: " << endl;
    // for (int i = 0; i < arrList.size(); ++i) {
    //     cout << arrList[i] << " ";
    // }
    // cout << endl;

    // int count = 0;
    // for (int i = 1; i < arrList.size(); ++i) {
    //     arrList[i] += arrList[i - 1];
    //     count += arrList[i];
    // }

    // cout << "List: " << endl;
    // for (int i = 0; i < arrList.size(); ++i) {
    //     cout << arrList[i] << " ";
    // }
    // cout << endl;

    cout << sum << endl;
}
