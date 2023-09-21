#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>
#include <limits>
#include <cstring>

using namespace std;

const int N = 200000;

long long arr[N];


int main() {
    long long n, k;
    cin >> n >> k;
    
    long long v;
    for (int i = 0; i < n; i++) {
        cin >> v;

        arr[i] = v;
    }

    int countTimes = 0;
    int left = 0;
    int right = 1;
    long long sumValue = arr[0];
    while (right < n || sumValue >= k) {
        // cout << "Enter: " << left << " " << right << " " << sumValue << endl;
        if (sumValue > k) {
            left++;
            sumValue -= arr[left - 1];
        }
        else if (sumValue < k) {
            right++;
            sumValue += arr[right - 1];
        }
        else {
            // equal
            countTimes++;

            left++;
            sumValue -= arr[left - 1];
        }
    }


    cout << countTimes << endl;
}
    