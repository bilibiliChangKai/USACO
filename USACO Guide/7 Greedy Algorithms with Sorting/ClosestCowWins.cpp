#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 200000;

struct Glass {
    int pos;
    long long value;

    Glass() : pos(0), value(0) {}
};

long long glassPrefix[N + 2];
Glass glasses[N];
int oppoCows[N];

bool CompPos(const Glass& a, const Glass& b) {
    return a.pos < b.pos;
}

bool CompIntPos(const Glass& a, const int b) {
    return a.pos < b;
}

bool CompFloatPos(const Glass& a, const float b) {
    return a.pos < b;
}

struct GlassGroup {
    bool isSingleGroup;
    
    int startIndex;
    int endIndex;

    long long sumValue;

    void SetSingleGroup(int left, int right) {
        startIndex = left;
        endIndex = right;

        isSingleGroup = true;

        sumValue = glassPrefix[endIndex] - glassPrefix[startIndex];
    }

    void SetMidGroup(int left, int right, int leftCowPos, int rightCowPos) {
        startIndex = left;
        endIndex = right;

        int midCowPos = (rightCowPos - leftCowPos + 1) / 2;

        if (endIndex == startIndex + 1) {
            isSingleGroup = true;

            sumValue = glassPrefix[endIndex] - glassPrefix[startIndex];
            return;
        }

        Glass comp;

        isSingleGroup = false;
        sumValue = 0;
        for (int i = left; i < right; ++i) {
            int glassPos = glasses[i].pos;

            int firstDis = i;
            
            comp.pos = glassPos + midCowPos;
            int lastDis = lower_bound(glasses + left, glasses + right, comp, CompPos) - glasses;

            if (firstDis == left && lastDis == right) {
                isSingleGroup = true;

                sumValue = glassPrefix[endIndex] - glassPrefix[startIndex];
                return;
            }

            long long newSumValue = glassPrefix[lastDis] - glassPrefix[firstDis];
            if (newSumValue > sumValue) {
                sumValue = newSumValue;
            }
        }
    }

    bool operator()(const GlassGroup& a, const GlassGroup& b) const {
        return a.sumValue < b.sumValue;
    }
};

priority_queue<GlassGroup, vector<GlassGroup>, GlassGroup> pq;

void SplitGlassGroup(const GlassGroup& group) {
    if (group.isSingleGroup) {
        return;
    }

    GlassGroup newGroup;
    newGroup.SetSingleGroup(group.startIndex, group.endIndex);
    newGroup.sumValue = newGroup.sumValue - group.sumValue;
    pq.push(newGroup);
}


void solve() {
    long long k, m, n;

    cin >> k >> m >> n;

    for (int i = 0; i < k; ++i) {
        cin >> glasses[i].pos >> glasses[i].value;
    }

    for (int i = 0; i < m; ++i) {
        cin >> oppoCows[i];
    }

    sort(glasses, glasses + k, CompPos);
    sort(oppoCows, oppoCows + m);

    glassPrefix[0] = 0;
    for (int i = 0; i < k; ++i) {
        glassPrefix[i + 1] = glassPrefix[i] + glasses[i].value;
    }

    GlassGroup group;
    Glass comp;
    comp.pos = oppoCows[0];

    // find first and end
    int firstDis = lower_bound(glasses, glasses + k, comp, CompPos) - glasses;
    if (firstDis > 0) {
        group.SetSingleGroup(0, firstDis);
        pq.push(group);
    }

    comp.pos = oppoCows[m - 1];
    int lastDis = upper_bound(glasses, glasses + k, comp, CompPos) - glasses;
    if (lastDis < k) {
        group.SetSingleGroup(lastDis, k);
        pq.push(group);
    }


    for (int i = 0; i < m - 1; ++i) {
        comp.pos = oppoCows[i];
        firstDis = upper_bound(glasses, glasses + k, comp, CompPos) - glasses;

        comp.pos = oppoCows[i + 1];
        lastDis = lower_bound(glasses, glasses + k, comp, CompPos) - glasses;

        if (firstDis >= k) {
            break;
        }

        //cout << "Find: " << i << " " << firstDis << " " << lastDis << endl;
        if (firstDis != lastDis) {
            group.SetMidGroup(firstDis, lastDis, oppoCows[i], oppoCows[i + 1]);
            pq.push(group);
        }
    }

    // cout << "Queue: " << endl;
    // priority_queue<GlassGroup, vector<GlassGroup>, GlassGroup> debugQ(pq);
    // while (!debugQ.empty()) {
    //     group = debugQ.top();
    //     debugQ.pop();

    //     cout << group.startIndex << " " << group.endIndex << " " << group.sumValue << " " << group.isSingleGroup << endl;
    // }

    long long sumValue = 0;
    while (!pq.empty() && n > 0) {
        --n;
        group = pq.top();
        pq.pop();

        sumValue += group.sumValue;
        if (!group.isSingleGroup) {
            SplitGlassGroup(group);
        }
    }

    cout << sumValue << endl;
}

int main() {
    solve();
}