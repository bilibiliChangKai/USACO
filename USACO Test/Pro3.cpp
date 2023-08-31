#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline int GetExpressionIndex(char a, char b) {
    if (a == '0' && b =='0') {
        return 0;
    }
    else if (a == '0' && b == '1') {
        return 1;
    }
    else if (a == '1' && b == '0') {
        return 2;
    }
    else {
        return 3;
    }
}

int CheckUpdate(int currentLen, vector<string> &storeArr, vector<char> &ansArr) {
    bool expressionAppear[4] {false, false, false, false} ;

    // check expression
    for (int i = 0; i < storeArr.size(); ++i) {
        int index = GetExpressionIndex(storeArr[i][currentLen], ansArr[i]);
        expressionAppear[index] = true;
    }

    int appearTimes = 0;
    for (int i = 0; i < 4; ++i) {
        if (expressionAppear[i]) {
            ++appearTimes;
        }
    }

    // 不用看后面的了，可以直接出结果了
    if (appearTimes == 1) {
        return 1;
    }
    else if (appearTimes == 2) {
        // 两种情况，如果是后面一种，就不需要处理了
        if ((expressionAppear[0] & expressionAppear[1]) || (expressionAppear[2] & expressionAppear[3])) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else if (appearTimes == 4) {
        return 0;
    }

    // 这里需要移除一些同样的样本
    char removeKey = '0';
    if (expressionAppear[0] & expressionAppear[1]) {
        removeKey = '1';
    }
    else {
        removeKey = '0';
    }

    for (int i = storeArr.size() - 1; i >= 0; --i) {
        if (storeArr[i][currentLen] == removeKey) {
            storeArr.erase(storeArr.begin() + i);
            ansArr.erase(ansArr.begin() + i);
        }
    }
    
    // 这里表示继续
    return -1;
}

bool Caculate() {
    int ansNum, bitNum;
    char line;

    cin >> bitNum >> ansNum;
    line = getchar();

    vector<string> storeArr(ansNum);
    vector<char> ansArr(ansNum);

    // 记录还没使用过的数组
    vector<int> remainIndexArr(bitNum);

    for (int i = 0; i < ansNum; ++i) {
        cin >> storeArr[i] >> ansArr[i];
    }

    for (int i = 0; i < bitNum; ++i) {
        remainIndexArr[i] = i;
    }

    while (remainIndexArr.size() > 0) {
        int i = 0;
        for (; i < remainIndexArr.size(); ++i) {        
            int index = remainIndexArr[i];
            int result = CheckUpdate(index, storeArr, ansArr);
            // cout << "Debug: " << result << endl;

            // 这里表示满足条件
            if (result == 1) {
                return true;
            }
            else if (result == -1) {
                // result == -1 表示可以先处理
                break;
                
            }

            // -1 => continue
        }
    
        // 这里表示所有的情况
        if (i == remainIndexArr.size()) {
            return false;
        }
        else {
            remainIndexArr.erase(remainIndexArr.begin() + i);
        }
    }

    return false;
}

int main() {

    int nums;
    cin >> nums;
    
    for (int i = 0; i < nums; ++i) {
        getchar();
        bool isOk = Caculate();
        cout << (isOk ? "OK" : "LIE") << endl;
    }

    return 0;
}
