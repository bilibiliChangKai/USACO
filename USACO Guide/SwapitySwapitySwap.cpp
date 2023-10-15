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

struct GraphNode {
    int nextID;
    int groupLen;

    GraphNode() : nextID(0), groupLen(-1) {}
};

GraphNode graph[N + 1];
int outArr[N + 1];

void CalculateGraphLength(int i) {
    int len = 1;
    int currentID = i;
    while (graph[currentID].nextID != i) {
        len++;
        currentID = graph[currentID].nextID;
    }

    currentID = i;
    for (int i = 0; i < len; ++i) {
        graph[currentID].groupLen = len;
        currentID = graph[currentID].nextID;
    }
}

void CalculateOutputArr(int i, int step, int len) {
    int currentID = i;
    for (int j = 0; j < step; ++j) {
        currentID = graph[currentID].nextID;
    }

    int outArrID = currentID;
    currentID = i;
    for (int j = 0; j < len; ++j) {
        outArr[currentID] = outArrID;

        currentID = graph[currentID].nextID;
        outArrID = graph[outArrID].nextID;
    }
}

void solve() {
    ifstream fin;
    ofstream fout;

    fin.open("swap.in");
    fout.open("swap.out");

    int n, m, k;
    fin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) {
        graph[i].nextID = i;
        graph[i].groupLen = -1;
    }

    int left, right, mid;
    for (int i = 0; i < m; ++i) {
        fin >> left >> right;

        mid = (left + right + 1) / 2;
        for (int j = 0; j < mid - left; ++j) {
            int temp = graph[left + j].nextID;
            graph[left + j].nextID = graph[right - j].nextID;
            graph[right - j].nextID = temp;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (graph[i].groupLen == -1) {
            CalculateGraphLength(i);
        }

        if (outArr[i] == 0) {
            int step = k % graph[i].groupLen;
            CalculateOutputArr(i, step, graph[i].groupLen);
        }
    }

    for (int i = 1; i <= n; ++i) {
        fout << outArr[i] << endl;
    }

    // cout << "Group: " << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << graph[i].groupLen << " " << graph[i].nextID << endl;
    // }
}

int main() {
    solve();
}
    