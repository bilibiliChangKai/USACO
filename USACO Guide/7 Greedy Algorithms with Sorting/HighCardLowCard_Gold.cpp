#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <set>

#define Pair pair<int, int>
#define f first
#define s second
#define DebugPrint(p) cout << (p).f << " " << (p).s << endl;


using namespace std;


bool CompDescending(const int a, const int b) {
    return a > b;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("cardgame.in");
    fout.open("cardgame.out");

    int n;
    fin >> n;
    
    int t;
    vector<int> elsieCardList;
    vector<int> elsieOwerCardList;

    set<int> bessieAscendingCardSet;
    set<int, greater<int>> bessieDescendingCardSet;
    

    for (int i = 0; i < n; ++i) {
        fin >> t;
        elsieCardList.push_back(t);
        elsieOwerCardList.push_back(t);
    }

    sort(elsieOwerCardList.begin(), elsieOwerCardList.end());

    int cardNum = 0;
    int elsieIndex = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i == elsieOwerCardList[elsieIndex]) {
            ++elsieIndex;
        }
        else {
            ++cardNum;
            if (cardNum <= n / 2) {
                bessieDescendingCardSet.insert(i);
            }
            else {
                bessieAscendingCardSet.insert(i);
            }
        }
    }

    // for (int i = 0; i < n / 2; ++i) {
    //     cout << bessieDescendingCardSet[i] << " " << bessieAscendingCardSet[i] << endl;
    // }

    int i = 0;
    int score = 0;
    for (; i < n / 2; ++i) {
        int card = elsieCardList[i];
        auto it = bessieAscendingCardSet.upper_bound(card);
        if (it != bessieAscendingCardSet.end()) {
            ++score;
            bessieAscendingCardSet.erase(it);
        }
    }

    for (; i < n; ++i) {
        int card = elsieCardList[i];
        auto it = bessieDescendingCardSet.upper_bound(card);
        if (it != bessieDescendingCardSet.end()) {
            ++score;
            bessieDescendingCardSet.erase(it);
        }
    }

    fout << score << endl;
}
