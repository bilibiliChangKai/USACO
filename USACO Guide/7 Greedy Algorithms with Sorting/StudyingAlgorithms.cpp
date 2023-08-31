#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

#define Pair pair<int, int>
#define f first
#define s second

using namespace std;

bool Comp(const Pair &a, const Pair &b) {
    return a.f < b.f;
}

// bool CompBinary(const Pair &a, const int b) {
//     return a.f < b;
// }

bool CompBinary(const int a, const Pair &b) {
    return a < b.f;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    int t;
    vector<int> bookList;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        bookList.push_back(t);
    }

    sort(bookList.begin(), bookList.end());

    int sum = 0; 
    for (int i = 0; i < n; ++i) {
        sum += bookList[i];
        if (sum > x) {
            cout << i - 0 << endl;

            return 0;
        }
    }

    cout << n << endl;
}
    