#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;


bool Comp(const string &s1, const string &s2) {
    return s1 + s2 < s2 + s1;
}

const int N = 510000;

string strList[N];

int main() {
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> strList[i];
    }
    
    sort(strList, strList + n, Comp);

    for (int i = 0; i < n; ++i) {
        cout << strList[i];
    }

    cout << endl;
}