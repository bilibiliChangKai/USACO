#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define IsG(x) (x) 

void Caculate() {
    int crowNumber, stepNumber;
    char line;

    cin >> crowNumber >> stepNumber;
    line = getchar();

    vector<bool> crowArr(crowNumber);
    vector<char> plantArr(crowNumber, '.');
    for (int i = 0; i < crowNumber; ++i) {
        crowArr[i] = getchar() == 'G';
    }
    getchar();

    int temp;
    int platNum = 0;

    for (int i = 0; i < crowNumber; ++i) {
        if (IsG(crowArr[i])) {
            ++platNum;
            plantArr[min(i + stepNumber, crowNumber - 1)] = 'G';
            i += 2 * stepNumber;
        }
    }

    for (int i = 0; i < crowNumber; ++i) {
        if (!IsG(crowArr[i])) {
            ++platNum;
            temp = min(i + stepNumber, crowNumber - 1);
            if (plantArr[temp] == 'G') {
                plantArr[temp - 1] = 'H';
            }
            else {
                plantArr[temp] = 'H';
            }
            
            i += 2 * stepNumber;
        }
    }

    cout << platNum << endl;
    for (int i = 0; i < crowNumber; ++i) {
        cout << plantArr[i];
    }
    cout << endl;
}

int main() {

    int nums;
    cin >> nums;
    getchar();

    for (int i = 0; i < nums; ++i) {
        Caculate();
    }

    return 0;
}
