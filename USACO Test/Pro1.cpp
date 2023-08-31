#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int crowNumber;
    char line;

    cin >> crowNumber;
    line = getchar();


    vector<int> priceArr(crowNumber);
    for (int i = 0; i < crowNumber; ++i) {
        cin >> priceArr[i];
        line = getchar();
    }

    
    sort(priceArr.begin(), priceArr.end());
    
    long long maxPrice = 0;
    int maxNum = 0;

    for (int i = 0; i < crowNumber; ++i) {
        long long currentPrice = (long long)(crowNumber - i) * priceArr[i];
        if (currentPrice > maxPrice) {
            maxPrice = currentPrice;
            maxNum = priceArr[i];
        }
    }

    cout << maxPrice << ' ' << maxNum << endl;

    return 0;
}