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

int citys[N];
int nets[N];

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> citys[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nets[i];
    }

    
    int left = 0;
    int right = left + 1;
    int maxR = 0;

    if (m == 1) {
        for (int i = 0; i < n; i++) {
            int distance = abs(citys[i] - nets[0]);
            maxR = max(maxR, distance);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            while (true) {
                if (right == m - 1 || citys[i] <= nets[right]) {
                    break;
                }

                left++;
                right = left + 1;
            }

            

            int distanceA = abs(citys[i] - nets[left]);
            int distanceB = abs(citys[i] - nets[right]);
            int minDistance = min(distanceA, distanceB);

            //cout << "Distance: " << left << " " << right << " " << distanceA << " " << distanceB << endl;

            maxR = max(maxR, minDistance);
        }
    }

    cout << maxR << endl;
}
    