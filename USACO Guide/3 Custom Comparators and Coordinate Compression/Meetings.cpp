#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <limits.h>

using namespace std;

const int N = 50000;

int toRightCow[N];
int toLeftCow[N];

// #TODO: modify
pair<int, int> oriWeights[N];

bool Comp(const pair<int, int> &left, const pair<int, int> &right) {
    return left.first < right.first;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("meetings.in");
    fout.open("meetings.out");


    int n, l;
    fin >> n >> l;

    int pos = 0;
    int weight = 0;
    int right = 0;

    int leftCount = 0;
    int rightCount = 0;
    int totalWeight = 0;
    for (size_t i = 0; i < n; i++)
    {
        fin >> weight >> pos >> right;

        oriWeights[i].first = pos;
        oriWeights[i].second = weight;
        totalWeight += weight;

        if (right == 1) {
            toRightCow[rightCount] = pos;

            rightCount++;
        }
        else {
            toLeftCow[leftCount] = pos;

            leftCount++;
        }
    }

    sort(oriWeights, oriWeights + n, Comp);
    sort(toLeftCow, toLeftCow + leftCount);
    sort(toRightCow, toRightCow + rightCount);

    // cell int
    totalWeight = (totalWeight + 1) / 2;
    int currentWeight = 0;
    int li = 0;
    int ri = rightCount - 1;

    int minHitTimes = 0;
    while (currentWeight < totalWeight) {
        if (li == leftCount) {
            currentWeight += oriWeights[ri + leftCount].second;
            --ri;

            minHitTimes = l - toRightCow[ri];
        }
        else if (ri < 0) {
            currentWeight += oriWeights[li].second;
            ++li;

            minHitTimes = toLeftCow[li];
        }
        else {
            int lt = toLeftCow[li];
            int rt = l - toRightCow[ri];

            // maybe lt == rt
            if (lt <= rt) {
                currentWeight += oriWeights[li].second;
                ++li;

                minHitTimes = lt;
            }

            if (lt >= rt) {
                currentWeight += oriWeights[ri + leftCount].second;
                --ri;

                minHitTimes = rt;
            }
        }

        // cout << "currentWeight: " << currentWeight << " " << minHitTimes << endl;
    }

    // cout << "Count: " << leftCount << " " << rightCount << endl;
    // cout << li << " " << ri << endl;
    
    int hitCount = 0;
    for (int li = leftCount - 1; li >= 0; li--)
    {
        int leftPos = toLeftCow[li];

        int* ra = lower_bound(toRightCow, toRightCow + rightCount, leftPos - (2 * minHitTimes));
        int* rb = lower_bound(toRightCow, toRightCow + rightCount, leftPos);
        hitCount += rb - ra;
    }
    
    // cout << "Weight: " << totalWeight << " hitTime: " << minHitTimes << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << oriWeights[i].second << " ";
    // }
    // cout << endl;
    

    fout << hitCount << endl;
}